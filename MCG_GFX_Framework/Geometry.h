#ifndef _GEOMETRY_H
#define _GEOMETRY_H
#include "Ray.h"
#include "Sphere.h"
class Geometry
{
public:
	struct sphereIntersection
	{
		glm::fvec3 m_intersectionPoint;
		float m_distance;
		bool hit;
	};

	glm::fvec3 getClosestPointToLine(Ray _ray, glm::fvec3 _qryPoint);
	sphereIntersection raySphereIntersection(Ray _ray, Sphere _sphere);
	Geometry();
	~Geometry();
};

#endif