#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

typedef struct node {

	int data; 
	struct node *link;
}Node;

Node*top = NULL;
int total = 0;

Node*makeNode();
void insert();
void show();
void search();
void pop();
void deleted();
void first();

void main() {
	int n;

	while (1) {
		printf("################ ������ ���� (stack) ################\n");
		printf("############### 1. ������ ��ȸ        ###############\n");
		printf("############### 2. ������ ����        ###############\n");
		printf("############### 3. ������ �˻�        ###############\n");
		printf("############### 4. ������ ����        ###############\n");
		printf("############### 5. ������ ������ ���� ###############\n");
		printf("############### 6. 5 �ʱ�ȭ           ###############\n");
		printf("#####################################################\n");
		printf("�Է� : "); scanf("%d", &n);
		system("cls");
				switch (n) {
		case 1: show();
			system("pause");
			system("cls");
			break;
		case 2: insert();
			system("pause");
			system("cls");
			break;
		case 3: search();
			system("pause");
			system("cls");
			break;
		case 4: pop();
			system("pause");
			system("cls");
			break;
		case 5: deleted();
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
	total = 0;
	printf("�ʱ�ȭ �Ϸ�\n");
}

void deleted() {
	printf("������ ������ ���� : %d\n", total);

}
void pop() {
	if (top == NULL) {
		printf("������ ����\n");
		return;
	}
	Node*keeper = top;
	total += keeper->data;
	top = top->link;
	free(keeper);
	printf("���� �Ϸ�\n");
}

void search() {
	int k;
	printf("������ �˻�(����) : "); scanf("%d", &k);
	Node*exist = top;
	while (1) {
		if (exist == NULL) {
			printf("%d��(��) ����\n",k);
			return;
		}
		else if (exist->data == k) {
			printf("%d��(��) ����\n",k);
			return;
		}
		else {
			exist = exist->link;
		}
	}
}
void show() {
	if (top == NULL) {
		printf("������ ����\n");;
		return;
	}
	printf("################### ����� ������ ##################\n");
	Node*show = top;
	while (1) {
		printf("%d\n", show->data);
		show = show->link;
		if (show == NULL) {
			return;
		}
	}
}

Node*makeNode() {
	Node*makeNew = (Node*)malloc(sizeof(Node));
	makeNew->link = NULL;

	return makeNew;
}

void insert() {
	int s;
	printf("������ �Է� : "); scanf("%d", &s);

	if (top == NULL) {
		top = makeNode();
		top->data = s;
		return;
	}
	Node*newNode = makeNode();
	newNode->data = s;
	newNode->link = top;
	top = newNode;
}

