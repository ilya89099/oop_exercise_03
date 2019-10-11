#include "Trapeze.h"


Trapeze::Trapeze(Point p1, Point p2, Point p3, Point p4)
: Figure(4, "Trapeze") {
    Vector v1(p1, p2), v2(p3, p4);
    if (v1 = Vector(p1, p2), v2 = Vector(p3, p4), parallel(v1, v2)) {
        if (v1 * v2 < 0) {
            std::swap(p3,p4);
        }
    } else if (v1 = Vector(p1,p3), v2 = Vector(p2,p4), parallel(v1,v2)) {
        if (v1 * v2 < 0) {
            std::swap(p2, p4);
        }
        std::swap(p2,p3);
    } else if (v1 = Vector(p1, p4), v2 = Vector(p2, p3), parallel(v1, v2)) {
        if (v1 * v2 < 0) {
            std::swap(p2, p3);
        }
        std::swap(p2,p4);
        std::swap(p3,p4);
    } else {
        throw std::logic_error("At least 2 sides of trapeze must be parallel");
    }
    points_ = {p1, p2, p3, p4};

}

Point Trapeze::Center() const {
    Point first_centroid = (points_[0] + points_[1] + points_[2]) / 3.0;
    Point second_centroid = (points_[1] + points_[2] + points_[3]) / 3.0;
    return (first_centroid + second_centroid) / 2;
}

double Trapeze::Area() const {
    Point p0 = points_[0];
    Point p1 = points_[2];
    Point p2 = points_[3];
    double A = p1.y - p2.y;
    double B = p2.x - p1.x;
    double C = p1.x*p2.y - p2.x*p1.y;
    double height = (std::abs(A*p0.x + B*p0.y + C) / sqrt(A*A + B*B));
    return (Vector(points_[0], points_[1]).length() + Vector(points_[2], points_[3]).length()) * height / 2;
}