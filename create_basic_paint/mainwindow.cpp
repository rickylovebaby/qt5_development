#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    image = QImage(this->size(),QImage::Format_RGB32);
    image.fill(Qt::white);

    drawing = false;
    brushColor = Qt::black;
    brushSize = 2;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)//确定按钮是否是鼠标左键
    {
        drawing = true;
        lastPoint = event->pos();

    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        drawing = false;
    }
}



void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if((event->buttons() & Qt::LeftButton) && drawing)
    {
        QPainter painter(&image);
        //RoundCap定义的是线条末端的形状是圆形的，RoundJoin定义的则是两条线段连接点出的形状是圆形的。
        painter.setPen(QPen(brushColor,brushSize,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
        painter.drawLine(lastPoint,event->pos());

        lastPoint = event->pos();
        this->update();

    }
}


void MainWindow::paintEvent(QPaintEvent * )
{
    QPainter canvasPainter(this);
    canvasPainter.drawImage(this->rect(),image,image.rect());

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QImage newImage(event->size(), QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));

    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), image);
    image = newImage;
}



void MainWindow::on_actionSave_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this,"Save Image","","PNG (*.png);;JPEG (*.jpg *.jpeg);All files (*.*)");

    if(filePath == "")
        return;

    image.save(filePath);


}

void MainWindow::on_actionClear_triggered()
{
    image.fill(Qt::white);
    this->update();


}

void MainWindow::on_action2px_triggered()
{
    brushSize = 2;

}

void MainWindow::on_action5px_triggered()
{
    brushSize = 5;

}

void MainWindow::on_actionPx_triggered()
{
    brushSize = 10;


}



void MainWindow::on_actionBlack_triggered()
{
    brushColor =  Qt::black;

}

void MainWindow::on_actionWhite_triggered()
{
    brushColor = Qt::white;

}


void MainWindow::on_actionRed_triggered()
{
    brushColor = Qt::red;

}


void MainWindow::on_actionGreem_triggered()
{
    brushColor = Qt::green;

}

void MainWindow::on_actionBlue_triggered()
{
    brushColor = Qt::blue;

}
