/*shape.h*/

/*  Project 4 Shape List
  Course: CS 251, Spring 2023
  Author: Lily Eap
  NetID: leap2
  UIN: 67697798
  File: shape.h, code for shape class
  Description: implementation for shape class that has a base class and derived classes of specific shapes 
                which share some of the same functionalities but differ in some private variables & getters/setters.

*/

#pragma once

using namespace std;

class Shape
{
    protected:
        int x;
        int y;

    public: 
        Shape(){x = 0; y = 0;};
        Shape(int x, int y){this->x = x; this->y = y;};

        virtual ~Shape(){};
        virtual Shape* copy(){
            Shape* copyShape = new Shape(x, y);
            return copyShape;
        };

        int getX() const {return x;};
        int getY() const {return y;};
        void setX(int x){this->x = x;};
        void setY(int y){this->y = y;};
        
        virtual void printShape() const{
            cout << "It's a Shape at x: " << x
                << ", y: " << y << endl;
        };
};


class Circle : public Shape 
{
    private:
        int radius;

    public: 
        Circle(){x = 0; y = 0; radius = 0;};
        Circle(int r){x = 0; y = 0; radius = r;};
        Circle(int x, int y, int r) {this->x = x; this->y = y; radius = r;};

        virtual ~Circle() {};
        virtual Circle* copy() {
            Circle* copyCircle = new Circle(x, y, radius); 
            return copyCircle;
        };
        
        int getRadius() const{return radius;};
        void setRadius(int r){radius = r;};
        
        virtual void printShape() const{
            cout << "It's a Circle" 
                << " at x: " << x
                << ", y: " << y
                << ", radius: " << radius << endl;
        };
};


class Rectangle : public Shape 
{
    private:
        int width;
        int height;

    public: 
        Rectangle(){x = 0; y = 0; width = 0; height = 0;};
        Rectangle(int w, int h){width = w; height = h;};
        Rectangle(int x, int y, int w, int h){this->x = x; this->y = y; width = w; height = h;};
        
        virtual ~Rectangle() {};
        virtual Rectangle* copy() {
            Rectangle* copyRectangle = new Rectangle(x,y,width,height); 
            return copyRectangle;
        };
        
        int getWidth() const {return width;};
        int getHeight() const {return height;};
        void setWidth(int w) {width = w;};
        void setHeight(int h) {height = h;};
        
        virtual void printShape() const{
            cout << "It's a Rectangle" 
                << " at x: " << x
                << ", y: " << y
                << " with width: " << width 
                << " and height: " << height << endl; 
        };
};

class RightTriangle : public Shape 
{
    private:
        int base;
        int height;

    public: 
        RightTriangle(){x = 0; y = 0; base = 0; height = 0;};;
        RightTriangle(int b, int h){base = b; height = h;};;
        RightTriangle(int x, int y, int b, int h){this->x = x; this->y = y; base = b; height = h;};
        
        virtual ~RightTriangle() {};
        virtual RightTriangle* copy() {
            RightTriangle* copyTriangle = new RightTriangle(x, y, base, height);
            return copyTriangle;
        };
        
        int getBase() const {return base;};
        int getHeight() const {return height;};
        void setBase(int b) {base = b;};
        void setHeight(int h) {height = h;};

        virtual void printShape() const{
            cout << "It's a Right Triangle" 
                << " at x: " << x
                << ", y: " << y
                << " with base: " << base 
                << " and height: " << height << endl; 
        };
};
