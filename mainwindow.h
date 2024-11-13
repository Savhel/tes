#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "processus.h"
#include "listResult.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
        void reloadTableProc();
        void FCFS();
        void startGanttDiagramFCFS();
        void updateGanttDiagramFCFS();
        void SJF();
        void startGanttDiagramSJF();
        void updateGanttDiagramSJF();
        void SRTF();
        void startGanttDiagramSRTF();
        void updateGanttDiagramSRTF();
        void updateGanttDiagramRRP();
        void RR();
        // void afficherOrdreExecution();
        void afficherDiagrammeGantt();
        void startGanttDiagramRR();
        void startGanttDiagramRRP();
        void trierParPriorite();
        void calculerTempsAttente();
        void calculerTempsSejour();
        void RRP();
        void resetState();
private:
    Ui::MainWindow *ui;
    int NB_PROCESSUS;
    std::vector<Processus> proc;
    std::vector<Processus> proc2;
    std::vector<result> Result;
    QTimer *timer;
    QTimer *timerSJF;
    QTimer *timerSRTF;
    QTimer *timerRR;
    QTimer *timerRRP;
    QString dataFCFS;
    QString dataSJF;
    QString dataRR;
    QString dataSRTF;
    QString dataRRP;
    QString ganttDiagram;
    QString ganttDiagramFCFS;
    QString ganttDiagramSJF;
    QString ganttDiagramRR;
    QString ganttDiagramSRTF;
    QString ganttDiagramRRP;
    QString averageTimes;
    int currentIndex;
    int totalProcesses;
    int gantt_index;
    int nbExecutions = 0;
    int quantum = 2;
    std::vector<int> gantt_process;
    std::vector<int> ordreExecution;
    std::vector<int> gantt_times;
    std::vector<int> completion_time;
    std::vector<int> temp_attente;
    std::vector<int> temp_sejour;
    std::vector<int> temp_fin;
    std::vector<int> remaining_temp;


};
#endif // MAINWINDOW_H
