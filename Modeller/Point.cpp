/*
 * Point.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#include "Point.h"
Point::Point(){
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}
Point::Point(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Point::~Point() {
	// TODO Auto-generated destructor stub
}
string Point::to_string(float number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();
}
string Point::to_string(){
	string str = "("+to_string(x)+", "+to_string(y)+", "+to_string(z)+")";
	return str;
};
void Point::setPoint(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
