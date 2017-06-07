#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "square.h"
#include "drawing.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Establece el tamaño del pixmap segun el label
    pix = new QPixmap(ui->drawing_area->width(), ui->drawing_area->height()); //Tamaño canvas
    pix->fill(Qt::black); //Fondo negro

    paint = new QPainter(pix);

    autoGeneraCuadros();
    drawList();

    ui->drawing_area->setPixmap(*pix);
}

void MainWindow::drawSquare(square *s)
{
    drawing::lineBresenham(this->paint,s->ubicacion,s->ubicacion,s->size,s->color,s->alpha);
}

void MainWindow::drawList()
{
    for(int i = 0; i <cuadros.count(); i++){
        drawSquare(cuadros[i]);
    }
}

void MainWindow::autoGeneraCuadros()
{
    int y_count = 0;
    //int column_count = 0;
    int x, y;
    int alpha = 5;
    int separacion = 30;

    x= 0; y = 0;
    for(int i = 0; i < 600; i++){
        QPointF* p = new QPointF(x, y);
        square* s = new square(p,alpha);
        cuadros.append(s);

        y_count++;
        y += separacion;

        if (y_count >= 20){
            y_count = 0;
            y = 0;
            x+=separacion;
            alpha+=10;
            if (alpha >255)
                alpha =255;
        }



    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
