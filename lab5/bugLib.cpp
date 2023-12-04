#include "bugLib.hpp"
#include <iostream>

// Default constructor
Bug::Bug() : position(0), dir(1) {}

// Constructor with initial position
Bug::Bug(int initialPosition) : position(initialPosition), dir(1) {}

// Member function to move the bug
void Bug::move() {
    position += dir;
}

// Member function to turn the bug
void Bug::turn() {
    dir = -dir; // Change direction
}

// Member function to display bug's data
void Bug::display() {
    std::cout << "position = " << position << ", direction = " << dir << std::endl;
}