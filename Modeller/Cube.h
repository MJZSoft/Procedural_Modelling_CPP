/*
 * Cube.h
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#ifndef CUBE_H_
#define CUBE_H_

#include "Color.h"
#include "Texture.h"
#include "Quad.h"

class Cube{
public:
	Quad sides[6];
	Color color;
	Texture texture;
	bool valid;
public:
	Cube(Quad side1, Quad side2, Quad side3, Quad side4, Quad side5, Quad side6, Color color = Color(), Texture texture=Texture());
	virtual ~Cube();
	bool isValid();
	string to_string();
};

#endif /* CUBE_H_ */
