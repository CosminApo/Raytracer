#include "Sphere.h"
#include "MCG_GFX_Lib.h"
#include "UTILITY.h"


glm::fvec3 Sphere::getColour(Ray _ray, glm::fvec3 _intersectionPoint)
{
	/*
	L=(w_i . N)*L_i * K_d
	w = vector pointing towards light
	N = surface normal from the intersection
	K = material diffuse colour
	L_i = light colour
	w_i = constant value for simplicity
	N = (intersection - sphere origin )/r;

	*/
	glm::fvec3 colour = { 0,0,0 };
	glm::fvec3 lightSource = { -40,-30, 40 };//w_i
	lightSource = glm::normalize(lightSource-_intersectionPoint );
	glm::fvec3 normalVector;
	normalVector = glm::normalize((_intersectionPoint - this->origin) / this->radius); // N


	glm::fvec3 lightColour = { 1,1,1 }; //L_i white light


	glm::fvec3 materialColour = { 255,0,0 }; //K_d

	float dotProduct = glm::dot(lightSource, normalVector);

	if (dotProduct > 0)
		colour = (dotProduct)*lightColour*materialColour;

	return colour;

}

Sphere::Sphere()
{
}


Sphere::~Sphere()
{
}
