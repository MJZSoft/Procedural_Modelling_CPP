/*
 * Angles.h
 *
 *  Created on: Sep 20, 2015
 *      Author: mjz
 */

#ifndef ANGLES_H_
#define ANGLES_H_

#define _USE_MATH_DEFINES

#include <math.h>
#include "Point.h"

class Angles: public Point {
public:
	Angles();
	Angles(float xAxis, float yAxis, float zAxis);
	virtual ~Angles();
	float xRadian();
	float yRadian();
	float zRadian();
	void setAngles(float xAxis, float yAxis, float zAxis);
};

#endif /* ANGLES_H_ */

