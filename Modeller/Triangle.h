/*
 * Triangle.h
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Point.h"
#include "Color.h"
#include "Texture.h"
#include <string>

class Triangle{
public:
	Point points[3];
	Color colors[3];
	Texture texture;
	bool valid;
public:
	Triangle();
	Triangle(Point p1, Point p2, Point p3);
	Triangle(Point p1, Point p2, Point p3, Texture t);
	Triangle(Point p1, Point p2, Point p3, Color c1);
	Triangle(Point p1, Point p2, Point p3, Color c1, Color c2);
	Triangle(Point p1, Point p2, Point p3, Color c1, Color c2, Color c3);
	Triangle(Point p1, Point p2, Point p3, Color c1, Color c2, Color c3, Texture t);
	virtual ~Triangle();
	string to_string();
	bool isValid();
};

#endif /* TRIANGLE_H_ */
