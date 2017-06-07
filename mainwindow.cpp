#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "square.h"
#include "drawing.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Establece el tamaño del pixmap segun el label
    pix = new QPixmap(ui->drawing_area->width(), ui->drawing_area->height()); //Tamaño canvas
    pix->fill(Qt::black); //Fondo negro
    paint = new QPainter(pix);

    // Genera los cuadros automaticamente, manipulando X, Y y alpha
    autoGeneraCuadros();

    // Dibuja todos los cuadros en la lista
    drawList();

    // Asigna el pixmap al label
    ui->drawing_area->setPixmap(*pix);
}

void MainWindow::drawSquare(square *s)
{
    // Dibuja linea bresenham usando las propiedades del cuadrado
    drawing::lineBresenham(this->paint,s->ubicacion,s->ubicacion,s->size,s->color,s->alpha);
}

// Recorre toda la lista y dibuja cada cuadro
void MainWindow::drawList()
{
    for(int i = 0; i <cuadros.count(); i++){
        drawSquare(cuadros[i]);
    }
}

void MainWindow::autoGeneraCuadros()
{
    // Cantidad de cuadros dibujados en la columna actual
    int y_count = 0;

    // Posición actual en el lienzo
    int x, y;

    // Opacidad inicial
    int alpha = 5;

    // Separanción entre cada cuadro
    int separacion = 30;

    // Inicia a dibujar en (10, 10)
    x= 10; y = 10;

    // Recorre dibujando máximo 600 cuadros. Número arbitrario
    for(int i = 0; i < 600; i++){
        // Crea un punto con la ubicación actual
        QPointF* p = new QPointF(x, y);

        // Agrega un cuadro con sus propiedades a la lista
        square* s = new square(p,alpha);
        cuadros.append(s);

        // Incrementa la cantidad de cuadros dibujados en la columna
        y_count++;

        //Deja el espacio entre cada cuadro
        y += separacion;

        // Si ya se dibujaron mas de 19 cuadros en la columna, salta a la siguiente columna
        // En cada columna se incrementa en 10 la opacidad
        if (y_count >= 20){
            y_count = 0;
            y = 0;
            x+=separacion;
            alpha+=10;

            // En caso de exceder el valor máximo de alpha lo regresa a 255
            if (alpha >255)
                alpha =255;

        }



    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
