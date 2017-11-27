#ifndef _COW_H
#define _COW_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <math.h>

class Cow
{
public:
	float x,y,z;
	Cow();
	void head(GLuint texture[]);
	void backLeftLegTop(GLuint texture[]);
	void backRightLegTop(GLuint texture[]);
	void backLeftLegBot(GLuint texture[]);
	void backRightLegBot(GLuint texture[]);
	void frontLeftLegBot(GLuint texture[]);
	void frontRightLegBot(GLuint texture[]);
	void frontLeftLegTop(GLuint texture[]);
	void frontRightLegTop(GLuint texture[]);
	void body(GLuint texture[]);
	void drawCow(GLuint texture[]);
};

#endif