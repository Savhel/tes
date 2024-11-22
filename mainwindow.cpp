// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QDebug>
#include <QPixmap>
#include <QIcon>
#include <QTimer>
#include "processus.h"
#include "FCFS_wrapper.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(new QTimer(this))
    , timer2(new QTimer(this))
    , timerSJF(new QTimer(this))
    , timerSRTF(new QTimer(this))
    ,timerRR(new QTimer(this))
    ,timerRRP(new QTimer(this))
    , currentIndex(0)
    , totalProcesses(0)
{
    ui->setupUi(this);

    QIcon icon(":/verrouiller.png");
    ui->Lancer->setIcon(icon);

    QIcon icone(":/sortir.png");
    ui->Sortir->setIcon(icone);

    ui->Sortir->setStyleSheet("QPushButton { "
                              "background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 0), stop:1 rgba(255, 255, 255, 0)); "
                              "color: white; "
                              "border-radius: 10px; "
                              "border-width: 1px; "
                              "border-style: solid; "
                              "} "
                              "QPushButton:hover { "
                              "background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 red, stop:1 white); "
                              "border: none;"
                              "color : black;"
                              "}");

    ui->Lancer->setStyleSheet("QPushButton { "
                              "background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 0), stop:1 rgba(255, 255, 255, 0)); "
                              "color: white; "
                              "border-radius: 10px; "
                              "border-width: 1px; "
                              "border-style: solid; "
                              "} "
                              "QPushButton:hover { "
                              "background: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 white, stop:1 white); "
                              "border: none;"
                              "color : black;"
                              "border-radius: 10px;"
                              "}");

    ui->tableProcessGenerer->setStyleSheet("background: rgba(255, 255, 255, 0); border-width: 1px; border-style: solid; border-radius: 10px");

    ui->textBrowser->setStyleSheet("background: rgba(255, 255, 255, 0); border: none;");

    QLabel *background = new QLabel(ui->page1);
    QPixmap pixmap(":/Car_Dark2.png");
    pixmap = pixmap.scaled(ui->stackedWidget->size(), Qt::KeepAspectRatioByExpanding);
    background->setPixmap(pixmap);
    background->setGeometry(ui->stackedWidget->rect());
    background->lower();  // Pour envoyer le QLabel en arrière-plan
    pixmap = pixmap.scaled(size(), Qt::KeepAspectRatioByExpanding);
    background->setPixmap(pixmap);

    connect(ui->retour2, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->Acceuil);  // Retourner à l'accueil
    });

    connect(ui->Sortir, &QPushButton::clicked, qApp, &QApplication::quit);

    background = new QLabel(ui->Acceuil);
    QPixmap pixmap1(":/Car_Dark.png");
    pixmap1 = pixmap1.scaled(ui->stackedWidget->size(), Qt::KeepAspectRatioByExpanding);
    background->setPixmap(pixmap1);
    background->setGeometry(ui->stackedWidget->rect());
    background->lower();  // Pour envoyer le QLabel en arrière-plan
    pixmap1 = pixmap1.scaled(size(), Qt::KeepAspectRatioByExpanding);
    background->setPixmap(pixmap1);

    reloadTableProc();

    connect(ui->Lancer, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->page1);
    });
    connect(ui->lancerUnAlgo, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->page2);
    });
    connect(ui->retour3, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->page1);
    });
    connect(ui->retour5, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->page1);
    });
    connect(ui->retour4, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->page2);
    });
    connect(ui->FCFS_button, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->page3);
        FCFS();
    });
    connect(ui->SJF_button, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->page3);
        SJF();
    });
    connect(ui->SRTF_button, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->page3);
        SRTF();
    });
    connect(ui->RR_button, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->page3);
        RR();
    });
    connect(ui->RRP_button, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->page3);
         RRP();
    });
    connect(ui->actualiser, &QPushButton::clicked, [this](){
        reloadTableProc();
    });
    connect(ui->comparerLesAlgo, &QPushButton::clicked, [this](){
        ui->stackedWidget->setCurrentWidget(ui->page4);
        // FCFS();
        // resetState();
        // SJF();
        // resetState();
        // // RR();
        // resetState();
        // // SRTF();
        // resetState();
        // RRP();
    });

    connect(timer, &QTimer::timeout, this, &MainWindow::updateGanttDiagramFCFS);
    connect(timerSJF, &QTimer::timeout, this, &MainWindow::updateGanttDiagramSJF);
    connect(timerSRTF, &QTimer::timeout, this, &MainWindow::updateGanttDiagramSRTF);
    connect(timerRR, &QTimer::timeout, this, &MainWindow::afficherDiagrammeGantt);
    connect(timerRRP, &QTimer::timeout, this, &MainWindow::updateGanttDiagramRRP);
}

void MainWindow::reloadTableProc(){
    Result.resize(5);
    srand(time(NULL)); // Initialisation du générateur de nombres aléatoires avec le temps actuel

    NB_PROCESSUS = rand() % 20 + 1;
    proc2.resize(NB_PROCESSUS);
    proc.resize(NB_PROCESSUS);  // Initialisez le vecteur avec la bonne taille

    for (int i = 0; i < NB_PROCESSUS; i++) {
        proc[i].id = i + 1;
        proc[i].temps_execution = rand() % 10 + 1;
        proc[i].temps_attente = 0;
        proc[i].temps_arriver = rand() % 10 + 1;
        proc[i].temps_fin = 0;
        proc[i].temps_sejour = 0;
        proc[i].heures_debut = 0;
        proc[i].temps_restant = 0;
        proc[i].priorite = rand() % 10 + 1;
    }
    for (int i = 0; i < NB_PROCESSUS; ++i) {
        proc2[i] = proc[i];
    }

    // ui->tableProcessGenerer->clearContents();
    ui->tableProcessGenerer->setRowCount(NB_PROCESSUS);
    for (int i = 0; i < NB_PROCESSUS; ++i) {
        ui->tableProcessGenerer->setItem(i, 0, new QTableWidgetItem(QString::number(proc2[i].id)));
        ui->tableProcessGenerer->setItem(i, 1, new QTableWidgetItem(QString::number(proc2[i].temps_execution)));
        ui->tableProcessGenerer->setItem(i, 2, new QTableWidgetItem(QString::number(proc2[i].temps_attente)));
        ui->tableProcessGenerer->setItem(i, 3, new QTableWidgetItem(QString::number(proc2[i].temps_fin)));
        ui->tableProcessGenerer->setItem(i, 4, new QTableWidgetItem(QString::number(proc2[i].temps_arriver)));
        ui->tableProcessGenerer->setItem(i, 5, new QTableWidgetItem(QString::number(proc2[i].heures_debut)));
        ui->tableProcessGenerer->setItem(i, 6, new QTableWidgetItem(QString::number(proc2[i].temps_sejour)));
        ui->tableProcessGenerer->setItem(i, 7, new QTableWidgetItem(QString::number(proc2[i].temps_restant)));
        ui->tableProcessGenerer->setItem(i, 8, new QTableWidgetItem(QString::number(proc2[i].priorite)));
    }
    //FCFS();
}

