#pragma once

#include "Figure.h"
#include <exception>

class Trapeze : public Figure {
public:
    Trapeze(Point p1, Point p2, Point p3, Point p4);
    // конструктор проверяет корректность переданных данных
    // если переданные точки не могут быть точками трапеции, выбрасывается исключение
    // вектора (points_[0], points_[1]) и (points_[2], points_[3]) являются параллельными и сонаправленными
    Point Center() const override;
    double Area() const override;
};

