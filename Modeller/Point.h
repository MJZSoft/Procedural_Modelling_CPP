/*
 * Point.h
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#ifndef POINT_H_
#define POINT_H_

#include <string>
#include <sstream>
using namespace std;
class Point {
public:
	float x;
	float y;
	float z;
public:
	Point(float x, float y, float z);
	Point();
	virtual ~Point();
	string to_string();
	void setPoint(float x, float y, float z);
private:
	string to_string(float number);
};

#endif /* POINT_H_ */
