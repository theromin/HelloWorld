/*
水仙花数是指一个N位正整数（N≥3），它的每个位上的数字的N次幂之和等于它本身。例如：153=1^3+5^3+3^3。
*/
int narcissistic( int number )
{
	int t=number,i=0,sum=0;
	for(;t>0;i++)	t/=10;
	int a=i,b;
	t=number;
	for(;i>0;i--){
		b=t%10;
		sum+=pow(b,a);
		t=t/10;
	}
	if(sum==number)	return 1;
	else return 0;
} 
