//
//  Vector.cpp
//  NumeriC++
//
//  Created by Thierry BM on 2014-10-09.
//  Copyright (c) 2014 Thierry BM. All rights reserved.
//

#include "Vector.h"
#include <vector>
#include <numeric>

using namespace std;

Vector operator-(const Vector& v) {
    Vector result (v.size());
    transform(v.begin(), v.end(), result.begin(),
              [](double d) {
                  return -d;
              });
    return result;
}

Vector operator-(const Vector& v1, const Vector& v2) {
    Vector result (v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), result.begin(),
              [](double a, double b) {
                  return a-b;
              });
    return result;
}

Vector operator+(const Vector& v1, const Vector& v2) {
    Vector result (v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), result.begin(),
              [](double a, double b) {
                  return a+b;
              });
    return result;
}

Vector operator*(double s, const Vector& v) {
    Vector result (v.size());
    std::transform(v.begin(), v.end(), result.begin(),
              [&](double a) {
                  return s*a;
              });
    return result;
}

double operator*(const Vector& v1, const Vector& v2) {
    return inner_product(begin(v1), end(v1), begin(v2), 0.0);
}
