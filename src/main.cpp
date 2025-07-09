#include <QApplication>
#include "gui/wallet_window.h"
#include "gui/splashscreen.cpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    showSplashScreen();

    WalletWindow wallet;
    wallet.show();

    return app.exec();
}
