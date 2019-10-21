#ifndef _TRACER_H
#define _TRACER_H

#include "MCG_GFX_Lib.h"
#include "Ray.h"
#include <vector>
#include "Sphere.h"
#include "Geometry.h"

class Tracer
{
public:
	std::vector<Sphere> allSpheres;
	glm::fvec3 getColour(Ray _ray, Geometry::sphereIntersection* myIntersection);
	Tracer();
	~Tracer();
};

#endif // !_TRACER_H