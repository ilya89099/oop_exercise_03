
#pragma once

#include "Figure.h"

class Square : public Figure {
public:
    Square(Point p1, Point p2, Point p3, Point p4);
    Point Center() const override;
    void print(std::ostream& os) const override;
    double Area() const override;

private:
    Point p1_, p2_, p3_, p4_;
};


Square::Square(Point p1, Point p2, Point p3, Point p4)
        : p1_(p1), p2_(p2), p3_(p3), p4_(p4){
    if (is_perpendecular(Vector(p1_, p2_), Vector(p1_,p3_))
        && is_perpendecular(Vector(p4_, p2_), Vector(p4_,p3_))
        && is_perpendecular(Vector(p1_, p3_), Vector(p3_,p4_))
        && is_perpendecular(Vector(p1_, p2_), Vector(p2_,p4_))) {

    } else if (is_perpendecular(Vector(p1_, p4_), Vector(p1_,p3_))
               && is_perpendecular(Vector(p2_, p4_), Vector(p2_,p3_))
               && is_perpendecular(Vector(p1_, p3_), Vector(p3_,p2_))
               && is_perpendecular(Vector(p1_, p4_), Vector(p2_,p4_))){
        std::swap(p2_,p4_);
    } else if (is_perpendecular(Vector(p1_, p2_), Vector(p1_,p4_))
               && is_perpendecular(Vector(p3_, p2_), Vector(p3_,p4_))
               && is_perpendecular(Vector(p1_, p2_), Vector(p2_,p3_))
               && is_perpendecular(Vector(p1_, p4_), Vector(p4_,p3_))) {
        std::swap(p3_,p4_);
    } else {
        throw std::logic_error("Это не квадрат, стороны не перпендикулярны");
    }
    double s1 = Vector(p1_, p2_).length();
    double s2 = Vector(p1_, p3_).length();
    double s3 = Vector(p2_, p4_).length();
    double s4 = Vector(p4_, p3_).length();
    if (!(s1 == s2 && s2 == s3 && s3 == s4 && s4 == s1)) {
        throw std::logic_error("Это не квадрат, стороны не равны");
    }
}

double Square::Area() const {
    return std::pow(Vector(p1_,p2_).length(), 2);
}

Point Square::Center() const {
    return (p2_ + p3_) / 2;
}

void Square::print(std::ostream& os) const {
    os << "Квадрат p1:" << p1_ << ", p2:" << p2_ << ", p3:" << p3_ << ", p4:" << p4_;
}