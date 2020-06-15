#ifndef RANDOMISER_H
#define RANDOMISER_H

#include <time.h>
#include <stdlib.h>

class Randomiser
{
private:

public:
	Randomiser();
	int getRandBetween(int lower /*! Lower bound */, int upper /*! Upper bound */); //!< Returns a random number between the lower and upper bounds
	float getRandBetween(float lower /* Lower bound */, float upper /* Upper bound */);
};
#endif