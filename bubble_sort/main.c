/**
 *ð������(C����)
 *
 **/
#include <stdio.h>

// ���鳤��
#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
// ������ֵ
#define swap(a,b)    (a^=b,b^=a,a^=b)

//a -- ����������
//n -- ����ĳ���
void bubble_sort(int a[], int n)
{
    int i,j;
    int flag;                 // ���

    for (i=n-1; i>0; i--)
    {
        flag = 0;            // ��ʼ�����Ϊ0

        // ��a[0...i]���������ݷ���ĩβ
        for (j=0; j<i; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                flag = 1;    // ������������������Ϊ1
            }
        }

        if (flag==0)
            break;          // ��û������������˵������������
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
