/*
 * Shape.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#include "Shape.h"

Shape::Shape(Types ignoreType){
	this->type = TEmpty;
	this->translate = Point();
	this->xRotate = 0;
	this->yRotate = 0;
	this->zRotate = 0;
	this->valid = false;
};
Shape::Shape(Point translate){
	this->type = TEmpty;
	this->translate = translate;
	this->xRotate = 0;
	this->yRotate = 0;
	this->zRotate = 0;
	this->valid = true;
};
Shape::Shape(float xRotate, float yRotate, float zRotate){
	this->type = TEmpty;
	this->translate = Point();
	this->xRotate = xRotate;
	this->yRotate = yRotate;
	this->zRotate = zRotate;
	this->valid = true;
};
Shape::Shape(Point translate, float xRotate, float yRotate, float zRotate){
	this->type = TEmpty;
	this->translate = translate;
	this->xRotate = xRotate;
	this->yRotate = yRotate;
	this->zRotate = zRotate;
	this->valid = true;
};
void Shape::setQuad(Quad* quad){
	this->quad = quad;
	this->type = TQuad;
	this->valid = true;
};
void Shape::setCube(Cube* cube){
	this->cube = cube;
	this->type = TCube;
	this->valid = true;
};
void Shape::setTriangle(Triangle* triangle){
	this->triangle = triangle;
	this->type = TTriangle;
	this->valid = true;
};
void Shape::setPrimed(Primed* primed){
	this->primed = primed;
	this->type = TPrimed;
	this->valid = true;
};
void Shape::setCircle(Circle* circle){
	this->circle = circle;
	this->type = TCircle;
	this->valid = true;
};
void Shape::setSphere(Sphere* sphere){
	this->sphere = sphere;
	this->type = TSphere;
	this->valid = true;
};
void Shape::setCone(Cone* cone){
	this->cone = cone;
	this->type = TCone;
	this->valid = true;
};
void Shape::setCylinder(Cylinder* cylinder){
	this->cylinder = cylinder;
	this->type = TCylinder;
	this->valid = true;
};
Shape::~Shape() {
	// TODO Auto-generated destructor stub
};
bool Shape::isValid(){
	return this->valid;
};
string Shape::to_string(float number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();
}
string Shape::to_string(int number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();
}
string Shape::to_string(){
	string tmp = (this->isValid()?"1":"0");
	string str = "\n*******\nSHAPE("+tmp+"): \n"
			   + "\t{\n"
			   + " 		Translate= "+this->translate.to_string()+"\n"
			   + " 		Rotate(X,Y,Z)= ("+this->to_string(this->xRotate)+" , "+this->to_string(this->yRotate)+" , "+this->to_string(this->zRotate)+")\n"
			   + " 		Type= "+this->to_string(this->type)+"\n"
			   + "		Properties=[\n";
	 switch(this->type)
		  {
		  	  case TQuad:
		  		str += this->quad->to_string();
		  		break;
		  	  case TCube:
		  		str += this->cube->to_string();
		  		break;
		  	  case	TTriangle:
		  		str += this->triangle->to_string();
		  		break;
		  	  case TPrimed:
		  		str += this->primed->to_string();
		  		break;
		  	  case TCircle:
		  		str += this->circle->to_string();
		  		break;
		  	  case TSphere:
		  		str += this->sphere->to_string();
		  		break;
		  	  case TCone:
		  		str += this->cone->to_string();
		  		break;
		  	  case TCylinder:
		  		str += this->cylinder->to_string();
		  		break;
		  	  default:
		  		  break;
		  }
		   str += "			]\n\t}\n";
	return str;
}
