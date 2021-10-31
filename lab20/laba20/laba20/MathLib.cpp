#include "MathLib.h"
#include <math.h>
#include <stdexcept>
using namespace std;
namespace MathFuncs
{
	double MyMathFuncs::Per(double a, double b, double c)
	{
		if (a > b + c) throw invalid_argument("Triangle does not exist");
		if (b > a + c) throw invalid_argument("Triangle does not exist");
		if (c > b + a) throw invalid_argument("Triangle does not exist");
		if (a <= 0 || b <= 0 || c <= 0) throw invalid_argument("Triangle does not exist");

		return a + b + c;
	}
	double MyMathFuncs::Square(double a, double b, double c)
	{
		if (a > b + c) throw invalid_argument("Triangle does not exist");
		if (b > a + c) throw invalid_argument("Triangle does not exist");
		if (c > b + a) throw invalid_argument("Triangle does not exist");
		if (a <= 0 || b <= 0 || c <= 0) throw invalid_argument("Triangle does not exist");

		double p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
}