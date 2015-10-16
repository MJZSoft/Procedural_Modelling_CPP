/*
 * Cone.h
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#ifndef CONE_H_
#define CONE_H_

#include "Color.h"
#include "Texture.h"
#include "Circle.h"

class Cone{
public:
	float baseRadius; //Specifies the radius of the cylinder at z = 0.
	float height; //Specifies the height of the cylinder.
	float slices; //Specifies the number of subdivisions around the z axis.
	float stacks; //Specifies the number of subdivisions along the z axis
	Circle bottom; // A filled circle to block bottom (base) of the cylinder (optional)
	Color color; // Color of the side of Cylinder and it can be used for head and bottom also
	Texture texture; // Texture of the side of Cylinder and it can be used for head and bottom also
	bool valid;
public:
	Cone(float baseRadius, float height, float slices, float stacks, Color color= Color(), Texture texture= Texture());
	Cone(float baseRadius, float height, float slices, float stacks, Circle bottom, Color color= Color(), Texture texture= Texture());
	virtual ~Cone();
	bool isValid();
	string to_string();
private:
	string to_string(float number);
};

#endif /* CONE_H_ */
