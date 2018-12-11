/*
本题要求实现一个计算整数因子和的简单函数，并利用其实现另一个函数，
输出两正整数m和n（0<m≤n≤10000）之间的所有完数。所谓完数就是该数恰好等于除自身外的因子之和。
例如：6=1+2+3，其中1、2、3为6的因子。
其中函数factorsum须返回int number的因子和；
函数PrintPN要逐行输出给定范围[m, n]内每个完数的因子累加形式的分解式，
每个完数占一行，格式为“完数 = 因子1 + 因子2 + ... + 因子k”，其中完数和因子均按递增顺序给出。
如果给定区间内没有完数，则输出一行“No perfect number”。
*/
int factorsum( int number )
{
	int n=number-1;
	int sum=0;
	if(number==1)
	{
		sum=1;
	}
	for(;n>0;n--)
	{
		if(number%n==0)
		{
			sum+=n;
		}
	}
	return sum;
}

void PrintPN( int m, int n )
{
	int i,cnt=0;
	for(;m<=n;m++)
	{
		if(factorsum(m)==m)
		{
			cnt+=1;
			printf("%d = 1",m);
			for(i=2;i<m;i++)
			{
				if(m%i==0)
				{
					printf(" + %d",i);
				}
			}
			printf("\n");
		}
	}
	if(cnt==0)
	{
		printf("No perfect number");
	}
}
