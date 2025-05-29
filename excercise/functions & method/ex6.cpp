#include <iostream>
#include <string.h>

using namespace std;

class Point {
    double x;
    double y;

public:
Point(double x, double y) {
    this->setX(x);
    this->setY(y);
}
void setX(double x) {
    this->x = x;
}
void setY(double y) {
    this->y = y;
}
double getX() {
    return this->x;
}
double getY() {
    return this->y;
}
void moveBy(double x,double y){
    this->setX(this->getX() + x);
    this->setY(this->getY() + y);
}
};

class Rectangle {
    Point theUpperLeft;
    Point theLowerRight;

public:

Rectangle(Point anUpperLeft, Point aLowerRight) {
    this->setUpperLeft(anUpperLeft);
    this->setLowerRight(aLowerRight);
}
double getArea(){
    return (this->getHeight() * this->getWidth());
}
double getHeight() {
    return (this->theLowerRight.getY() - this->theUpperLeft.getY());
}
double getWidth() {
    return (this->theLowerRight.getX() - this->theUpperLeft.getX());
}
void moveBy(double anX, double anY) {
    this->theUpperLeft.moveBy(anX, anY);
    this->theLowerRight.moveBy(anX, anY);
}
bool isPointInRectangle(Point aPoint) { ... }
};
int main(){
    Point A(1, 2);
    Point B(3, 4);
    Rectangle rect(A, B);
    cout << "Area: " << rect.getArea() << endl;
    cout << "Width: " << rect.getWidth() << endl;
    cout << "Height: " << rect.getHeight() << endl;
    
}