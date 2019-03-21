#define MAX 255
int R[MAX];
int Partition(int i,int j)
{/* 调用Partition(R，low，high)时，对R[low..high]做划分，*/
     /* 并返回基准记录的位置 */
      int pivot=R[i]; /* 用区间的第1个记录作为基准 */
      while(i<j){ /* 从区间两端交替向中间扫描，直至i=j为止 */
        while(i<j&&R[j]>=pivot) /* pivot相当于在位置i上 */
          j--;  /* 从右向左扫描，查找第1个关键字小于pivot.key的记录R[j] */
        if(i<j) /* 表示找到的R[j]的关键字<pivot.key  */
            R[i++]=R[j]; /* 相当于交换R[i]和R[j]，交换后i指针加1 */
        while(i<j&&R[i]<=pivot) /* pivot相当于在位置j上*/
            i++; /* 从左向右扫描，查找第1个关键字大于pivot.key的记录R[i] */
        if(i<j) /* 表示找到了R[i]，使R[i].key>pivot.key */
            R[j--]=R[i]; /* 相当于交换R[i]和R[j]，交换后j指针减1 */
       } /* endwhile */
      R[i]=pivot; /* 基准记录已被最后定位*/
      return i;
} /* end of partition  */

void Quick_Sort(int low,int high)
{ /* 对R[low..high]快速排序 */
     int pivotpos; /* 划分后的基准记录的位置 */
     if(low<high){/* 仅当区间长度大于1时才须排序 */
	pivotpos=Partition(low,high); /* 对R[low..high]做划分 */
        Quick_Sort(low,pivotpos-1); /* 对左区间递归排序 */
        Quick_Sort(pivotpos+1,high); /* 对右区间递归排序 */
      }
} /* end of Quick_Sort */
