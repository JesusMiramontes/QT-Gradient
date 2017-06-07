#include "square.h"

square::square()
{

}

square::square(QPointF *u, int a, int size, QColor c)
{
    ubicacion = u;
    alpha = a;
    color = c;
    this->size = size;
}
