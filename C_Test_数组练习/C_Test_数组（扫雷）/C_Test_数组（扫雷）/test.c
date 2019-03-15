#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//1.ʹ�ö�ά��������ʾ��ͼ
//   a�����׵Ĳ���ͼ��char ���͵����飬��'0'��ʾ���ǵ��ף�'1'��ʾ�ǵ��ף�
//   b����ҿ����ĵ�ͼ����Щλ��δ��������Щλ�÷�������
//     ��char ���͵������ʾ�����' '��ʾδ����������������ʾ�Ѿ����������ҵ�ǰλ����Χ8�������м����ף�
//2.��ʼ��
//   a�����׵Ĳ��ֵ�ͼ���Ȱ������ά����ȫ������ʼ����'0'��������趨���ɸ�λ��Ϊ����
//   b����ҿ����ĵ�ͼ��ȫ����ʼ����' '����ʾΪ����
//3.�ȴ�ӡ��ͼ����ҿ����ĵ�ͼ������ʾ��ҳ������ꡣ
//4.�����ҷ����ĸ����ǵ��ף�����Ϸ��������ʾɨ��ʧ�ܣ�
//5.�����ҷ����ĸ��Ӳ��ǵ��ף�������������ǵ�ͼ�Ϸǵ��׵����һ��λ�ã�ɨ�׳ɹ�
//6.�����ҷ����Ĳ��ǵ��ף���������Ӳ��ǵ�ͼ�����һ���ǵ���λ�ã�
//  �Ͱѵ�ͼ�ϵ�λ������Ϊչ��״̬�����Ҹ��¸�λ����Χ8�����ӵĵ�����


#define ROW 9
#define COL 9
#define MINE_COUNT 10

int Menu() {
	printf("==================\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.������Ϸ\n");
	printf("==================\n");
	printf("����������ѡ��");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void Init(char show_map[ROW + 2][COL + 2],
	      char mine_map[ROW + 2][COL + 2]) {
	//1.��show_map��ʼ��ȫ��' '
	for (int row = 0; row < ROW + 2;++row) {
		for (int col = 0; col < COL + 2;++col) {
			show_map[row][col] = ' ';
		}
	}
	//2.��mine_map��ʼ��Ϊȫ��'0'
	for (int row = 0; row < ROW + 2; ++row) {
		for (int col = 0; col < COL + 2; ++col) {
			mine_map[row][col] = '0';
		}
	}
	//3.��mmine_map��Щλ���ǵ��ף��Ų���
	int mine_count = MINE_COUNT;
	while (mine_count > 0) {
		//����������õ���
		//�����������λ��[1,9]
		int row = rand() % ROW + 1;
		int col = rand() % COL + 1;
		if (mine_map[row][col] == '1') {
			//��ǰ��������������Ѿ��е�����
			continue;
		}
		mine_map[row][col] = '1';
		--mine_count;
	}
}

void DisplayMap(char map[ROW + 2][COL + 2]) {
	//��ӡ��ͼ
	//����Ҫ��ӡ����ͼ����ϸ���ݣ�˳���ӡ������
	
	//�ȴ�ӡ�����ϽǵĿո�
	printf("    ");
	//��ӡ�е�����
	for (int i = 1; i <= ROW;++i) {
		printf("%d ",i);
	}
	printf("\n");
	//��ӡ�ϱ߿�
	for (int i = 1; i <= ROW; ++i) {
		printf("---");
	}
	printf("\n");
	//���д�ӡ��ͼ������
	for (int row = 1; row <= ROW; ++row) {
		//�ȴ�ӡ�к�
		printf(" %d| ",row);
		//�ٴ�ӡ���е�ÿһ��
		for (int col = 1; col <= COL;++col) {
			printf("%c ",map[row][col]);
		}
		printf("\n");
	}
}


void UpdateShowMap(char show_map[ROW + 2][COL + 2], char mine_map[ROW + 2][COL + 2],
	int row, int col) {
	//ͳ�Ƶ�ǰλ����Χ8�������м������ף���������µ� show_map��
	int count = 0;
	//���û�б߿�����Ҫ�����ж�:
	//if (row - 1 >= 0 && row - 1 < ROW + 1
	//	&& col - 1 >= 0 && col - 1 < COL + 1) {
	//	if (mine_map[row - 1][col - 1 == '1']) {
	//		++count;
	//	}
	//}
	//���˱߿�֮��:
	/*if (mine_map[row - 1][col - 1] == '1') {
		++count;
	}
	if (mine_map[row - 1][col] == '1') {
		++count;
	}
	if (mine_map[row - 1][col + 1] == '1') {
		++count;
	}
	if (mine_map[row][col - 1] == '1') {
		++count;
	}
	if (mine_map[row][col + 1] == '1') {
		++count;
	}
	if (mine_map[row + 1][col - 1] == '1') {
		++count;
	}
	if (mine_map[row + 1][col] == '1') {
		++count;
	}
	if (mine_map[row + 1][col - 1] == '1') {
		++count;
	}
	if (mine_map[row + 1][col + 1] == '1') {
		++count;
	}*/
	//����Ĵ�����Լ�Ϊ
	count = (mine_map[row - 1][col - 1] - '0')
		+ (mine_map[row - 1][col] - '0')
		+ (mine_map[row - 1][col + 1] - '0')
		+ (mine_map[row][col - 1] - '0')
		+ (mine_map[row][col + 1] - '0')
		+ (mine_map[row + 1][col - 1] - '0')
		+ (mine_map[row + 1][col] - '0')
		+ (mine_map[row + 1][col + 1] - '0');
	//
	show_map[row][col] = '0' + count;
}
//ÿ�ε���Game()�ͽ���һ����Ϸ
void Game() {
	//�ٵ�ͼ��������һȦ�߿�
	char show_map[ROW + 2][COL + 2];
	char mine_map[ROW + 2][COL + 2];
	//������Ϊ��������ʽת��Ϊָ�룬�����������������������Ѿ���Ϊָ��
	//�ٺ����ڲ��Բ��������޸��ǻ�Ӱ�쵽�ⲿ�������
	Init(show_map, mine_map);
	int safe_blank_count = 0;
	while (1) {
		DisplayMap(show_map);
		int row = 0;
		int col = 0;
		printf("����������:");
		scanf("%d %d", &row, &col);
		if (row < 1 || row >ROW || col < 1 || col > COL) {
			//��������Ƿ�����Ҫע�⣡��ͼ�Ǵ��߿�ģ������ж�����ҪС��
			printf("����������겻�Ϸ������������룡\n");
			continue;
		}
		//��֤�Ƿ�ȵ�����
		if (mine_map[row][col] == '1') {
			printf("��Ϸ������ɨ��ʧ�ܣ�\n");
			break;
		}
		//��֤�Ƿ�ɨ�׳ɹ�
		++safe_blank_count;
		if (safe_blank_count == ROW * COL - MINE_COUNT) {
			printf("��Ϸ������ɨ�׳ɹ���\n");
			break;
		}
		//���µ�ͼ��״̬
		UpdateShowMap(show_map,mine_map,row,col);
		system("cls");
	}
	DisplayMap(mine_map);
}

int main()
{
	srand((unsigned)time(0));
	while (1) {
		int choice = Menu();
		if (choice == 0) {
			printf("GoodBye!\n");
			break;
		}
		if (choice == 1) {
			Game();
		}
	}
    system("pause");
    return 0;   
}