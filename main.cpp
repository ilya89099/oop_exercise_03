#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include "Figure.h"
#include "Trapeze.h"
#include "Rhombus.h"
#include "Pentagon.h"

int main() {
    std::vector<Figure*> figures;
    std::string command;
    while (std::cin >> command) {
        if (command == "add") {
            std::string fig_type;
            std::cin >> fig_type;
            Figure* new_fig;
            if (fig_type == "Trapeze") {
                new_fig = new Trapeze;
            } else if (fig_type == "Rhombus") {
                new_fig = new Rhombus;
            } else if (fig_type == "Pentagon") {
                new_fig = new Pentagon;
            } else {
                std::cout << "Invalid figure type\n";
                std::cin.ignore(30000, '\n');
                continue;
            }
            try {
                std::cin >> (*new_fig);
            } catch (std::exception& e) {
                std::cout << e.what() << "\n";
                delete new_fig;
                continue;
            }
            figures.push_back(new_fig);
            std::cout << "Created figure\n";
            std::cout << *new_fig << "\n";
        } else if (command == "print") {
            int index;
            std::cin >> index;
            index--;
            if (index < 0 || index >= figures.size()) {
                std::cout << "No object at that index\n";
                continue;
            }
            std::cout << "Figure at index " << index + 1 << " - " << *figures[index] << "\n";
        } else if (command == "area") {
            int index;
            std::cin >> index;
            index--;
            if (index < 0 || index >= figures.size()) {
                std::cout << "No object at that index\n";
                continue;
            }
            std::cout << *figures[index] << "\n";
            std::cout << "Area: " << figures[index]->Area() << "\n";
        } else if (command == "center") {
            int index;
            std::cin >> index;
            index--;
            if (index < 0 || index >= figures.size()) {
                std::cout << "No object at that index\n";
                continue;
            }
            std::cout << *figures[index] << "\n";
            std::cout << "Center: " << figures[index]->Center() << "\n";
        } else if (command == "delete") {
            int index;
            std::cin >> index;
            index--;
            if (index < 0 || index >= figures.size()) {
                std::cout << "No object at that index\n";
                continue;
            }
            delete figures[index];
            figures.erase(figures.begin() + index);
        } else if (command == "count") {
            std::cout << "Elements count: " << figures.size() << "\n";
        }
    }
    for (Figure* ptr : figures) {
        delete ptr;
    }
    return 0;
}