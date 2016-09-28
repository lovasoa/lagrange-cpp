/**
This program reads coordinates of points in the format
x1 y1
x2 y2
on its standard input, and prints newline-separated coefficients of a polynomial on its standard
output. The polynomial is such that for all i P(x_i) = y_i.

This program works in O(N^3) where N is the number of input points.

(C) 2016 Ophir LOJKINE
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    double x;
    double y;
} point_t;


/**
* Generate the polynomials coefficients of the lagrange interpolation polynomial
* for the given points
*/
vector<double>* lagrange_coeffs(const vector<point_t> points) {
    auto len = points.size();
    auto res = new vector<double> (len, 0);
    
    for (auto curpoint : points) {
        vector<double> tmpcoeffs (len, 0);
        // Start with a constant polynomial
        tmpcoeffs[0] = curpoint.y;
        double prod = 1;
        for(auto point : points) {
            if (curpoint.x == point.x) continue;
            prod *= curpoint.x - point.x;
            double precedent = 0;
            for (auto resptr = tmpcoeffs.begin(); resptr < tmpcoeffs.end(); resptr++) {
                // Compute the new coefficient of X^i based on
                // the old coefficients of X^(i-1) and X^i
                double newres = (*resptr) * (-point.x) + precedent;
                precedent = *resptr;
                *resptr = newres;
            }
        }
        transform(res->begin(), res->end(),
                  tmpcoeffs.begin(),
                  res->begin(),
                  [=] (double oldcoeff, double add) {return oldcoeff+add/prod;}
                  );
    }
    return res;
}


int main()
{
    vector<point_t> points;
 
    point_t p;
    while((cin >> p.x) && (cin >> p.y)) {
        points.push_back(p);
    }

    for (auto coeff : *lagrange_coeffs(points)) {
        cout << coeff << endl;
    }
    return 0;
}
