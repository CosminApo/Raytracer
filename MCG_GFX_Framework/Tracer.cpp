#include "Tracer.h"
#include "Geometry.h"


glm::fvec3 Tracer::getColour(Ray _ray, Geometry::sphereIntersection* myIntersection)
{
	float minDistance = 999999; //arbitrary maximum possible distance
	glm::fvec3 colour = { 0,0,0 };
	std::vector<Sphere>::iterator itr;
	
	bool intersectionFound = false;
	Geometry myGeometry;
	Sphere mySphere;
	for (itr = allSpheres.begin(); itr < allSpheres.end(); itr++) //chose the closest sphere
	{
		*myIntersection = myGeometry.raySphereIntersection(_ray, *itr);
		if ((*myIntersection).hit)
		{
			mySphere = *itr;
			minDistance = (*myIntersection).m_distance;
			intersectionFound = true;
		}
		
	}
	if (intersectionFound) //checks if the sphere exists
	{
		colour = mySphere.getColour(_ray, (myIntersection->m_intersectionPoint));	

	}
	return colour;
}

Tracer::Tracer()
{
}


Tracer::~Tracer()
{
}
