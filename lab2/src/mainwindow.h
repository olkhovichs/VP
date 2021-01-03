#define MAINWINDOW_H

#include <QMainWindow>
#include <QtXML>
#include <QFileDialog>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QListWidgetItem>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void parsingXML();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

