#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdio.h>
#pragma warning(disable: 4996)


void screen() {
	int num;
	num = 0;

	printf("********************\n");
	printf("1. å ��� ����\n");
	printf("2. å ����\n");
	printf("3. å �ݳ�\n");
	printf("4. ������\n");
	printf("********************\n");
	printf("���ϴ� �۾� ��ȣ : ");
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
	printf("****å ��� ȭ��****\n");
	printf("å�̸� ���Ⱑ�ɱǼ�\n");
	printf("********************\n");
	ShowBook();
	printf("\n");
	printf("\n");
	printf("�ƹ�Ű�� �Է��ϸ� ȭ�� �̵�\n");
	_getch();
	system("cls");
	screen();
}

void screen2() {
	char BookName[50];
	char* Book = NULL;
	Book = &BookName;

	printf("********************\n");
	printf("****å ���� ȭ��****\n");
	printf("********************\n");
	printf("������ å �̸� : ");
	scanf("%s", BookName);
	CheckOutBook(Book);
	printf("\n");
	printf("\n");
	printf("�ƹ�Ű�� �Է��ϸ� ȭ�� �̵�\n");
	_getch();
	system("cls");
	screen();

}

void screen3() {
	char BookName[50];
	char* Book = NULL;
	Book = &BookName;

	printf("********************\n");
	printf("****å �ݳ� ȭ��****\n");
	printf("********************\n");
	printf("�ݳ��� å �̸� : ");
	scanf("%s", BookName);
	CheckInBook(Book);
	printf("\n");
	printf("\n");
	printf("�ƹ�Ű�� �Է��ϸ� ȭ�� �̵�\n");
	_getch();
	system("cls");
	screen();

}