void MainWindow::FCFS() {
    int n = NB_PROCESSUS;
    temp_attente.resize(n);
    temp_sejour.resize(n);
    completion_time.resize(n);
    std::sort(std::begin(proc), std::end(proc), [](const Processus& a, const Processus& b) {
        return a.temps_arriver < b.temps_arriver;
    });

    // Calcul des temps de fin pour chaque processus
    completion_time[0] = proc[0].temps_arriver + proc[0].temps_execution;

    for (int i = 1; i < n; i++) {
        if (proc[i].temps_arriver > completion_time[i - 1]) {
            completion_time[i] = proc[i].temps_arriver + proc[i].temps_execution;
        } else {
            completion_time[i] = completion_time[i - 1] + proc[i].temps_execution;
        }
    }

    // Calcul du temps de séjour et du temps d'attente
    for (int i = 0; i < n; i++) {
        temp_sejour[i] = completion_time[i] - proc[i].temps_arriver;
        temp_attente[i] = temp_sejour[i] - proc[i].temps_execution;
    }

    // Mettre à jour le tableau des processus
    ui->tableProcessEnd->setRowCount(n);
    for (int i = 0; i < n; ++i) {
        ui->tableProcessEnd->setItem(i, 0, new QTableWidgetItem(QString::number(proc[i].id)));
        ui->tableProcessEnd->setItem(i, 1, new QTableWidgetItem(QString::number(proc[i].temps_execution)));
        ui->tableProcessEnd->setItem(i, 2, new QTableWidgetItem(QString::number(temp_attente[i])));
        ui->tableProcessEnd->setItem(i, 3, new QTableWidgetItem(QString::number(completion_time[i])));
        ui->tableProcessEnd->setItem(i, 4, new QTableWidgetItem(QString::number(proc[i].temps_arriver)));
        if(i == 0){
            ui->tableProcessEnd->setItem(i, 5, new QTableWidgetItem(QString::number(proc[i].temps_arriver)));
        }else{
            ui->tableProcessEnd->setItem(i, 5, new QTableWidgetItem(QString::number(completion_time[i-1])));
        }

        ui->tableProcessEnd->setItem(i, 6, new QTableWidgetItem(QString::number(temp_sejour[i])));
        ui->tableProcessEnd->setItem(i, 7, new QTableWidgetItem(QString::number(proc[i].temps_restant)));
        ui->tableProcessEnd->setItem(i, 8, new QTableWidgetItem(QString::number(proc[i].priorite)));
    }

    // Préparez à afficher le diagramme de Gantt en temps réel
    startGanttDiagramFCFS();
}

void MainWindow::startGanttDiagramFCFS() {
    ganttDiagram.clear();
    ganttDiagram.append("Diagramme de Gantt:\n  ");
    currentIndex = 0;
    totalProcesses = NB_PROCESSUS;
    timer->start(1000);  // Mise à jour toutes les secondes
}

void MainWindow::updateGanttDiagramFCFS() {

    if (currentIndex < totalProcesses) {
        int j = (currentIndex == 0) ? 0 : completion_time[currentIndex - 1];
        ganttDiagram.append("| P" + QString::number(proc[currentIndex].id) + " [");
        ganttDiagramFCFS.append("| P" + QString::number(proc[currentIndex].id) + " [");
        ganttDiagram.append(QString::number(j) + "-----" + QString::number(completion_time[currentIndex]) + "] ");
        ganttDiagramFCFS.append(QString::number(j) + "-----" + QString::number(completion_time[currentIndex]) + "] ");
        // ui->diagrammeDeGanttFcfs_2->setText(dataFCFS);
        ui->diagrammeDeGanttFcfs->setText(ganttDiagram); // Afficher le diagramme dans un QTextBrowser
        currentIndex++;
    } else {
        timer->stop();

        // Calcul et affichage des temps moyens d'attente et de séjour
        float temp_attente_moyen = 0, temp_de_sejour_moyen = 0;
        for (int i = 0; i < totalProcesses; i++) {
            temp_attente_moyen += temp_attente[i];
            temp_de_sejour_moyen += temp_sejour[i];
        }

        // Afficher les temps moyens dans le QTextBrowser
        QString averageTimes;
        dataFCFS.append("\n");
        averageTimes.append("Temps d'attente moyen: " + QString::number(temp_attente_moyen / totalProcesses, 'f', 2) + "\n");
        averageTimes.append("Temps de séjour moyen: " + QString::number(temp_de_sejour_moyen / totalProcesses, 'f', 2) + "\n");
        // Result[0].tempsMoyen = temp_de_sejour_moyen / totalProcesses;
        // Result[0].tempsTotal = temp_attente_moyen / totalProcesses;
        ui->diagrammeDeGanttFcfs_2->setText("Temps d'attente moyen: "+ QString::number(temp_attente_moyen / totalProcesses) + "\n Temps de séjour moyen: " + QString::number(temp_de_sejour_moyen / totalProcesses) );
        ui->Temps->setText(averageTimes); // Ajouter les temps moyens au QTextBrowser

        // qDebug() << proc[3].temps_attente;
        resetState();
        // qDebug() << proc[3].temps_attente;
    }

}

void MainWindow::resetState() {
    ordreExecution.clear();
    nbExecutions = 0;
    ganttDiagram.clear();
    ganttDiagramFCFS.clear();
    currentIndex = 0;
    totalProcesses = NB_PROCESSUS;
    completion_time.resize(NB_PROCESSUS);
    temp_attente.resize(NB_PROCESSUS);
    temp_sejour.resize(NB_PROCESSUS);
    for (int i = 0; i < NB_PROCESSUS; ++i) {
        proc[i] = proc2[i];
    }
}

