/*
本题要求编写程序，输入10个字符，统计其中英文字母、空格或回车、数字字符和其他字符的个数。
*/
#include <stdio.h>
int main ()
{
	int t;
	int digit=0,letter=0,blank=0,other=0;
	char a;
	int i[11];
	for(t=1;t<=10;t++){
		scanf("%c",&a);
		if(a>='0'&&a<='9') digit++;
		else if((a>='a'&&a<='z')||(a>='A'&&a<='Z')) letter++;
		else if(a==' '||a=='\n') blank++;
		else other++;
	}
	printf("letter = %d, blank = %d, digit = %d, other = %d",letter,blank,digit,other);
}
