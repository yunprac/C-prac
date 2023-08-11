#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Partition(int A[], int start, int end)
{
    //기본적으로 quicksort의 pivot 선정 후 교환 과정과 동일
   //본 예제에서 pivot은 가장 왼쪽의 인덱스를 사용하기로 함

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
    //찾고자 하는 인덱스가 범위 내에 존재할 경우
    if (select > 0 && select <= end - start + 1) {
        int pos = Partition(A, start, end);

        if (pos - start == select - 1) {            //찾고자 하는 숫자를 찾은 경우
            return A[pos];
        }
        else if (pos - start > select - 1) {      //찾고자 하는 숫자가 small group에 존재
            return select_Prob(A, start, pos - 1, select);
        }
        else {                                            //찾고자 하는 숫자가 large group에 존재
            return select_Prob(A, pos + 1, end, select - pos + start - 1);
        }
    }
    return -1; // 탐색 실패했을 경우
}

int main(void) {
    int n, index, value;  // n:A size, index: k, value: 탐색된 값 
    int* A = NULL;

    printf("배열의 크기를 입력하시오 : ");
    scanf("%d", &n);

    A = (int*)malloc(sizeof(int) * n);
    printf("배열의 원소를 입력하시오 : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", (A + i));
    }
    printf("몇 번째의 원소를 찾으십니까? : ");
    scanf("%d", &index);
    if (index > n) {
        while (index > n) {
            printf("입력된 원소의 범위를 벗어납니다. 다시 입력해주세요.\n몇 번째의 원소를 찾으십니까? : ");
            scanf("%d", &index);
        }
    }

    value = select_Prob(A, 0, n - 1, n + 1 - index);    // index 번째로 큰 수 = n + 1 - index 번째 수  ex) 4번째로 큰 수 = 오름차순 정렬 기준 7번째 수
    printf("찾고자 하는 %d 번째로 큰 원소의 값은 %d 입니다. \n", index, value);
    return 0;
}