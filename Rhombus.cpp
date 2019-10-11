#include "Rhombus.h"

Rhombus::Rhombus(Point p1, Point p2, Point p3, Point p4)
: Figure(4, "Rhombus"){
    if (Vector(p1, p2).length() == Vector(p1, p4).length()
        && Vector(p3, p4).length() == Vector(p2, p3).length()
        && Vector(p1, p2).length() == Vector(p2, p3).length()) {

    } else if (Vector(p1, p4).length() == Vector(p1, p3).length()
           && Vector(p2, p3).length() == Vector(p2, p4).length()
           && Vector(p1, p4).length() == Vector(p2, p4).length()) {
        std::swap(p2,p3);
    } else if (Vector(p1, p3).length() == Vector(p1, p2).length()
              && Vector(p2, p4).length() == Vector(p3, p4).length()
              && Vector(p1, p2).length() == Vector(p1, p4).length()) {
        std::swap(p3,p4);
    } else {
        throw std::logic_error("This is not rhombus, sides arent equal");
    }
    Vector v1(p1,p4);
    Vector v2(p1,p2);
    Vector v3(p3,p4);
    Vector v4(p2,p3);
    double cos1 = v1 * v2 / (v1.length() * v2.length());
    double cos2 = v3 * v4 / (v3.length() * v4.length());
    double cos3 = v1 * v3 / (v1.length() * v3.length());
    double cos4 = v2 * v4 / (v2.length() * v4.length());
    if (cos1 != cos2 || cos3 != cos4) {
        throw std::logic_error("This is not rhombus, opposite angles arent equal");
    }
    points_ = {p1, p2, p3, p4};
}