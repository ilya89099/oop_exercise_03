//
// Created by ilya on 09.10.2019.
//

#include "Figure.h"

Point operator + (Point lhs, Point rhs) {
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

Point operator - (Point lhs, Point rhs) {
    return {lhs.x - rhs.x, lhs.y - rhs.y};
}

Point operator / (Point lhs, double a) {
    return { lhs.x / a, lhs.y / a};
}

Point operator * (Point lhs, double a) {
    return {lhs.x * a, lhs.y * a};
}

bool operator < (Point lhs, Point rhs) {
    return (lhs.x * lhs.x + lhs.y * lhs.y) < (lhs.x * lhs.x + lhs.y * lhs.y);
}

double operator * (Vector lhs, Vector rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

bool parallel(Vector lhs, Vector rhs) {
    return (std::abs(lhs * rhs - lhs.length() * rhs.length()) < std::numeric_limits<double>::epsilon() * 100);
}

bool Vector::operator == (Vector rhs) {
    return
        std::abs(x - rhs.x) < std::numeric_limits<double>::epsilon() * 100
        && std::abs(y - rhs.y) < std::numeric_limits<double>::epsilon() * 100;
}

double Vector::length() const {
    return sqrt(x*x + y*y);
}

Vector::Vector(double a, double b)
: x(a), y(b) {

}



Vector::Vector(Point a, Point b)
: x(b.x - a.x), y(b.y - a.y){

}

Vector Vector::operator - () {
    return Vector(-x, -y);
}

std::ostream& operator << (std::ostream& str, Point p) {
    return str << p.x << " " << p.y;
}

std::ostream& operator << (std::ostream& str, const Figure& fig) {
    for (Point p : fig.points_) {
        str << p << " ";
    }
    return str;
}

std::string Figure::GetName() const {
    return figure_name_;
}

Figure::Figure(size_t points_count, std::string figure_name)
: points_(points_count), figure_name_(figure_name) {}
