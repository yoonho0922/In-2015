#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

typedef struct node {

	char name[20];
	int price;	
	struct node*link;

}Node;

Node*front = NULL;
Node*rear = NULL;
int tal = 0;

Node*makeNode();
void add();
void show();
void search();
void sell();
void total();
void first();


void main() {
	int b;
	while(1) {
		printf("#################### ��ǰ ���� ####################\n");
		printf("################ 1. ��ǰ ��ȸ       ###############\n");
		printf("################ 2. ��ǰ �߰�       ###############\n");
		printf("################ 3. ��ǰ �˻�       ###############\n");
		printf("################ 4. ��ǰ �Ǹ� (�Ǿ�)###############\n");
		printf("################ 5. �� ����         ###############\n");
		printf("################ 6. �� ���� �ʱ�ȭ  ###############\n");
		printf("###################################################\n");
		printf("�Է� : "); scanf("%d", &b);
		system("cls");
		
		switch (b) {
		case 1: show();
			system("pause");
			system("cls");
			break;
		case 2: add();
			system("pause");
			system("cls");
			break;
		case 3: search();
			system("pause");
			system("cls");
			break;
		case 4: sell();
			system("pause");
			system("cls");
			break;
		case 5: total();
			system("pause");
			system("cls");
			break;
		case 6: first();
			system("pause");
			system("cls");
			break;
		}
	}
}

void first() {
	tal = 0;
	printf("�� ������ �ʱ�ȭ �Ǿ����ϴ�.\n");
}

void total() {

	printf("�� ���� : %d\n", tal);

}

void sell() {
	if (front == NULL) {
		printf("������ ����\n");
		return;
	}
	Node*keeper = front;

	tal += keeper->price;

	front = front->link;
	free(keeper);

	printf("�Ǹ� �Ϸ�\n");
}

void search() {
	char sear[20] = ""; int e = 0;
	printf("��ǰ �˻� : ");
	scanf("%s", &sear);
	Node*exist = front;
	while (1) {
		if (exist == NULL) {
			if (e == 0) {
				printf("%s ��(��) ����\n", sear);
				return;
			}else {
				return;
			}
		}
		else if (strcmp(exist->name,sear) == 0) {
			e = 1;
			printf("%s, %d��\n", sear, exist->price);
			exist = exist->link;
		}
		else {
			exist = exist->link;
		}
	}
}

void show() {
	if (front == NULL) {
		printf("������ ����\n");
		return;
	}
	Node*sh = front;
	while (1) {
		printf("%s, %d��\n",sh->name , sh->price);
		sh = sh->link;
		if (sh == NULL) {
			return;
		}
	}
}

Node*makeNode() {
	Node*makeNew = (Node*)malloc(sizeof(Node));
	makeNew->link = NULL;	

	return makeNew;
}

void add() {
	char n[20];
	int p;
	printf("��ǰ�� : ");
	scanf("%s", &n);
	printf("���� : ");
	scanf("%d", &p);
	if (front == NULL) {
		front = makeNode();
		strcpy(front->name, n);
		front->price = p;
		rear = front;
		return;
	}
	Node*newNode = makeNode();
	strcpy(newNode->name, n);
	newNode->price = p;
	rear->link = newNode;
	rear = newNode;

}

