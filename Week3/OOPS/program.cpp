#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Abstract Class
class Compartment {
public:
    virtual string notice() = 0; // Pure Virtual Function
};

// Derived Classes
class FirstClass : public Compartment {
public:
    string notice() override {
        return "First Class Compartment";
    }
};

class Ladies : public Compartment {
public:
    string notice() override {
        return "Ladies Compartment";
    }
};

class General : public Compartment {
public:
    string notice() override {
        return "General Compartment";
    }
};

class Luggage : public Compartment {
public:
    string notice() override {
        return "Luggage Compartment";
    }
};

int main() {
    srand(time(0));

    Compartment* arr[10];

    // Randomly create compartments
    for (int i = 0; i < 10; i++) {
        int n = rand() % 4 + 1; // 1 to 4

        switch (n) {
            case 1:
                arr[i] = new FirstClass();
                break;
            case 2:
                arr[i] = new Ladies();
                break;
            case 3:
                arr[i] = new General();
                break;
            case 4:
                arr[i] = new Luggage();
                break;
        }
    }

    // Polymorphic behavior
    cout << "Compartments and Notices:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Compartment " << i + 1 << ": "
             << arr[i]->notice() << endl;
    }

    // Free memory
    for (int i = 0; i < 10; i++) {
        delete arr[i];
    }

    return 0;
}