#include "Geometry.h"
#include "UTILITY.h"
#include <iostream>

glm::fvec3 Geometry::getClosestPointToLine(Ray _ray, glm::fvec3 _qryPoint)
{
	/*
	x = closest point
	P = query point
	X = a + ((P-a).n)n
	*/

	glm::fvec3 n = _ray.direction;
	glm::fvec3 a = _ray.origin;
	glm::fvec3 X = a + ((glm::dot((_qryPoint - a), n))*n);
	return X;
}

Geometry::sphereIntersection Geometry::raySphereIntersection(Ray _ray, Sphere _sphere)
{
	sphereIntersection intersection;
	glm::fvec3 intersectionPoint;
	intersection.hit = false;
	 
	if (glm::distance(_sphere.origin, _ray.origin) < _sphere.radius) //check if ray origin is inside sphere
	{
		std::cout << "ERROR: Ray origin inside sphere\n";
		return intersection;
	}

	glm::fvec3 closesPointFromSphere = getClosestPointToLine(_ray, _sphere.origin);  //get closes point on the ray to the centre of sphere
	
	if (glm::dot(closesPointFromSphere, _ray.origin) <= 0) //check if the sphere is behind the camera
	{
		std::cout << "ERROR: Sphere behind the camera\n";
		return intersection;
	}

	/* d = ||P-a-((P-a).n)n||
	 d = distance
	 ((P-a).n)n = closestPointToLine
	 P = query point
	 a = ray origin
	 */

	float distanceFromRadius = glm::length(_sphere.origin - _ray.origin-(glm::dot((_sphere.origin - _ray.origin), _ray.direction)*_ray.direction));
	intersection.m_distance = distanceFromRadius;
	if (distanceFromRadius > _sphere.radius) //check if ray does not hit sphere
	{
		return intersection;
	}
	else
	{
		/*
		closest intersection
		a+(((P-a).n)-x)n

		a= ray origin
		P= sphere origin
		n = _ray.direction;
		x = sqrt(sphere radius^2 - distance from Radius^2)

		*/
		intersectionPoint = _ray.origin + ((glm::dot((_sphere.origin - _ray.origin), _ray.direction)) - sqrt(pow(_sphere.radius, 2.0f) - pow(distanceFromRadius,2.0f)))*_ray.direction;
		intersection.hit = true;

	}
	intersection.m_intersectionPoint = intersectionPoint;
	return intersection;
}
Geometry::Geometry()
{
}


Geometry::~Geometry()
{
}
