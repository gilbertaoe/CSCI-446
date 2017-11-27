#ifndef _COW_H
#define _COW_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <math.h>

class Cow
{
public:
	int x,y,z;
	Cow();
	void head();
	void backLeftLegTop();
	void backRightLegTop();
	void backLeftLegBot();
	void backRightLegBot();
	void frontLeftLegBot();
	void frontRightLegBot();
	void frontLeftLegTop();
	void frontRightLegTop();
	void body();
	void drawCow();
	GLuint texture;
};

#endif