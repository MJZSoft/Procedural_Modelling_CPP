/*
 * visualizer.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: mjz
 */

#include "renderer.h"


/* The number of our GLUT window */
int window;

vector<Shape> Renderer::shapes;
string Renderer::appName;
int    Renderer::width;
int    Renderer::height;
bool   Renderer::fullScreenMode;
bool   Renderer::xAxesSelected;
bool   Renderer::yAxesSelected;
bool   Renderer::zAxesSelected;
bool   Renderer::lightOn;
float  Renderer::translateFraction;
float  Renderer::angleFraction;
float  Renderer::lightAmbient[4];
float  Renderer::lightDiffuse[4];
float  Renderer::lightPosition[4];
Point  Renderer::camPosition;
Point  Renderer::camFrontVector;
Point  Renderer::camUpVector;
Angles Renderer::camFrontVectorAngles;
Angles Renderer::camUpVectorAngles;

//
Renderer::Renderer(string appName, vector<Shape> shapes, int width, int height, bool fullScreenMode) {
	this->appName = appName;
	this->shapes = shapes;
	this->width = width;
	this->height = height;
	this->fullScreenMode = fullScreenMode;
	this->camPosition = *(new Point(0,0,10));
	this->camUpVector = *(new Point(0,1,0));
	this->camFrontVector = *(new Point(0,0,-1));
	this->camUpVectorAngles = *(new Angles(90,0,270));
	this->camFrontVectorAngles = *(new Angles(90,270,180));
	this->xAxesSelected = false;
	this->yAxesSelected = false;
	this->zAxesSelected = false;
	this->translateFraction = 0.1f;
	this->angleFraction = 0.5f;
	//
	this->lightAmbient[0]  = 0.8f;
	this->lightAmbient[1]  = 0.8f;
	this->lightAmbient[2]  = 0.8f;
	this->lightAmbient[3]  = 1.0f;
	//
	this->lightDiffuse[0]  =  1.0f;
	this->lightDiffuse[1]  =  1.0f;
	this->lightDiffuse[2]  =  1.0f;
	this->lightDiffuse[3]  =  1.0f;
	//
	this->lightPosition[0] = 0.0f;
	this->lightPosition[1] = 4.0f;
	this->lightPosition[2] = 2.0f;
	this->lightPosition[3] = 1.0f;
	//
	this->lightOn = true;
};

