#include "include.h"


double myPow(double x, int n)
{
	//思考一下递归基
	if (n == 0)return 1;
	if (n == 1)return x;
	if (n == 2)return x*x;
	double tmp = myPow(x, n / 2);
	if (n % 2 == 0)return myPow(tmp, 2);
	else return n > 0 ? myPow(tmp, 2)*x : 1 / x*myPow(tmp, 2);
}
