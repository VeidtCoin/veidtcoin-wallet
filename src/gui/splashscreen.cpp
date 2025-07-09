#include <QSplashScreen>
#include <QPixmap>
#include <QThread>
#include <QApplication>

void showSplashScreen() {
    QPixmap pixmap("resources/splash.png");
    QSplashScreen splash(pixmap);
    splash.show();

    QThread::sleep(2); // Simulate loading delay
    qApp->processEvents();
    splash.close();
}
