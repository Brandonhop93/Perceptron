#ifndef MACHINELEARNING_PERCEPTRON_H
#define MACHINELEARNING_PERCEPTRON_H
#include <iostream>
#include "random.h"

/**
* Single layer perceptron.
**/
class Perceptron
{
public:
    /** Class constructor. **/
    explicit Perceptron(const int inputs);

    /** Class destructor. **/
    ~Perceptron();

    /** Computes and returns: σ(w · x + b). **/
    int predict(const int* const x) const;

    /** Train weights to match input data with output data. **/
    void train(const int count, const int* const x, const int* const y);

    /** Prints out weights and bias. */
    void print() const;

private:
    // Perceptron weights.
    float* weights;
    // Perceptron bias.
    float bias;
    // Perceptron inputs.
    int inputs;
};

#endif //MACHINELEARNING_PERCEPTRON_H
