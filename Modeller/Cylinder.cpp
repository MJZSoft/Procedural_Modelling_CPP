/*
 * Cylinder.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#include "Cylinder.h"

Cylinder::Cylinder(float baseRadius, float topRadius, float height, float slices, float stacks, Color color, Texture texture){
	this->baseRadius = baseRadius;
	this->topRadius = topRadius;
	this->height = height;
	this->slices = slices;
	this->stacks = stacks;
	this->head = Circle();
	this->bottom = Circle();
	this->color = color;
	this->texture = texture;
	this->valid = true;
};
Cylinder::Cylinder(float baseRadius, float topRadius, float height, float slices, float stacks, Circle bottom, Color color, Texture texture){
	this->baseRadius = baseRadius;
	this->topRadius = topRadius;
	this->height = height;
	this->slices = slices;
	this->stacks = stacks;
	this->head = Circle();
	this->bottom = bottom;
	this->color = color;
	this->texture = texture;
	this->valid = true;
}
Cylinder::Cylinder(float baseRadius, float topRadius, float height, float slices, float stacks, Circle head, Circle bottom, Color color, Texture texture){
	this->baseRadius = baseRadius;
	this->topRadius = topRadius;
	this->height = height;
	this->slices = slices;
	this->stacks = stacks;
	this->head = head;
	this->bottom = bottom;
	this->color = color;
	this->texture = texture;
	this->valid = true;
}
Cylinder::~Cylinder() {
	// TODO Auto-generated destructor stub
}
bool Cylinder::isValid(){
	return this->valid;
};

string Cylinder::to_string(float number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();
};
string Cylinder::to_string(){
	string tmp = (this->isValid()?"1":"0");
	string str = "Cylinder("+tmp+"): \n"
			   + "\t{\n"
			   + "  	BaseRd= "+this->to_string(this->baseRadius)
			   + "\n	TopRdu= "+this->to_string(this->topRadius)
			   + "\n	Height= "+this->to_string(this->height)
			   + "\n	Slices= "+this->to_string(this->slices)
			   + "\n	Stacks= "+this->to_string(this->stacks)
			   + "\n	HeadCr= "+this->head.to_string()
			   + "  	BotmCr= "+this->bottom.to_string()
			   + "  	Color = "+this->color.to_string()+ "\n"
			   + "\t}\n";
	return str;
};
