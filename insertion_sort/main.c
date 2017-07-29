/**
 *��������C����
 *
 */
 #include <stdio.h>

 //�������鳤��
 #define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )

 /**
  *����˵��
  * aΪ����
  * nΪ���鳤��
  *
  */
void insertion_sort(int *a,int n)//aΪ���飬nΪ�������
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
