#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //난수  
#include <time.h> //씨드값 시간으로 두기위해

void main()
{
	int answer[3];  //답을 저장할 배열 생성 
	int player[3]; //사용자가 정답을 입력할 배열 생성  
	int strike = 0, ball = 0, out = 0;  // strike 와 ball은 0으로 초기화한다.  
	int i, j;
	int cnt = 0; //사용자가 입력한 횟수를 입력한다.  

	for (i = 0; i < 3; i++) {
		srand(time(NULL)); //현재 시간을 이용해서 씨드 결정
		answer[i] = rand() % 9 + 1; // 1~9 사이의 숫자를 랜덤으로 answer[] 입력 
		for (j = 0; j < i; j++) {
			if (answer[i] == answer[j]) { //answer[]배열의 중복된 숫자를 검사  
				i--;
				break;
			}
		}
	}
	printf("9번 이상 입력하면  실패입니다.");
	while (1) { //무한 루프 돌리기 Strike가 3이거나 cnt가 9회이상이면은 빠져나감 

		cnt++;

		printf("\n숫자 3개를 입력하세요(1 ~ 9까지의 숫자를 입력 숫자는 1칸씩 띄고 합니다.) : ");
		scanf("%d %d %d", &player[0], &player[1], &player[2]);

		if (player[0] == player[1] || (player[1] == player[2]) || (player[0] == player[2])) { //중복된 숫자를 검사 
			printf("숫자는 중복을 허용하지 않습니다. 다시\n");
			cnt--; //중복된 숫자를 입력했기 때문에 cnt(사용자 입력 횟수)를 다시 원래의 값으로 되돌린다. 
			continue;
		}
		if (player[0] == 0 || player[1] == 0 || player[2] == 0) { // 0을 입력받지 못하도록 검사  
			printf("숫자는 0을 허용하지 않습니다. \n");
			cnt--; //중복된 숫자를 입력했기 때문에 cnt(사용자 입력 횟수)를 다시 원래의 값으로 되돌린다.
			continue;
		}
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if ((answer[i] == player[j]) && i == j) { //컴퓨터가 입력한 숫자와 사용자가 입력한 숫자와 자리가 같을 경우 strike 값을 증가  
					strike++;
				}
				if ((answer[i] == player[j]) && i != j) {  //같은 값이지만 자리가 다르면 ball값을 증가  
					ball++;
				}
				if ((answer[i]) != player[j]) { //모든 숫자가 동일하지 않을 경우 out의 값을 증가 
					out++;
				}
			}
		}
		if (strike == 3) {                     //값과 자리가 모두 동일하게 되면 정답  
			printf("정답을  맞추셨습니다.");
			break;
		}
		if (out >= 9) {                       //out이 9이상이면 모든 숫자가 맞지 않기 떄문에 밑에 printf문을 출력 
			printf("맞는 숫자가 하나도 없습니다(out) .\n");
			out = 0;
		}
		else {
			printf("%d 스트라이크 %d 볼입니다.\n", strike, ball); // strike와 ball을 출력
			out = 0;
		}



		if (cnt == 9) {                      //사용자 입력값이 9번 초과하여 프로그램 종료  
			printf("사용 횟수를 초과하여 실패입니다.");
			break;
		}
		strike = 0;
		ball = 0;
	}
}