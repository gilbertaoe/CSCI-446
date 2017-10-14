#ifndef _CAMERA_H_
#define _CAMERA_H_

class Camera
{
public:
	Camera();
	void position();

	//angle of rotation
	float xpos, ypos, zpos, xrot, yrot, zrot, angle;
	float lastx, lasty;
	float cRadius; // our radius distance from our character
};

#endif