Renderer::~Renderer() {

};
int sign(float x){
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}
/* The main drawing function. */
void DrawGLScene()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
  glLoadIdentity();				// Reset The View
  // Set the camera
  Renderer::setCamera();
  int num = Renderer::shapes.size();
  for(int i=0; i<num; i++)
  {
	  Shape shape = Renderer::shapes[i];
	  switch(shape.type)
	  {
	  	  case TQuad:
	  		Renderer::drawQuad(shape);
	  		break;
	  	  case TCube:
	  		Renderer::drawCube(shape);
	  		break;
	  	  case	TTriangle:
	  		Renderer::drawTriangle(shape);
	  		break;
	  	  case TPrimed:
	  		Renderer::drawPrimed(shape);
	  		break;
	  	  case TCircle:
	  		Renderer::drawCircle(shape);
	  		break;
	  	  case TSphere:
	  		Renderer::drawSphere(shape);
	  		break;
	  	  case TCone:
	  		Renderer::drawCone(shape);
	  		break;
	  	  case TCylinder:
	  		Renderer::drawCylinder(shape);
	  		break;
	  	  default:
	  		  break;
	  }
	  //break;
  }
  // we need to swap the buffer to display our drawing.
  glutSwapBuffers();
}
/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void Renderer::initGL()	        // We call this right after our OpenGL window is created.
{
  glClearColor(0.6f, 0.7f, 1.0f, 0.0f);		// This Will Clear The Background Color To Black
  glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
  glDepthFunc(GL_LESS);				// The Type Of Depth Test To Do
  glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
  glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();				// Reset The Projection Matrix

  gluPerspective(45.0f,(GLfloat)this->width/(GLfloat)this->height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window

  glMatrixMode(GL_MODELVIEW);

  // set up light number 1.
  glLightfv(GL_LIGHT1, GL_AMBIENT,  Renderer::lightAmbient);  // add lighting. (ambient)
  glLightfv(GL_LIGHT1, GL_DIFFUSE,  Renderer::lightDiffuse);  // add lighting. (diffuse).
  glLightfv(GL_LIGHT1, GL_POSITION, Renderer::lightPosition); // set light position.
  glEnable(GL_LIGHT1);                             // turn light 1 on.
}

/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */
void ReSizeGLScene(int Width, int Height)
{
  if (Height==0)				// Prevent A Divide By Zero If The Window Is Too Small
    Height=1;

  glViewport(0, 0, Width, Height);		// Reset The Current Viewport And Perspective Transformation

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
  glMatrixMode(GL_MODELVIEW);
}
/* The function called whenever a ascii key is pressed. */
void processNormalKeysDown(unsigned char key, int x, int y)
{
	/* ASCII code for the escape key. */
	const unsigned char ESCAPE=27;
    /* sleep to avoid thrashing this procedure */
    usleep(100);

    /* If escape is pressed, kill everything. */
    switch(key)
    {
    	case ESCAPE:
    		/* shut down our window */
			glutDestroyWindow(window);
			/* exit the program...normal termination. */
			exit(0);
    	case 'l':
    	case 'L':
    		Renderer::lightOn = !Renderer::lightOn;
    		if(Renderer::lightOn)
    			glDisable(GL_LIGHTING);
    		else
    			glEnable(GL_LIGHTING);
    		break;
    	case 'x':
    	case 'X':
    		Renderer::xAxesSelected = true;
    		break;
    	case 'y':
    	case 'Y':
    		Renderer::yAxesSelected = true;
    		break;
    	case 'z':
    	case 'Z':
    		Renderer::zAxesSelected = true;
    		break;
    	default:
    		Renderer::xAxesSelected = false;
    		Renderer::yAxesSelected = false;
    		Renderer::zAxesSelected = false;
    }
}
void processNormalKeysUp(unsigned char key, int x, int y){
	Renderer::xAxesSelected = false;
	Renderer::yAxesSelected = false;
	Renderer::zAxesSelected = false;
};
/* The function called whenever a non ascii key is pressed. */
void processSpecialKeys(int key, int x, int y)
{
	/* sleep to avoid thrashing this procedure */
	usleep(100);

	int mod = glutGetModifiers(); // Detects Alt, Shift, Ctrl
	float d = 0.0;
	switch (key) {
		case GLUT_KEY_F1:
			Renderer::camUpVectorAngles.setAngles(90,0,270);
			Renderer::camFrontVectorAngles.setAngles(90,270,180);
			Renderer::camUpVector.x = cos(Renderer::camUpVectorAngles.xRadian());
			Renderer::camUpVector.y = cos(Renderer::camUpVectorAngles.yRadian());
			Renderer::camUpVector.z = cos(Renderer::camUpVectorAngles.zRadian());
			Renderer::camFrontVector.x = cos(Renderer::camFrontVectorAngles.xRadian());
			Renderer::camFrontVector.y = cos(Renderer::camFrontVectorAngles.yRadian());
			Renderer::camFrontVector.z = cos(Renderer::camFrontVectorAngles.zRadian());
			Renderer::camPosition.setPoint(0,0,10);
			break;
		case GLUT_KEY_F2:
			cout<<"Please enter the degree to rotate camera around ";
			if(Renderer::zAxesSelected)
				cout<<"Z : ";
			else if(Renderer::xAxesSelected)
				cout<<"X : ";
			else
				cout<<"Y : ";
			cin>>d;
			break;
		case GLUT_KEY_LEFT :
			if(Renderer::zAxesSelected) // effects on XY surface
			{
				Renderer::camUpVectorAngles.x += Renderer::angleFraction;
				Renderer::camUpVectorAngles.y += Renderer::angleFraction;
				Renderer::camUpVector.x = cos(Renderer::camUpVectorAngles.xRadian());
				Renderer::camUpVector.y = cos(Renderer::camUpVectorAngles.yRadian());
			}
			else if(Renderer::yAxesSelected || mod==GLUT_ACTIVE_SHIFT) // effects on XZ surface
			{
				Renderer::camFrontVectorAngles.x += Renderer::angleFraction;
				Renderer::camFrontVectorAngles.z += Renderer::angleFraction;
				Renderer::camFrontVector.x = cos(Renderer::camFrontVectorAngles.xRadian());
				Renderer::camFrontVector.z = cos(Renderer::camFrontVectorAngles.zRadian());
			}
			else //if(Renderer::xAxesSelected)
			{
				//Wrong calculation!
				//Renderer::camPosition.x -= sign(Renderer::camFrontVector.y*Renderer::camUpVector.z - Renderer::camFrontVector.z*Renderer::camUpVector.y)*Renderer::translateFraction;
				Point vector(Renderer::camFrontVector.y*Renderer::camUpVector.z - Renderer::camFrontVector.z*Renderer::camUpVector.y,
											 Renderer::camFrontVector.z*Renderer::camUpVector.x - Renderer::camFrontVector.x*Renderer::camUpVector.z,
											 Renderer::camFrontVector.x*Renderer::camUpVector.y - Renderer::camFrontVector.y*Renderer::camUpVector.x);
				Renderer::camPosition.x -= Renderer::translateFraction*vector.x;
				Renderer::camPosition.y -= Renderer::translateFraction*vector.y;
				Renderer::camPosition.z -= Renderer::translateFraction*vector.z;
			}
			break;
		case GLUT_KEY_RIGHT :
			if(Renderer::zAxesSelected) // effects on XY surface
			{
				Renderer::camUpVectorAngles.x -= Renderer::angleFraction;
				Renderer::camUpVectorAngles.y -= Renderer::angleFraction;
				Renderer::camUpVector.x = cos(Renderer::camUpVectorAngles.xRadian());
				Renderer::camUpVector.y = cos(Renderer::camUpVectorAngles.yRadian());
			}
			else if(Renderer::yAxesSelected || mod==GLUT_ACTIVE_SHIFT) // effects on XZ surface
			{
				Renderer::camFrontVectorAngles.x -= Renderer::angleFraction;
				Renderer::camFrontVectorAngles.z -= Renderer::angleFraction;
				Renderer::camFrontVector.x = cos(Renderer::camFrontVectorAngles.xRadian());
				Renderer::camFrontVector.z = cos(Renderer::camFrontVectorAngles.zRadian());
			}
			else //if(Renderer::xAxesSelected)
			{
				//Wrong calculation!
				//Renderer::camPosition.x += sign(Renderer::camFrontVector.y*Renderer::camUpVector.z - Renderer::camFrontVector.z*Renderer::camUpVector.y)*Renderer::translateFraction;
				Point vector(Renderer::camFrontVector.y*Renderer::camUpVector.z - Renderer::camFrontVector.z*Renderer::camUpVector.y,
							 Renderer::camFrontVector.z*Renderer::camUpVector.x - Renderer::camFrontVector.x*Renderer::camUpVector.z,
							 Renderer::camFrontVector.x*Renderer::camUpVector.y - Renderer::camFrontVector.y*Renderer::camUpVector.x);
				Renderer::camPosition.x += Renderer::translateFraction*vector.x;
				Renderer::camPosition.y += Renderer::translateFraction*vector.y;
				Renderer::camPosition.z += Renderer::translateFraction*vector.z;
			}
			break;
		case GLUT_KEY_UP :
			if(Renderer::xAxesSelected)
			{
				Renderer::camFrontVectorAngles.y -= Renderer::angleFraction;
				Renderer::camFrontVectorAngles.z -= Renderer::angleFraction;
				Renderer::camUpVectorAngles.y -= Renderer::angleFraction;
				Renderer::camUpVectorAngles.z -= Renderer::angleFraction;
				Renderer::camFrontVector.y = cos(Renderer::camFrontVectorAngles.yRadian());
				Renderer::camFrontVector.z = cos(Renderer::camFrontVectorAngles.zRadian());
				Renderer::camUpVector.y = cos(Renderer::camUpVectorAngles.yRadian());
				Renderer::camUpVector.z = cos(Renderer::camUpVectorAngles.zRadian());
			}
			else if(Renderer::zAxesSelected || mod==GLUT_ACTIVE_SHIFT)
			{
				//Wrong calculation!
				//Renderer::camPosition.z += sign(cos(Renderer::camFrontVectorAngles.zRadian()))*Renderer::translateFraction;
				Renderer::camPosition.x += Renderer::translateFraction*Renderer::camFrontVector.x;
				Renderer::camPosition.y += Renderer::translateFraction*Renderer::camFrontVector.y;
				Renderer::camPosition.z += Renderer::translateFraction*Renderer::camFrontVector.z;
			}
			else //if(Renderer::yAxesSelected)
			{
				//Wrong calculation!
				//Renderer::camPosition.y += sign(cos(Renderer::camUpVectorAngles.yRadian()))*Renderer::translateFraction;
				Renderer::camPosition.x += Renderer::translateFraction*Renderer::camUpVector.x;
				Renderer::camPosition.y += Renderer::translateFraction*Renderer::camUpVector.y;
				Renderer::camPosition.z += Renderer::translateFraction*Renderer::camUpVector.z;
			}
			break;
		case GLUT_KEY_DOWN :
			if(Renderer::xAxesSelected)
			{
				Renderer::camFrontVectorAngles.y += Renderer::angleFraction;
				Renderer::camFrontVectorAngles.z += Renderer::angleFraction;
				Renderer::camUpVectorAngles.y += Renderer::angleFraction;
				Renderer::camUpVectorAngles.z += Renderer::angleFraction;
				Renderer::camFrontVector.y = cos(Renderer::camFrontVectorAngles.yRadian());
				Renderer::camFrontVector.z = cos(Renderer::camFrontVectorAngles.zRadian());
				Renderer::camUpVector.y = cos(Renderer::camUpVectorAngles.yRadian());
				Renderer::camUpVector.z = cos(Renderer::camUpVectorAngles.zRadian());
			}
			else if(Renderer::zAxesSelected || mod==GLUT_ACTIVE_SHIFT)
			{
				//Renderer::camPosition.z -= sign(cos(Renderer::camFrontVectorAngles.zRadian()))* Renderer::translateFraction;
				Renderer::camPosition.x -= Renderer::translateFraction*Renderer::camFrontVector.x;
				Renderer::camPosition.y -= Renderer::translateFraction*Renderer::camFrontVector.y;
				Renderer::camPosition.z -= Renderer::translateFraction*Renderer::camFrontVector.z;
			}
			else //if(Renderer::yAxesSelected)
			{
				//Renderer::camPosition.y -= sign(cos(Renderer::camUpVectorAngles.yRadian()))* Renderer::translateFraction;
				Renderer::camPosition.x -= Renderer::translateFraction*Renderer::camUpVector.x;
				Renderer::camPosition.y -= Renderer::translateFraction*Renderer::camUpVector.y;
				Renderer::camPosition.z -= Renderer::translateFraction*Renderer::camUpVector.z;
			}

			break;
	}
}
void Renderer::setCamera(){
	glLoadIdentity(); // make sure we're no longer rotated and not transfered.
	// Set the camera
	gluLookAt(	Renderer::camPosition.x, Renderer::camPosition.y, Renderer::camPosition.z,
				Renderer::camPosition.x+Renderer::camFrontVector.x, Renderer::camPosition.y+Renderer::camFrontVector.y,  Renderer::camPosition.z+Renderer::camFrontVector.z,
				Renderer::camUpVector.x, Renderer::camUpVector.y, Renderer::camUpVector.z);
	Renderer::lightPosition[0] = Renderer::camPosition.x;
	Renderer::lightPosition[1] = Renderer::camPosition.y-Renderer::camFrontVector.y>0;
	Renderer::lightPosition[2] = Renderer::camPosition.z+(Renderer::camFrontVector.z>0? Renderer::camFrontVector.z+2.0f : Renderer::camFrontVector.z-2.0f);
	Renderer::lightPosition[3] = 1.0f;
	//
	// set up light number 1.
	glLightfv(GL_LIGHT2, GL_AMBIENT,  Renderer::lightAmbient);  // add lighting. (ambient)
	glLightfv(GL_LIGHT2, GL_DIFFUSE,  Renderer::lightDiffuse);  // add lighting. (diffuse).
	glLightfv(GL_LIGHT2, GL_POSITION, Renderer::lightPosition); // set light position.
	glEnable(GL_LIGHT2);                             // turn light 1 on.
};
void Renderer::render()
{
	// Initialize GL, TCircleUT state - glut will take any command line arguments that pertain to it or
	// X Windows - look at its documentation at http://reality.sgi.com/mjk/spec3/spec3.html
	char *argv[1];
	int argc=1;
	argv [0]=strdup(this->appName.c_str());
	glutInit(&argc, argv);

	// Select type of Display mode:
	// Double buffer
	// RGBA color
	// Alpha components supported
	// Depth buffer
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);

	// get a 640 x 480 window
	glutInitWindowSize(this->width, this->height);

	// the window starts at the upper left corner of the screen
	glutInitWindowPosition(0, 0);

	// Open a window
	window = glutCreateWindow(this->appName.c_str());

	// Register the function to do all our OpenGL drawing.
	glutDisplayFunc(&DrawGLScene);

	// Go fullscreen.  This is as soon as possible.
	if(this->fullScreenMode)
		glutFullScreen();

	// Even if there are no events, redraw our gl scene.
	glutIdleFunc(&DrawGLScene);

	// Register the function called when our window is resized.
	glutReshapeFunc(&ReSizeGLScene);

	// Register the function called when the keyboard is pressed.
	glutKeyboardFunc(&processNormalKeysDown);
	glutSpecialFunc(&processSpecialKeys);
	glutKeyboardUpFunc(&processNormalKeysUp);
	// Initialize our window.
	this->initGL();

	// Start Event Processing Engine
	glutMainLoop();
};
void Renderer::drawTriangle(Shape shape){
	  glTranslatef(shape.translate.x, shape.translate.y, shape.translate.z);
	  glRotatef(shape.xRotate,1.0f,0.0f,0.0f);
	  glRotatef(shape.yRotate,0.0f,1.0f,0.0f);
	  glRotatef(shape.zRotate,0.0f,0.0f,1.0f);
	  Triangle* triangle = shape.triangle;
	  glBegin(GL_TRIANGLES);				// start drawing a polygon
	  if(triangle->colors[0].isValid())
		  glColor4f(triangle->colors[0].getR(), triangle->colors[0].getG(), triangle->colors[0].getB(), triangle->colors[0].getA());
      glVertex3f( triangle->points[0].x, triangle->points[0].y, triangle->points[0].z);
      if(triangle->colors[1].isValid())
    	  glColor4f(triangle->colors[1].getR(), triangle->colors[1].getG(), triangle->colors[1].getB(), triangle->colors[1].getA());
	  glVertex3f( triangle->points[1].x, triangle->points[1].y, triangle->points[1].z);
	  if(triangle->colors[2].isValid())
	  	  glColor4f(triangle->colors[2].getR(), triangle->colors[2].getG(), triangle->colors[2].getB(), triangle->colors[2].getA());
	  glVertex3f( triangle->points[2].x, triangle->points[2].y, triangle->points[2].z);
	  glEnd();					// we're done with the polygon (smooth color interpolation)
	  if(shape.translate.x !=0 || shape.translate.y !=0 || shape.translate.z !=0 ||
			  shape.xRotate !=0 || shape.yRotate !=0 || shape.zRotate !=0
		  )
		  	  Renderer::setCamera(); // make sure we're no longer rotated and not transfered.
};
void Renderer::drawQuad(Shape shape){
	glTranslatef(shape.translate.x, shape.translate.y, shape.translate.z);
	glRotatef(shape.xRotate,1.0f,0.0f,0.0f);
	glRotatef(shape.yRotate,0.0f,1.0f,0.0f);
	glRotatef(shape.zRotate,0.0f,0.0f,1.0f);
	Quad* quad = shape.quad;
	glBegin(GL_QUADS);				// start drawing a polygon
	if(quad->colors[0].isValid())
		glColor4f(quad->colors[0].getR(), quad->colors[0].getG(), quad->colors[0].getB(), quad->colors[0].getA());
	glVertex3f( quad->points[0].x, quad->points[0].y, quad->points[0].z);
	if(quad->colors[1].isValid())
		glColor4f(quad->colors[1].getR(), quad->colors[1].getG(), quad->colors[1].getB(), quad->colors[1].getA());
	glVertex3f( quad->points[1].x, quad->points[1].y, quad->points[1].z);
	if(quad->colors[2].isValid())
		glColor4f(quad->colors[2].getR(), quad->colors[2].getG(), quad->colors[2].getB(), quad->colors[2].getA());
	glVertex3f( quad->points[2].x, quad->points[2].y, quad->points[2].z);
	if(quad->colors[3].isValid())
		glColor4f(quad->colors[3].getR(), quad->colors[3].getG(), quad->colors[3].getB(), quad->colors[3].getA());
	glVertex3f( quad->points[3].x, quad->points[3].y, quad->points[3].z);
	glEnd();					// we're done with the polygon (smooth color interpolation)
	if(shape.translate.x !=0 || shape.translate.y !=0 || shape.translate.z !=0 ||
			shape.xRotate !=0 || shape.yRotate !=0 || shape.zRotate !=0
	  )
		Renderer::setCamera(); // make sure we're no longer rotated and not transfered.
};
void Renderer::drawPrimed(Shape shape){
	glTranslatef(shape.translate.x, shape.translate.y, shape.translate.z);
	glRotatef(shape.xRotate,1.0f,0.0f,0.0f);
	glRotatef(shape.yRotate,0.0f,1.0f,0.0f);
	glRotatef(shape.zRotate,0.0f,0.0f,1.0f);
	Primed* primed = shape.primed;
	for(int i=0; i<4; i++)
	{
		Triangle side = primed->sides[i];
		Color color = primed->color;
		if(!side.colors[0].isValid() && color.isValid())
		{
			side.colors[0] = color;
			side.colors[1] = color;
			side.colors[2] = color;
			side.colors[3] = color;
		}
		Shape* temporal = new Shape(TTriangle);
		temporal->setTriangle(&side);
		Renderer::drawTriangle(*temporal);
		delete temporal;
	}
	if(primed->square.isValid())
	{
		Quad quad = primed->square;
		Color color = primed->color;
		if(!quad.colors[0].isValid() && color.isValid())
		{
			quad.colors[0] = color;
			quad.colors[1] = color;
			quad.colors[2] = color;
			quad.colors[3] = color;
		}
		Shape* temporal = new Shape(TQuad);
		temporal->setQuad(&quad);
		Renderer::drawQuad(*temporal);
		delete temporal;
	}
	if(shape.translate.x !=0 || shape.translate.y !=0 || shape.translate.z !=0 ||
			shape.xRotate !=0 || shape.yRotate !=0 || shape.zRotate !=0
	  )
		Renderer::setCamera(); // make sure we're no longer rotated and not transfered.
};
void Renderer::drawCube(Shape shape){
	glTranslatef(shape.translate.x, shape.translate.y, shape.translate.z);
	glRotatef(shape.xRotate,1.0f,0.0f,0.0f);
	glRotatef(shape.yRotate,0.0f,1.0f,0.0f);
	glRotatef(shape.zRotate,0.0f,0.0f,1.0f);
	Cube* cube = shape.cube;
	for(int i=0; i<6; i++)
	{
		Quad side = cube->sides[i];
		Color color = cube->color;
		if(!side.colors[0].isValid() && color.isValid())
		{
			side.colors[0] = color;
			side.colors[1] = color;
			side.colors[2] = color;
			side.colors[3] = color;
		}
		Shape* temporal = new Shape(TQuad);
		temporal->setQuad(&side);
		Renderer::drawQuad(*temporal);
		delete temporal;
	}
	if(shape.translate.x !=0 || shape.translate.y !=0 || shape.translate.z !=0 ||
			shape.xRotate !=0 || shape.yRotate !=0 || shape.zRotate !=0
	  )
		Renderer::setCamera(); // make sure we're no longer rotated and not transfered.
};
void Renderer::drawCircle(Shape shape){
	glTranslatef(shape.translate.x, shape.translate.y, shape.translate.z);
	glRotatef(shape.xRotate,1.0f,0.0f,0.0f);
	glRotatef(shape.yRotate,0.0f,1.0f,0.0f);
	glRotatef(shape.zRotate,0.0f,0.0f,1.0f);
	//
	Circle* circle = shape.circle;
	//
	float radius = circle->radius;
	float cx = circle->center.x;
	float cy = circle->center.y;
	float cz = circle->center.z;
	//
	if(circle->color.isValid())
		glColor4f(circle->color.getR(), circle->color.getG(), circle->color.getB(), circle->color.getA());
	//
	if(circle->filled)
		glBegin(GL_POLYGON);				// start drawing a polygon
	else
		glBegin(GL_LINE_LOOP);				// start drawing connected lines
	//
	for(double i = 0; i < 2 * M_PI; i += M_PI/(radius*4*360) )
	 		glVertex3f(cos(i)*radius + cx, sin(i)*radius + cy, cz);
	glEnd();
	//
	if(shape.translate.x !=0 || shape.translate.y !=0 || shape.translate.z !=0 ||
		  shape.xRotate !=0 || shape.yRotate !=0 || shape.zRotate !=0
	  )
		  Renderer::setCamera(); // make sure we're no longer rotated and not transfered.
};
void Renderer::drawSphere(Shape shape){
	glTranslatef(shape.translate.x, shape.translate.y, shape.translate.z);
	glRotatef(shape.xRotate,1.0f,0.0f,0.0f);
	glRotatef(shape.yRotate,0.0f,1.0f,0.0f);
	glRotatef(shape.zRotate,0.0f,0.0f,1.0f);
	//
	Sphere* sphere = shape.sphere;
	//
	float radius = sphere->radius;
	float sx = sphere->center.x;
	float sy = sphere->center.y;
	float sz = sphere->center.z;
	glTranslatef(sx+radius, sy+radius, sz+radius);
	//
	if(sphere->color.isValid())
		glColor4f(sphere->color.getR(), sphere->color.getG(), sphere->color.getB(), sphere->color.getA());
	//
	GLUquadricObj* quadric = gluNewQuadric();
	gluSphere(quadric, radius, sphere->slices, sphere->stacks);
	gluDeleteQuadric(quadric);
	//
	if(shape.translate.x !=0 || shape.translate.y !=0 || shape.translate.z !=0 ||
		  shape.xRotate !=0 || shape.yRotate !=0 || shape.zRotate !=0 || sx != 0 || sy != 0 || sz != 0
	  )
		  Renderer::setCamera(); // make sure we're no longer rotated and not transfered.
};
void Renderer::drawCylinder(Shape shape){
	glTranslatef(shape.translate.x, shape.translate.y, shape.translate.z);
	glRotatef(shape.xRotate,1.0f,0.0f,0.0f);
	glRotatef(shape.yRotate,0.0f,1.0f,0.0f);
	glRotatef(shape.zRotate,0.0f,0.0f,1.0f);
	//
	Cylinder* cylinder = shape.cylinder;
	//
	Circle head= cylinder->head; // A filled circle to block top of the cylinder (optional)
	if(head.isValid())
	{
		Shape* temporal = new Shape(TCircle);
		temporal->setCircle(&head);
		Renderer::drawCircle(*temporal);
		delete temporal;
	}
	Circle bottom= cylinder->bottom; // A filled circle to block bottom (base) of the cylinder (optional)
	if(head.isValid())
	{
		Shape* temporal = new Shape(TCircle);
		temporal->setCircle(&bottom);
		Renderer::drawCircle(*temporal);
		delete temporal;
	}
	//
	Color color= cylinder->color;
	//
	if(cylinder->color.isValid())
		glColor4f(cylinder->color.getR(), cylinder->color.getG(), cylinder->color.getB(), cylinder->color.getA());
	//
	GLUquadricObj* quadric = gluNewQuadric();
	gluCylinder(quadric, cylinder->baseRadius, cylinder->topRadius, cylinder->height, cylinder->slices, cylinder->stacks);
	gluDeleteQuadric(quadric);
	//
	if(shape.translate.x !=0 || shape.translate.y !=0 || shape.translate.z !=0 ||
		  shape.xRotate !=0 || shape.yRotate !=0 || shape.zRotate !=0
	  )
		  Renderer::setCamera(); // make sure we're no longer rotated and not transfered.
};
void Renderer::drawCone(Shape shape){
	glTranslatef(shape.translate.x, shape.translate.y, shape.translate.z);
	glRotatef(shape.xRotate,1.0f,0.0f,0.0f);
	glRotatef(shape.yRotate,0.0f,1.0f,0.0f);
	glRotatef(shape.zRotate,0.0f,0.0f,1.0f);
	Cone* cone = shape.cone;
	// We make a cylinder with top radius 0
	Cylinder* cylinder = new Cylinder(cone->baseRadius, 0.0f, cone->height, cone->slices, cone->stacks, cone->bottom, cone->color, cone->texture);
	Shape* temporal = new Shape(TCylinder);
	temporal->setCylinder(cylinder);
	Renderer::drawCylinder(*temporal);
	delete cylinder;
	delete temporal;
	if(shape.translate.x !=0 || shape.translate.y !=0 || shape.translate.z !=0 ||
			shape.xRotate !=0 || shape.yRotate !=0 || shape.zRotate !=0
	  )
		Renderer::setCamera(); // make sure we're no longer rotated and not transfered.
};

