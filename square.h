#ifndef SQUARE_H
#define SQUARE_H
#include <QPointF>
#include <QColor>

class square
{
public:
    square();
    square(QPointF* u, int a, int size = 20, QColor c = Qt::red); // Si se desea modificar el color, cambie el valor
                                                                  //por defecto en c, o defina el color al crear el cuadro
    QPointF* ubicacion;
    QColor color;
    int alpha;
    int size;
};

#endif // SQUARE_H