void MainWindow::findWaitingTimeRRP()
{
    int t = 0; // temps actuel
    std::vector<int> rem_bt(proc.size());
    for (size_t i = 0; i < proc.size(); i++) {
        rem_bt[i] = proc[i].temps_execution;
    }

    while (true) {
        bool done = true;
        for (size_t i = 0; i < proc.size(); i++) {
            if (rem_bt[i] > 0) {
                done = false; // Il reste des Processus à traiter
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    proc[i].temps_attente = t - proc[i].temps_execution;
                    rem_bt[i] = 0;
                }
            }
        }
        if (done) break;
    }
}

void MainWindow::findTurnAroundTimeRRP()
{
    for (auto& p : proc) {
        p.temps_sejour = p.temps_execution + p.temps_attente;
    }
}

void MainWindow::findAvgTimeRRP()
{
    int totalWaitingTime = 0, totalTurnAroundTime = 0;
    findWaitingTimeRRP();
    findTurnAroundTimeRRP();

    ui->tableProcessEnd->setRowCount(NB_PROCESSUS);
    for (int i = 0; i < NB_PROCESSUS; ++i) {

        totalWaitingTime += proc[i].temps_attente;
        totalTurnAroundTime += proc[i].temps_sejour;
        qDebug() << proc[i].temps_execution;
        ui->tableProcessEnd->setItem(i, 0, new QTableWidgetItem(QString::number(0)));
        ui->tableProcessEnd->setItem(i, 1, new QTableWidgetItem(QString::number(proc[i].temps_execution)));
        ui->tableProcessEnd->setItem(i, 2, new QTableWidgetItem(QString::number(proc[i].temps_attente)));
        ui->tableProcessEnd->setItem(i, 3, new QTableWidgetItem(QString::number(proc[i].temps_fin)));
        ui->tableProcessEnd->setItem(i, 4, new QTableWidgetItem(QString::number(proc[i].temps_arriver)));
        ui->tableProcessEnd->setItem(i, 5, new QTableWidgetItem(QString::number(proc[i].heures_debut)));
        ui->tableProcessEnd->setItem(i, 6, new QTableWidgetItem(QString::number(proc[i].temps_sejour)));
        ui->tableProcessEnd->setItem(i, 7, new QTableWidgetItem(QString::number(proc[i].temps_restant)));
        ui->tableProcessEnd->setItem(i, 8, new QTableWidgetItem(QString::number(proc[i].priorite)));
    }

    QString averageTimes;
    dataFCFS.append("\n");
    averageTimes.append("Temps d'attente moyen: " + QString::number(totalWaitingTime / NB_PROCESSUS, 'f', 2) + "\n");
    averageTimes.append("Temps de séjour moyen: " + QString::number(totalTurnAroundTime / NB_PROCESSUS, 'f', 2) + "\n");
    // Result[0].tempsMoyen = temp_de_sejour_moyen / totalProcesses;
    // Result[0].tempsTotal = temp_attente_moyen / totalProcesses;
    ui->diagrammeDeGanttFcfs_2->setText("Temps d'attente moyen: "+ QString::number(totalTurnAroundTime / NB_PROCESSUS) + "\n Temps de séjour moyen: " + QString::number(totalTurnAroundTime / totalProcesses) );
    ui->Temps->setText(averageTimes); // Ajouter les temps moyens au QTextBrowser
}

void MainWindow::runRRP()
{
    std::sort(std::begin(proc), std::end(proc), [](const Processus& a, const Processus& b) {
        return a.temps_arriver < b.temps_arriver;
    });
    findAvgTimeRRP();
}

void MainWindow::printGanttChart()
{
    qDebug() << "\nGantt Chart:\n";
    int t = 0;
    std::vector<std::string> chart;
    std::vector<int> rem_bt(proc.size());
    for (size_t i = 0; i < proc.size(); i++) {
        rem_bt[i] = proc[i].temps_execution;
    }
    while (true) {
        bool done = true;
        for (size_t i = 0; i < proc.size(); i++) {
            if (rem_bt[i] > 0) {
                done = false; // Il reste des Processus à traiter
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    chart.push_back("P" + std::to_string(proc[i].id));
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    chart.push_back("P" + std::to_string(proc[i].id));
                    rem_bt[i] = 0;
                }
            }
        }
        if (done) break;
    }
    for (const auto& p : chart) {
        qDebug() << "| " << p << " ";
    }
    qDebug() << "|\n0";
    t = 0;
    for (const auto& p : chart) {
        t += quantum;
        qDebug() << "    " << t;
    }
    qDebug() << "\n";
}

int MainWindow::mainRRP()
{

    int currentTime = 0;
    runRRP();
    printGanttChart();
    return 0;
}



void MainWindow::SJF() {
    runSJF();
   // startGanttDiagramSJF();

}

void MainWindow::runSJF()
{
    std::sort(std::begin(proc), std::end(proc), [](const Processus& a, const Processus& b) {
        if (a.temps_arriver == b.temps_arriver) {
            // Si les temps d'arrivée sont égaux, trier par temps d'exécution croissant
            return a.temps_execution < b.temps_execution;
        } // Sinon, trier par temps d'arrivée croissant
        return a.temps_arriver < b.temps_arriver;

    });

    startGanttDiagramSJF();
    // tempsMoyenTotalSJF();
}

void MainWindow::tempsAttenteTotalSJF()
{
    proc[0].temps_attente = 0; // Le premier processus n'a pas de temps d'attente
    proc[0].heures_debut = proc[0].temps_arriver;
    proc[0].temps_fin = proc[0].heures_debut + proc[0].temps_execution;

    for (int i = 1; i < NB_PROCESSUS; i++) {

        proc[i].temps_attente = proc[i - 1].temps_fin - proc[i].temps_arriver;
        proc[i].temps_fin = proc[i].temps_attente + proc[i].temps_execution + proc[i].temps_arriver;

        qDebug() << "le temps d'attente "+ QString::number(proc[i].heures_debut);

    }
}

void MainWindow::tempsSejourTotalSJF()
{
    for (int i = 0; i < NB_PROCESSUS; i++) {
        proc[i].temps_sejour = proc[i].temps_fin - proc[i].heures_debut;

    }
}

