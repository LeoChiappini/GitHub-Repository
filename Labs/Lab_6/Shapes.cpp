#include <iostream>
//#include "Shapes.h"

using namespace std;

// Shape2D Class

void Shape2D::ShowArea() const {
    cout << GetName2D() << endl;
    cout << to_string(Area()) << endl;
}

bool Shape2D::operator>(const Shape2D &rhs) const {
    if (this->Area() > rhs.Area()) {
        return true;
    }

    return false;
}

bool Shape2D::operator<(const Shape2D &rhs) const {
    if (this->Area() > rhs.Area()) {
            return true;
        }

        return false;
}

bool Shape2D::operator==(const Shape2D &rhs) const {
    if (this->Area() == rhs.Area()) 
        {
            return true;
        }

        return false;
}

// Square Class

// Constructors
Square::Square() {
    squareLen = 0;
}

Square::Square(float len) {
    squareLen = len;
}

// Side Length Getter and Setter Methods
float Square::getLength() const {
    return squareLen;
}

void Square::setLength(float newlen) {
    squareLen = newlen;
}

// Getname - WIP
string Square::GetName2D() const {
    string res;

    return res;
}

// Returns the area of the shape - Untested
float Square::Area() const {
    return (squareLen * squareLen);
}

// Scaling method - WIP
void Square::Scale(float factor) {
    this->setLength(factor * this->getLength());
}

void Square::Display() const {
    cout << "The area of the Square is : " << to_string(this->Area()) << endl;
    cout << "Length of a side: " << to_string(this->squareLen) << endl << endl;;
}


// Triangle Class

// Constructors
Triangle::Triangle() { 
    triangleBase = 0;
    triangleHeight = 0;
}

Triangle::Triangle(float base, float height) { 
    triangleBase = base;
    triangleHeight = height;
}

float Triangle::GetBase() const { // Untested
    return triangleBase;
}

float Triangle::GetHeight() const { // Untested
    return triangleHeight;
}

void Triangle::SetBase(float base) { // Untested
    triangleBase = base;
}

void Triangle::SetHeight(float height) { // Untested
    triangleHeight = height;
}

// Area and Scaling Methods
float Triangle::Area() const { // Untested
    return (0.5f * triangleBase * triangleHeight);
}

void Triangle::Scale(float factor) { // Untested
    triangleBase = triangleBase * factor;
    triangleHeight = triangleHeight * factor;
}

string Triangle::GetName2D() const { // WIP
    string res;
    return res;
}

void Triangle::Display() const { // Untested
    cout << "The area of the Triangle is : " << to_string(this->Area()) << endl;
    cout << "Base: " << to_string(this->GetBase()) << endl;
    cout << "Height: " << to_string(this->GetHeight()) << endl << endl;
}

// Circle Class

// Constructors
Circle::Circle() { // Untested
    circleRadius = 0;
}

Circle::Circle(float radius) { // Untested
    circleRadius = radius;
}

// Radius Getter and Setter methods
float Circle::GetRadius() const{ // Untested
    return circleRadius;
}

void Circle::SetRadius(float radius) { // Untested
    circleRadius = radius;
}

float Circle::Area() const{ // Untested
    return (circleRadius * circleRadius * pi);
}

void Circle::Scale(float factor) { // Untested
    circleRadius = circleRadius * factor;
}

string Circle::GetName2D() const {  // WIP
    return "";
}

void Circle::Display() const { // Untested
    cout << "The area of the Circle is : " << to_string(this->Area()) << endl;
    cout << "Radius: " << to_string(this->GetRadius()) << endl;
}

// Shape3D Class

void Shape3D::ShowVolume() const {
    cout << "Volume: " << endl;
}

bool Shape3D::operator>(const Shape3D &rhs) const {
    if (this->Volume() > rhs.Volume()) {
        return true;
    }
    return false;
}
bool Shape3D::operator<(const Shape3D &rhs) const {
    if (this->Volume() < rhs.Volume()) {
        return true;
    }
    return false;
}
bool Shape3D::operator==(const Shape3D &rhs) const {
    if (this->Volume() == rhs.Volume()) {
        return true;
    }
    return false;
}

// Triangular Pyramid Class

TriangularPyramid::TriangularPyramid() {
    pyramidBase = new Triangle();
    pyramidHeight = 0;
}

TriangularPyramid::TriangularPyramid(float height, float triangleLength, float triangleHeight) {
    pyramidBase = new Triangle(triangleLength, triangleHeight);
    pyramidHeight = height;
}

const Triangle* const TriangularPyramid::GetBase() const {
    return pyramidBase;
}

float TriangularPyramid::GetHeight() const {
    return pyramidHeight;
}

float TriangularPyramid::Volume() const {
    return (0.333 * pyramidHeight * (pyramidBase->Area()));
}

string TriangularPyramid::GetName3D() const {
    return "";
}

void TriangularPyramid::Scale(float factor) {
    pyramidHeight *= factor;
    pyramidBase->SetBase((pyramidBase->GetBase())*factor);
}

void TriangularPyramid::Display() const {

}

// Cylinder Class

// Constructors
Cylinder::Cylinder() {
    cylinderBase = new Circle();
    cylinderHeight = 0;
}

Cylinder::Cylinder(float radius, float height) {
    cylinderBase = new Circle(radius);
    cylinderHeight = height;
}

float Cylinder::Volume() const {
    return (cylinderBase->Area())*cylinderHeight;
}

string Cylinder::GetName3D() const {
    return "";
}

void Cylinder::Scale(float factor) {
    cylinderHeight *= factor;
    cylinderBase->SetRadius((cylinderBase->GetRadius())*factor);
}

void Cylinder::Display() const {

}


// Sphere Class

Sphere::Sphere() {
    SphereBase = new Circle();
}

Sphere::Sphere(float radius) {
    SphereBase = new Circle(radius);
}

float Sphere::Volume() const {
    return (1.3333 * pi * pow(SphereBase->GetRadius(), 3));
}

string Sphere::GetName3D() const {
    return "";
}

void Sphere::Scale(float factor) {
    
}

void Sphere::Display() const {

}