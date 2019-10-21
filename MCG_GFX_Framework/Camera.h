#ifndef _CAMERA_H
#define _CAMERA_H
#include "Ray.h"
#include "Sphere.h"

class Camera
{
private:
	
public:
	glm::mat4x4 viewingMat;
	glm::mat4x4 projectionMat;

	Ray getRay(glm::fvec2 _pixelCoord);
	Camera();
	~Camera();
};

#endif
