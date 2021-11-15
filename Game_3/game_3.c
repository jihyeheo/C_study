#include <stdio.h>
#include <time.h>
#include <windows.h>

void printG(int money, int lev) //현재 보유중인 골드와 레벨을 표시해주는 함수.
{
	printf("┌──────────┐\n");
	printf("  %d G  │ Level : %d \n", money, lev);
	printf("└──────────┘\n");
}

int upgrade(int level, int luck, int* ptr)
{
	int i;
	srand((unsigned int)time(NULL)); //현재 시각의 값을 rand의 seed값으로 적용. 
	int random = rand() % 100 + 5; //5~100까지의 난수를 생성. 
	printf("강화중");
	for (i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(1000); //3초 대기.. 
	}
	printf("\n뽑힌 랜덤수: %d\n", random);
	if (random < luck)
	{
		printf("성공! +80 G\n");
		*ptr = *ptr + 80; //메인함수에 있는 money 변수에 +80
		return level + 1; //강화성공에 따라 레벨 1 증가. 
	}
	else
	{
		printf("실패..\n");
		return level; //실패시 기존 레벨을 반환.  
	}
}

int main()
{
	char ch;
	int maxluck, money = 200, level = 1;
	int cost = level * 50;
	int* ptr = &money;
	printf("│######<강화 시뮬레이션 프로그램입니다>######│\n");
	printf("│@현재 컴퓨터 시간에 따라 랜덤숫자가 뽑히는데│\n│@랜덤수가 강화 성공확률보다 낮으면 강화성공!│\n");
	while (1)
	{
		printG(money, level);
		maxluck = 100 - level * 5; //레벨이 1 증가함에 따라 강화확률 -5% 
		printf("┌─────┬────┐\n");
		printf("│비용:%d G │%d%% 확률│ 강화하시겠습니까? Y/N\n", cost, maxluck);
		printf("└─────┻────┘\n");
		ch = getch();
		system("cls"); //화면의 모든것을 지운다. 
		if (ch == 'y' || ch == 'Y')
		{
			if (money - cost >= 0)
			{
				money = money - cost;
				level = upgrade(level, maxluck, ptr);
			}
			else
			{
				printf("골드가 부족합니다\n");
				break; //골드가 부족할 경우 게임오버 
			}
		}
		else if (ch == 'n' || ch == 'N')
		{
			printf("종료하시겠습니까? Y/N\n");
			ch = getch();
			if (ch == 'y' || ch == 'Y')
			{
				break;
			}
		}
		else
		{
			printf("Y또는 N만 입력해주세요.\n");
		}
		if (level == 20)
		{
			printf("모든 강화를 마쳤습니다. 플레이해주셔서 감사합니다.\n");
			break; //강화 레벨의 최대치는 20. 
		}
	}
	printf("게임종료.\n아무키나 눌러주세요..");
	getch();
	return 0;
}

