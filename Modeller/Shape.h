/*
 * Shape.h
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include "Point.h"
#include "Angles.h"
#include "Circle.h"
#include "Cone.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Primed.h"
#include "Quad.h"
#include "Sphere.h"

enum Types {TEmpty, TQuad, TCube, TTriangle, TPrimed, TCircle, TSphere, TCone, TCylinder};

class Shape {
public:
	Point translate; // Indicates to which point we need to translate the origin. Note the origin will be left there.
					// So I strongly recommend you to not use this option at all. And add translation to vertices.
	float xRotate;
	float yRotate;
	float zRotate; //Rotations are in degree between ±1 and ±359 or even more!
	Types type; // keeps the type of the instantiated class;
	Quad* quad;
	Cube* cube;
	Triangle* triangle;
	Primed* primed;
	Circle* circle;
	Sphere* sphere;
	Cone* cone;
	Cylinder* cylinder;
	bool valid;
public:
	Shape(Types type = TEmpty);
	Shape(Point translate, float xRotate, float yRotate, float zRotate);
	Shape(float xRotate, float yRotate, float zRotate);
	Shape(Point translate);
	virtual ~Shape();
	void setQuad(Quad* quad);
	void setCube(Cube* cube);
	void setTriangle(Triangle* triangle);
	void setPrimed(Primed* primed);
	void setCircle(Circle* circle);
	void setSphere(Sphere* sphere);
	void setCone(Cone* cone);
	void setCylinder(Cylinder* cylinder);
	bool isValid();
	string to_string();
private:
	string to_string(float number);
	string to_string(int number);
};

#endif /* SHAPE_H_ */
