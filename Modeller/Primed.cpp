/*
 * Primed.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#include "Primed.h"

Primed::Primed(Triangle side1, Triangle side2, Triangle side3, Triangle side4, Color color, Texture texture) {
	this->sides[0] = side1;
	this->sides[1] = side2;
	this->sides[2] = side3;
	this->sides[3] = side4;
	this->square = Quad();
	this->color = color;
	this->texture = texture;
	this->valid = true;
};
Primed::Primed(Triangle side1, Triangle side2, Triangle side3, Triangle side4, Quad square, Color color, Texture texture) {
	this->sides[0] = side1;
	this->sides[1] = side2;
	this->sides[2] = side3;
	this->sides[3] = side4;
	this->square = square;
	this->color = color;
	this->texture = texture;
	this->valid = true;
};
Primed::~Primed() {
	// TODO Auto-generated destructor stub
}
bool Primed::isValid(){
	return this->valid;
};
string Primed::to_string(){
	string tmp = (this->isValid()?"1":"0");
	string str = "Primed("+tmp+"): \n"
			   + "\t{\n"
			   + "		Side1= "+this->sides[0].to_string()
			   + "		Side2= "+this->sides[1].to_string()
			   + "		Side3= "+this->sides[2].to_string()
			   + "		Side4= "+this->sides[3].to_string()
			   + "		Square= "+this->square.to_string()
			   + "		Color= "+this->color.to_string()+"\n"
			   + "\t}\n";
	return str;
}

