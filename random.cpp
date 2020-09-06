#include "random.h"

/** Class constructor with initialization list. **/
Random::Random() : distribution(0.0, 1.0)
{
    // Uniformly-distributed integer random number generator to produce a random seed.
    // Generated seed value is based off a system API call or a predefined value.
    std::random_device random;

    // Initialise Mersenne Twister seed.
    // Function random() returns an unsigned int.
    mersenneTwister_32.seed(random());
}

/** Return next randomly distributed number. */
float Random::next()
{
    return distribution(mersenneTwister_32);
}


