#include "stdafx.h"
extern int MaxBookarry[50];

void ShowBook() {
	FILE* fs;
	fs = fopen("C:\\Users\\�պ���\\source\\repos\\GaonProject\\GaonProject\\BookList.txt", "r");
	if (fs == NULL)
	{
		printf("������ �����ϴ�. ���α׷��� �����մϴ�.");
		return 0;
	}
	char str[50];
	while (fgets(str, sizeof(str), fs) != NULL) {
		printf("%s", str);
	}
	fclose(fs);
}


void CheckInBook(char* Book) { //�ݳ�     �Լ��� ���� ���̱� ������ ���� �� �ʱ�ȭ��.
	//==============================
	//int MaxBookarry[50] = { 0, }; //�ʱ�ȭ
	char strr[50] = "Garbage"; //�ʱ�ȭ
	int LineNumm = 0; //�ʱ�ȭ

	//FILE* fx;
	//fx = fopen("C:\\Users\\�պ���\\source\\repos\\GaonProject\\GaonProject\\BookList.txt", "r+");
	//if (fx == NULL) {
	//	printf("������ �����ϴ�. ���α׷��� �����մϴ�.");
	//	return 0;
	//}

	//while (fgets(strr, sizeof(strr), fx) != NULL) {
	//	char* pos;
	//	pos = strpbrk(strr, " ");
	//	pos++;
	//	MaxBookarry[LineNumm] = atoi(pos);  //�ƽ�Ű�ڵ带 int������ �ٲٴ� �Լ�  atoi(pos)= å ��
	//	LineNumm++;
	//}
	//printf("%d\n", MaxBookarry[0]);
	//printf("%d\n", MaxBookarry[1]);
	//printf("%d\n", MaxBookarry[2]);
	//printf("%d\n", MaxBookarry[3]);
	//printf("%d\n", MaxBookarry[4]);


	//fclose(fx);
	//==================================
	//MaxBookarry�� �� ���Դ��� Ȯ���ϱ�
	FILE* fs;
	fs = fopen("C:\\Users\\�պ���\\source\\repos\\GaonProject\\GaonProject\\BookList.txt", "r+");
	if (fs == NULL)
	{
		printf("������ �����ϴ�. ���α׷��� �����մϴ�.");
		return 0;
	}


	char str[50] = "Garbage"; //�ʱ�ȭ
	char* OneLine = NULL;
	OneLine = &str;
	char buf[30] = "Garbage";

	int find_word;
	char* p_temp = "Garbage";
	int LineNum = 0;


	int count = 0;

	while (fgets(str, sizeof(str), fs) != NULL) {
		if (strstr(OneLine, Book)) { // ã�� ���ϸ� null ��ȯ
			if (Plus_BookCount(OneLine, Book) > MaxBookarry[count]) {
				printf("�ݳ��� �Ұ��մϴ�.");
			}

			else {
				printf("�ݳ��� �Ϸ�Ǿ����ϴ�.\n");
				printf("\n");
				printf("�ݳ��� ���� �� : ");
				printf("%s", Book);
				printf("\n");
				printf("���� ���� �� : %d��", Plus_BookCount(OneLine, Book));
				sprintf(buf, "%s %d", Book, Plus_BookCount(OneLine, Book));
				
				p_temp = strstr(OneLine, Book);
				find_word = strlen(OneLine) - (p_temp - OneLine) + 1; //p_temp���� find_word���� ���� �ٽ� �����ϱ�!
				fseek(fs, -1 * find_word, SEEK_CUR);
				fwrite(buf, sizeof(Book) - 1, 1, fs); //fwrite(,�� ���� ���� ũ�⿴��,,)
				fseek(fs, find_word - sizeof(Book) - 1, SEEK_CUR);
				
			}
		}
		count++;
		
	}

	fclose(fs);


}

void CheckOutBook(char* Book) { //����

	FILE* fs;
	fs = fopen("C:\\Users\\�պ���\\source\\repos\\GaonProject\\GaonProject\\BookList.txt", "r+");
	if (fs == NULL)
	{
		printf("������ �����ϴ�. ���α׷��� �����մϴ�.");
		return 0;
	}


	char str[50] = "Garbage"; //�ʱ�ȭ
	char* OneLine = NULL;
	OneLine = &str;
	char buf[30] = "Garbage";

	int find_word;
	char* p_temp = "Garbage";


	while (fgets(str, sizeof(str), fs) != NULL) {
		if (Minus_BookCount(OneLine, Book) == -1) {
			printf("������ �Ұ��մϴ�\n");
			break;
		}
		else {
			if (strstr(OneLine, Book)) { // ã�� ���ϸ� null ��ȯ
				printf("������ �Ϸ�Ǿ����ϴ�.\n");
				printf("\n");
				printf("������ ���� �� : ");
				printf("%s", Book);
				printf("\n");
				printf("���� ���� �� : %d��", Minus_BookCount(OneLine, Book));
				sprintf(buf, "%s %d", Book, Minus_BookCount(OneLine, Book));
				
				p_temp = strstr(OneLine, Book);
				find_word = strlen(OneLine) - (p_temp - OneLine) + 1; //p_temp���� find_word���� ���� �ٽ� �����ϱ�!
				fseek(fs, -1 * find_word, SEEK_CUR);
				fwrite(buf, sizeof(Book) - 1, 1, fs); //fwrite(,�� ���� ���� ũ�⿴��,,)
				fseek(fs, find_word - sizeof(Book) - 1, SEEK_CUR);
				break;
			}
		}
		
	}
	fclose(fs);

}





int Plus_BookCount(char*OneLine,char* Book) {     //�ݳ� �Ǽ� ����

	if (strstr(OneLine, Book) != NULL) {
		char* pos;
		pos = strpbrk(OneLine, " ");
		pos++;
		int Plus_BookCount = atoi(pos);
		return Plus_BookCount + 1;
	}
}

int Minus_BookCount(char* OneLine, char* Book) {     //���� �Ǽ� ����

	if (strstr(OneLine, Book) != NULL) {
		char* pos;
		pos = strpbrk(OneLine, " ");
		pos++;
		int Minus_BookCount = atoi(pos);
		return Minus_BookCount - 1;
	}
}





void MaxBook() { // �迭�� ����ִ� �Լ� MaxBookarry ��� �迭�� ����.
	char strr[50] = "Garbage"; //�ʱ�ȭ
	int LineNumm = 0; //�ʱ�ȭ

	FILE* fx;
	fx = fopen("C:\\Users\\�պ���\\source\\repos\\GaonProject\\GaonProject\\BookList.txt", "r+");
	if (fx == NULL) {
		printf("������ �����ϴ�. ���α׷��� �����մϴ�.");
		return 0;
	}

	while (fgets(strr, sizeof(strr), fx) != NULL) {
		char* pos;
		pos = strpbrk(strr, " ");
		pos++;
		MaxBookarry[LineNumm] = atoi(pos);  //�ƽ�Ű�ڵ带 int������ �ٲٴ� �Լ�  atoi(pos)= å ��
		LineNumm++;
	}


	fclose(fx);

}
