#include <iostream>
//#include "Shapes.h"
#include <math.h>
#include <string>
using namespace std;


class Shape {

    public: 
        const float pi = 3.14159f;
        virtual void Scale(float scaleFactor) = 0;
        virtual void Display() const = 0;
};


class Shape2D : virtual public Shape {
    
    public:

        virtual float Area() const = 0;

        virtual string GetName2D() const = 0;

        void ShowArea() const {
            cout << GetName2D() << endl;
            cout << to_string(Area()) << endl;
        }

        bool operator>(const Shape2D &rhs) const {
            if (this->Area() > rhs.Area()) {
                return true;
            }

            return false;
        }

        bool operator<(const Shape2D &rhs) const {
            if (this->Area() > rhs.Area()) {
                    return true;
                }

                return false;
        }

        bool operator==(const Shape2D &rhs) const {
            if (this->Area() == rhs.Area()) 
                {
                    return true;
                }

                return false;
        }
};

class Square: public Shape2D {

    private:
        float squareLen;
    
    public:

        // Constructors
        Square() {
            squareLen = 0;
        }

        Square(float len) {
            squareLen = len;
        }

        // Side Length Getter and Setter Methods
        float getLength() const {
            return squareLen;
        }

        void setLength(float newlen) {
            squareLen = newlen;
        }

        // Getname - WIP
        string GetName2D() const override {
            string res;

            return res;
        }

        // Returns the area of the shape - Untested
        float Area() const override {
            return (squareLen * squareLen);
        }

        // Scaling method - WIP
        void Scale(float factor) override {
            this->setLength(factor * this->getLength());
        }

        void Display() const override {
            cout << "The area of the Square is : " << to_string(this->Area()) << endl;
            cout << "Length of a side: " << to_string(this->squareLen) << endl << endl;;
        }
};


class Triangle: public Shape2D {

    private:
        float triangleBase;
        float triangleHeight;

    public:

        // Constructors
        Triangle() { 
            triangleBase = 0;
            triangleHeight = 0;
        }

        Triangle(float base, float height) { 
            triangleBase = base;
            triangleHeight = height;
        }

        // Base and Height Getter and Setter Methods
        float GetBase() const { // Untested
            return triangleBase;
        }

        float GetHeight() const { // Untested
            return triangleHeight;
        }

        void SetBase(float base) { // Untested
            triangleBase = base;
        }

        void SetHeight(float height) { // Untested
            triangleHeight = height;
        }

        // Area and Scaling Methods
        float Area() const override { // Untested
            return (0.5f * triangleBase * triangleHeight);
        }

        void Scale(float factor) override{ // Untested
            triangleBase = triangleBase * factor;
            triangleHeight = triangleHeight * factor;
        }

        string GetName2D() const override{ // WIP
            string res;
            return res;
        }

        void Display() const override { // Untested
            cout << "The area of the Triangle is : " << to_string(this->Area()) << endl;
            cout << "Base: " << to_string(this->GetBase()) << endl;
            cout << "Height: " << to_string(this->GetHeight()) << endl << endl;
        }
};

class Circle: public Shape2D {

    private:
        float circleRadius;

    public:

        // Constructors
        Circle() { // Untested
            circleRadius = 0;
        }

        Circle(float radius) { // Untested
            circleRadius = radius;
        }

        // Radius Getter and Setter methods
        float GetRadius() const{ // Untested
            return circleRadius;
        }

        void SetRadius(float radius) { // Untested
            circleRadius = radius;
        }

        float Area() const{ // Untested
            return (circleRadius * circleRadius * pi);
        }

        void Scale(float factor) override{ // Untested
            circleRadius = circleRadius * factor;
        }

        string GetName2D() const override {  // WIP
            string res;
            return res;
        }

        void Display() const override { // Untested
            cout << "The area of the Circle is : " << to_string(this->Area()) << endl;
            cout << "Radius: " << to_string(this->GetRadius()) << endl;
        }
};


class Shape3D : virtual public Shape {
    public:
        virtual float Volume() const = 0;
        void ShowVolume() const {
            cout << "Volume: " << endl;
        }
        virtual string GetName3D() const = 0;

        bool operator>(const Shape3D &rhs) const {
            if (this->Volume() > rhs.Volume()) {
                return true;
            }
            return false;
        }
        bool operator<(const Shape3D &rhs) const {
            if (this->Volume() < rhs.Volume()) {
                return true;
            }
            return false;
        }
        bool operator==(const Shape3D &rhs) const {
            if (this->Volume() == rhs.Volume()) {
                return true;
            }
            return false;
        }
};

class TriangularPyramid: public Shape3D {

    private:
        Triangle* pyramidBase;
        float pyramidHeight;

    public: 

        TriangularPyramid() {
            pyramidBase = new Triangle();
            pyramidHeight = 0;
        }

        TriangularPyramid(float height, float triangleLength, float triangleHeight) {
            pyramidBase = new Triangle(triangleLength, triangleHeight);
            pyramidHeight = height;
        }

        Triangle* GetBase() const {
            return pyramidBase;
        }

        float GetHeight() const {
            return pyramidHeight;
        }

        float Volume() const override {
            return (0.333 * pyramidHeight * (pyramidBase->Area()));
        }

        string GetName3D() const override{
            string res;
            return res;
        }

        void Scale(float factor) override {
            pyramidHeight *= factor;
            pyramidBase->SetBase((pyramidBase->GetBase())*factor);
        }

        void Display() const override {

        }


};

class Cylinder: public Shape3D {

    private:
        Circle* cylinderBase;
        float cylinderHeight;

    public:

        // Constructors
        Cylinder() {
            cylinderBase = new Circle();
            cylinderHeight = 0;
        }

        Cylinder(float radius, float height) {
            cylinderBase = new Circle(radius);
            cylinderHeight = height;
        }

        float Volume() const override {
            return (cylinderBase->Area())*cylinderHeight;
        }

        string GetName3D() const override {
            return "";
        }

        void Scale(float factor) override {
            cylinderHeight *= factor;
            cylinderBase->SetRadius((cylinderBase->GetRadius())*factor);
        }

        void Display() const override {

        }

};

class Sphere: public Shape3D {

    private:
        Circle* SphereBase;

    public:
        Sphere() {
            SphereBase = new Circle();
        }

        Sphere(float radius) {
            SphereBase = new Circle(radius);
        }

        float Volume() const {
            return (1.3333 * pi * pow(SphereBase->GetRadius(), 3));
        }

        string GetName3D() const override {
            return "";
        }

        void Scale(float factor) override {
            
        }

        void Display() const override {

        }
};