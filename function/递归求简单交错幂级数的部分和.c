/*
本题要求实现一个函数，计算下列简单交错幂级数的部分和：
f(x,n)=x−x^​2​​ +x^​3​​ −x^​4​​ +⋯+(−1)​^(n−1​​)*x^​n​​
*/
double fn(double x, int n)
{
	double result;
	if (n == 0 || n == 1) result = x;
	else result = x - x * fn(x, n - 1);
	return result;
}
