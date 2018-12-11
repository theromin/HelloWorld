/*
根据系数情况，输出不同结果：
1)如果方程有两个不相等的实数根，则每行输出一个根，先大后小；
2)如果方程有两个不相等复数根，则每行按照格式“实部+虚部i”输出一个根，先输出虚部为正的，后输出虚部为负的；
3)如果方程只有一个根，则直接输出此根；
4)如果系数都为0，则输出"Zero Equation"；
5)如果a和b为0，c不为0，则输出"Not An Equation"。
*/
#include <stdio.h>
#include <math.h>
int main(void)
{
	double a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	if(a==0&&b==0&&c==0)
	{
		printf("Zero Equation");
	}
	else if(a==0&&b==0)
	{
		printf("Not An Equation");
	}
	else
	{
		if (a==0)
		{
			printf("%.2f",-c/b);
		}
		else
		{
			double i,x1,x2;
			i=pow(b,2)-4*a*c;
			if(i==0)
			{
				x1=-b/(2*a);
				printf("%.2f",x1);
			}
			else if(i>0)
			{
				if(a>0)
				{
					x1=(-b+pow(i,0.5))/(2*a);
					x2=(-b-pow(i,0.5))/(2*a);
				}
				else
				{
					x1=(-b-pow(i,0.5))/(2*a);
					x2=(-b+pow(i,0.5))/(2*a);
				}
				printf("%.2f\n%.2f",x1,x2);
			} 
			else
			{
				double sb,xb;
				
				i=-i;
				sb=-b/(2*a);
				if(sb==0)
				{
					sb=0;
				}
				xb=pow(i,0.5)/(2*a);
				printf("%.2f+%.2fi\n",sb,xb);
				printf("%.2f-%.2fi",sb,xb);
			}
		}
	}
    return 0;
}
