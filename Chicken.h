#ifndef _CHICKEN_H
#define _CHICKEN_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <math.h>

class Chicken
{
public:
	GLfloat LAngle, RAngle;
	int lastSub, lastAdd;
	float x, y, z;
	Chicken();
	void drawChicken(GLuint texture[]);
	void rWing();
	void lWing();
};

#endif