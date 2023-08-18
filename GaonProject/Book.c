#include "stdafx.h"
extern int MaxBookarry[50];

void ShowBook() {
	FILE* fs;
	fs = fopen("C:\\Users\\손병일\\source\\repos\\GaonProject\\GaonProject\\BookList.txt", "r");
	if (fs == NULL)
	{
		printf("파일이 없습니다. 프로그램을 종료합니다.");
		return 0;
	}
	char str[50];
	while (fgets(str, sizeof(str), fs) != NULL) {
		printf("%s", str);
	}
	fclose(fs);
}


void CheckInBook(char* Book) { //반납     함수가 새로 쓰이기 때문에 전부 다 초기화됨.
	//==============================
	//int MaxBookarry[50] = { 0, }; //초기화
	char strr[50] = "Garbage"; //초기화
	int LineNumm = 0; //초기화

	//FILE* fx;
	//fx = fopen("C:\\Users\\손병일\\source\\repos\\GaonProject\\GaonProject\\BookList.txt", "r+");
	//if (fx == NULL) {
	//	printf("파일이 없습니다. 프로그램을 종료합니다.");
	//	return 0;
	//}

	//while (fgets(strr, sizeof(strr), fx) != NULL) {
	//	char* pos;
	//	pos = strpbrk(strr, " ");
	//	pos++;
	//	MaxBookarry[LineNumm] = atoi(pos);  //아스키코드를 int형으로 바꾸는 함수  atoi(pos)= 책 수
	//	LineNumm++;
	//}
	//printf("%d\n", MaxBookarry[0]);
	//printf("%d\n", MaxBookarry[1]);
	//printf("%d\n", MaxBookarry[2]);
	//printf("%d\n", MaxBookarry[3]);
	//printf("%d\n", MaxBookarry[4]);


	//fclose(fx);
	//==================================
	//MaxBookarry에 잘 들어왔는지 확인하기
	FILE* fs;
	fs = fopen("C:\\Users\\손병일\\source\\repos\\GaonProject\\GaonProject\\BookList.txt", "r+");
	if (fs == NULL)
	{
		printf("파일이 없습니다. 프로그램을 종료합니다.");
		return 0;
	}


	char str[50] = "Garbage"; //초기화
	char* OneLine = NULL;
	OneLine = &str;
	char buf[30] = "Garbage";

	int find_word;
	char* p_temp = "Garbage";
	int LineNum = 0;


	int count = 0;

	while (fgets(str, sizeof(str), fs) != NULL) {
		if (strstr(OneLine, Book)) { // 찾지 못하면 null 반환
			if (Plus_BookCount(OneLine, Book) > MaxBookarry[count]) {
				printf("반납이 불가합니다.");
			}

			else {
				printf("반납이 완료되었습니다.\n");
				printf("\n");
				printf("반납한 도서 명 : ");
				printf("%s", Book);
				printf("\n");
				printf("남은 도서 수 : %d권", Plus_BookCount(OneLine, Book));
				sprintf(buf, "%s %d", Book, Plus_BookCount(OneLine, Book));
				
				p_temp = strstr(OneLine, Book);
				find_word = strlen(OneLine) - (p_temp - OneLine) + 1; //p_temp값과 find_word값이 같음 다시 공부하기!
				fseek(fs, -1 * find_word, SEEK_CUR);
				fwrite(buf, sizeof(Book) - 1, 1, fs); //fwrite(,이 값은 글자 크기였음,,)
				fseek(fs, find_word - sizeof(Book) - 1, SEEK_CUR);
				
			}
		}
		count++;
		
	}

	fclose(fs);


}

void CheckOutBook(char* Book) { //대출

	FILE* fs;
	fs = fopen("C:\\Users\\손병일\\source\\repos\\GaonProject\\GaonProject\\BookList.txt", "r+");
	if (fs == NULL)
	{
		printf("파일이 없습니다. 프로그램을 종료합니다.");
		return 0;
	}


	char str[50] = "Garbage"; //초기화
	char* OneLine = NULL;
	OneLine = &str;
	char buf[30] = "Garbage";

	int find_word;
	char* p_temp = "Garbage";


	while (fgets(str, sizeof(str), fs) != NULL) {
		if (Minus_BookCount(OneLine, Book) == -1) {
			printf("대출이 불가합니다\n");
			break;
		}
		else {
			if (strstr(OneLine, Book)) { // 찾지 못하면 null 반환
				printf("대출이 완료되었습니다.\n");
				printf("\n");
				printf("대출한 도서 명 : ");
				printf("%s", Book);
				printf("\n");
				printf("남은 도서 수 : %d권", Minus_BookCount(OneLine, Book));
				sprintf(buf, "%s %d", Book, Minus_BookCount(OneLine, Book));
				
				p_temp = strstr(OneLine, Book);
				find_word = strlen(OneLine) - (p_temp - OneLine) + 1; //p_temp값과 find_word값이 같음 다시 공부하기!
				fseek(fs, -1 * find_word, SEEK_CUR);
				fwrite(buf, sizeof(Book) - 1, 1, fs); //fwrite(,이 값은 글자 크기였음,,)
				fseek(fs, find_word - sizeof(Book) - 1, SEEK_CUR);
				break;
			}
		}
		
	}
	fclose(fs);

}





int Plus_BookCount(char*OneLine,char* Book) {     //반납 권수 계산기

	if (strstr(OneLine, Book) != NULL) {
		char* pos;
		pos = strpbrk(OneLine, " ");
		pos++;
		int Plus_BookCount = atoi(pos);
		return Plus_BookCount + 1;
	}
}

int Minus_BookCount(char* OneLine, char* Book) {     //대출 권수 계산기

	if (strstr(OneLine, Book) != NULL) {
		char* pos;
		pos = strpbrk(OneLine, " ");
		pos++;
		int Minus_BookCount = atoi(pos);
		return Minus_BookCount - 1;
	}
}





void MaxBook() { // 배열에 담아주는 함수 MaxBookarry 라는 배열을 만듬.
	char strr[50] = "Garbage"; //초기화
	int LineNumm = 0; //초기화

	FILE* fx;
	fx = fopen("C:\\Users\\손병일\\source\\repos\\GaonProject\\GaonProject\\BookList.txt", "r+");
	if (fx == NULL) {
		printf("파일이 없습니다. 프로그램을 종료합니다.");
		return 0;
	}

	while (fgets(strr, sizeof(strr), fx) != NULL) {
		char* pos;
		pos = strpbrk(strr, " ");
		pos++;
		MaxBookarry[LineNumm] = atoi(pos);  //아스키코드를 int형으로 바꾸는 함수  atoi(pos)= 책 수
		LineNumm++;
	}


	fclose(fx);

}
