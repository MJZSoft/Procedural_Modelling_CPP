/*
 * Cone.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#include "Cone.h"
Cone::Cone(float baseRadius, float height, float slices, float stacks, Color color, Texture texture){
	this->baseRadius = baseRadius;
	this->height = height;
	this->slices = slices;
	this->stacks = stacks;
	this->bottom = Circle();
	this->color = color;
	this->texture = texture;
	this->valid = true;
}
Cone::Cone(float baseRadius, float height, float slices, float stacks, Circle bottom, Color color, Texture texture){
	this->baseRadius = baseRadius;
	this->height = height;
	this->slices = slices;
	this->stacks = stacks;
	this->bottom = bottom;
	this->color = color;
	this->texture = texture;
	this->valid = true;
}
Cone::~Cone() {
	// TODO Auto-generated destructor stub
}
bool Cone::isValid(){
	return this->valid;
};
string Cone::to_string(float number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();
};
string Cone::to_string(){
	string tmp = (this->isValid()?"1":"0");
	string str = "Cone("+tmp+"): \n"
			   + "\t{\n"
			   + "  	BaseRd= "+this->to_string(this->baseRadius)
			   + "\n	Height= "+this->to_string(this->height)
			   + "\n	Slices= "+this->to_string(this->slices)
			   + "\n	Stacks= "+this->to_string(this->stacks)
			   + "\n	BotmCr= "+this->bottom.to_string()
			   + "  	Color = "+this->color.to_string()+ "\n"
			   + "\t}\n";
	return str;
};
