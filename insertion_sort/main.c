/**
 *插入排序：C语言
 *
 */
 #include <stdio.h>

 //计算数组长度
 #define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )

 /**
  *参数说明
  * a为数组
  * n为数组长度
  *
  */
void insertion_sort(int *a,int n)//a为数组，n为数组个数
{
    int i,j,key;

    for (j = 1;j < n;j++) {
        key = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > key) {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
}

int main()
{
    int i;
    int a[] = {20,40,30,10,60,50};
    int ilen = LENGTH(a);

    printf("before sort:");
    for (i=0; i<ilen; i++)
        printf("%d ", a[i]);
    printf("\n");

    insertion_sort(a, ilen);

    printf("after  sort:");
    for (i=0; i<ilen; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
