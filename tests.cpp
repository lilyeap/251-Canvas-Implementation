/*tests.cpp*/

/*  Project 4 Shape List
  Course: CS 251, Spring 2023
  Author: Lily Eap
  NetID: leap2
  UIN: 67697798
  File: tests.cpp, test cases
  Description: using Catch to test the functionality of Shape class and Canvaslist class

*/

// This tells Catch to provide a main()
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "shape.h"
#include "canvaslist.h"

using namespace std;

TEST_CASE("(1) default shape") 
{
  Shape testShape;
  REQUIRE(testShape.getX() == 0);
  REQUIRE(testShape.getY() == 0);

  Circle circle;
  REQUIRE(circle.getX() == 0);
  REQUIRE(circle.getY() == 0);
  REQUIRE(circle.getRadius() == 0);

  Rectangle rectangle;
  REQUIRE(rectangle.getX() == 0);
  REQUIRE(rectangle.getY() == 0);
  REQUIRE(rectangle.getWidth() == 0);
  REQUIRE(rectangle.getHeight() == 0);

  RightTriangle triangle;
  REQUIRE(triangle.getX() == 0);
  REQUIRE(triangle.getY() == 0);
  REQUIRE(triangle.getBase() == 0);
  REQUIRE(triangle.getHeight() == 0);
}

TEST_CASE("(2) parameterized shape") 
{
  Shape testShape(4,10);
  REQUIRE(testShape.getX() == 4);
  REQUIRE(testShape.getY() == 10);

  Circle circle(5,5,4);
  REQUIRE(circle.getX() == 5);
  REQUIRE(circle.getY() == 5);
  REQUIRE(circle.getRadius() == 4);

  Rectangle rectangle(1,2,3,4);
  REQUIRE(rectangle.getX() == 1);
  REQUIRE(rectangle.getY() == 2);
  REQUIRE(rectangle.getWidth() == 3);
  REQUIRE(rectangle.getHeight() == 4);

  RightTriangle triangle(1,2,3,4);
  REQUIRE(triangle.getX() == 1);
  REQUIRE(triangle.getY() == 2);
  REQUIRE(triangle.getBase() == 3);
  REQUIRE(triangle.getHeight() == 4);
}

TEST_CASE("(3) getters/setters shape") 
{
  Shape testShape(4,10);
  testShape.setX(1);
  testShape.setY(3);
  REQUIRE(testShape.getX() == 1);
  REQUIRE(testShape.getY() == 3);

  Circle circle1(5,4,4);
  circle1.setX(3);
  circle1.setRadius(5);
  REQUIRE(circle1.getX() == 3);
  REQUIRE(circle1.getY() == 4);
  REQUIRE(circle1.getRadius() == 5);

  Rectangle rectangle1(1,2,3,4);
  rectangle1.setY(5);
  rectangle1.setWidth(6);
  REQUIRE(rectangle1.getX() == 1);
  REQUIRE(rectangle1.getY() == 5);
  REQUIRE(rectangle1.getWidth() == 6);
  REQUIRE(rectangle1.getHeight() == 4);

  RightTriangle triangle1(1,2,3,4);
  triangle1.setY(5);
  triangle1.setBase(6);
  REQUIRE(triangle1.getX() == 1);
  REQUIRE(triangle1.getY() == 5);
  REQUIRE(triangle1.getBase() == 6);
  REQUIRE(triangle1.getHeight() == 4);

}

TEST_CASE("(4) default canvas features") 
{
  CanvasList myCanvas;
	REQUIRE(myCanvas.size() == 0);
  REQUIRE(myCanvas.front() == 0);
  REQUIRE(myCanvas.isempty() == true);
  REQUIRE(myCanvas.shapeAt(0) == nullptr);
}

TEST_CASE("(5) empty canvas with pop, insert after and remove at") 
{
  CanvasList myCanvas;
  REQUIRE(myCanvas.pop_front() == nullptr);
  REQUIRE(myCanvas.isempty() == true);
  REQUIRE(myCanvas.pop_back() == nullptr);
  REQUIRE(myCanvas.isempty() == true);
  REQUIRE(myCanvas.shapeAt(0) == nullptr);
  myCanvas.insertAfter(0, new Shape);
  REQUIRE(myCanvas.isempty() == true);
  myCanvas.removeAt(0);
  REQUIRE(myCanvas.isempty() == true);	
}

TEST_CASE("(6) canvas push front/back shape") 
{
  CanvasList myCanvas;
  Shape *s = new Shape(1, 1);
  Shape *s1 = new Circle(2, 4, 3);
  Shape *s2 = new Rectangle(3, 3);
	myCanvas.push_front(s);
  myCanvas.push_front(s1);
  myCanvas.push_back(s2);
  //circle, shape, rectangle
  s = new RightTriangle(1, 2, 3, 4);
  s1 = new Circle(2, 4, 3);
  myCanvas.push_front(s);
  myCanvas.push_back(s1);
  //right triangle, circle, shape, rectangle, circle
  REQUIRE(myCanvas.size() == 5);
	// REQUIRE(myCanvas.front() == s);
}

