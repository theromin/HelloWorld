#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -1
typedef int ElementType;
typedef int Position;

typedef struct LNode *List;
typedef struct LNode list;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* 保存线性表中最后一个元素的位置 */
};

int main()
{
	printf("%d %d %d\n", sizeof(struct LNode), sizeof(List),sizeof(list));
	return 0;
}
