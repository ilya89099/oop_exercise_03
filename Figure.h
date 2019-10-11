#pragma once

#include <numeric>
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

struct Point {
    double x;
    double y;
    friend std::ostream& operator << (std::ostream& str, Point p);
    friend Point operator + (Point lhs, Point rhs);
    friend Point operator - (Point lhs, Point rhs);
    friend Point operator / (Point lhs, double a);
    friend Point operator * (Point lhs, double a);
    friend  bool operator < (Point lhs, Point rhs);
};

class Vector {
public:
    explicit Vector(double a, double b);
    explicit Vector(Point a, Point b);
    bool operator == (Vector rhs);
    Vector operator - ();
    friend double operator * (Vector lhs, Vector rhs);
    double length() const;
    double x;
    double y;
};

bool parallel(Vector lhs, Vector rhs);

class Figure {
public:
    virtual Point Center() const = 0;
    virtual double Area() const = 0;
    std::string GetName() const;
    friend std::ostream& operator << (std::ostream& str, const Figure& fig);
    virtual ~Figure() = default;
protected:
    Figure(size_t points_count, std::string figure_name);
    std::vector<Point> points_;
private:
    std::string figure_name_;
};

