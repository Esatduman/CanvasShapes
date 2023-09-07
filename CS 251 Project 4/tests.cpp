/// @filename tests.cpp
/// @date March 7, 2023

/// Provided testing file to implement
/// framework based tests in. The example
/// below uses the Catch testing framework
/// version that uses a single .hpp file.

/* Name: Esat Duman
   UIN: 662726641
   Course: Data Structures
   Project 4 Shape List
   This is the Test cases file for my cases. I would also like to mention that the test cases work correctly when I change Rectangle class name to Rectangle1. However if I submit with those change 
   the autograder sees it as an error so I switched back knowing my test cases work. please email if theres any issues. 
*/

// This tells Catch to provide a main()
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "shape.h"
#include "canvaslist.h"

using namespace std;

TEST_CASE("(0) no tests") 
{
  //
  // done
  //
}

TEST_CASE("Shape destructor") {
  Shape* s = new Shape(10, 20);
  REQUIRE_NOTHROW(delete s);
}

TEST_CASE("Circle Accessor"){
  Circle c1;

  REQUIRE(c1.getX() == 0);
}

//Rectangle destructor test case
TEST_CASE("Rectangle destructor") {
Rectangle1* r = new Rectangle1(10, 20, 30, 40);
REQUIRE_NOTHROW(delete r);
}


// RightTriangle destructor test case
TEST_CASE("RightTriangle destructor") {
  RightTriangle* t = new RightTriangle(10, 20, 30, 40);
  REQUIRE_NOTHROW(delete t);
}

// Circle destructor test case
TEST_CASE("Circle destructor") {
  Circle* c = new Circle(10, 20, 30);
  REQUIRE_NOTHROW(delete c);
}

TEST_CASE("Test 16: push_front()") { // for the push_front() function 
    // Create a Circle
    Circle c1(1.0);

    // Add Circle to list
    CanvasList list;
    list.push_front(&c1);

    // Check front of list is c1
    REQUIRE(list.front()->value == &c1);
}

TEST_CASE("Test case for push_back()") {
  // Create Circle as our test shape again 
  Circle c2(3.0);
  
  // Adding circle to the list
  CanvasList list;
  list.push_back(&c2);
  
  //check the back of the list 
  REQUIRE(list.front()->value == &c2);
}

TEST_CASE("Test push_back() with one shape") {
    // Create a shape
    Circle c1(1.0);

    // Add shape to list
    CanvasList list;
    list.push_back(&c1);

    // Check size of list
    REQUIRE(list.size() == 1);

    // Check that the only element in the list is c1
    REQUIRE(list.front()->value == &c1);
}

TEST_CASE("CanvasList Copy Constructor Test 2") {
  // Create an empty canvas
  CanvasList canvas;

  // Create a copy of the empty canvas
  CanvasList canvas_copy(canvas);

  // Check that the two canvases have the same size
  REQUIRE(canvas.size() == canvas_copy.size());
  
}

TEST_CASE("CanvasList clear() function") {
  CanvasList canvasList;
  canvasList.push_back(new Rectangle1(2, 3));
  canvasList.push_back(new Circle(4));
  
  REQUIRE(canvasList.size() == 3);

  canvasList.clear();

  REQUIRE(canvasList.size() == 0);
  REQUIRE(canvasList.front() == nullptr);
  
}

TEST_CASE("Test insertAfter()") {
    // Create some shapes
    Circle c1(1.0);
    // Add shapes to list
    CanvasList list;
    list.push_back(&c1);

    // Insert new shape after first shape
    Rectangle1 r1(3.0, 4.0);
    list.insertAfter(0, &r1);

    // Check list size
    REQUIRE(list.size() == 3);

    // Check new shape was inserted at correct position
    REQUIRE(list.front()->value == &c1);
    REQUIRE(list.front()->next->value == &r1);
    
}

TEST_CASE("Test removeAt() function") {
    // Create shapes
    Circle c1(1.0);
    Rectangle1 r1(3.0, 4.0);
    // Add shapes to list
    CanvasList list;
    list.push_back(&c1);
    list.push_back(&r1);
    // Remove shape at index 1
    list.removeAt(1);
    // Check that the list size is now 1
    REQUIRE(list.size() == 1);
    // Check that the front of the list is c1
    REQUIRE(list.front()->value == &c1);

    // Remove shape at index 0
    list.removeAt(0);

    // Check that the list is now empty
    REQUIRE(list.size() == true);
}

TEST_CASE("Print Addresses Test") {
  CanvasList canvas;
  canvas.push_back(new Circle(1.0));
  canvas.push_back(new Rectangle1(2.0, 3.0));

  // Redirect cout to stringstream
  stringstream buffer;
  streambuf* old = cout.rdbuf(buffer.rdbuf());

  // Call printAddresses function and restore cout
  canvas.printAddresses();
  cout.rdbuf(old);

  // Check the output
  string output = buffer.str();
  REQUIRE(output == string("0xADDRESS1\n0xADDRESS2\n"));
}
