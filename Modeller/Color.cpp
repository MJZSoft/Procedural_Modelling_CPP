/*
 * Color.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#include "Color.h"

Color::Color() {
	this->r = 0.0;
	this->g = 0.0;
	this->b = 0.0;
	this->a = 0.0;
	this->valid = false;
}
Color::Color(float r, float g, float b, float a){
	this->setA(a);
	this->setR(r);
	this->setG(g);
	this->setB(b);
	this->valid = true;
};

Color* Color::disturb() {
  float newB = getB() + 0.2;
  if (newB > 1.0) { newB -= 1.0; }
  setB(newB);
  return this;
}

bool Color::setR(float r){

	if(r>=0 && r<=1.0)
	{
		this->r = r;
		return true;
	}
	return false;

};
bool Color::setG(float g){
	if(g>=0 && g<=1.0)
	{
		this->g = g;
		return true;
	}
	return false;
};
bool Color::setB(float b){
	if(b>=0 && b<=1.0)
	{
		this->b = b;
		return true;
	}
	return false;
};
bool Color::setA(float a){
	if(a>=0 && a<=1.0)
	{
		this->a = a;
		return true;
	}
	return false;
};
float Color::getR(){
	return this->r;
};
float Color::getG(){
	return this->g;
};
float Color::getB(){
	return this->b;
};
float Color::getA(){
	return this->a;
};
vector<float> Color::getColor(){
	vector<float> c(4);
	c.push_back(this->r);
	c.push_back(this->g);
	c.push_back(this->b);
	c.push_back(this->a);
	return c;
};
bool Color::setColor(float r, float g, float b, float a){
	if(r>=0 && r<=1.0 && g>=0 && g<=1.0 && b>=0 && b<=1.0 && a>=0 && a<=1.0)
	{
		this->setA(a);
		this->setR(r);
		this->setG(g);
		this->setB(b);
		this->valid = true;
		return true;
	}
	return false;
};
bool Color::isValid(){
	return this->valid;
};

Color::~Color() {
	// TODO Auto-generated destructor stub
}
string Color::to_string(float number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();
}
string Color::to_string(){
	string str = "("+ to_string(r)+", "+ to_string(g)+", "+ to_string(b)+", "+ to_string(a)+")";
	return str;
};
