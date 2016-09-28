/**
This reads a file containing polynomial coefficient, and evaluates the polynomial
function at the points given on standard input.

(C) 2016 Ophir LOJKINE
**/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

template <class T>
T poly_eval(const vector<T> coeffs, T point) {
    T res = 0;
    T multiplier = 1;
    for(T coeff: coeffs) {
        res += coeff * multiplier;
        multiplier *= point;
    }
    return res;
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " coefficient_file.txt" << endl;
        return 1;
    }

    ifstream coeff_file (argv[1]);
    if (!coeff_file) {
        cerr << "Unable to open " << argv[1] << endl;
        return 1;
    }

    vector<double> coeffs;
    double x;
    while(coeff_file >> x) {
        coeffs.push_back(x);
    }
    coeff_file.close();

    while(cin >> x) {
        cout << poly_eval(coeffs, x) << endl;
    }

    return 0;
}
