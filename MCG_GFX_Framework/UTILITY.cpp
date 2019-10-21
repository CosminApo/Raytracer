#define _USE_MATH_DEFINES
#include "UTILITY.h"
#include <cmath>




float UTILITY::dotProduct(glm::fvec3 _vector1, glm::fvec3 _vector2)
{
	float dotProduct = (_vector1.x * _vector2.x) + (_vector1.y * _vector2.y) + (_vector1.z * _vector2.z);
	return dotProduct;
}

float UTILITY::map(float min_scale1, float max_scale1, float min_scale2, float max_scale2, float numToConvert)
{

	float numConverted;

	numConverted = min_scale2 + (max_scale2 - min_scale2)*((numToConvert - min_scale1) / (max_scale1 - min_scale1));
	return numConverted;

}

double UTILITY::degreesToRad(double _angleDegree)
{
	double angle_radians = _angleDegree * (M_PI / 180);
	return angle_radians;
}
UTILITY::UTILITY()
{
}


UTILITY::~UTILITY()
{
}
