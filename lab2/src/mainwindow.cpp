#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {}

MainWindow::~MainWindow() {}

void MainWindow::parsingXML() {
    auto xmlFile = new QFile("config.xml");
            if (!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
                    QMessageBox::critical(this,"Load XML File Problem",
                    "Couldn't open xmlfile.xml to load settings for download",
                    QMessageBox::Ok);
                    return;
            }
    auto xmlReader = new QXmlStreamReader(xmlFile);


    //Parse the XML until we reach end of it
    while(!xmlReader->atEnd() && !xmlReader->hasError()) {
            // Read next element
            QXmlStreamReader::TokenType token = xmlReader->readNext();
            //If token is just StartDocument - go to next
            if(token == QXmlStreamReader::StartDocument) {
                    continue;
            }
            //If token is StartElement - read it
            if(token == QXmlStreamReader::StartElement) {

                    if(xmlReader->name() == "name") {
                            continue;
                    }

                    if(xmlReader->name() == "id") {
                        qDebug() << xmlReader->readElementText();
                    }
            }
    }

    if(xmlReader->hasError()) {
            QMessageBox::critical(this,
            "xmlFile.xml Parse Error",xmlReader->errorString(),
            QMessageBox::Ok);
            return;
    }

    //close reader and flush file
    xmlReader->clear();
    xmlFile->close();
}
