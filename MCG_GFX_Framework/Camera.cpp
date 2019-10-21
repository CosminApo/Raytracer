#include "Camera.h"
#include "UTILITY.h"
#include <iostream>


Ray Camera::getRay(glm::fvec2 _pixelCoord)
{
	Ray myRay;

	glm::fvec4 coordsOne = { UTILITY::map(0,480,-1,1,_pixelCoord.y), UTILITY::map(0,640,1,-1,_pixelCoord.x), -1,1 };
	glm::fvec4 coordsTwo = { UTILITY::map(0,480,-1,1,_pixelCoord.y), UTILITY::map(0,640,1,-1,_pixelCoord.x),  1,1 };
	coordsOne =  glm::inverse(projectionMat)*coordsOne;
	coordsOne = coordsOne / coordsOne.w;
	coordsOne =  glm::inverse(viewingMat)*coordsOne;

	coordsTwo =  glm::inverse(projectionMat)*coordsTwo;
	coordsTwo = coordsTwo / coordsTwo.w;
	coordsTwo =  glm::inverse(viewingMat)*coordsTwo;

	myRay.origin = coordsOne;
	myRay.direction = glm::normalize(coordsTwo- coordsOne); //normalise, get direction from coords one to coords two
	return myRay;
}


Camera::Camera() :viewingMat(1.0f)
{
	projectionMat  = glm::perspective( glm::radians(45.0f), 480.0f/640.0f, 0.1f, 100.0f);
}


Camera::~Camera()
{
}
