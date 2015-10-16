/*
 * Triangle.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#include "Triangle.h"
Triangle::Triangle() {
	this->points[0] = Point();
	this->points[1] = Point();
	this->points[2] = Point();
	this->colors[0] = Color();
	this->colors[1] = Color();
	this->colors[2] = Color();
	this->texture = Texture();
	this->valid = false;
};
Triangle::Triangle(Point p1, Point p2, Point p3) {
	this->points[0] = p1;
	this->points[1] = p2;
	this->points[2] = p3;
	this->colors[0] = Color();
	this->colors[1] = Color();
	this->colors[2] = Color();
	this->texture = Texture();
	this->valid = true;
};
Triangle::Triangle(Point p1, Point p2, Point p3, Texture t) {
	this->points[0] = p1;
	this->points[1] = p2;
	this->points[2] = p3;
	this->colors[0] = Color();
	this->colors[1] = Color();
	this->colors[2] = Color();
	this->texture = t;
	this->valid = true;
};
Triangle::Triangle(Point p1, Point p2, Point p3, Color c1) {
	this->points[0] = p1;
	this->points[1] = p2;
	this->points[2] = p3;
	this->colors[0] = c1;
	this->colors[1] = c1;
	this->colors[2] = c1;
	this->texture = Texture();
	this->valid = true;
};
Triangle::Triangle(Point p1, Point p2, Point p3, Color c1, Color c2) {
	this->points[0] = p1;
	this->points[1] = p2;
	this->points[2] = p3;
	this->colors[0] = c1;
	this->colors[1] = c2;
	this->colors[2] = c2;
	this->texture = Texture();
	this->valid = true;
};
Triangle::Triangle(Point p1, Point p2, Point p3, Color c1, Color c2, Color c3) {
	this->points[0] = p1;
	this->points[1] = p2;
	this->points[2] = p3;
	this->colors[0] = c1;
	this->colors[1] = c2;
	this->colors[2] = c3;
	this->texture = Texture();
	this->valid = true;
};
Triangle::Triangle(Point p1, Point p2, Point p3, Color c1, Color c2, Color c3, Texture t) {
	this->points[0] = p1;
	this->points[1] = p2;
	this->points[2] = p3;
	this->colors[0] = c1;
	this->colors[1] = c2;
	this->colors[2] = c3;
	this->texture = t;
	this->valid = true;
};
bool Triangle::isValid(){
	return this->valid;
};
Triangle::~Triangle() {
	// TODO Auto-generated destructor stub
}
string Triangle::to_string(){
	string tmp = (this->isValid()?"1":"0");
	string str = "Triangle("+tmp+"): \n"
			   + "\t{\n"
			   + "		Points=> "+this->points[0].to_string()+" , "+this->points[1].to_string()+" , "+this->points[2].to_string() + "\n"
			   + "		Colors=> "+this->colors[0].to_string()+" , "+this->colors[1].to_string()+" , "+this->colors[2].to_string() + "\n"
			   + "\t}\n";
	return str;
};
