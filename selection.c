#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Partition(int A[], int start, int end)
{
    //�⺻������ quicksort�� pivot ���� �� ��ȯ ������ ����
   //�� �������� pivot�� ���� ������ �ε����� ����ϱ�� ��

    int pivot = A[start];
    int low = start + 1, high = end;
    int temp = 0;
    while (low <= high)
    {
        while (low <= end && A[low] <= pivot)
        {
            low++;
        }
        while (high >= (start + 1) && A[high] >= pivot)
        {
            high--;
        }
        if (low <= high)
        {
            temp = A[low];
            A[low] = A[high];
            A[high] = temp;
        }
    }
    temp = A[start];
    A[start] = A[high];
    A[high] = temp;

    return high;
}
int select_Prob(int A[], int start, int end, int select) {
    //ã���� �ϴ� �ε����� ���� ���� ������ ���
    if (select > 0 && select <= end - start + 1) {
        int pos = Partition(A, start, end);

        if (pos - start == select - 1) {            //ã���� �ϴ� ���ڸ� ã�� ���
            return A[pos];
        }
        else if (pos - start > select - 1) {      //ã���� �ϴ� ���ڰ� small group�� ����
            return select_Prob(A, start, pos - 1, select);
        }
        else {                                            //ã���� �ϴ� ���ڰ� large group�� ����
            return select_Prob(A, pos + 1, end, select - pos + start - 1);
        }
    }
    return -1; // Ž�� �������� ���
}

int main(void) {
    int n, index, value;  // n:A size, index: k, value: Ž���� �� 
    int* A = NULL;

    printf("�迭�� ũ�⸦ �Է��Ͻÿ� : ");
    scanf("%d", &n);

    A = (int*)malloc(sizeof(int) * n);
    printf("�迭�� ���Ҹ� �Է��Ͻÿ� : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", (A + i));
    }
    printf("�� ��°�� ���Ҹ� ã���ʴϱ�? : ");
    scanf("%d", &index);
    if (index > n) {
        while (index > n) {
            printf("�Էµ� ������ ������ ����ϴ�. �ٽ� �Է����ּ���.\n�� ��°�� ���Ҹ� ã���ʴϱ�? : ");
            scanf("%d", &index);
        }
    }

    value = select_Prob(A, 0, n - 1, n + 1 - index);    // index ��°�� ū �� = n + 1 - index ��° ��  ex) 4��°�� ū �� = �������� ���� ���� 7��° ��
    printf("ã���� �ϴ� %d ��°�� ū ������ ���� %d �Դϴ�. \n", index, value);
    return 0;
}