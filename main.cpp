#include "mainwindow.h"// Inclusion du fichier d'en-tête généré par Qt
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QIcon>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow; // Utilisation de votre classe personnalisée MainWindow

    mainWindow.show();
    return app.exec();
}