TEST_CASE("(7) canvas pop front/back + shapeAt functionality ") 
{
  CanvasList myCanvas;
  Shape *s = new Shape(1, 1);
  Shape *s1 = new Circle(2, 4, 3);
  Shape *s2 = new Rectangle(3, 3);
  Shape *s3 = new RightTriangle(1, 2, 3, 4);
  Shape *s4 = new Circle(2, 4, 3);
  Shape *s5 = new Rectangle(0, 10);
	myCanvas.push_back(s);
  myCanvas.push_back(s1);
  myCanvas.push_back(s2);  
	myCanvas.push_back(s3);
  myCanvas.push_back(s4);
  myCanvas.push_back(s5);
  //shape, circle, rectangle, right triangle, circle, rectangle
  REQUIRE(myCanvas.size() == 6);

  delete myCanvas.pop_front();
  delete myCanvas.pop_front();
  delete myCanvas.pop_back();
  //rectangle, right triangle, circle
  REQUIRE(myCanvas.size() == 3);
  REQUIRE(myCanvas.shapeAt(0) == s2);
  REQUIRE(myCanvas.shapeAt(1) == s3);
  REQUIRE(myCanvas.shapeAt(2) == s4);
  REQUIRE(myCanvas.shapeAt(3) == nullptr);
}


TEST_CASE("(8) push front/back, clear, push one + shapeAt"){
  CanvasList myCanvas;
  Shape *s = new Shape(1, 1);
  Shape *s1 = new Circle(2, 4, 3);
  Shape *s2 = new Rectangle(3, 3);
	myCanvas.push_back(s);
  myCanvas.push_back(s1);
  myCanvas.push_back(s2);
  REQUIRE(myCanvas.size() == 3);

  myCanvas.clear();
  REQUIRE(myCanvas.isempty() == true);

  myCanvas.push_back(s); 
  REQUIRE(myCanvas.size() == 1);
  REQUIRE(myCanvas.shapeAt(0) == s);
  REQUIRE(myCanvas.shapeAt(1) == nullptr);
}

TEST_CASE("(9) copy constructor + insertAfter"){
  //create a canvas
  CanvasList myCanvas;
  Shape *s = new Shape(1, 1);
  Shape *s1 = new Circle(2, 4, 3);
  Shape *s2 = new Rectangle(3, 3);
  myCanvas.push_back(s);
  myCanvas.push_back(s1);
  myCanvas.push_back(s2);

  //copy canvas, change original canvas and change new canvas
  CanvasList copyCanvas = myCanvas;
  myCanvas.pop_back();
  myCanvas.pop_back();
  Shape *s3 = new RightTriangle(1,1);
  copyCanvas.push_back(s3); //shape, circle, rectangle, right triangle
  REQUIRE(myCanvas.size() == 1);
  REQUIRE(copyCanvas.size() == 4);
  REQUIRE(copyCanvas.shapeAt(3) == s3);
  REQUIRE(copyCanvas.shapeAt(4) == nullptr);


  //check insertAfter functionality on copyCanvas
  Shape *s4 = new Rectangle(3,4,5,5);
  copyCanvas.insertAfter(1, s4); //shape, circle, rectangle (s4), rectangle (s2), right triangle
  REQUIRE(copyCanvas.shapeAt(2) == s4);
  REQUIRE(copyCanvas.shapeAt(3) == s2);

  REQUIRE(myCanvas.isempty() == false);
  REQUIRE(copyCanvas.isempty() == false);
}

TEST_CASE("(10) assignment operator + removeAt"){
  //create a canvas
  CanvasList myCanvas;
  Shape *s = new Shape(1, 1);
  Shape *s1 = new Circle(2, 4, 3);
  Shape *s2 = new Rectangle(3, 3);
  myCanvas.push_back(s);
  myCanvas.push_back(s1);
  myCanvas.push_back(s2);
  REQUIRE(myCanvas.isempty() == false); 

  CanvasList newCanvas;
  Shape *s3 = new RightTriangle(1, 2, 3, 4);
  Shape *s4 = new Circle(2, 4, 3);
  Shape *s5 = new Rectangle(0, 10);
	newCanvas.push_back(s3);
  newCanvas.push_back(s4);
  newCanvas.push_back(s5);

  newCanvas = myCanvas; 
  REQUIRE(newCanvas.shapeAt(0) == s);
  REQUIRE(newCanvas.shapeAt(1) == s1);
  REQUIRE(newCanvas.shapeAt(2) == s2);
  REQUIRE(newCanvas.shapeAt(3) == nullptr);
  REQUIRE(newCanvas.isempty() == false);

  newCanvas.removeAt(0); //remove at from a copy canvas and check other canvas is untouched
  REQUIRE(newCanvas.shapeAt(0) == s1);
  REQUIRE(newCanvas.shapeAt(1) == s2);
  REQUIRE(newCanvas.shapeAt(2) == nullptr);
  REQUIRE(myCanvas.shapeAt(0) == s);
  REQUIRE(myCanvas.shapeAt(1) == s1);
  REQUIRE(myCanvas.shapeAt(2) == s2);
  REQUIRE(myCanvas.shapeAt(3) == nullptr);
}

TEST_CASE("(10) find x, y"){
  CanvasList myCanvas;
  Shape *s = new Shape(1, 2);
  Shape *s1 = new Circle(1, 2, 3);
  Shape *s2 = new Rectangle(2, 2, 3, 3);
  myCanvas.push_back(s);
  myCanvas.push_back(s1);
  myCanvas.push_back(s2);
  REQUIRE(myCanvas.find(1,2) == 0); //find first 
  REQUIRE(myCanvas.find(0,0) == -1); //find none
}
	