#include <stdio.h>
#include <time.h>
#include <windows.h>

void printG(int money, int lev) //���� �������� ���� ������ ǥ�����ִ� �Լ�.
{
	printf("������������������������\n");
	printf("  %d G  �� Level : %d \n", money, lev);
	printf("������������������������\n");
}

int upgrade(int level, int luck, int* ptr)
{
	int i;
	srand((unsigned int)time(NULL)); //���� �ð��� ���� rand�� seed������ ����. 
	int random = rand() % 100 + 5; //5~100������ ������ ����. 
	printf("��ȭ��");
	for (i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(1000); //3�� ���.. 
	}
	printf("\n���� ������: %d\n", random);
	if (random < luck)
	{
		printf("����! +80 G\n");
		*ptr = *ptr + 80; //�����Լ��� �ִ� money ������ +80
		return level + 1; //��ȭ������ ���� ���� 1 ����. 
	}
	else
	{
		printf("����..\n");
		return level; //���н� ���� ������ ��ȯ.  
	}
}

int main()
{
	char ch;
	int maxluck, money = 200, level = 1;
	int cost = level * 50;
	int* ptr = &money;
	printf("��######<��ȭ �ùķ��̼� ���α׷��Դϴ�>######��\n");
	printf("��@���� ��ǻ�� �ð��� ���� �������ڰ� �����µ���\n��@�������� ��ȭ ����Ȯ������ ������ ��ȭ����!��\n");
	while (1)
	{
		printG(money, level);
		maxluck = 100 - level * 5; //������ 1 �����Կ� ���� ��ȭȮ�� -5% 
		printf("������������������������\n");
		printf("�����:%d G ��%d%% Ȯ���� ��ȭ�Ͻðڽ��ϱ�? Y/N\n", cost, maxluck);
		printf("������������������������\n");
		ch = getch();
		system("cls"); //ȭ���� ������ �����. 
		if (ch == 'y' || ch == 'Y')
		{
			if (money - cost >= 0)
			{
				money = money - cost;
				level = upgrade(level, maxluck, ptr);
			}
			else
			{
				printf("��尡 �����մϴ�\n");
				break; //��尡 ������ ��� ���ӿ��� 
			}
		}
		else if (ch == 'n' || ch == 'N')
		{
			printf("�����Ͻðڽ��ϱ�? Y/N\n");
			ch = getch();
			if (ch == 'y' || ch == 'Y')
			{
				break;
			}
		}
		else
		{
			printf("Y�Ǵ� N�� �Է����ּ���.\n");
		}
		if (level == 20)
		{
			printf("��� ��ȭ�� ���ƽ��ϴ�. �÷������ּż� �����մϴ�.\n");
			break; //��ȭ ������ �ִ�ġ�� 20. 
		}
	}
	printf("��������.\n�ƹ�Ű�� �����ּ���..");
	getch();
	return 0;
}

