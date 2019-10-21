#ifndef _SPHERE_H
#define _SPHERE_H

#include "MCG_GFX_Lib.h"
#include "Ray.h"

class Sphere
{
public:
	glm::fvec3 getColour(Ray _ray, glm::fvec3 _intersectionPoint);
	glm::fvec3 origin;
	float radius;
	Sphere();
	~Sphere();
};

#endif // !_SPHERE_H