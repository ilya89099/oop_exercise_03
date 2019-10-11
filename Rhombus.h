#pragma once
#include "Figure.h"

class Rhombus : public Figure {
public:
    Rhombus(Point p1, Point p2, Point p3, Point p4);
    Point Center() const override;
    double Area() const override;
};