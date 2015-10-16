/*
 * visualizer.h
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#ifndef RENDERER_H_
#define RENDERER_H_

#include <unistd.h>           // Header File for sleeping
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <math.h>
#include "../Modeller/Shape.h"
#ifdef __APPLE__
	#  include <OpenGL/gl.h>
	#  include <OpenGL/glu.h>
	#  include <GLUT/glut.h>
#else
	#  include <GL/gl.h>         // Header File For The OpenGL32 Library
	#  include <GL/glu.h>        // Header File For The GLu32 Library
	#  include <GL/glut.h>       // Header File For The GLUT Library
#endif
using namespace std;

class Renderer {
public:
	static string appName;
	static int width;
	static int height;
	static bool fullScreenMode;
	static Point camPosition;
	static Point camFrontVector;
	static Angles camFrontVectorAngles;
	static Point camUpVector;
	static Angles camUpVectorAngles;
	static vector<Shape> shapes;
	static bool xAxesSelected;
	static bool yAxesSelected;
	static bool zAxesSelected;
	static float translateFraction;
	static float angleFraction;
	static float lightAmbient[4]; // white ambient light at half intensity (rgba)
	static float lightDiffuse[4]; // super bright, full intensity diffuse light.
	static float lightPosition[4]; // position of light (x, y, z, (position of light))
	static bool  lightOn;
public:
	Renderer(string str, vector<Shape> shapes, int width=1024, int height=768, bool fullScreenMode=true);
	virtual ~Renderer();
	void  initGL();
	void  render();
	static void drawQuad(Shape shape);
	static void drawCube(Shape shape);
	static void drawTriangle(Shape shape);
	static void drawPrimed(Shape shape);
	static void drawCircle(Shape shape);
	static void drawSphere(Shape shape);
	static void drawCone(Shape shape);
	static void drawCylinder(Shape shape);
	static void setCamera(void);
};

#endif /* RENDERER_H_ */
