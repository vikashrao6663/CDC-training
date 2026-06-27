#include <iostream>
using namespace std;

/* ------------------- 1. Interface (Abstract Class) ------------------- */
class test {
public:
    virtual int square(int x) = 0;
};

class arithmetic : public test {
public:
    int square(int x) {
        return x * x;
    }
};

class ToTestInt {
public:
    static void run() {
        arithmetic obj;
        cout << "1. Square: " << obj.square(5) << endl;
    }
};


/* ------------------- 2. Outer + Inner Class ------------------- */
class Outer {
public:
    void display() {
        cout << "2. Outer class display" << endl;
    }

    class Inner {
    public:
        void display() {
            cout << "2. Inner class display" << endl;
        }
    };
};


/* ------------------- 3. Point Class ------------------- */
class Point {
private:
    int x, y;

public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    void setXY(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void display() {
        cout << "3. Point -> x=" << x << ", y=" << y << endl;
    }
};


/* ------------------- 4. Box + Box3D ------------------- */
class Box {
protected:
    double length, breadth;

public:
    void setValue(double l, double b) {
        length = l;
        breadth = b;
    }

    double area() {
        return length * breadth;
    }
};

class Box3D : public Box {
private:
    double height;

public:
    void setValue(double l, double b, double h) {
        length = l;
        breadth = b;
        height = h;
    }

    double volume() {
        return length * breadth * height;
    }
};


/* ------------------- MAIN FUNCTION ------------------- */
int main() {

    // 1
    ToTestInt::run();

    // 2
    Outer o;
    o.display();

    Outer::Inner i;
    i.display();

    // 3
    Point p1;
    p1.setXY(10, 20);
    p1.display();

    Point p2(5, 15);
    p2.display();

    // 4
    Box3D b;
    b.setValue(10, 5, 2);

    cout << "4. Area: " << b.area() << endl;
    cout << "4. Volume: " << b.volume() << endl;

    return 0;
}