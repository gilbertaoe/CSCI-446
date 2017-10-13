#ifndef _CAMERA_H_
#define _CAMERA_H_

class Camera
{
public:
	Camera();
	void position();
private:
	//angle of rotation
	float xpos, ypos, zpos, xrot, yrot, angle;
	float lastx, lasty;	
};

#endif