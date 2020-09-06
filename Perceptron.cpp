#include "Perceptron.h"

/** Class constructor. **/
Perceptron::Perceptron(const int inputs)
{
    // Random number generator.
    Random random;

    // Initialise inputs.
    this->inputs = inputs;

    // Initialise weights array.
    weights = new float[inputs];

    // Loop over weights array.
    for (int i = 0; i < inputs; i++)
    {
        weights[i] = random.next();
    }

    // Initialise bias.
    bias = random.next();
}

/** Class destructor. **/
Perceptron::~Perceptron()
{
    // Delete weights array.
    delete[](weights);
}

/** Computes and returns: σ(w · x + b). **/
int Perceptron::predict(const int* const x) const
{
    float summation = bias;

    // Dot product of inputs and weights.
    for (int i = 0; i < inputs; i++)
    {
        summation += (float)x[i] * weights[i];
    }

    // Map summation to 0 or 1.
    return summation > 0;
}

/** Train weights to match input data with output data. **/
void Perceptron::train(const int count, const int* const x, const int* const y)
{
    while (true)
    {
        // Exit flag.
        bool passed = true;

        // Loop over all corresponding inputs (x) and outputs (y).
        for (int i = 0; i < count; i += inputs)
        {
            // p(i)
            int prediction = predict(x + i);

            // ⍺(t - p(i))
            float weightChange = 0.1f * (float)(y[(int)(i / inputs)] - prediction);

            // Perceptron training rule: w + ⍺(t - p(i)) * x
            for (int j = 0; j < inputs; j++)
            {
                weights[j] += weightChange * (float)x[i + j];
            }

            bias += weightChange;

            if (prediction != y[i / inputs])
            {
                passed = false;
            }
        }

        if (passed)
        {
            return;
        }
    }
}

/** Prints out weights and bias. */
void Perceptron::print() const
{
    std::cout << "Weights |";

    // Loop over all weights.
    for (int i = 0; i < inputs; i++)
    {
        std::cout << weights[i] << "|";
    }

    std::cout << std::endl << "Bias |" << bias << "|" << std::endl;
}
