/*
 * Cube.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#include "Cube.h"

Cube::Cube(Quad side1, Quad side2, Quad side3, Quad side4, Quad side5, Quad side6, Color color, Texture texture){
	this->sides[0] = side1;
	this->sides[1] = side2;
	this->sides[2] = side3;
	this->sides[3] = side4;
	this->sides[4] = side5;
	this->sides[5] = side6;
	this->color = color;
	this->texture = texture;
	this->valid = true;
}
Cube::~Cube() {
	// TODO Auto-generated destructor stub
}
bool Cube::isValid(){
	return this->valid;
};

string Cube::to_string(){
	string tmp = (this->isValid()?"1":"0");
	string str = "Cube("+tmp+"): \n"
			   + "\t{\n"
			   + "		Side1= "+this->sides[0].to_string()
			   + "		Side2= "+this->sides[1].to_string()
			   + "		Side3= "+this->sides[2].to_string()
			   + "		Side4= "+this->sides[3].to_string()
			   + "		Side5= "+this->sides[4].to_string()
			   + "		Side6= "+this->sides[5].to_string()
			   + "		Color= "+this->color.to_string()+"\n"
			   + "\t}\n";
	return str;
};
