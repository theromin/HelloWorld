/*
给定四种水果，分别是苹果（apple）、梨（pear）、桔子（orange）、葡萄（grape），
单价分别对应为3.00元/公斤、2.50元/公斤、4.10元/公斤、10.20元/公斤。
首先在屏幕上显示以下菜单：
[1] apple
[2] pear
[3] orange
[4] grape
[0] exit
用户可以输入编号1~4查询对应水果的单价。当连续查询次数超过5次时，程序应自动退出查询；
不到5次而用户输入0即退出；输入其他编号，显示价格为0。
*/
#include <stdio.h>
int main(){
	int a,i,t=0;
	printf("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n");
	for(i=1;i<=5;i++){
		scanf("%d",&a);
		switch (a){
			case 1: printf("price = 3.00\n");break;
			case 2:	printf("price = 2.50\n");break;
			case 3:	printf("price = 4.10\n");break;
			case 4: printf("price = 10.20\n");break;
			case 0: t=1;break;
			default: printf("price = 0.00\n");
		}
		if(t==1) break;
	}
  return 0;
}
