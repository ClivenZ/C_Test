#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

//1.ʹ���ַ����Ͷ�ά��������ʾ���̣�3 * 3��
//ʹ�á�x����ʾ��ҵ��ӣ���0����ʾ���Ե���
//2.������ӣ������һ���Ѻõ���ʾ����ʾ��������ӣ�����һ������
//== > �ж���Ϸ����
//a����һ�ʤ
//b�����Ի�ʤ
//c������
//d����Ϸû����
//3.�������ӣ�������ķ�ʽ
//== > �ж���Ϸ����
//a����һ�ʤ
//b�����Ի�ʤ
//c������
//d����Ϸû����

#define ROW 3
#define COL 3

//g_ǰ׺��ʾȫ�ֱ���
char g_broad[ROW][COL];

//��ʼ��
void Init() {
	//�������е�ÿ��Ԫ�ض���ʼ���ɿո�
	for (int row = 0; row < ROW; ++row) {
		for (int col = 0; col < COL; ++col) {
			g_broad[row][col] = ' ';
		}
	}
}
//��ӡ����
void Print() {
	for (int row = 0; row < ROW; ++row) {
		printf("| %c | %c | %c |\n",
			g_broad[row][0], g_broad[row][1], g_broad[row][2]);
		if (row != ROW - 1) {
			printf("|---|---|---|\n");
		}
	}
}
//�������
void PlayerMove() {
	printf("������ӣ�\n");
	while (1) {
		printf("������һ������(row col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL) {
			printf("��������Ƿ������������룡\n");
			continue;
		}
		if (g_broad[row][col] != ' ') {
			printf("��ǰλ���Ѿ������ˣ����������룡\n");
			continue;
		}
		g_broad[row][col] = 'x';
		break;
	}
}
//������˷���1�����û������0
int IsFull() {
	//��������
	for (int row = 0; row < ROW; ++row) {
		for (int col = 0; col < COL; ++col) {
			if (g_broad[row][col] == ' ');
			return 0;
		}
	}
	return 1;
}
//���ص�ǰ����Ϸʤ�����
//���ء�x����ʾ��һ�ʤ�����ء�0����ʾ���Ի�ʤ
//����'q'��ʾ���壬����' '��ʾ��Ϸû�н���
char CheckWinner() {
	//�ȼ�����е���
	for (int row = 0; row < ROW; ++row) {
		if (g_broad[row][0] == g_broad[row][1]
			&& g_broad[row][0] == g_broad[row][2]
			&& g_broad[row][0] != ' '){
			return g_broad[row][0];
			}
	}
	//�ټ�����е���
	for (int col = 0; col < COL; ++col) {
		if (g_broad[0][col] == g_broad[1][col]
			&& g_broad[0][col] == g_broad[2][col]
			&& g_broad[0][col] != ' ') {
			return g_broad[0][col];
		}
	}
	//�ټ�����еĶԽ�
	if (g_broad[0][0] == g_broad[1][1]
		&& g_broad[0][0] == g_broad[2][2]
		&& g_broad[0][0] != ' ') {
		return g_broad[0][0];
	}
	if (g_broad[2][0] == g_broad[1][1]
		&&g_broad[2][0] == g_broad[0][2]
		&&g_broad[2][0] != ' ') {
		return g_broad[2][0];
	}
	if (IsFull()) {
		return 'q';
	}
	return' ';
}

void ComputerMove() {
	printf("�������ӣ�\n");
	while (1) {
		int row = rand() % ROW;
		int col = rand() % COL;
		if (g_broad[row][col] != ' ') {
			continue;
		}
		g_broad[row][col] = 'o';
		break;
	}
}
int main()
{
	srand((unsigned)time(0));
	Init();
	char winner = '\0';
	while (1) {
		Print();
		PlayerMove();
		winner = CheckWinner();
		if (winner != ' ') {
			break;
		}
		ComputerMove();
		winner = CheckWinner();
		if (winner != ' ') {
			break;
		}
		system("cls");
	}
	Print();
	if (winner == 'x') {
		printf("��Ӯ��\n");
	}
	else if (winner == '0') {
		printf("������!\n");
	}
	else{
		printf("����!\n");
	}
    system("pause");
    return 0;   
}