void MainWindow::tempsMoyenTotalSJF()
{

    int total_wt = 0, total_tat = 0;
    tempsAttenteTotalSJF();
    tempsSejourTotalSJF();

    ui->tableProcessEnd->setRowCount(NB_PROCESSUS);
    for (int i = 0; i < NB_PROCESSUS; ++i) {
        total_wt += proc[i].temps_attente;
        total_tat += proc[i].temps_sejour;
        ui->tableProcessEnd->setItem(i, 0, new QTableWidgetItem(QString::number(proc[i].id)));
        ui->tableProcessEnd->setItem(i, 1, new QTableWidgetItem(QString::number(proc[i].temps_execution)));
        ui->tableProcessEnd->setItem(i, 2, new QTableWidgetItem(QString::number(proc[i].temps_attente)));
        ui->tableProcessEnd->setItem(i, 3, new QTableWidgetItem(QString::number(proc[i].temps_fin)));
        ui->tableProcessEnd->setItem(i, 4, new QTableWidgetItem(QString::number(proc[i].temps_arriver)));
        ui->tableProcessEnd->setItem(i, 5, new QTableWidgetItem(QString::number(proc[i].heures_debut)));
        ui->tableProcessEnd->setItem(i, 6, new QTableWidgetItem(QString::number(proc[i].temps_sejour)));
        ui->tableProcessEnd->setItem(i, 7, new QTableWidgetItem(QString::number(proc[i].temps_restant)));
        ui->tableProcessEnd->setItem(i, 8, new QTableWidgetItem(QString::number(proc[i].priorite)));
    }

    QString averageTimes;
    averageTimes.append("Temps d'attente moyen: " + QString::number(total_wt / NB_PROCESSUS, 'f', 2) + "\n");
    averageTimes.append("Temps de séjour moyen: " + QString::number(total_tat / NB_PROCESSUS, 'f', 2) + "\n");
    ui->Temps->setText(averageTimes);
    ui->diagrammeDeGanttSJF_2->setText(averageTimes );
    startGanttDiagramSJF();

}

int MainWindow::compareBurstTimeSJF(const void *a, const void *b)
{
    Processus *p1 = (Processus *)a;
    Processus *p2 = (Processus *)b;
    return p1->temps_execution - p2->temps_execution;
}

void MainWindow::startGanttDiagramRRP() {
    ganttDiagram.clear();
    ganttDiagram.append("Diagramme de Gantt:\n  ");
    currentIndex = 0;
    totalProcesses = gantt_process.size();
    timerRRP->start(1000);  // Mise à jour toutes les secondes

    connect(timerRRP, &QTimer::timeout, this, &MainWindow::updateGanttDiagramRRP);
}

void MainWindow::updateGanttDiagramRRP() {
    if (currentIndex < totalProcesses) {
        int j = (currentIndex == 0) ? 0 : gantt_times[currentIndex - 1];
        ganttDiagram.append("| P" + QString::number(gantt_process[currentIndex]) + " [");
        ganttDiagram.append(QString::number(j) + "-----" + QString::number(gantt_times[currentIndex]) + "] ");
        ganttDiagramRRP.append("| P" + QString::number(gantt_process[currentIndex]) + " [");
        ganttDiagramRRP.append(QString::number(j) + "-----" + QString::number(gantt_times[currentIndex]) + "] ");
        ui->diagrammeDeGanttFcfs->setText(ganttDiagram); // Afficher le diagramme dans un QTextBrowser
        currentIndex++;
    } else {
        timerRRP->stop();
        // Afficher les temps moyens d'attente et de séjour
        double moyenne_attente = 0, moyenne_sejour = 0;
        for (int i = 0; i < NB_PROCESSUS; i++) {
            moyenne_attente += temp_attente[i];
            moyenne_sejour += temp_sejour[i];
        }
        QString data;
        data.append(" **************** Rapport *****************\n");
        data.append("Temps d'attente moyen: " + QString::number(moyenne_attente / NB_PROCESSUS) + "\n");
        data.append("Temps de séjour moyen: " + QString::number(moyenne_sejour / NB_PROCESSUS));
        ui->Temps->setText(data);
        ui->diagrammeDeGanttRRP_2->setText(data);

        proc.clear();
        for (int i = 0; i < NB_PROCESSUS; ++i) {
            proc[i] = proc2[i];
        }
    }
}


