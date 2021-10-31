#ifdef MATHFUNCSDLL_EXPORTS
#define MATHFUNCSDLL_API __declspec(dllexport)
#else
#define MATHFUNCSDLL_API __declspec(dllimport)
#endif
#pragma once

namespace MathFuncs
{
	
	class MyMathFuncs
	{
	public:
		
		static MATHFUNCSDLL_API double Square(double a, double b, double c);
		static MATHFUNCSDLL_API double Per(double a, double b, double c);
	};
}