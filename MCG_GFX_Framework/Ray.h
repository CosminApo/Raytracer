#ifndef _RAY_H
#define _RAY_H

#include "MCG_GFX_Lib.h"

class Ray
{
public:	
	glm::fvec3 origin; 
	glm::fvec3 direction; //unit vector
	Ray();
	~Ray();
};

#endif // !_RAY_H