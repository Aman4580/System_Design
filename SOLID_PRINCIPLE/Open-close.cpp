

// class should open for extension but close for modification


// Without OCP:
// Here, every time you want to add a new shape, you have to modify the existing class to include logic for the new shape.

#include <bits/stdc++.h>
using namespace std;

class AreaCalculator {
public:
    double calculateArea(const string& shape, double dimension1, double dimension2 = 0) {
        if (shape == "Circle") {
            return M_PI * pow(dimension1, 2);
        } else if (shape == "Rectangle") {
            return dimension1 * dimension2;
        } else {
            cerr << "Unknown shape!" << endl;
            return 0;
        }
    }
};

int main() {
    AreaCalculator calc;
    cout << "Area of Circle: " << calc.calculateArea("Circle", 5) << endl;
    cout << "Area of Rectangle: " << calc.calculateArea("Rectangle", 5, 10) << endl;
    return 0;
}


//Problem:

// If you want to add a new shape (e.g., Triangle), you will need to modify the AreaCalculator class by adding a new else if block, which violates the Open/Closed Principle. This could lead to errors, especially in large projects.
// With OCP (Open for Extension, Closed for Modification):
// Now, let's modify the design to allow the addition of new shapes without modifying the existing AreaCalculator class. We can do this by creating a base class for shapes and letting specific shapes (like Circle, Rectangle) extend it.

// Base Shape class
 class Shape {
public:
    virtual double calculateArea() const = 0;  // Pure virtual function
    virtual ~Shape() {}  // Virtual destructor
};

// Circle class inherits from Shape
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r){
        radius = r;
    }

    double calculateArea() const override {
        return M_PI * pow(radius, 2);
    }
};

// Rectangle class inherits from Shape
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double calculateArea() const override {
        return length * width;
    }
};

// Function to calculate area of any shape
void printArea(const Shape& shape) {
    cout << "Area: " << shape.calculateArea() << endl;
}

int main() {
    Circle circle(5);
    Rectangle rectangle(5, 10);

    printArea(circle);      // Prints area of circle
    printArea(rectangle);   // Prints area of rectangle

    return 0;
}


// What's Happening Here?
// Base class Shape: We define an abstract base class with a pure virtual function calculateArea(). All shapes must implement this function.
// Derived classes (Circle, Rectangle): Each shape implements the calculateArea() function according to its own specific logic.
// printArea function: This function can now accept any shape derived from Shape and calculate its area. If we add more shapes later, we don't need to modify this function or any existing classes.
// Benefits of OCP:
// Open for Extension: You can add new shapes (like Triangle, Square, etc.) by simply creating new classes that extend Shape.
// Closed for Modification: The existing AreaCalculator logic is not modified when you add new shapes, ensuring that old functionality works as expected.