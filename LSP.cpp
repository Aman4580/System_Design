// if class b is subtype of class a, then we should be able to replace object a with object b without breaking the program


// Let's take an example where we have a Bird class and two subclasses: Parrot and Penguin. Both subclasses should be able to substitute for the base class (Bird) without causing any issues.

//Without LSP Violation:

#include <bits/stdc++.h>
using name std;

// Base class: Bird
class Bird {
public:
    string name;

    // Constructor
    Bird(const string& n){
        name = n;
    }

    // Virtual method to be overridden by subclasses
    virtual void fly() const {
        cout << name << " is flying." << endl;
    }

    virtual ~Bird() {}
};

// Subclass: Parrot (inherits from Bird)
class Parrot : public Bird {
public:
    Parrot(const string& n){
        name = n;
    }

    void fly() const override {
        cout << name << " is flying and talking!" << endl;
    }
};

// Subclass: Penguin (inherits from Bird)
class Penguin : public Bird {
public:
    Penguin(const string& n){
        name = n;
    }

    void fly() const override {
        cout << name << " cannot fly." << endl;
    }
};

// Function to demonstrate LSP
void makeBirdFly(Bird* bird) {
    bird->fly();  // This should work for both Parrot and Penguin
}

int main() {
    Parrot parrot("Parrot");
    Penguin penguin("Penguin");

    makeBirdFly(&parrot);   // Should print: Parrot is flying and talking!
    makeBirdFly(&penguin);  // Should print: Penguin cannot fly.

    return 0;
}
Explanation:
Bird Class: The base class with a constructor that initializes the name and a virtual method fly(). We make the fly() method virtual because subclasses should be able to provide their own specific implementation.
Parrot Class: A subclass of Bird. The parrot can fly and talk, so we override the fly() method.
Penguin Class: A subclass of Bird, but penguins cannot fly. We override the fly() method to reflect that the penguin cannot fly.