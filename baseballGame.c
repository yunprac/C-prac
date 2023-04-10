# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int i, j;
	int ranball[4] = { 0 }; //컴퓨터가 뽑은 숫자  {0}:한 줄에 4자리 수 모두 입력 가능하게 함
	int temp;
	int myball[4] = { 0 }; //사용자가 뽑은 숫자  {0}:한 줄에 4자리 수 모두 입력 가능하게 함
	int count = 1; //몇번째 시도
	int strike;
	int ball;
	int chance = 1; //몇회차
	char user = 0; //게임을 다시 시작할 것인가에 대한 변수
	srand((unsigned)time(NULL));
	do {
		for (i = 0; i < 4; i++) {
			temp = (rand() % 9) + 1;
			ranball[i] = temp;
			for (j = 0; j < i; j++) {
				if (temp == ranball[j] && i != j)
					i--;
			}
		}
		printf("%d회차 게임\n", chance);
		while (1) {
			printf("[%d번째 시도]\n", count);
			while (1) {
				printf("4자리 숫자를 한칸씩 띄어서 입력해주세요 : ");
				scanf_s("%d %d %d %d", &myball[0], &myball[1], &myball[2], &myball[3]);
				if (myball[0] < 1 || myball[0] > 9 || myball[1] < 1 || myball[1] > 9 || myball[2] < 1 || myball[2] > 9 || myball[3] < 1 || myball[3] > 9) {
					printf("범위 외의 숫자를 입력해선 안됩니다.\n");
					continue;
				}
				else if (myball[0] == myball[1] || myball[0] == myball[2] || myball[0] == myball[3] || myball[1] == myball[2] || myball[1] == myball[3] || myball[2] == myball[3]) {
					printf("중복된 숫자를 입력해선 안됩니다.\n");
					continue;
				}
				break;
			}
			ball = 0;
			strike = 0;
			for (i = 0; i < 4; i++)
				for (j = 0; j < 4; j++)
					if (ranball[i] == myball[j])
						if (i == j)
							strike++;
						else
							ball++;
			printf("스트라이크 : %d, 볼 : %d\n", strike, ball);

			if (strike == 4) {
				printf("이겼습니다.\n");
				break;
			}
			else if (count == 20) {
				printf("패배했습니다. 정답 : %d %d %d %d\n", ranball[0], ranball[1], ranball[2], ranball[3]);
				break;
			}
			count++;
		}
		printf("게임을 다시 시작할까요? : ");
		scanf_s(" %c", &user);      //%c 앞에 띄어쓰기 이유: 띄어쓰기 안 해서 작동이 안돼요ㅜㅜ
		++chance;
		strike = 0;
		ball = 0;
		count = 1;
	} while (user == 'Y' || user == 'y');

	printf("게임을 종료합니다.");
	return 0;
}