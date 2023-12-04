#ifndef BUGLIB_HPP
#define BUGLIB_HPP

class Bug {
private:
    int position;
    int dir;

public:
    // Default constructor
    Bug();

    // Constructor with initial position
    Bug(int initialPosition);

    // Member function to move the bug
    void move();

    // Member function to turn the bug
    void turn();

    // Member function to display bug's data
    void display();
};

#endif // BUGLIB_HPP