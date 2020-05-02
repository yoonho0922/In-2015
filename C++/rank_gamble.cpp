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
	
	printf("참가자 수?..."); scanf("%d", &num);
	system("cls");

	while (num <= 2) {
		printf("3명이상 참가 가능합니다.\n");
		printf("참가자 수?..."); scanf("%d", &num);
		system("cls");
	}
	
	int wn = winNum();
	while (1) {
		printf("%d번째 사람이 승리합니다.\n\n", wn);
		printf("1.입력하기\n");
		printf("2.결과보기\n");
		printf("3.목록보기\n");
		printf("4.게임설명\n");
		printf("입력 : "); scanf("%d", &s);

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
			printf("참가자가 부족합니다.\n");
			return;
		}	
		
	}
	if (keeper == NULL) {
		printf("참가자가 부족합니다.\n");
		return;
	}
		printf("%d번째인 '%s(%d)'의 승리\n", wn, keeper->name, keeper->data);
		return;

}

void ex() {
	printf("간단한 게임입니다.\n");
	printf("1을 누르면 이름과 숫자를 입력합니다.\n");
	printf("이름들은 제일 큰수를 시작으로\n");
	printf("위에서부터 아래로 정렬됩니다.\n");
	printf("위에서 %d번째에있는 사람이 승리하게됩니다.\n\n",wn);
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
		printf("참가자 없음\n\n");
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
	printf("이름 입력 : "); scanf("%s", n);
	printf("숫자 입력 : "); scanf("%d", &s);
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
		printf("%d번째는 이미 있습니다!!\n", s);
		return;
	}
}

