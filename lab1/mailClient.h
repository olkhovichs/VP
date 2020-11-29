#pragma once

#include "ui_mailClient.h"

#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QListWidget>
#include <QGroupBox>
#include <QTextCodec>


namespace Ui {
    class mailClient;
}

class mailClient : public QMainWindow {

    Q_OBJECT

public:
    explicit mailClient(QWidget* parent = Q_NULLPTR);

    static const int windowWidth = 1080;
    static const int windowHeight = 720;

    void setMenuBar();
    void setInterface();

private:
    Ui::mailClientClass ui;

    QMenu* menu = new QMenu;

    QAction* quit = new QAction("Quit", this);
    QAction* newEmail = new QAction("New email", this);
    QAction* deleteEmail = new QAction("Delete", this);
    QAction* setting = new QAction("Setting", this);

    QWidget* centralWidget = new QWidget;
    QListWidget* listMails = new QListWidget;
    QListWidget* listEmails = new QListWidget;
    QListWidget* textEmail = new QListWidget;
    QGroupBox* groupBoxButtons = new QGroupBox;

    QHBoxLayout* centralLayout = new QHBoxLayout;
    QHBoxLayout* hBoxButtons = new QHBoxLayout;
    QVBoxLayout* vBoxRight = new QVBoxLayout;

    QPushButton* replay = new QPushButton(trUtf8("Àïð"), this);
    QPushButton* deleteMail = new QPushButton("Delete", this);
    QPushButton* spam = new QPushButton("Spam", this);
};