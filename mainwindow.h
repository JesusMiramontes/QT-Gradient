#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPainter>
#include "square.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    // Elementos usados para dibujar
    QPixmap *pix;
    QPainter* paint;

    void drawSquare(square* s);
    void drawList();
    void autoGeneraCuadros();

    QTimer* timer_cada_uno;
    QTimer* timer_columnas;
    int j;

    QList<square*> cuadros;

    // Almacena el último color seleccionado con el ColorDialog
    QColor color;

    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void timerCadaUno();
    void timerColumnas();

private slots:
    void on_pushButton_clicked();
    void on_btnDibujar_clicked();
    void on_btnCuadro_clicked();
    void on_btnColumna_clicked();
    void on_btnColor_clicked();
};

#endif // MAINWINDOW_H
