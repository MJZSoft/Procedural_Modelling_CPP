/*
 * Quad.h
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#ifndef QUAD_H_
#define QUAD_H_

#include "Point.h"
#include "Color.h"
#include "Texture.h"

class Quad{
public:
	Point points[4];
	Color colors[4];
	Texture texture;
	bool valid;
public:
	Quad();
	Quad(Point p1, Point p2, Point p3, Point p4);
	Quad(Point p1, Point p2, Point p3, Point p4, Texture t);
	Quad(Point p1, Point p2, Point p3, Point p4, Color c1);
	Quad(Point p1, Point p2, Point p3, Point p4, Color c1, Color c2);
	Quad(Point p1, Point p2, Point p3, Point p4, Color c1, Color c2, Color c3);
	Quad(Point p1, Point p2, Point p3, Point p4, Color c1, Color c2, Color c3, Color c4);
	Quad(Point p1, Point p2, Point p3, Point p4, Color c1, Color c2, Color c3, Color c4, Texture t);
	virtual ~Quad();
	bool isValid();
	string to_string();
};

#endif /* QUAD_H_ */
