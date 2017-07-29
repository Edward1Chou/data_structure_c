/**
 *冒泡排序(C语言)
 *
 **/
#include <stdio.h>

// 数组长度
#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
// 交互数值
#define swap(a,b)    (a^=b,b^=a,a^=b)

//a -- 待排序数组
//n -- 数组的长度
void bubble_sort(int a[], int n)
{
    int i,j;
    int flag;                 // 标记

    for (i=n-1; i>0; i--)
    {
        flag = 0;            // 初始化标记为0

        // 将a[0...i]中最大的数据放在末尾
        for (j=0; j<i; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                flag = 1;    // 若发生交换，则设标记为1
            }
        }

        if (flag==0)
            break;          // 若没发生交换，则说明数列已有序。
    }
}

int main()
{
    int i;
    int a[] = {100,40,30,10,50,60};
    int ilen = LENGTH(a);

    printf("before sort:");
    for (i=0; i<ilen; i++)
        printf("%d ", a[i]);
    printf("\n");

    bubble_sort(a, ilen);

    printf("after  sort:");
    for (i=0; i<ilen; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
