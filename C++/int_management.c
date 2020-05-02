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
		printf("################ 데이터 관리 (stack) ################\n");
		printf("############### 1. 데이터 조회        ###############\n");
		printf("############### 2. 데이터 삽입        ###############\n");
		printf("############### 3. 데이터 검색        ###############\n");
		printf("############### 4. 데이터 삭제        ###############\n");
		printf("############### 5. 삭제된 데이터 총합 ###############\n");
		printf("############### 6. 5 초기화           ###############\n");
		printf("#####################################################\n");
		printf("입력 : "); scanf("%d", &n);
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
	printf("초기화 완료\n");
}

void deleted() {
	printf("삭제된 데이터 총합 : %d\n", total);

}
void pop() {
	if (top == NULL) {
		printf("데이터 없음\n");
		return;
	}
	Node*keeper = top;
	total += keeper->data;
	top = top->link;
	free(keeper);
	printf("삭제 완료\n");
}

void search() {
	int k;
	printf("데이터 검색(숫자) : "); scanf("%d", &k);
	Node*exist = top;
	while (1) {
		if (exist == NULL) {
			printf("%d은(는) 없음\n",k);
			return;
		}
		else if (exist->data == k) {
			printf("%d은(는) 존재\n",k);
			return;
		}
		else {
			exist = exist->link;
		}
	}
}
void show() {
	if (top == NULL) {
		printf("데이터 없음\n");;
		return;
	}
	printf("################### 저장된 데이터 ##################\n");
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
	printf("데이터 입력 : "); scanf("%d", &s);

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

