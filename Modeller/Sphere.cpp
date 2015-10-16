/*
 * Sphere.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#include "Sphere.h"
Sphere::Sphere(){
	this->center = Point();
	this->radius = 0;
	this->slices = 0;
	this->stacks = 0;
	this->color = Color();
	this->texture = Texture();
	this->valid = false;
}
Sphere::Sphere(Point center, float radius, float slices, float stacks, Color color, Texture texture){
	this->center = center;
	this->radius = radius;
	this->slices = slices;
	this->stacks = stacks;
	this->color = color;
	this->texture = texture;
	this->valid = true;
}

Sphere::~Sphere() {
	// TODO Auto-generated destructor stub
}
bool Sphere::isValid(){
	return this->valid;
};
string Sphere::to_string(float number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();
};
string Sphere::to_string(){
	string tmp = (this->isValid()?"1":"0");
	string str = "Sphere("+tmp+"): \n"
			   + "\t{\n"
			   + "		Center= "+this->center.to_string()
			   + "\n	Radius= "+this->to_string(this->radius)
			   + "\n	Slices= "+this->to_string(this->slices)
			   + "\n	Stacks= "+this->to_string(this->stacks)
			   + "\n	Color = "+this->color.to_string()+ "\n"
			   + "\t}\n";
	return str;
};
