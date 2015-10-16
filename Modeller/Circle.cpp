/*
 * Circle.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#include "Circle.h"

Circle::Circle(){
	this->center = Point();
	this->radius = 0;
	this->color = Color();
	this->texture = Texture();
	this->filled = false;
	this->valid = false;
};

Circle::Circle(Point center, float radius, bool filled, Color color, Texture texture){
	this->center = center;
	this->radius = radius;
	this->color = color;
	this->texture = texture;
	this->filled = filled;
	this->valid = true;
};

Circle::~Circle() {
	// TODO Auto-generated destructor stub
};

bool Circle::isValid(){
	return this->valid;
};

string Circle::to_string(float number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();
}
string Circle::to_string(){
	string tmp = (this->isValid()?"1":"0");
	string str = "Circle("
			   + tmp
			   + "): \n"
			   + "\t{\n"
			   + "		Center= "+this->center.to_string()
			   + "\n	Radius= "+this->to_string(this->radius)
			   + "\n	Filled= "+(this->filled?"Yes":"No")
			   + "\n	Color = "+this->color.to_string()+ "\n"
			   + "\t}\n";
	return str;
};
