/*
 * Cylinder.h
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#ifndef CYLINDER_H_
#define CYLINDER_H_

#include "Color.h"
#include "Texture.h"
#include "Circle.h"

class Cylinder{
public:
	float baseRadius; //Specifies the radius of the cylinder at z = 0.
	float topRadius; //Specifies the radius of the cylinder at z = height.
	float height; //Specifies the height of the cylinder.
	float slices; //Specifies the number of subdivisions around the z axis.
	float stacks; //Specifies the number of subdivisions along the z axis
	Circle head; // A filled circle to block top of the cylinder (optional)
	Circle bottom; // A filled circle to block bottom (base) of the cylinder (optional)
	Color color; // Color of the side of Cylinder and it can be used for head and bottom also
	Texture texture; // Texture of the side of Cylinder and it can be used for head and bottom also
	bool valid;
public:
	Cylinder(float baseRadius, float topRadius, float height, 	float slices, float stacks, Color color=Color(), Texture texture=Texture()); // for pipe
	Cylinder(float baseRadius, float topRadius, float height, 	float slices, float stacks, Circle bottom, Color color=Color(), Texture texture=Texture());
	Cylinder(float baseRadius, float topRadius, float height, 	float slices, float stacks, Circle head, Circle bottom, Color color=Color(), Texture texture=Texture());
	virtual ~Cylinder();
	bool isValid();
	string to_string();
private:
	string to_string(float number);
};

#endif /* CYLINDER_H_ */
