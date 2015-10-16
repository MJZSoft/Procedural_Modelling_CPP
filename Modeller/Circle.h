/*
 * Circle.h
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_
//#include <string>
#include "Point.h"
#include "Color.h"
#include "Texture.h"

class Circle {
public:
	Point center;
	float radius;
	Color color;
	Texture texture;
	bool filled; // if set to false it just will be an empty circle
	bool valid;
public:
	Circle();
	Circle(Point center, float radius, bool filled=false, Color color= Color(), Texture texture = Texture());
	virtual ~Circle();
	bool isValid();
	string to_string();
private:
	string to_string(float number);
};

#endif /* CIRCLE_H_ */
