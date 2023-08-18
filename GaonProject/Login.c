#include "stdafx.h"
#include <stdio.h>
void login() {

	char id[10];
	int password;
	password = 0;
	printf("**** 도서 관리 프로그램 ****\n");
	printf("아이디 : ");
	scanf("%s", id);
	printf("비밀번호 : ");
	scanf("%d", &password);

	if (strcmp(id, "admin")== 0 && password == 1234) {
		printf("로그인 성공\n");
		printf("\n");

		printf("아무키나 입력하면 화면 이동\n");
		_getch();
		system("cls"); //화면 전환

	}
	else {
		printf("로그인 실패\n");
		exit(0);
	}

}