#include<QtWidgets>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scribblearea.h"

//MainWindow::MainWindow(QWidget *parent)
//    : QMainWindow(parent)
//    , ui(new Ui::MainWindow)
//{
//    ui->setupUi(this);
//}

MainWindow::~MainWindow()
{
    scribbleArea = new ScribbleArea;
    setCentralWidget(scribbleArea);
    createActions();
    createMenus();
    setWindowTitle(tr("Scribble"));
    resize(500,500);
}

void MainWindow:: closeEvent(QCloseEvent *event){
    if(maybeSave()){
        event->accept();
    }else {
        event->ignore();
    }
}
void MainWindow::open(){
    if(maybeSave()){
        QString fileName = QFileDialog::getOpenFileName(this,
                 tr("Open File"),QDir::currentPath());
        if(!fileName.isEmpty()){
            scribbleArea->openImage(fileName);
        }
    }
}

void MainWindow::save(){
    QAction *action = qobject_cast<QAction *>(sender());
    QByte fileFormat = action->data().toByteArray();
    saveFile(fileFormat);
}
void MainWindow:: penColor(){
    QColor newColor = QColorDialog::getColor(scribblearea->penColor());
    if(newColor.isValid()){
        scribbleArea->setPenColor(newColor);
    }
}

void MainWindow:: penWidth(){
    bool ok;
    int newWidth = QInputDialog::getInt(this,tr("Scribble"),
                                     tr("Select pen width : "),
                                        ScribbleArea->penWidth(),
                                        1,50,1, &ok);
    
    if(ok){
        ScribbleArea->setPenWidth(newWidth);
    } 
}

void MainWindow::about(){
    QMessageBox::about(this, tr("About Scribble"),
                       tr("<p>The <b>Scribble</b> example is awesome</b>"));
    
}

void MainWindow::createActions(){
    openAct = new QAction(tr("&Open"),this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct,SIGNAL(triggered()),this, SLOT(open()));
    foreach (QByteArray format,QImageWriter::supportedImageFormats()) {
        QString text = tr("%1...").arg(QString(format).toUpper());
        QAction *action = new QAction(text,this);
        action->setData(format);
        connet(action,SIGNAL(triggered()),this,SLOT(save()));
        saveAsActs.append(action);
    }
    printAct = new QAction(tr("&Print..."),this);
    connect(printAct,SIGNAL(triggered()),scribbleArea,SLOT(print()));
    exitAct = new QActions(tr("E&xit"),this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct,SIGNAL(triggered()),this,SLOT(close()));

    penColorAct = new QAction(tr("&Pen Color..."),this);
    connect(penColorAct,SIGNAL(triggered()),scribbleArea,SLOT(penColor()));


}





















