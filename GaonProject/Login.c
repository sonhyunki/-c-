#include "stdafx.h"
#include <stdio.h>
void login() {

	char id[10];
	int password;
	password = 0;
	printf("**** ���� ���� ���α׷� ****\n");
	printf("���̵� : ");
	scanf("%s", id);
	printf("��й�ȣ : ");
	scanf("%d", &password);

	if (strcmp(id, "admin")== 0 && password == 1234) {
		printf("�α��� ����\n");
		printf("\n");

		printf("�ƹ�Ű�� �Է��ϸ� ȭ�� �̵�\n");
		_getch();
		system("cls"); //ȭ�� ��ȯ

	}
	else {
		printf("�α��� ����\n");
		exit(0);
	}

}