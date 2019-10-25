#pragma once

#include "Figure.h"

class Pentagon : public Figure {
public:
    Pentagon() = default;
    explicit Pentagon(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5);
    Point Center() const override;
    double Area() const override;
    void Print(std::ostream& os) const override;
    void Scan(std::istream& is) override;

private:
    Point p1_, p2_, p3_, p4_, p5_;
};