#include "Camera.h"

Camera::Camera(void)
{
	xpos = 0;	ypos = 0;	zpos = 0;	xrot = 0;	yrot = 0;	angle=0.0; cRadius = 10.0f;
}

void Camera::position()
{
    glRotatef(xrot,1.0,0.0,0.0);  //rotate our camera on teh x-axis (left and right)
    glRotatef(yrot,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
    glTranslated(-xpos,-ypos,-zpos); //translate the screen to the position of our camera
}