#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdio.h>
#pragma warning(disable: 4996)


void screen() {
	int num;
	num = 0;

	printf("********************\n");
	printf("1. 책 목록 보기\n");
	printf("2. 책 대출\n");
	printf("3. 책 반납\n");
	printf("4. 나가기\n");
	printf("********************\n");
	printf("원하는 작업 번호 : ");
	scanf("%d", &num);

	if (num == 1) {
		system("cls");
		screen1();
	}
		
	if (num == 2) {
		system("cls");
		screen2();
	}

	if (num == 3) {
		system("cls");
		screen3();
	}

	if (num == 4) {
		exit(0);
	}

}

void screen1() {
	printf("********************\n");
	printf("****책 목록 화면****\n");
	printf("책이름 대출가능권수\n");
	printf("********************\n");
	ShowBook();
	printf("\n");
	printf("\n");
	printf("아무키나 입력하면 화면 이동\n");
	_getch();
	system("cls");
	screen();
}

void screen2() {
	char BookName[50];
	char* Book = NULL;
	Book = &BookName;

	printf("********************\n");
	printf("****책 대출 화면****\n");
	printf("********************\n");
	printf("대출할 책 이름 : ");
	scanf("%s", BookName);
	CheckOutBook(Book);
	printf("\n");
	printf("\n");
	printf("아무키나 입력하면 화면 이동\n");
	_getch();
	system("cls");
	screen();

}

void screen3() {
	char BookName[50];
	char* Book = NULL;
	Book = &BookName;

	printf("********************\n");
	printf("****책 반납 화면****\n");
	printf("********************\n");
	printf("반납할 책 이름 : ");
	scanf("%s", BookName);
	CheckInBook(Book);
	printf("\n");
	printf("\n");
	printf("아무키나 입력하면 화면 이동\n");
	_getch();
	system("cls");
	screen();

}