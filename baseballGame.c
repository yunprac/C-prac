# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int i, j;
	int ranball[4] = { 0 }; //��ǻ�Ͱ� ���� ����  {0}:�� �ٿ� 4�ڸ� �� ��� �Է� �����ϰ� ��
	int temp;
	int myball[4] = { 0 }; //����ڰ� ���� ����  {0}:�� �ٿ� 4�ڸ� �� ��� �Է� �����ϰ� ��
	int count = 1; //���° �õ�
	int strike;
	int ball;
	int chance = 1; //��ȸ��
	char user = 0; //������ �ٽ� ������ ���ΰ��� ���� ����
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
		printf("%dȸ�� ����\n", chance);
		while (1) {
			printf("[%d��° �õ�]\n", count);
			while (1) {
				printf("4�ڸ� ���ڸ� ��ĭ�� �� �Է����ּ��� : ");
				scanf_s("%d %d %d %d", &myball[0], &myball[1], &myball[2], &myball[3]);
				if (myball[0] < 1 || myball[0] > 9 || myball[1] < 1 || myball[1] > 9 || myball[2] < 1 || myball[2] > 9 || myball[3] < 1 || myball[3] > 9) {
					printf("���� ���� ���ڸ� �Է��ؼ� �ȵ˴ϴ�.\n");
					continue;
				}
				else if (myball[0] == myball[1] || myball[0] == myball[2] || myball[0] == myball[3] || myball[1] == myball[2] || myball[1] == myball[3] || myball[2] == myball[3]) {
					printf("�ߺ��� ���ڸ� �Է��ؼ� �ȵ˴ϴ�.\n");
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
			printf("��Ʈ����ũ : %d, �� : %d\n", strike, ball);

			if (strike == 4) {
				printf("�̰���ϴ�.\n");
				break;
			}
			else if (count == 20) {
				printf("�й��߽��ϴ�. ���� : %d %d %d %d\n", ranball[0], ranball[1], ranball[2], ranball[3]);
				break;
			}
			count++;
		}
		printf("������ �ٽ� �����ұ��? : ");
		scanf_s(" %c", &user);      //%c �տ� ���� ����: ���� �� �ؼ� �۵��� �ȵſ�̤�
		++chance;
		strike = 0;
		ball = 0;
		count = 1;
	} while (user == 'Y' || user == 'y');

	printf("������ �����մϴ�.");
	return 0;
}