#ifndef _ENVIRONMENT_H
#define _ENVIRONMENT_H

#include "./raygl.h"
#include "./raygldefs.h"

class Environment
{
public:
	Environment();
	void drawEnvironment(GLuint texture[]);
};

#endif