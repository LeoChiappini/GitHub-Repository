#pragma once

#include <math.h>
#include <string>

class Shape {

    public: 
        const float pi = 3.14159f;
        virtual void Scale(float scaleFactor) = 0;
        virtual void Display() const = 0;
};

class Shape2D : virtual public Shape {
    
    public:

        virtual float Area() const = 0;

        virtual std::string GetName2D() const = 0;

        void ShowArea() const;

        bool operator>(const Shape2D &rhs) const ;

        bool operator<(const Shape2D &rhs) const ;

        bool operator==(const Shape2D &rhs) const ;
};

class Square: public Shape2D {

    private:
        float squareLen;
    
    public:

        // Constructors
        Square() ;

        Square(float len) ;

        // Side Length Getter and Setter Methods
        float getLength() const ;

        void setLength(float newlen) ;

        // Getname - WIP
        std::string GetName2D() const override ;

        // Returns the area of the shape - Untested
        float Area() const override ;

        // Scaling method - WIP
        void Scale(float factor) override ;

        void Display() const override ;
};


class Triangle: public Shape2D {

    private:
        float triangleBase;
        float triangleHeight;

    public:

        // Constructors
        Triangle() ;

        Triangle(float base, float height) ;

        // Base and Height Getter and Setter Methods
        float GetBase() const ;

        float GetHeight() const ;

        void SetBase(float base) ;

        void SetHeight(float height) ;

        // Area and Scaling Methods
        float Area() const override ;

        void Scale(float factor) override ;

        std::string GetName2D() const override ;

        void Display() const override ;
};

class Circle: public Shape2D {

    private:
        float circleRadius;

    public:

        // Constructors
        Circle() ;

        Circle(float radius) ;

        // Radius Getter and Setter methods
        float GetRadius() const ;

        void SetRadius(float radius) ;

        float Area() const ;

        void Scale(float factor) override;

        std::string GetName2D() const override ;

        void Display() const override ;
};


class Shape3D : virtual public Shape {
    public:
        virtual float Volume() const = 0;
        void ShowVolume() const ;
        virtual std::string GetName3D() const = 0;

        bool operator>(const Shape3D &rhs) const ;

        bool operator<(const Shape3D &rhs) const ;

        bool operator==(const Shape3D &rhs) const ;
};

class TriangularPyramid: public Shape3D {

    private:
        Triangle* pyramidBase;
        float pyramidHeight;

    public: 

        TriangularPyramid() ;

        TriangularPyramid(float height, float triangleLength, float triangleHeight) ;

        const Triangle* const GetBase() const ;

        float GetHeight() const ;

        float Volume() const override ;

        std::string GetName3D() const override ;

        void Scale(float factor) override ;

        void Display() const override ;

};

class Cylinder: public Shape3D {

    private:
        Circle* cylinderBase;
        float cylinderHeight;

    public:

        // Constructors
        Cylinder() ;

        Cylinder(float radius, float height) ;

        float Volume() const override ;

        std::string GetName3D() const override ;

        void Scale(float factor) override ;

        void Display() const override ;

};

class Sphere: public Shape3D {

    private:
        Circle* SphereBase;

    public:
        Sphere() ;

        Sphere(float radius) ;

        float Volume() const ;

        std::string GetName3D() const override ;

        void Scale(float factor) override ;

        void Display() const override ;
};