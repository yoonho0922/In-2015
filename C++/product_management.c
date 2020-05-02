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
		printf("#################### 상품 관리 ####################\n");
		printf("################ 1. 상품 조회       ###############\n");
		printf("################ 2. 상품 추가       ###############\n");
		printf("################ 3. 상품 검색       ###############\n");
		printf("################ 4. 상품 판매 (맨앞)###############\n");
		printf("################ 5. 총 매출         ###############\n");
		printf("################ 6. 총 매출 초기화  ###############\n");
		printf("###################################################\n");
		printf("입력 : "); scanf("%d", &b);
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
	printf("총 매출이 초기화 되었습니다.\n");
}

void total() {

	printf("총 매출 : %d\n", tal);

}

void sell() {
	if (front == NULL) {
		printf("데이터 없음\n");
		return;
	}
	Node*keeper = front;

	tal += keeper->price;

	front = front->link;
	free(keeper);

	printf("판매 완료\n");
}

void search() {
	char sear[20] = ""; int e = 0;
	printf("상품 검색 : ");
	scanf("%s", &sear);
	Node*exist = front;
	while (1) {
		if (exist == NULL) {
			if (e == 0) {
				printf("%s 은(는) 없음\n", sear);
				return;
			}else {
				return;
			}
		}
		else if (strcmp(exist->name,sear) == 0) {
			e = 1;
			printf("%s, %d원\n", sear, exist->price);
			exist = exist->link;
		}
		else {
			exist = exist->link;
		}
	}
}

void show() {
	if (front == NULL) {
		printf("데이터 없음\n");
		return;
	}
	Node*sh = front;
	while (1) {
		printf("%s, %d원\n",sh->name , sh->price);
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
	printf("상품명 : ");
	scanf("%s", &n);
	printf("가격 : ");
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

