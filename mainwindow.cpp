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

    QPointF* p = new QPointF(100, 100);
    square* s = new square(p,100);
    s->color = Qt::green;
    s->size = 200;
    s->alpha = 255;

    drawing::lineBresenham(paint,s->ubicacion,s->ubicacion,s->size,s->color,s->alpha);

    ui->drawing_area->setPixmap(*pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}
