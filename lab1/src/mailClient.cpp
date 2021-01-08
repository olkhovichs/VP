#include "mailClient.h"

#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QListWidget>
#include <QGroupBox>

mailClient::mailClient(QWidget *parent)
    : QMainWindow(parent) {
    ui.setupUi(this);

    resize(windowWidth, windowHeight);
    setWindowTitle("Ïî÷ò");
    setWindowIcon(QIcon("windowIcon.png"));
    this->setCentralWidget(centralWidget);
    
    setMenuBar();
    setInterface();
}

void mailClient::setMenuBar() {
    menu = menuBar()->addMenu("Menu");
    menu->addAction(newEmail);
    menu->addAction(deleteEmail);
    menu->addAction(setting);
    menu->addAction(quit);
    connect(newEmail, &QAction::triggered, qApp, QApplication::beep);
    connect(deleteEmail, &QAction::triggered, qApp, QApplication::beep);
    connect(setting, &QAction::triggered, qApp, QApplication::beep);
    connect(quit, &QAction::triggered, qApp, QApplication::quit);
    connect(quit, &QAction::triggered, qApp, QApplication::beep);
}

void mailClient::setInterface() {
    hBoxButtons->setSpacing(3);
    hBoxButtons->addWidget(replay);
    hBoxButtons->addWidget(deleteMail);
    hBoxButtons->addWidget(spam);
    groupBoxButtons->setTitle("Manage emails");
    groupBoxButtons->setLayout(hBoxButtons);

    listEmails->addItem("Important email");
    listEmails->addItem("Spam");
    listEmails->addItem("Spam");
    listEmails->addItem("Spam");
    textEmail->addItem("Some kind spam");

    vBoxRight->addWidget(listEmails);
    vBoxRight->addWidget(groupBoxButtons);
    vBoxRight->addWidget(textEmail);

    centralLayout->addWidget(listMails);
    centralLayout->addLayout(vBoxRight);

    this->centralWidget->setLayout(centralLayout);
}


