#include "Randomiser.h"

Randomiser::Randomiser()
{
	//!< Seeds Rand with current time. To make it random on every load.
	srand(time(NULL));
}
int Randomiser::getRandBetween(int lower /* Lower bound */, int upper /* Upper bound */) //!< Returns a random number between the lower and upper bounds
{
	double delta = upper - lower;
	double randomScalar = (double)rand() / (double)RAND_MAX;
	double randomDelta = delta * randomScalar;
	return lower + (int)randomDelta;
}
float Randomiser::getRandBetween(float lower /* Lower bound */, float upper /* Upper bound */)//!< Returns a random number between the lower and upper bounds
{
	double delta = upper - lower;
	double randomScalar = (double)rand() / (double)RAND_MAX;
	double randomDelta = delta * randomScalar;
	return lower + (float)randomDelta;
}