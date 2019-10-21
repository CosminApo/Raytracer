#ifndef _UTILITY_H
#define _UTILITY_H
#include "MCG_GFX_Lib.h"


class UTILITY
{
public:
	static float map(float min_scale1, float max_scale1, float min_scale2, float max_scale2, float numToConvert);
	static float dotProduct(glm::fvec3 _vector1, glm::fvec3 _vector2);
	static double degreesToRad(double _angleDegree);
	UTILITY();
	~UTILITY();
};
#endif
