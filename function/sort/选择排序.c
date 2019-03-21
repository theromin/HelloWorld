#define MAX 255
int R[MAX];
void Select_Sort(int n)
{
   int i,j,k;
   for(i=1;i<n;i++)
   {/* 做第i趟排序(1≤i≤n-1) */
     k=i;
     for(j=i+1;j<=n;j++) /* 在当前无序区R[i..n]中选key最小的记录R[k] */
       if(R[j]<R[k])
         k=j; /* k记下目前找到的最小关键字所在的位置 */
       if(k!=i)
       { /* 交换R[i]和R[k] */
         R[0]=R[i]; R[i]=R[k]; R[k]=R[0]; /* R[0]作暂存单元 */
       } /* endif */
     } /* endfor */
} /* end of Select_Sort */
