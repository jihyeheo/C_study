#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //����  
#include <time.h> //���尪 �ð����� �α�����

void main()
{
	int answer[3];  //���� ������ �迭 ���� 
	int player[3]; //����ڰ� ������ �Է��� �迭 ����  
	int strike = 0, ball = 0, out = 0;  // strike �� ball�� 0���� �ʱ�ȭ�Ѵ�.  
	int i, j;
	int cnt = 0; //����ڰ� �Է��� Ƚ���� �Է��Ѵ�.  

	for (i = 0; i < 3; i++) {
		srand(time(NULL)); //���� �ð��� �̿��ؼ� ���� ����
		answer[i] = rand() % 9 + 1; // 1~9 ������ ���ڸ� �������� answer[] �Է� 
		for (j = 0; j < i; j++) {
			if (answer[i] == answer[j]) { //answer[]�迭�� �ߺ��� ���ڸ� �˻�  
				i--;
				break;
			}
		}
	}
	printf("9�� �̻� �Է��ϸ�  �����Դϴ�.");
	while (1) { //���� ���� ������ Strike�� 3�̰ų� cnt�� 9ȸ�̻��̸��� �������� 

		cnt++;

		printf("\n���� 3���� �Է��ϼ���(1 ~ 9������ ���ڸ� �Է� ���ڴ� 1ĭ�� ��� �մϴ�.) : ");
		scanf("%d %d %d", &player[0], &player[1], &player[2]);

		if (player[0] == player[1] || (player[1] == player[2]) || (player[0] == player[2])) { //�ߺ��� ���ڸ� �˻� 
			printf("���ڴ� �ߺ��� ������� �ʽ��ϴ�. �ٽ�\n");
			cnt--; //�ߺ��� ���ڸ� �Է��߱� ������ cnt(����� �Է� Ƚ��)�� �ٽ� ������ ������ �ǵ�����. 
			continue;
		}
		if (player[0] == 0 || player[1] == 0 || player[2] == 0) { // 0�� �Է¹��� ���ϵ��� �˻�  
			printf("���ڴ� 0�� ������� �ʽ��ϴ�. \n");
			cnt--; //�ߺ��� ���ڸ� �Է��߱� ������ cnt(����� �Է� Ƚ��)�� �ٽ� ������ ������ �ǵ�����.
			continue;
		}
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if ((answer[i] == player[j]) && i == j) { //��ǻ�Ͱ� �Է��� ���ڿ� ����ڰ� �Է��� ���ڿ� �ڸ��� ���� ��� strike ���� ����  
					strike++;
				}
				if ((answer[i] == player[j]) && i != j) {  //���� �������� �ڸ��� �ٸ��� ball���� ����  
					ball++;
				}
				if ((answer[i]) != player[j]) { //��� ���ڰ� �������� ���� ��� out�� ���� ���� 
					out++;
				}
			}
		}
		if (strike == 3) {                     //���� �ڸ��� ��� �����ϰ� �Ǹ� ����  
			printf("������  ���߼̽��ϴ�.");
			break;
		}
		if (out >= 9) {                       //out�� 9�̻��̸� ��� ���ڰ� ���� �ʱ� ������ �ؿ� printf���� ��� 
			printf("�´� ���ڰ� �ϳ��� �����ϴ�(out) .\n");
			out = 0;
		}
		else {
			printf("%d ��Ʈ����ũ %d ���Դϴ�.\n", strike, ball); // strike�� ball�� ���
			out = 0;
		}



		if (cnt == 9) {                      //����� �Է°��� 9�� �ʰ��Ͽ� ���α׷� ����  
			printf("��� Ƚ���� �ʰ��Ͽ� �����Դϴ�.");
			break;
		}
		strike = 0;
		ball = 0;
	}
}