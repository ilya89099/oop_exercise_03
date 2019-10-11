#include <iostream>
#include <algorithm>
#include "Trapeze.h"

int main() {
    std::vector<Point> a{{0,6},{4,4},{0,0},{4,0}};
    for (int i = 0; i < 24; ++i) {
        Trapeze t = {a[0], a[1], a[2], a[3]};
        std::cout << t.Area() << " " << t.Center() << std::endl;
        std::next_permutation(a.begin(), a.end());
    }


    return 0;
}