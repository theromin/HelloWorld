//在线处理
int MAxSubseqSum(int a[], int N)
{
  int ThisSum,MaxSum;
  int i;
  ThisSum=MaxSum=0;
  for(i=0;i<N;i++)
  {
    ThisSum+=a[i];
    if(MaxSum>ThisSum)
      MaxSum = ThisSum;
    else if(ThisSum<0)
      ThisSum = 0;
  }
  return MaxSum;
}
