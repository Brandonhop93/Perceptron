#ifndef MACHINELEARNING_RANDOM_H
#define MACHINELEARNING_RANDOM_H
#include <iostream>
#include <random>

class Random
{
public:
    /** Class constructor with initialization list. **/
    explicit Random();

    /** Return next randomly distributed number. */
    float next();

private:
    // Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits.
    std::mt19937 mersenneTwister_32;

    // Normal distribution with a mean of 0 and a standard deviation of 1.
    std::normal_distribution<float> distribution;
};

#endif //MACHINELEARNING_RANDOM_H
