#pragma once

#include "Figure.h"
#include <exception>

class Trapeze : public Figure {
public:
    Trapeze() = default;
    Trapeze(Point p1, Point p2, Point p3, Point p4);
    Point Center() const override;
    double Area() const override;
    void Print(std::ostream& os) const override;
    void Scan(std::istream& is) override;

private:
    Point p1_, p2_, p3_, p4_;
};

