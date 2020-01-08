#include <QtWidgets>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printdialog)
#include <QPrinter>
#include <QPrintDialog>
#endif
#endif


scribblearea::scribblearea(QWidget *parent): QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    modified = false;
    scribbling = false;
    myPenWidth = 1;
    myPenColor = Qt::blue;
}

bool ScribbleArea::openImage(const QString &fileName){
    QImage loadedImage;
    if(!loadedImage.load(fileName)){
        return false;
    }
    QSize newSize = loadImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    image=loadedImage;
    modified = false;
    update();
    return true;
}
bool ScribbleArea::saveImage(const QString &fileName, const char *fileFormat){
    QImage visibleImage = image;
    resize(&visibleImage, size()){
        modified = false;
        return true;
    }else {
        return false;
    }
}
void ScribbleArea:: setPenColor(const QColor &newColor){
    myPenColor = newColor;
}
void Scribble::setPenWidth(int newWidth){
    myPenWidth = newWidth;
}
void ScribbleArea::clearImage(){
    image.fill(qRgb(255,255,255));
    modified = true;
    update();
}
void ScribbleArea::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::leftButton){
        lastPoint = event->pos();
        scribbling = true;
    }
}
void ScribbleArea::mouseMoveEvent(QMouseEvent *event){
    if((event->buttons() & Qt::LeftButton) && scribbling)
        drawLineTo(event->pos());
}
void ScribbleArea::mouseReleaseEvent(QMouseEvent *event){
    if((event->buttons() & Qt::LeftButton) && scribbling)
    {
        drawLineTo(event->pos());
        scribbling =false;
    }

}









