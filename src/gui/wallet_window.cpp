#include "wallet_window.h"
#include <QLabel>

WalletWindow::WalletWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("VeidtCoin Wallet");
    setFixedSize(500, 300);

    QLabel *label = new QLabel("Welcome, Cipherholder.\nYour wealth is unseen.", this);
    label->setAlignment(Qt::AlignCenter);
    label->setGeometry(50, 100, 400, 100);
}
