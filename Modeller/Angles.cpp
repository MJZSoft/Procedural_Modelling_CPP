/*
 * Angles.cpp
 *
 *  Created on: Sep 20, 2015
 *      Author: mjz
 */

#include "Angles.h"
Angles::Angles() : Point(){
}
Angles::Angles(float xAxis, float yAxis, float zAxis) : Point(xAxis, yAxis, zAxis){
}

Angles::~Angles() {
	// TODO Auto-generated destructor stub
}
float Angles::xRadian(){
	return this->x*M_PI/180;
};
float Angles::yRadian(){
	return this->y*M_PI/180;
};
float Angles::zRadian(){
	return this->z*M_PI/180;
};
void Angles::setAngles(float xAxis, float yAxis, float zAxis){
	this->x = xAxis;
	this->y = yAxis;
	this->z = zAxis;
};
