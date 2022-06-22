#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int main() {

	char vowels[]{ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	char consonants[]{ 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z', 'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};

	setlocale(LC_ALL, "");
	cout << "Запись статистики в файл" << endl;

	char* file1 = new char[256];
	char* file2 = new char[256];

	cout << "Введите наименование файла 1, из которого будет считываться информация" << endl;
	cin >> file1;
	cout << "Введите наименование файла 2, в который будет записываться статистика файла 1" << endl;
	cin >> file2;

	FILE* f1;
	f1 = fopen(file1, "r");

	if (f1 == NULL) {
		cout << "Невозможно открыть файл " << f1 << endl;
		return 0;
	}

	FILE* f2;
	f2 = fopen(file2, "a");

	if (f2 == NULL) {
		cout << "Невозможно открыть файл " << f2 << endl;
		return 0;
	}
	
	int count_rows = 0;
	int digits = 0;
	int vows = 0;
	int consons = 0;
	int symbols = 0;
	char c;
	while (!feof(f1)) {
		
		c = fgetc(f1);
		symbols++;
		bool ctrl = true;
		for (size_t i = 0; i < 10; i++) {
			if (c == vowels[i]) {
				vows++;
				ctrl = false;
				break;
			}
		}
		if (ctrl) {
			for (size_t j = 0; j < 42; j++) {
				if (c == consonants[j]) {
					consons++;
					ctrl = false;
					break;
				}
			}
		}
		if (ctrl) {
			if ((int)c > 47 && (int)c < 58) {
				digits++;
				ctrl = false;
			}
		}
		if (ctrl) {
			if (c == '\n') {
				count_rows++;
			}
		}
	}

	fclose(f1);
	
	char* filename = new char[] {"Наименование файла: "};
	strcat(filename, file2);
	fputs(filename, f2);
	char* cvows = new char[20];
	_itoa_s(vows, cvows, 20, 10);
	char* strvows = new char[] {"Количество гласных: "};
	strcat(strvows, cvows);
	fputs(strvows, f2);
	char* ccon = new char[20];
	_itoa_s(consons, ccon, 20, 10);
	char* strcons = new char[] {"Количество согласных: "};
	strcat(strcons, ccon);
	fputs(strcons, f2);
	char* cdigs = new char[20];
	_itoa_s(digits, cdigs, 20, 10);
	char* strdigs = new char[] {"Количество цифр: "};
	strcat(strdigs, cdigs);
	fputs(strdigs, f2);
	char* crows = new char[20];
	_itoa_s(count_rows, crows, 20, 10);
	char* strrows = new char[] {"Количество строк: "};
	strcat(strrows, crows);
	fputs(strrows, f2);
	char* csymbs = new char[20];
	_itoa_s(symbols, csymbs, 20, 10);
	char* strsymbs = new char[] {"Количество согласных: "};
	strcat(strsymbs, csymbs);
	fputs(strsymbs, f2);


	fclose(f2);

	_getch();


	return 0;
}

