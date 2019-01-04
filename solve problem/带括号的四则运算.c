#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void CheckNum(char *c)
{
	char *s = c;
	while (*s != '\0') 
		if ((*s >= '0' && *s <= '9') || *s == '+' || *s == '-' 
			|| *s == '*' || *s == '/' || *s == '.' || *s == '(' || *s == ')') 
			s++;
		else 
		{
			printf("错误:数字 %s 里面有不符合规范的字符。\n", c);
			exit(0);
		}
}

double StrToNum(char *c)
{
	double num = 0;
	int len = strlen(c);
	int start = 0, fla = 1;  //start是字符串的数字开始的位置，fla标记是否是负数
	if (*c == '-') 
	{
		start = 1;
		fla = -1;
	}
	num = c[start] - '0';
	int t = -1;  //小数部分计算过程中10的指数部分的值
	int hasPoint = 0;
	for (int i = start + 1; i < len; i++) 
	{
		if (c[i] == '.') 
		{
			hasPoint = 1;
			continue;
		}
		if (hasPoint) 
		{
			num = num + (c[i] - '0')*pow(10, t);
			t--;
		}
		else num = num * 10 + c[i] - '0';
	}
	return num * fla;
}

int MyRemove1(double *s, int len, int index) 
{
	for (int i = index; i < len - 1; i++) 
		s[i] = s[i + 1];
	return len - 1;
}

int MyRemove(char *s, int len, int index) 
{
	int i;
	for (i = index; i < len - 1; i++)
		s[i] = s[i + 1];
	s[i] = '\0';
	return len - 1;
}

double MyCalculate(char *c)
{
	//puts(c);
	double digit[100];  //四则运算的数字
	char symbol[100];   //四则运算的符号
	int di = 0;  //保存数字数组的序号
	int si = 0;  //保存字符数组的序号
	int ni = 0;  //记录需要转化成数字的字符串的序号
	while (*c != '\0')
	{

		char num[22];
		switch (*c) 
		{
			case '+':case '-':case '*':case '/':
				symbol[si++] = *c;
				if (*(c - 1) != ')') 
				{
					num[ni] = '\0';
					ni = 0;
					digit[di++] = StrToNum(num);
				}
				break;
			case '(':
			{
				int k = 1;
				char str[100];
				int j = 0;
				while (k > 0)
				{
					c++;
					str[j++] = *c;
					if (*c == '(') k++;
					else if (*c == ')') k--;
				}
				str[j - 1] = '\0';
				digit[di++] = MyCalculate(str);//递归 
				break;
			}
			default:
				num[ni++] = *c;
				if (*(c + 1) == '\0')
				{
					num[ni] = '\0';
					ni = 0;
					digit[di++] = StrToNum(num);
				}
				break;
		}
		c++;
	}
	symbol[si] = '\0';
	for (int i = 0; i < si; i++) 
	{
		if (symbol[i] == '*') 
		{
			digit[i + 1] = digit[i] * digit[i + 1];
			di = MyRemove1(digit, di, i);
			si = MyRemove(symbol, si, i);
		}
		else if (symbol[i] == '/')
		{
			digit[i + 1] = digit[i]/digit[i + 1];
			di = MyRemove1(digit, di, i);
			si = MyRemove(symbol, si, i);
		}
	}
	for (int i = 0; i < si; i++) 
	{
		if (symbol[i] == '+') 
		{
			digit[i + 1] = digit[i] + digit[i + 1];
			di = MyRemove1(digit, di, i);
			si = MyRemove(symbol, si, i);
		}
		else if (symbol[i] == '-')
		{
			digit[i + 1] = digit[i] - digit[i + 1];
			di = MyRemove1(digit, di, i);
			si = MyRemove(symbol, si, i);
		}
	}
	return digit[0];
}

int main()
{
	char str[11111], s1[999];

	//2.3*((2+3)*3+1)+11
	while (~scanf("%s", s1)) 
	{
		printf("-----%d\n", strlen(s1));
		strcpy(str, s1);
	}
	CheckNum(str);
	printf("%s = %lf\n", str, MyCalculate(str));
	system("pause");

	return 0;
}
