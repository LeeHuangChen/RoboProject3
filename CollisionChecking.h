#ifndef COLLISION_CHECKING_H_
#define COLLISION_CHECKING_H_

#include <vector>
#include <cmath>
#include <iostream>

struct Rectangle
{
    // Coordinate of the lower left corner of the rectangle
    double x, y;
    // The width (x-axis extent) of the rectangle
    double width;
    // The height (y-axis extent) of the rectangle
    double height;
};

// Definition of our robot.
struct Robot
{
    // Type = {c,s,p}.  Circle, square, or point robot
    char type;
    // The location of the robot in the environment
    double x, y;
    // The orientation of the square robot.  Undefined for point or circle robot
    double theta;
    // The length of a side of the square robot or the radius of the circle robot
    // Undefined for the point robot.
    double length;
};

bool valueInRange(double k, double k1, double k2);

bool rangesOverlap(double s1k1, double s1k2, double s2k1, double s2k2);

// Intersects the line segment defined by x1, y1, x2, y2, with lines of the Rectangle rect.
// Returns true if the line segment does not intersect with the rectangle
bool isValidSegment(double x1, double y1, double x2, double y2, Rectangle &rect);

double rotatedX(double x0, double y0, double theta, double xt);

double rotatedY(double x0, double y0, double theta, double yt);

// Intersect the point (x,y) with the set of rectangles.  If the point lies outside of all obstacles, return true.
bool isValidPoint(double x, double y, const std::vector<Rectangle>& obstacles);

// Intersect a circle with center (x,y) and given radius with the set of rectangles.  If the circle
// lies outside of all obstacles, return true
bool isValidCircle(double x, double y, double radius, const std::vector<Rectangle>& obstacles);

// Intersect a square with center at (x,y), orientation theta, and the given side length with the set of rectangles.
// If the square lies outside of all obstacles, return true
bool isValidSquare(double x, double y, double theta, double sideLength, const std::vector<Rectangle>& obstacles);

// Custom debugging/development code.  Takes the list of robots, the list of obstacles,
// and whether or not each configuation should be valid or not.
void debugMode(const std::vector<Robot>& robots, const std::vector<Rectangle>& obstacles, const std::vector<bool>& valid);

#endif