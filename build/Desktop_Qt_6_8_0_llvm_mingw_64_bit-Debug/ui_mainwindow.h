/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *Acceuil;
    QLabel *label;
    QTextBrowser *textBrowser;
    QPushButton *Sortir;
    QPushButton *Lancer;
    QWidget *page2;
    QPushButton *retour3;
    QWidget *widget;
    QPushButton *FCFS_button;
    QPushButton *SJF_button;
    QPushButton *RR_button;
    QPushButton *SRTF_button;
    QPushButton *RRP_button;
    QTextBrowser *textBrowser_2;
    QLabel *label_4;
    QWidget *page1;
    QPushButton *retour2;
    QPushButton *lancerUnAlgo;
    QPushButton *comparerLesAlgo;
    QLabel *label_2;
    QLabel *label_3;
    QTableWidget *tableProcessGenerer;
    QPushButton *actualiser;
    QWidget *page4;
    QLabel *label_6;
    QTextEdit *diagrammeDeGanttFcfs_2;
    QTextEdit *diagrammeDeGanttSJF_2;
    QTextEdit *diagrammeDeGanttRR_2;
    QTextEdit *diagrammeDeGanttSRT_2;
    QTextEdit *diagrammeDeGanttRRP_2;
    QPushButton *retour5;
    QWidget *page3;
    QLabel *label_5;
    QPushButton *retour4;
    QTableWidget *tableProcessEnd;
    QTextEdit *Temps;
    QTextEdit *diagrammeDeGanttFcfs;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaylistShuffle));
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, -20, 800, 600));
        stackedWidget->setMinimumSize(QSize(800, 600));
        stackedWidget->setMaximumSize(QSize(800, 600));
        Acceuil = new QWidget();
        Acceuil->setObjectName("Acceuil");
        Acceuil->setMinimumSize(QSize(800, 600));
        Acceuil->setMaximumSize(QSize(800, 600));
        Acceuil->setAutoFillBackground(true);
        label = new QLabel(Acceuil);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 60, 621, 51));
        QFont font;
        font.setPointSize(24);
        font.setWeight(QFont::ExtraBold);
        font.setUnderline(true);
        label->setFont(font);
        textBrowser = new QTextBrowser(Acceuil);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(50, 210, 701, 160));
        textBrowser->setMinimumSize(QSize(701, 160));
        textBrowser->setMaximumSize(QSize(701, 160));
        Sortir = new QPushButton(Acceuil);
        Sortir->setObjectName("Sortir");
        Sortir->setGeometry(QRect(50, 480, 151, 71));
        QFont font1;
        font1.setPointSize(15);
        font1.setItalic(true);
        Sortir->setFont(font1);
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        Sortir->setIcon(icon1);
        Lancer = new QPushButton(Acceuil);
        Lancer->setObjectName("Lancer");
        Lancer->setGeometry(QRect(560, 480, 191, 71));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial Black")});
        font2.setPointSize(21);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(true);
        Lancer->setFont(font2);
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::SyncSynchronizing));
        Lancer->setIcon(icon2);
        stackedWidget->addWidget(Acceuil);
        page2 = new QWidget();
        page2->setObjectName("page2");
        retour3 = new QPushButton(page2);
        retour3->setObjectName("retour3");
        retour3->setGeometry(QRect(300, 520, 141, 41));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setItalic(true);
        retour3->setFont(font3);
        widget = new QWidget(page2);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 280, 761, 91));
        FCFS_button = new QPushButton(widget);
        FCFS_button->setObjectName("FCFS_button");
        FCFS_button->setGeometry(QRect(30, 20, 111, 51));
        SJF_button = new QPushButton(widget);
        SJF_button->setObjectName("SJF_button");
        SJF_button->setGeometry(QRect(180, 20, 111, 51));
        RR_button = new QPushButton(widget);
        RR_button->setObjectName("RR_button");
        RR_button->setGeometry(QRect(330, 20, 111, 51));
        SRTF_button = new QPushButton(widget);
        SRTF_button->setObjectName("SRTF_button");
        SRTF_button->setGeometry(QRect(480, 20, 111, 51));
        RRP_button = new QPushButton(widget);
        RRP_button->setObjectName("RRP_button");
        RRP_button->setGeometry(QRect(620, 20, 121, 51));
        textBrowser_2 = new QTextBrowser(page2);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(70, 170, 641, 91));
        label_4 = new QLabel(page2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 30, 621, 51));
        label_4->setFont(font);
        stackedWidget->addWidget(page2);
        page1 = new QWidget();
        page1->setObjectName("page1");
        retour2 = new QPushButton(page1);
        retour2->setObjectName("retour2");
        retour2->setGeometry(QRect(322, 528, 141, 41));
        retour2->setFont(font3);
        lancerUnAlgo = new QPushButton(page1);
        lancerUnAlgo->setObjectName("lancerUnAlgo");
        lancerUnAlgo->setGeometry(QRect(40, 480, 191, 51));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setUnderline(true);
        lancerUnAlgo->setFont(font4);
        comparerLesAlgo = new QPushButton(page1);
        comparerLesAlgo->setObjectName("comparerLesAlgo");
        comparerLesAlgo->setGeometry(QRect(530, 480, 231, 51));
        QFont font5;
        font5.setPointSize(11);
        font5.setBold(true);
        font5.setUnderline(true);
        comparerLesAlgo->setFont(font5);
        label_2 = new QLabel(page1);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 30, 621, 51));
        label_2->setFont(font);
        label_3 = new QLabel(page1);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 80, 621, 51));
        QFont font6;
        font6.setPointSize(17);
        font6.setWeight(QFont::ExtraBold);
        font6.setUnderline(true);
        label_3->setFont(font6);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tableProcessGenerer = new QTableWidget(page1);
        if (tableProcessGenerer->columnCount() < 9)
            tableProcessGenerer->setColumnCount(9);
        QFont font7;
        font7.setPointSize(7);
        font7.setBold(true);
        font7.setUnderline(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font7);
        tableProcessGenerer->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font8;
        font8.setPointSize(6);
        font8.setBold(true);
        font8.setUnderline(true);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font8);
        tableProcessGenerer->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font8);
        tableProcessGenerer->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QFont font9;
        font9.setBold(true);
        font9.setUnderline(true);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font9);
        tableProcessGenerer->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font8);
        tableProcessGenerer->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font8);
        tableProcessGenerer->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font8);
        tableProcessGenerer->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font7);
        tableProcessGenerer->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font8);
        tableProcessGenerer->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tableProcessGenerer->setObjectName("tableProcessGenerer");
        tableProcessGenerer->setGeometry(QRect(40, 130, 731, 341));
        QFont font10;
        font10.setBold(true);
        tableProcessGenerer->setFont(font10);
        tableProcessGenerer->setTabKeyNavigation(false);
        tableProcessGenerer->horizontalHeader()->setDefaultSectionSize(81);
        tableProcessGenerer->verticalHeader()->setVisible(false);
        actualiser = new QPushButton(page1);
        actualiser->setObjectName("actualiser");
        actualiser->setGeometry(QRect(710, 90, 51, 31));
        actualiser->setFont(font3);
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::ViewRefresh));
        actualiser->setIcon(icon3);
        stackedWidget->addWidget(page1);
        page4 = new QWidget();
        page4->setObjectName("page4");
        label_6 = new QLabel(page4);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(90, 30, 621, 51));
        label_6->setFont(font);
        diagrammeDeGanttFcfs_2 = new QTextEdit(page4);
        diagrammeDeGanttFcfs_2->setObjectName("diagrammeDeGanttFcfs_2");
        diagrammeDeGanttFcfs_2->setGeometry(QRect(40, 80, 731, 81));
        diagrammeDeGanttSJF_2 = new QTextEdit(page4);
        diagrammeDeGanttSJF_2->setObjectName("diagrammeDeGanttSJF_2");
        diagrammeDeGanttSJF_2->setGeometry(QRect(40, 170, 731, 81));
        diagrammeDeGanttRR_2 = new QTextEdit(page4);
        diagrammeDeGanttRR_2->setObjectName("diagrammeDeGanttRR_2");
        diagrammeDeGanttRR_2->setGeometry(QRect(40, 260, 731, 81));
        diagrammeDeGanttSRT_2 = new QTextEdit(page4);
        diagrammeDeGanttSRT_2->setObjectName("diagrammeDeGanttSRT_2");
        diagrammeDeGanttSRT_2->setGeometry(QRect(40, 350, 731, 81));
        diagrammeDeGanttRRP_2 = new QTextEdit(page4);
        diagrammeDeGanttRRP_2->setObjectName("diagrammeDeGanttRRP_2");
        diagrammeDeGanttRRP_2->setGeometry(QRect(40, 440, 731, 81));
        retour5 = new QPushButton(page4);
        retour5->setObjectName("retour5");
        retour5->setGeometry(QRect(320, 530, 131, 31));
        retour5->setFont(font3);
        stackedWidget->addWidget(page4);
        page3 = new QWidget();
        page3->setObjectName("page3");
        label_5 = new QLabel(page3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(80, 30, 621, 51));
        label_5->setFont(font);
        retour4 = new QPushButton(page3);
        retour4->setObjectName("retour4");
        retour4->setGeometry(QRect(310, 540, 131, 31));
        retour4->setFont(font3);
        tableProcessEnd = new QTableWidget(page3);
        if (tableProcessEnd->columnCount() < 9)
            tableProcessEnd->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font7);
        tableProcessEnd->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font8);
        tableProcessEnd->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font8);
        tableProcessEnd->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font9);
        tableProcessEnd->setHorizontalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font8);
        tableProcessEnd->setHorizontalHeaderItem(4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font8);
        tableProcessEnd->setHorizontalHeaderItem(5, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font8);
        tableProcessEnd->setHorizontalHeaderItem(6, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font7);
        tableProcessEnd->setHorizontalHeaderItem(7, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font8);
        tableProcessEnd->setHorizontalHeaderItem(8, __qtablewidgetitem17);
        tableProcessEnd->setObjectName("tableProcessEnd");
        tableProcessEnd->setGeometry(QRect(30, 90, 731, 291));
        tableProcessEnd->setFont(font10);
        tableProcessEnd->setStyleSheet(QString::fromUtf8("td:{\n"
"	text-align: center;\n"
"}"));
        tableProcessEnd->setTabKeyNavigation(false);
        tableProcessEnd->horizontalHeader()->setDefaultSectionSize(81);
        tableProcessEnd->verticalHeader()->setVisible(false);
        Temps = new QTextEdit(page3);
        Temps->setObjectName("Temps");
        Temps->setGeometry(QRect(30, 480, 731, 61));
        diagrammeDeGanttFcfs = new QTextEdit(page3);
        diagrammeDeGanttFcfs->setObjectName("diagrammeDeGanttFcfs");
        diagrammeDeGanttFcfs->setGeometry(QRect(30, 390, 731, 81));
        stackedWidget->addWidget(page3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Planification des processus", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "PLANIFICATION DES PROCESSUS", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:700;\">Simulation de la planification des processus dans un ordinateur . </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:700;\">Nous avons programmer quelquels algorithmes d'ordenancement des processus dans un ordinateur ... </sp"
                        "an></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:700;\">Appuyer sur lancer pour commencer la simulation</span></p></body></html>", nullptr));
        Sortir->setText(QCoreApplication::translate("MainWindow", "Sortir", nullptr));
        Lancer->setText(QCoreApplication::translate("MainWindow", "Lancer", nullptr));
        retour3->setText(QCoreApplication::translate("MainWindow", "<- RETOUR", nullptr));
        FCFS_button->setText(QCoreApplication::translate("MainWindow", "FCFS", nullptr));
        SJF_button->setText(QCoreApplication::translate("MainWindow", "SJF", nullptr));
        RR_button->setText(QCoreApplication::translate("MainWindow", "Round Robin", nullptr));
        SRTF_button->setText(QCoreApplication::translate("MainWindow", "SRTF", nullptr));
        RRP_button->setText(QCoreApplication::translate("MainWindow", "Round Robin v2", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-style:italic;\">Pour les processus pr\303\251cedents choisissez suivant quel algorithme ils seront ex\303\251cut\303\251s.</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "PLANIFICATION DES PROCESSUS", nullptr));
        retour2->setText(QCoreApplication::translate("MainWindow", "<- RETOUR", nullptr));
        lancerUnAlgo->setText(QCoreApplication::translate("MainWindow", "Simuler un algorithme", nullptr));
        comparerLesAlgo->setText(QCoreApplication::translate("MainWindow", "Comparer les algorithmes", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "PLANIFICATION DES PROCESSUS", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Liste des processus g\303\251n\303\251rer al\303\251atoirement", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableProcessGenerer->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableProcessGenerer->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Execution", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableProcessGenerer->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Attente", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableProcessGenerer->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Fin", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableProcessGenerer->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Arriv\303\251e", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableProcessGenerer->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "D\303\251but", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableProcessGenerer->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "S\303\251jour", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableProcessGenerer->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Restant", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableProcessGenerer->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Priorit\303\251", nullptr));
        actualiser->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "PLANIFICATION DES PROCESSUS", nullptr));
        retour5->setText(QCoreApplication::translate("MainWindow", "<- RETOUR", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "PLANIFICATION DES PROCESSUS", nullptr));
        retour4->setText(QCoreApplication::translate("MainWindow", "<- RETOUR", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableProcessEnd->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableProcessEnd->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Execution", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableProcessEnd->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Attente", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableProcessEnd->horizontalHeaderItem(3);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Fin", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableProcessEnd->horizontalHeaderItem(4);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Arriv\303\251e", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableProcessEnd->horizontalHeaderItem(5);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "D\303\251but", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableProcessEnd->horizontalHeaderItem(6);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "S\303\251jour", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableProcessEnd->horizontalHeaderItem(7);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "Restant", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableProcessEnd->horizontalHeaderItem(8);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "Priorit\303\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
