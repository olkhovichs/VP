#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {}

MainWindow::~MainWindow() {}

void MainWindow::writeToXML() {
    QFile* file = new QFile("config.xml");
        /*if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            emit Log(tr("Error of opening config"), LOG_LEVEL_ERROR);
            return false;
        }*/
     QXmlStreamReader xml(file);

     while (!xml.atEnd() && !xml.hasError())
         {
             QXmlStreamReader::TokenType token = xml.readNext();
             if (token == QXmlStreamReader::StartDocument)
                 continue;
             if (token == QXmlStreamReader::StartElement)
             {
                 if (xml.name() == "etaps")
                     continue;
                 if (xml.name() == "etap")
                     XMLConf.append(parseEtap(xml));
             }
         }
}

