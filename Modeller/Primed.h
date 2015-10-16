/*
 * Primed.h
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#ifndef PRIMED_H_
#define PRIMED_H_

#include "Color.h"
#include "Texture.h"
#include "Triangle.h"
#include "Quad.h"

class Primed{
public:
	Triangle sides[4]; // 4 triangles which can have their own color and texture.
	Quad square; // can be ignored if you don’t want to close bottom of primed.
	Color color; // The general color. If set and any of 5 previous does not have color this will use
	Texture texture;
	bool valid;
public:
	Primed(Triangle side1, Triangle side2, Triangle side3, Triangle side4, Color color = Color(), Texture texture = Texture());
	Primed(Triangle side1, Triangle side2, Triangle side3, Triangle side4, Quad square, Color color = Color(), Texture texture = Texture());
	virtual ~Primed();
	bool isValid();
	string to_string();
};

#endif /* PRIMED_H_ */
