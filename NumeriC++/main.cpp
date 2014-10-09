//
//  main.cpp
//  NumeriC++
//
//  Created by Thierry BM on 2014-10-08.
//  Copyright (c) 2014 Thierry BM. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>

using namespace std;

const double epsilon = 1e-8;
const double ro = 0.9;
const double c = 1e-4;

vector<double> operator-(const vector<double>& v) {
    vector<double> result (v.size());
    transform(v.begin(), v.end(), result.begin(),
              [](double d) {
                  return -d;
              });
    return result;
}

vector<double> operator-(const vector<double>& v1, const vector<double>& v2) {
    vector<double> result (v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), result.begin(),
              [](double a, double b) {
                  return a-b;
              });
    return result;
}

vector<double> operator+(const vector<double>& v1, const vector<double>& v2) {
    vector<double> result (v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), result.begin(),
              [](double a, double b) {
                  return a+b;
              });
    return result;
}

vector<double> operator*(double s, const vector<double>& v) {
    vector<double> result (v.size());
    transform(v.begin(), v.end(), result.begin(),
              [&](double a) {
                  return s*a;
              });
    return result;
}

double operator*(const vector<double>& v1, const vector<double>& v2) {
    return inner_product(begin(v1), end(v1), begin(v2), 0.0);
}


vector<double> grad(double (*f)(const vector<double>&), const vector<double>& x) {
    double x1 = x[0];
    double x2 = x[1];
    
    double ddx = (f({x1 + epsilon, x2}) - f(x))/epsilon;
    double ddy = (f({x1, x2 + epsilon}) - f(x))/epsilon;
    
    return { ddx, ddy };
}

// Make it lambda.
double f(const vector<double>& x) {
    double x1 = x[0];
    double x2 = x[1];
    
    return 100*pow((x2 - pow(x1,2.0)),2) + pow((1 - x1),2);
}

int main(int argc, const char * argv[]) {
    vector<double> x = { -1.2, 1.0 };
    auto p = [](vector<double> x) { return -grad(&f, x); };
    
    double alpha = 1;
    do {
        alpha = 1.0;
        while (f(x + alpha*p(x)) > f(x) + c*alpha*grad(&f,x)*p(x)) {
            alpha *= ro;
        }
        
        x = x - alpha*grad(&f,x);
    } while(fabs(f(x + alpha*p(x)) - f(x)) > 1.0e-12);
    
    cout << "The value of x1 is " << x[0] << endl;
    cout << "The value of x2 is " << x[1] << endl;
    cout << "The value of f(x) is " << f(x) << endl;
    return 0;
}
