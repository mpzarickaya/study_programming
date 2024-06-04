#include <iostream>
#include <cmath>
using namespace std;

// Abstract class Point
class Point {
public:
    virtual void represent() const = 0;
    virtual void move(double dx, double dy) = 0;
protected:
    double x{}, y{};
};

// Class Line
class Line : public virtual Point {
public:
    Line(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    void represent() const override {
        std::cout << "Line from (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << std::endl;
    }
    void move(double dx, double dy) override {
        x1 += dx;
        y1 += dy;
        x2 += dx;
        y2 += dy;
    }

    double x1;
    double y1;
    double x2;
    double y2;
};

// Class Square
class Square : public Line {
public:
    Square(double x, double y, double side) : Line(x, y, x + side, y), side(side) {
        Line(x + side, y, x + side, y + side);
        Line(x + side, y + side, x, y + side);
        Line(x, y + side, x, y);
    }
    void represent() const override {
        std::cout << "Square with side " << side << " and center at (" << x + side / 2 << ", " << y + side / 2 << ")" << std::endl;
    }
    void rotate(double angle) {
        double cx = x + side / 2;
        double cy = y + side / 2;
        double radian = angle * M_PI / 180.0;
        for (Line* line : {static_cast<Line*>(this), static_cast<Line*>(this) + 1,
                           static_cast<Line*>(this) + 2, static_cast<Line*>(this) + 3}) {
            double dx = line->x1 - cx;
            double dy = line->y1 - cy;
            line->x1 = cx + dx * cos(radian) - dy * sin(radian);
            line->y1 = cy + dx * sin(radian) + dy * cos(radian);
            dx = line->x2 - cx;
            dy = line->y2 - cy;
            line->x2 = cx + dx * cos(radian) - dy * sin(radian);
            line->y2 = cy + dx * sin(radian) + dy * cos(radian);
        }
    }

    double side;
};

// Class Rhombus
class Rhombus : public virtual Square {
public:
    Rhombus(double x, double y, double side, double angle) : Square(x, y, side) {
        rotate(angle);
    }
    void represent() const override {
        std::cout << "Rhombus with side " << side << " and center at (" << x + side / 2 << ", " << y + side / 2 << ")" << std::endl;
    }
};

// Class Rectangle
class Rectangle : public virtual Line {
public:
    Rectangle(double x1, double y1, double x2, double y2, double x, double y, double width, double height) :
    Line(x1,y1,x2,y2),
    width(width),height(height) {
        Line(x, y, x + width, y);
        Line(x + width, y, x + width, y + height);
        Line(x + width, y + height, x, y + height);
        Line(x, y + height, x, y);
    }void represent() const override {
        std::cout << "Rectangle with width " << width << " and height " << height
                  << " and center at (" << x + width / 2 << ", " << y + height / 2 << ")" << std::endl;
    }
    void rotate(double angle) {
        double cx = x + width / 2;
        double cy = y + height / 2;
        double radian = angle * M_PI / 180.0;
        for (Line* line : {static_cast<Line*>(this), static_cast<Line*>(this) + 1,
                           static_cast<Line*>(this) + 2, static_cast<Line*>(this) + 3}) {
            double dx = line->x1 - cx;
            double dy = line->y1 - cy;
            line->x1 = cx + dx * cos(radian) - dy * sin(radian);
            line->y1 = cy + dx * sin(radian) + dy * cos(radian);
            dx = line->x2 - cx;
            dy = line->y2 - cy;
            line->x2 = cx + dx * cos(radian) - dy * sin(radian);
            line->y2 = cy + dx * sin(radian) + dy * cos(radian);
        }
    }

    double height;
    double width;
};

// Class Parallelogram
class Parallelogram : public virtual Rectangle {
public:
    Parallelogram(double x1, double y1, double x2, double y2, double x, double y, double width, double height,
                  double angle) : Line(x1, y1, x2, y2), Rectangle(0, 0, 0, 0, x, y, width, height) {
        rotate(angle);
    }
    void represent() const override {
        std::cout << "Parallelogram with width " << width << " and height " << height
                  << " and center at (" << x + width / 2 << ", " << y + height / 2 << ")" << std::endl;
    }
};

int main() {
    Square square(0, 0, 5);
    square.represent();
    square.rotate(45);
    square.represent();

    Rhombus rhombus(10, 10, 10, 30);
    rhombus.represent();

    Rectangle rectangle(0, 0, 0, 0, 20, 20, 8, 6);
    rectangle.represent();
    rectangle.rotate(60);
    rectangle.represent();

    Parallelogram parallelogram(0, 0, 0, 0, 30, 30, 12, 9, 45);
    parallelogram.represent();

    return 0;
}
