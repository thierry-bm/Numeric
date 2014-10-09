//
//  Vector.h
//  NumeriC++
//
//  Created by Thierry BM on 2014-10-09.
//  Copyright (c) 2014 Thierry BM. All rights reserved.
//

#ifndef __NumeriC____Vector__
#define __NumeriC____Vector__

#include <stdio.h>
#include <vector>

class Vector : public std::vector<double>
{
    using vector<double>::vector;
};

Vector operator-(const Vector& v);
Vector operator-(const Vector& v1, const Vector& v2);
Vector operator+(const Vector& v1, const Vector& v2);
Vector operator*(double s, const Vector& v);
double operator*(const Vector& v1, const Vector& v2);

#endif /* defined(__NumeriC____Vector__) */
