/*
 * Sphere.h
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "Point.h"
#include "Color.h"
#include "Texture.h"

class Sphere {
public:
	Point center;
	float radius;
	float slices;
	float stacks;
	Color color;
	Texture texture;
	bool valid;
public:
	Sphere();
	Sphere(Point center, float radius, float slices=100, float stacks=100, Color color=Color(), Texture texture=Texture());
	virtual ~Sphere();
	bool isValid();
	string to_string();
private:
	string to_string(float number);
};

#endif /* SPHERE_H_ */
