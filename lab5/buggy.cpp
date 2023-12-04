#include "bugLib.hpp"

int main() {
    // Create Bug object at position 10
    Bug myBug(10);

    // Display initial position and direction
    myBug.display();

    // Move the bug and display
    myBug.move();
    myBug.display();

    // Turn the bug, move, and display
    myBug.turn();
    myBug.move();
    myBug.display();

    // Move the bug again and display
    myBug.move();
    myBug.display();

    return 0;
}