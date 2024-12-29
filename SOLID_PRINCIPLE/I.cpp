//ISP states that clients (classes) should not be forced to implement interfaces they don't use. Instead of having a large interface that contains methods that might not be relevant for all classes, we should split the large interface into smaller, more specific ones. This helps in creating a clean, maintainable, and flexible design.


//Example of ISP Violation:
#include <iostream>
using namespace std;

// A large interface that forces every class to implement both work() and eat()

// class Worker {
// public:
//     virtual void work() = 0;
//     virtual void eat() = 0; // Robots don't need this, but still forced to implement it
// };

// // Human class implements both methods
// class Human : public Worker {
// public:
//     void work() override {
//         cout << "Human is working" << endl;
//     }

//     void eat() override {
//         cout << "Human is eating" << endl;
//     }
// };

// // Robot class implements both methods, even though it doesn't need eat()
// class Robot : public Worker {
// public:
//     void work() override {
//         cout << "Robot is working" << endl;
//     }

//     void eat() override {
//         cout << "Robot is charging, not eating!" << endl; // Unnecessary implementation
//     }
// };

// int main() {
//     Human human;
//     Robot robot;

//     human.work(); // Human is working
//     human.eat();  // Human is eating

//     robot.work(); // Robot is working
//     robot.eat();  // Robot is charging, not eating!

//     return 0;
// }


// Problem:
// The Robot class doesn't need the eat() method but still has to implement it because the Worker interface forces all derived classes to implement both work() and eat(). This violates the Interface Segregation Principle (ISP).
// Solution (Applying ISP by Splitting Interfaces):
// Instead of having a single large interface (Worker), we split the functionality into smaller, more specific interfaces. For example, we can have IWork for work-related actions and IEat for eating-related actions.

//Corrected Example with ISP:
#include <iostream>
using namespace std;

// Interface for working
class IWork {
public:
    virtual void work() = 0;
};

// Interface for eating
class IEat {
public:
    virtual void eat() = 0;
};

// Human class implements both IWork and IEat
class Human : public IWork, public IEat {
public:
    void work() override {
        cout << "Human is working" << endl;
    }

    void eat() override {
        cout << "Human is eating" << endl;
    }
};

// Robot class implements only IWork because it doesn't eat
class Robot : public IWork {
public:
    void work() override {
        cout << "Robot is working" << endl;
    }
};

int main() {
    Human human;
    Robot robot;

    human.work();  // Human is working
    human.eat();   // Human is eating

    robot.work();  // Robot is working
    // robot.eat(); // Not required, robot does not eat

    return 0;
}
// Explanation:
// IWork Interface: This interface has only the work() method, which is applicable to both Human and Robot.
// IEat Interface: This interface has only the eat() method, which is applicable to the Human class but not to Robot.
// Human Class: Implements both IWork and IEat because humans can work and eat.
// Robot Class: Implements only the IWork interface because robots work but don't eat.
// Benefits of This Design:
// No unnecessary methods: The Robot class is not forced to implement methods it doesn't need (like eat()).
// Separation of concerns: Each interface focuses on a specific responsibility (IWork for work-related actions, IEat for eating-related actions).
// Flexibility: If we add more specific behaviors in the future (e.g., IDrive), we can extend the system without affecting unrelated classes.