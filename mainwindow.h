//#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>

//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

class scribbleArea;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
        void closEvent(QCloseEvent *event);

private slots:
        void opem();
        void save();
        void penColor();
        void penWidth();
        void about();

private:
//    Ui::MainWindow *ui;
    void createActions();
    void createMenus();
    bool maybeSave();
    bool saveFile(const QByteArray &fileFormate);
    scribblearea *scribbleArea;
    QMenu *saveAsMenu;
    QMenu *fileMenu;
    QMenu *optionMenu;
    QMenu *helpMenu;
    QAction *openAct;
    QList<QAction *> saveAsActs;
    QAction *penColorAct;
    QAction *penWidthAct;
    QAction *printAct;
    QAction *clearScreenAct;
    QAction *aboutAct;
    QAction *aboutQtAct;



};
//#endif // MAINWINDOW_H
