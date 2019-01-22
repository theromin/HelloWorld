/*
Katie, Kuro and Shiro are best friends. They have known each other since kindergarten.
That's why they often share everything with each other and work together on some very hard problems.
Today is Shiro's birthday.
She really loves pizza so she wants to invite her friends to the pizza restaurant near her house to celebrate her birthday,
including her best friends Katie and Kuro.
She has ordered a very big round pizza, in order to serve her many friends.
Exactly nn of Shiro's friends are here.
That's why she has to divide the pizza into n+1n+1 slices (Shiro also needs to eat).
She wants the slices to be exactly the same size and shape.
If not, some of her friends will get mad and go home early, and the party will be over.
Shiro is now hungry. She wants to cut the pizza with minimum of straight cuts. 
A cut is a straight segment, it might have ends inside or outside the pizza. 
But she is too lazy to pick up the calculator.
As usual, she will ask Katie and Kuro for help. But they haven't come yet.
Could you help Shiro with this problem?


*/

#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	char num[20];
	int i = 0, n, rec = 0,start=0;
	do
	{
		scanf("%c", &num[i++]);
	} while (num[i - 1] != '\n');
	n = i - 2;
	i = i - 2;
	do
	{
		if (num[i] == '9')
			num[i] = '0';
		else
		{
			num[i]++;
			break;
		}
		if (i == 0)
		{
			rec = 1;
			break;
		}
		i--;
	} while (1);
	if ((num[n] - '0') % 2)
	{
		if (rec)printf("1");
		if (n == 0 && num[0] == '1')
			printf("0");
		else
			for (i = 0; num[i] != '\n'; i++)
				printf("%c", num[i]);
		printf("\n");
	}
	else
	{
		for (i = 0; num[i] != '\n'; i++)
		{
			if ((10 * rec + (num[i] - '0')) / 2 == 0 && start == 0);
			else
			{
				start = 1;
				printf("%d", (10 * rec + (num[i] - '0')) / 2);
			}
			if ((num[i] - '0') % 2)
				rec = 1;
			else
				rec = 0;
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
