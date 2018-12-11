/*
输入n，打印规模为n（n为奇数）的菱形。
菱形长什么样子？
当n=3时，菱形如下：
 *
***
 *
当n=5时，菱形如下：
  *
 ***
*****
 ***
  *
【输入格式】
一行一个整数n，表示菱形的规模。
【输出格式】
如题意输出规模为n的菱形。
*/
#include <stdio.h>
#include <math.h>
int main ()
{
    int n,i,j;
    scanf("%d",&n);
    n/=2;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i+1;j++)
        {
            printf(" ");
        }
        for(j=1;j<=2*i-1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(i=1;i<=2*n+1;i++)
    {
        printf("*");
    }
    printf("\n");
    for(i=n;i>=1;i--)
    {
        for(j=1;j<=n-i+1;j++)
        {
            printf(" ");
        }
        for(j=1;j<=2*i-1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
