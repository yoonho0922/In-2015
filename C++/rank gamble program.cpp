#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct Node {
	char name[100];
	int data;
	struct Node*link;
}Node;

Node*head = NULL;
int num;
int wn = 1;

void enter();
Node*makeNode();
void show();
int winNum();
void ex();
void whoWin();

int main(void) {
	int s;
	
	printf("������ ��?..."); scanf("%d", &num);
	system("cls");

	while (num <= 2) {
		printf("3���̻� ���� �����մϴ�.\n");
		printf("������ ��?..."); scanf("%d", &num);
		system("cls");
	}
	
	int wn = winNum();
	while (1) {
		printf("%d��° ����� �¸��մϴ�.\n\n", wn);
		printf("1.�Է��ϱ�\n");
		printf("2.�������\n");
		printf("3.��Ϻ���\n");
		printf("4.���Ӽ���\n");
		printf("�Է� : "); scanf("%d", &s);

		system("cls");
		switch (s) {
		case 1: enter();
			system("pause");
			system("cls");
			break;
		case 2: whoWin();
			system("pause");
			system("cls");
			break;
		case 3: show();
			system("pause");
			system("cls");
			break;
		case 4: ex();
			system("pause");
			system("cls");
			break;
		}
	}
}
void whoWin() {
	Node*keeper = head;
	
	for (int i = 1; i < wn; i++) {		
		if (keeper != NULL) {
			keeper = keeper->link;
		}else if (keeper == NULL) {
			printf("�����ڰ� �����մϴ�.\n");
			return;
		}	
		
	}
	if (keeper == NULL) {
		printf("�����ڰ� �����մϴ�.\n");
		return;
	}
		printf("%d��°�� '%s(%d)'�� �¸�\n", wn, keeper->name, keeper->data);
		return;

}

void ex() {
	printf("������ �����Դϴ�.\n");
	printf("1�� ������ �̸��� ���ڸ� �Է��մϴ�.\n");
	printf("�̸����� ���� ū���� ��������\n");
	printf("���������� �Ʒ��� ���ĵ˴ϴ�.\n");
	printf("������ %d��°���ִ� ����� �¸��ϰԵ˴ϴ�.\n\n",wn);
}

int winNum() {

	while (1) {
		if (wn > 1 && wn < num ) {
			return wn;
		}
		else {
			wn = rand();
		}
	}
}
void show() {
	if (head == NULL) {
		printf("������ ����\n\n");
		return;
	}
	Node*keeper = head;
	int i = 1;
	while (1) {
		printf("%d. %s\n", i, keeper->name);
		keeper = keeper->link;
		i++;
		if (keeper == NULL) {
			return;
		}
	}
}


Node*makeNode() {
	Node*makeNew = (Node*)malloc(sizeof(Node));
	makeNew->link = NULL;
	return makeNew;
}
void enter() {

	char n[100];
	int s;
	printf("�̸� �Է� : "); scanf("%s", n);
	printf("���� �Է� : "); scanf("%d", &s);
	if (head == NULL) {
		head = makeNode();
		strcpy(head->name, n);
		head->data = s;
		return;
	}
	Node*newNode = makeNode();
	strcpy(newNode->name, n);
	newNode->data = s;
	if (newNode->data>head->data) {
		Node*keeper = head;
		head = newNode;
		newNode->link = keeper;
		return;
	}if (newNode->data<head->data) {
		Node*keeper = head;
		while (1) {
			if (newNode->data == keeper->data) {
				return;
			}if (keeper->link == NULL) {
				newNode->link = keeper->link;
				keeper->link = newNode;
				return;
			}if (newNode->data>keeper->link->data) {
				newNode->link = keeper->link;
				keeper->link = newNode;
				return;
			}keeper = keeper->link;
		}
	}if (newNode->data == head->data) {
		printf("%d��°�� �̹� �ֽ��ϴ�!!\n", s);
		return;
	}
}