void MainWindow::startGanttDiagramSJF() {
    ganttDiagram.clear();
    qDebug() << "test sur le SJF";
    ganttDiagram.append("Diagramme de Gantt:\n  ");
    currentIndex = 0;
    currentTime = 0;
    totalProcesses = NB_PROCESSUS;
    timerSJF->start(1000);  // Mise à jour toutes les secondes

}
void MainWindow::startGanttDiagramSRTF(){
    ganttDiagram.clear();
    ganttDiagram.append("Diagramme de Gantt:\n  ");
    currentIndex = 0;
    moyenne_attente = 0;
    moyenne_sejour = 0;
    totalProcesses = gantt_index;
    timerSRTF->start(1000);  // Mise à jour toutes les seconde
}
void MainWindow::updateGanttDiagramSJF() {
    qDebug() << QString::number(totalProcesses);
    if (currentIndex < totalProcesses) {
        if(proc[0].temps_arriver <= currentTime){
            proc[0].heures_debut = currentTime;
            proc[0].temps_fin = currentTime + proc[0].temps_execution;
            proc[0].temps_attente = currentTime - proc[0].temps_arriver;
            proc[0].temps_sejour = proc[0].temps_fin - proc[0].temps_arriver;
            currentTime += proc[0].temps_execution;

            ui->tableProcessEnd->setRowCount(currentIndex + 1);
            for (int i = 0; i < currentIndex + 1; ++i) {
                moyenne_attente += proc[i].temps_attente ;
                moyenne_sejour += proc[i].temps_sejour;
                ui->tableProcessEnd->setItem(i, 0, new QTableWidgetItem(QString::number(proc[i].id)));
                ui->tableProcessEnd->setItem(i, 1, new QTableWidgetItem(QString::number(proc[i].temps_execution)));
                ui->tableProcessEnd->setItem(i, 2, new QTableWidgetItem(QString::number(proc[i].temps_attente)));
                ui->tableProcessEnd->setItem(i, 3, new QTableWidgetItem(QString::number(proc[i].temps_fin)));
                ui->tableProcessEnd->setItem(i, 4, new QTableWidgetItem(QString::number(proc[i].temps_arriver)));
                ui->tableProcessEnd->setItem(i, 5, new QTableWidgetItem(QString::number(proc[i].heures_debut)));
                ui->tableProcessEnd->setItem(i, 6, new QTableWidgetItem(QString::number(proc[i].temps_sejour)));
                ui->tableProcessEnd->setItem(i, 7, new QTableWidgetItem(QString::number(proc[i].temps_restant)));
                ui->tableProcessEnd->setItem(i, 8, new QTableWidgetItem(QString::number(proc[i].priorite)));
            }

            qDebug() << QString::number(currentIndex) + " index";
            ganttDiagram.append("| P" + QString::number(proc[0].id) + " [");
            ganttDiagram.append(QString::number(proc[0].heures_debut) + "-----" + QString::number(proc[0].temps_fin) + "] ");

            ganttDiagramSJF.append("| P" + QString::number(proc[0].id) + " [");
            ganttDiagramSJF.append(QString::number(proc[0].heures_debut) + "-----" + QString::number(proc[0].temps_fin) + "] ");

            ui->diagrammeDeGanttFcfs->setText(ganttDiagram); // Afficher le diagramme dans un QTextBrowser
            QString data;
            data.append(" **************** Rapport *****************\n");
            qDebug() << QString::number(moyenne_attente) + " index";
            if(currentIndex > 0){
                data.append("Temps d'attente moyen: " + QString::number(moyenne_attente / currentIndex) + "\n");

                data.append("Temps de séjour moyen: " + QString::number(moyenne_sejour / currentIndex));
            }


            ui->Temps->setText(data);
            Processus process = proc[0];
            for (int var = 1; var < totalProcesses; ++var) {
                proc[var - 1] = proc[var];
            }
            proc[totalProcesses - 1] = process;

            currentIndex++;
        }else{
            currentTime ++;
        }
    } else {

        timerSJF->stop();
    }

}
void MainWindow::updateGanttDiagramSRTF() {
    if (currentIndex < totalProcesses) {
        int j = (currentIndex == 0) ? 0 : gantt_times[currentIndex - 1];
        ganttDiagram.append("| P" + QString::number(gantt_process[currentIndex]) + " [");
        ganttDiagram.append(QString::number(j) + "-----" + QString::number(gantt_times[currentIndex]) + "] ");
        ui->diagrammeDeGanttFcfs->setText(ganttDiagram); // Afficher le diagramme dans un QTextBrowser
        currentIndex++;
    } else {
        timerSRTF->stop();
        // Afficher les temps moyens d'attente et de séjour
        double moyenne_attente = 0, moyenne_sejour = 0;
        qDebug() << "bonjour" ;
        for (int i = 0; i < NB_PROCESSUS; i++) {
            qDebug() << proc[i].temps_attente ;
            moyenne_attente += proc[i].temps_attente;
            moyenne_sejour += proc[i].temps_sejour;
        }



        QString averageTimes;
        averageTimes.append("Temps d'attente moyen: " + QString::number(moyenne_attente / NB_PROCESSUS, 'f', 2) + "\n");
        averageTimes.append("Temps de séjour moyen: " + QString::number(moyenne_sejour / NB_PROCESSUS, 'f', 2) + "\n");
        ui->Temps->setText(averageTimes);
        ui->diagrammeDeGanttSRT_2->setText(averageTimes );

        resetState();
    }
}
// void MainWindow::updateGanttDiagramRRP(){
//     if (currentIndex < totalProcesses) {
//         int j = (currentIndex == 0) ? 0 : gantt_times[currentIndex - 1];
//         ganttDiagram.append("| P" + QString::number(gantt_process[currentIndex]) + " [");
//         ganttDiagram.append(QString::number(j) + "-----" + QString::number(gantt_times[currentIndex]) + "] ");
//         ganttDiagramRRP.append("| P" + QString::number(gantt_process[currentIndex]) + " [");
//         ganttDiagramRRP.append(QString::number(j) + "-----" + QString::number(gantt_times[currentIndex]) + "] ");
//         ui->diagrammeDeGanttFcfs->setText(ganttDiagram); // Afficher le diagramme dans un QTextBrowser
//         currentIndex++;
//     } else {
//         timerRRP->stop();
//         // Afficher les temps moyens d'attente et de séjour
//         double moyenne_attente = 0, moyenne_sejour = 0;
//         for (int i = 0; i < NB_PROCESSUS; i++) {
//             moyenne_attente += temp_attente[i];
//             moyenne_sejour += temp_sejour[i];
//         }
//         QString data;
//         data.append(" **************** Rapport *****************\n");
//         data.append("Temps d'attente moyen: "+ QString::number(moyenne_attente / NB_PROCESSUS)+"\n" );
//         data.append("Temps de séjour moyen: "+ QString::number(moyenne_sejour / NB_PROCESSUS) );
//         ui->Temps->setText(data);
//         ui->diagrammeDeGanttRRP_2->setText(data );

//         proc.clear();
//         for (int i = 0; i < NB_PROCESSUS; ++i) {
//             proc[i] = proc2[i];
//         }
//     }
// }

void MainWindow::RR(){
    averageTimes.clear();
    int n = NB_PROCESSUS;
    ordreExecution.resize(100); // Tableau pour stocker l'ordre d'exécution des processus
    // int nbExecutions = 0; // Compteur pour le nombre d'exécutions
    averageTimes.append("Rapport d'exécution \n");
    // Calculer le temps d'attente et le temps de séjour
    calculerTempsAttente();
    calculerTempsSejour();
    // qDebug() << "bonjour" << Qt::endl;

    // Affichage des résultats
    // printf("Processus    Temps Execution    Temps Attente    Temps Sejour    Temps Arrive    Temps Debut    Temps Fin\n");
    ui->tableProcessEnd->setRowCount(n);
    for (int i = 0; i < n; ++i) {
        ui->tableProcessEnd->setItem(i, 0, new QTableWidgetItem(QString::number(proc[i].id)));
        ui->tableProcessEnd->setItem(i, 1, new QTableWidgetItem(QString::number(proc[i].temps_execution)));
        ui->tableProcessEnd->setItem(i, 2, new QTableWidgetItem(QString::number(proc[i].temps_attente)));
        ui->tableProcessEnd->setItem(i, 3, new QTableWidgetItem(QString::number(proc[i].temps_fin)));
        ui->tableProcessEnd->setItem(i, 4, new QTableWidgetItem(QString::number(proc[i].temps_arriver)));
        ui->tableProcessEnd->setItem(i, 5, new QTableWidgetItem(QString::number(proc[i].heures_debut)));
        ui->tableProcessEnd->setItem(i, 6, new QTableWidgetItem(QString::number(proc[i].temps_sejour)));
        ui->tableProcessEnd->setItem(i, 7, new QTableWidgetItem(QString::number(proc[i].temps_restant)));
        ui->tableProcessEnd->setItem(i, 8, new QTableWidgetItem(QString::number(proc[i].priorite)));
    }

    startGanttDiagramRR();
}

