/*
 * Color.h
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#ifndef COLOR_H_
#define COLOR_H_
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;
class Color {
private:
	float r;
	float g;
	float b;
	float a;
	bool valid;
public:
	Color();
	Color(float r, float g, float b, float a=0.0f);
	virtual ~Color();
  Color* disturb();
	bool setR(float r);
	bool setG(float g);
	bool setB(float b);
	bool setA(float a);
	float getR();
	float getG();
	float getB();
	float getA();
	vector<float> getColor();
	bool setColor(float r, float g, float b, float a=0.0f);
	string to_string();
	bool isValid();
private:
	string to_string(float number);
};

#endif /* COLOR_H_ */
