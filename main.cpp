#include <iostream>
#include "Perceptron.h"
using namespace std;

int main()
{
    Perceptron perceptron(2);

    // Function inputs.
    int* x = new int[8]
            {0, 0,
             0, 1,
             1, 0,
             1, 1};

    // AND - outputs
    int* y = new int[4]
            {0,
             0,
             0,
             1};

//    // OR - outputs
//    int* y = new int[4]
//            {0,
//             1,
//             1,
//             1};

    cout << "Before Training:" << endl;
    cout << perceptron.predict(x) << endl;
    cout << perceptron.predict(x + 2) << endl;
    cout << perceptron.predict(x + 4) << endl;
    cout << perceptron.predict(x + 6) << endl;

    perceptron.train(8, x, y);

    cout << "After Training:" << endl;
    cout << perceptron.predict(x) << endl;
    cout << perceptron.predict(x + 2) << endl;
    cout << perceptron.predict(x + 4) << endl;
    cout << perceptron.predict(x + 6) << endl;

    perceptron.print();

    delete[](x);
    delete[](y);
    return 0;
}