void MainWindow::startGanttDiagramRR(){
    ganttDiagram.clear();
    ganttDiagram.append("Diagramme de Gantt:\n  ");
    currentIndex = 0;
    totalProcesses = gantt_index;
    timerRR->start(1000);  // Mise à jour toutes les seconde
}

void MainWindow::trierParPriorite(){
    for (int i = 0; i < NB_PROCESSUS - 1; i++) {
        for (int j = i + 1; j < NB_PROCESSUS; j++) {
            if (proc[i].priorite < proc[j].priorite) {
                struct Processus temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

void MainWindow::calculerTempsAttente() {
    int t = 0; // Current time
    int fini = 0; // Flag to check if all processes are finished
    int processusRestants = NB_PROCESSUS; // Number of remaining processes
    // QString averageTimes; // To store process execution details

    trierParPriorite();
    for (int i = 0; i < NB_PROCESSUS; i++) {
        proc[i].temps_restant = proc[i].temps_execution;
        proc[i].heures_debut = -1; // Initialize start time to -1 (undefined)
    }

    // Circular traversal of processes until all are completed
    while (processusRestants > 0) {
        fini = 1;
        for (int i = 0; i < NB_PROCESSUS; i++) {

            if (proc[i].temps_arriver <= t && proc[i].temps_restant > 0) {
                fini = 0;
                ordreExecution[nbExecutions] = proc[i].id;
                nbExecutions++;

                // If process has not started yet, record start time
                if (proc[i].heures_debut == -1) {
                    proc[i].heures_debut = t;
                    // averageTimes.append("P_" + QString::number(ordreExecution[nbExecutions - 1]) + " commence à la " + QString::number(t) + " unité de temps\n");
                }

                // Process for a quantum time
                if (proc[i].temps_restant > quantum) {
                    t += quantum;
                    proc[i].temps_restant -= quantum;
                    // averageTimes.append("P_" + QString::number(ordreExecution[nbExecutions - 1]) + " s'execute pour " + QString::number(quantum) + " unités de temps et il lui reste " +QString::number(proc[i].temps_restant) +" unités de temps \n");
                } else {
                    t += proc[i].temps_restant;
                    proc[i].temps_attente = t - proc[i].temps_execution - proc[i].heures_debut;
                    proc[i].temps_restant = 0;
                    proc[i].temps_fin = t; // Calculate finish time
                    // averageTimes.append("P_" + QString::number(ordreExecution[nbExecutions - 1]) + " est fini à " + QString::number(t) + "\n");
                    processusRestants--; // This process is now finished
                }
            }
        }

        // If not all processes are ready yet, advance time
        if (fini == 1) {
            int nextArrival = INT_MAX;
            for (int i = 0; i < NB_PROCESSUS; i++) {
                if (proc[i].temps_arriver > t && proc[i].temps_arriver < nextArrival) {
                    nextArrival = proc[i].temps_arriver;
                }
            }
            if (nextArrival != INT_MAX) {
                t = nextArrival;
            }
        }
    }

    // Display the process execution details
    // qDebug() << averageTimes;
    // Optionally, set the details to a UI element
    // ui->Temps->setText(averageTimes);
}

void MainWindow::calculerTempsSejour(){
    for (int i = 0; i < NB_PROCESSUS; i++) {
        proc[i].temps_sejour = proc[i].temps_fin - proc[i].heures_debut;
    }
}


void MainWindow::RRP() {
    int quantum = 2;
    // Sort processes by arrival time and priority
    std::sort(proc.begin(), proc.end(), [](const Processus& a, const Processus& b) {
        if (a.temps_arriver != b.temps_arriver)
            return a.temps_arriver < b.temps_arriver;
        return a.priorite > b.priorite;
    });
    tempsMoyenTotal();

    ui->tableProcessEnd->setRowCount(NB_PROCESSUS);
    for (int i = 0; i < NB_PROCESSUS; ++i) {
        ui->tableProcessEnd->setItem(i, 0, new QTableWidgetItem(QString::number(proc[i].id)));
        ui->tableProcessEnd->setItem(i, 1, new QTableWidgetItem(QString::number(proc[i].temps_execution)));
        ui->tableProcessEnd->setItem(i, 2, new QTableWidgetItem(QString::number(proc[i].temps_attente)));
        ui->tableProcessEnd->setItem(i, 3, new QTableWidgetItem(QString::number(proc[i].temps_fin)));
        ui->tableProcessEnd->setItem(i, 4, new QTableWidgetItem(QString::number(proc[i].temps_arriver)));
        ui->tableProcessEnd->setItem(i, 5, new QTableWidgetItem(QString::number(proc[i].temps_fin )));
        ui->tableProcessEnd->setItem(i, 6, new QTableWidgetItem(QString::number(proc[i].temps_sejour)));
        ui->tableProcessEnd->setItem(i, 7, new QTableWidgetItem(QString::number(proc[i].temps_restant)));
        ui->tableProcessEnd->setItem(i, 8, new QTableWidgetItem(QString::number(proc[i].priorite)));
    }

    // while (true) {
    //     bool done = true;

    //     for (size_t i = 0; i < proc.size(); ++i) {
    //         if (rem_bt[i] > 0) {
    //             done = false; // There is a pending process

    //             if (rem_bt[i] > quantum) {
    //                 t += quantum;
    //                 rem_bt[i] -= quantum;
    //                 ganttChart.push_back("P" + std::to_string(proc[i].id) + " [" + std::to_string(t - quantum) + " - " + std::to_string(t) + "]");
    //             } else {
    //                 t += rem_bt[i];
    //                 proc[i].temps_attente = t - proc[i].temps_execution;
    //                 rem_bt[i] = 0;
    //                 proc[i].temps_fin = t;
    //                 ganttChart.push_back("P" + std::to_string(proc[i].id) + " [" + std::to_string(t - rem_bt[i]) + " - " + std::to_string(t) + "]");
    //             }
    //         }
    //     }

    //     if (done) break;
    // }

    // for (auto& p : proc) {
    //     p.temps_sejour = p.temps_execution + p.temps_attente;
    // }
    // QString text;
    // // Printing Gantt Chart
    // text.append( "\nGantt Chart:\n");
    // for (const auto& entry : ganttChart) {
    //     text.append( "| " + entry + " ");
    // }
    // text.append("|\n");
    // ui->diagrammeDeGanttFcfs->setText(text);

    // // Printing average times
    // int totalWaitingTime = 0, totalTurnAroundTime = 0;
    // //std::cout << "Processus\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\tEnd Time\n";

    // ui->tableProcessEnd->setRowCount(NB_PROCESSUS);
    // for (int i = 0; i < NB_PROCESSUS; ++i) {
    //     ui->tableProcessEnd->setItem(i, 0, new QTableWidgetItem(QString::number(proc[i].id)));
    //     ui->tableProcessEnd->setItem(i, 1, new QTableWidgetItem(QString::number(proc[i].temps_execution)));
    //     ui->tableProcessEnd->setItem(i, 2, new QTableWidgetItem(QString::number(proc[i].temps_attente)));
    //     ui->tableProcessEnd->setItem(i, 3, new QTableWidgetItem(QString::number(proc[i].temps_fin)));
    //     ui->tableProcessEnd->setItem(i, 4, new QTableWidgetItem(QString::number(proc[i].temps_arriver)));
    //     ui->tableProcessEnd->setItem(i, 5, new QTableWidgetItem(QString::number(proc[i].temps_fin )));
    //     ui->tableProcessEnd->setItem(i, 6, new QTableWidgetItem(QString::number(proc[i].temps_sejour)));
    //     ui->tableProcessEnd->setItem(i, 7, new QTableWidgetItem(QString::number(proc[i].temps_restant)));
    //     ui->tableProcessEnd->setItem(i, 8, new QTableWidgetItem(QString::number(proc[i].priorite)));
    // }

    // averageTimes.append("Temps moyen d'attente : " + QString::number(totalWaitingTime / NB_PROCESSUS) + "\n");
    // averageTimes.append("\nTemps moyen de séjour : "+ QString::number(totalTurnAroundTime / NB_PROCESSUS));
    // ui->Temps->setText(averageTimes);

    /*std::cout << "Average waiting time = " << static_cast<float>(totalWaitingTime) / proc.size() << "\n";
    std::cout << "Average turnaround time = " << static_cast<float>(totalTurnAroundTime) / proc.size() << "\n";*/
}



void MainWindow::afficherDiagrammeGantt(){

    // int t = 0; // Temps global
    int dernierTemps = 0;
    int attente_total = 0;
    int sejour_total = 0;

    // Calculer le dernier temps d'exécution (final)
    for (int i = 0; i < NB_PROCESSUS; i++) {
        attente_total += proc[i].temps_attente;
        sejour_total += proc[i].temps_sejour;
        if (proc[i].temps_fin > dernierTemps) {
            dernierTemps = proc[i].temps_fin;
        }
    }

    // Affichage du diagramme de Gantt sous forme de texte
    if (currentIndex < nbExecutions) {
        if(currentIndex == nbExecutions - 1){
            ganttDiagram.append("P" + QString::number(ordreExecution[currentIndex]));
            ganttDiagramRR.append("P" + QString::number(ordreExecution[currentIndex]));
            ui->diagrammeDeGanttFcfs->setText(ganttDiagram); // Afficher le diagramme dans un QTextBrowser
            currentIndex++;
        }else{
            ganttDiagram.append("P" + QString::number(ordreExecution[currentIndex]) + "___");
            ganttDiagramRR.append("P" + QString::number(ordreExecution[currentIndex]) + "___");
            ui->diagrammeDeGanttFcfs->setText(ganttDiagram); // Afficher le diagramme dans un QTextBrowser
            currentIndex++;
        }
    } else {
        timerRR->stop();
        averageTimes.append("Nous avons eu :"+ QString::number(nbExecutions) +" exécutions processus de quantum secondes avec : \n");

        averageTimes.append("Temps moyen d'attente : " + QString::number(attente_total / NB_PROCESSUS) + "\n");
        averageTimes.append("\nTemps moyen de séjour : "+ QString::number(sejour_total / NB_PROCESSUS));
        ui->Temps->setText(averageTimes);
        ui->diagrammeDeGanttRR_2->setText(averageTimes);

    }

}

void MainWindow::SRTF(){
    int n = NB_PROCESSUS;
    temp_attente.resize(n);
    temp_sejour.resize(n);
    temp_fin.resize(n);
    remaining_temp.resize(n); // Temps d'exécution restant pour chaque processus

    // Initialiser les temps
    for (int i = 0; i < n; i++) {
        remaining_temp[i] = proc[i].temps_execution;
        temp_attente[i] = 0;
        temp_sejour[i] = 0;
        temp_fin[i] = 0;
        proc[i].temps_restant = proc[i].temps_execution;
    }

    int compte = 0, current_time = 0; // Compteur de processus terminés et temps actuel

    // Tableau pour le diagramme de Gantt
    gantt_times.resize(100); // Ajustez la taille si nécessaire
    gantt_process.resize(100); // Ajustez la taille si nécessaire
    gantt_index = 0;

    // Continue jusqu'à ce que tous les processus soient terminés
    while (compte < n) {
        int idx = -1;
        int min_remaining_temps = INT_MAX; // temps d'exécution restant minimum

        // Trouver le processus avec le temps d'exécution restant le plus court qui est prêt à s'exécuter
        for (int i = 0; i < n; i++) {
            if (proc[i].temps_arriver <= current_time && proc[i].temps_restant > 0 && proc[i].temps_restant < min_remaining_temps) {
                min_remaining_temps = proc[i].temps_restant;
                idx = i;
            }
        }

        if (idx != -1) {
            proc[idx].temps_restant--; // Exécuter le processus choisi
            gantt_process[gantt_index] = proc[idx].id; // Enregistrer l'id du processus pour le diagramme de Gantt
            gantt_times[gantt_index] = current_time; // Enregistrer le temps actuel pour le diagramme de Gantt
            gantt_index++;
            current_time++; // Incrémenter le temps actuel

            // Si le processus est terminé
            if (proc[idx].temps_restant == 0) {
                proc[idx].temps_fin = current_time; // Enregistrer le temps de fin
                proc[idx].temps_sejour = current_time - proc[idx].temps_arriver; // Calculer le temps de séjour
                proc[idx].temps_attente = proc[idx].temps_sejour - proc[idx].temps_execution; // Calculer le temps d'attente
                compte++; // Incrémenter le compteur de processus terminés
            }
        } else {
            current_time++; // Si aucun processus n'est prêt, incrémenter le temps actuel
        }
    }

    // Mettre à jour le tableau des processus
    ui->tableProcessEnd->setRowCount(n);
    for (int i = 0; i < n; ++i) {
        ui->tableProcessEnd->setItem(i, 0, new QTableWidgetItem(QString::number(proc[i].id)));
        ui->tableProcessEnd->setItem(i, 1, new QTableWidgetItem(QString::number(proc[i].temps_execution)));
        ui->tableProcessEnd->setItem(i, 2, new QTableWidgetItem(QString::number(proc[i].temps_attente)));
        ui->tableProcessEnd->setItem(i, 3, new QTableWidgetItem(QString::number(proc[i].temps_fin)));
        ui->tableProcessEnd->setItem(i, 4, new QTableWidgetItem(QString::number(proc[i].temps_arriver)));
        ui->tableProcessEnd->setItem(i, 5, new QTableWidgetItem(QString::number(proc[i].temps_fin - proc[i].temps_attente - proc[i].temps_execution)));
        ui->tableProcessEnd->setItem(i, 6, new QTableWidgetItem(QString::number(proc[i].temps_sejour)));
        ui->tableProcessEnd->setItem(i, 7, new QTableWidgetItem(QString::number(proc[i].temps_restant)));
        ui->tableProcessEnd->setItem(i, 8, new QTableWidgetItem(QString::number(proc[i].priorite)));
    }

    // Commencez l'affichage du diagramme de Gantt en temps réel
    startGanttDiagramSRTF();

}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::comparerPriorite(Processus *a, Processus *b)
{
    if(a->temps_arriver == a->temps_arriver){
        return a->priorite < a->priorite;
    }
    return a->temps_arriver < a->temps_arriver;
}

void MainWindow::tempsMoyenTotal()
{
    int temps_attente_total = 0, temps_sejour_total = 0, current_time = 0;
    int remaining_temps[NB_PROCESSUS]; // Temps restant d'exécution pour chaque processus

    // Initialiser les temps
    for (int i = 0; i < NB_PROCESSUS; i++) {
        remaining_temps[i] = proc[i].temps_execution;
        proc[i].temps_attente = 0;
        proc[i].temps_sejour = 0;
        proc[i].temps_fin = 0;
        proc[i].heures_debut = -1; // Initialiser heure de début à -1
    }

    int compte = 0; // Nombre de processus terminés

    // Initialiser le diagramme de Gantt
    int gantt_process[100], gantt_time[100];
    int gantt_index = 0;

    // Effectuer l'algorithme de planification
    while (compte < NB_PROCESSUS) {
        for (int i = 0; i < NB_PROCESSUS; i++) {
            if (remaining_temps[i] > 0) {
                // Si le processus n'a pas encore commencé, affecter son heure de début
                if (proc[i].heures_debut == -1) {
                    proc[i].heures_debut = current_time;
                }

                // Exécuter le processus pendant le quantum ou jusqu'à sa fin
                int temps_a_executer = (remaining_temps[i] > quantum) ? quantum : remaining_temps[i];
                remaining_temps[i] -= temps_a_executer;
                current_time += temps_a_executer;

                // Ajouter les informations au diagramme de Gantt
                for (int j = 0; j < temps_a_executer; j++) {
                    gantt_process[gantt_index] = proc[i].id;
                    gantt_time[gantt_index] = current_time - temps_a_executer + j + 1;
                    gantt_index++;
                }

                // Si le processus termine son exécution
                if (remaining_temps[i] == 0) {
                    proc[i].temps_fin = current_time;
                    proc[i].temps_sejour = proc[i].temps_fin - proc[i].heures_debut; // Calcul du temps de séjour
                    proc[i].temps_attente = proc[i].temps_sejour - proc[i].temps_execution;
                    temps_attente_total += proc[i].temps_attente;
                    temps_sejour_total += proc[i].temps_sejour;
                    compte++; // Incrémenter le nombre de processus terminés
                }
            }
        }
    }

    // Afficher les résultats
    ui->tableProcessEnd->setRowCount(NB_PROCESSUS);
    for (int i = 0; i < NB_PROCESSUS; ++i) {
        ui->tableProcessEnd->setItem(i, 0, new QTableWidgetItem(QString::number(proc[i].id)));
        ui->tableProcessEnd->setItem(i, 1, new QTableWidgetItem(QString::number(proc[i].temps_execution)));
        ui->tableProcessEnd->setItem(i, 2, new QTableWidgetItem(QString::number(proc[i].temps_attente)));
        ui->tableProcessEnd->setItem(i, 3, new QTableWidgetItem(QString::number(proc[i].temps_fin)));
        ui->tableProcessEnd->setItem(i, 4, new QTableWidgetItem(QString::number(proc[i].temps_arriver)));
        ui->tableProcessEnd->setItem(i, 5, new QTableWidgetItem(QString::number(proc[i].heures_debut)));
        ui->tableProcessEnd->setItem(i, 6, new QTableWidgetItem(QString::number(proc[i].temps_sejour)));
        ui->tableProcessEnd->setItem(i, 7, new QTableWidgetItem(QString::number(proc[i].temps_restant)));
        ui->tableProcessEnd->setItem(i, 8, new QTableWidgetItem(QString::number(proc[i].priorite)));
    }

    // Afficher les temps moyens
   // printf("\nTemps d'attente moyen: %.2f\n", (double)temps_attente_total / NB_PROCESSUS);
   // printf("Temps de séjour moyen: %.2f\n", (double)temps_sejour_total / NB_PROCESSUS);
    qDebug() << "testestest";
    averageTimes.append("Temps moyen d'attente : " + QString::number(attente_total / NB_PROCESSUS) + "\n");
    averageTimes.append("\nTemps moyen de séjour : "+ QString::number(sejour_total / NB_PROCESSUS));
    ui->Temps->setText(averageTimes);

    ui->diagrammeDeGanttRR_2->setText(averageTimes);

    // Afficher le diagramme de Gantt
    printf("\nDiagramme de Gantt:\n|");
    for (int i = 0; i < gantt_index; i++) {
        ganttDiagram.append("P" + QString::number(gantt_process[i]) + "___");
        ganttDiagramRR.append("P" + QString::number(gantt_process[i]) + "___");
        printf(" P%d |", gantt_process[i]);
    }
    ganttDiagram.append("\n");
    ganttDiagramRR.append("\n");
    printf("\n");

    for (int i = 0; i < gantt_index; i++) {
        ganttDiagram.append(QString::number(gantt_process[i]) + " ");
        ganttDiagramRR.append(QString::number(gantt_process[i]) + " ");
        printf("%d ", gantt_time[i]);
    }
    printf("%d\n", current_time);

    ui->diagrammeDeGanttFcfs->setText(ganttDiagram); // Afficher le diagramme dans un QTextBrowser
}
