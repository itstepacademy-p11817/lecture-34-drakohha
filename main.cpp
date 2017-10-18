#include<stdarg.h>
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fun_numbers(int num, ...) {
	va_list valist;
	int temp = 0;
	int rez = 0;
	va_start(valist, num);
	for (int i = 0; i < num; i++) {
		temp = va_arg(valist, int);
		if (temp == 1 || temp == 3 || temp == 5 || temp == 7 || temp == 11) {
			rez++;
		}
	}
	va_end(valist);
	return rez;
}



int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Rus");
	int flag_menu = 0;
	int num_ch = 0;
	int num_n_ch = 0;
	printf("Введите номер задания :");
	scanf_s("%d", &flag_menu);
	switch (flag_menu){
	case 1: {
		printf("\n Задача номер 1 : \n ");
		int rez = 0;
		printf("\n Дано : 1,3,7,8,9");
	
		rez = fun_numbers(5, 1, 3, 7, 8, 9);
		printf("\n Количество простых чисел =%d\n", rez);
		break;
	}
	case 2: {
		for (int i = 0; i < argc; i++) {
			if (*argv[i] % 2 == 0) {
				num_ch++;
			}
			else {
				num_n_ch++;
			}
			
		}
		if (num_ch > num_n_ch) {
			printf("\n Четных больше \n");

		}
		else if (num_ch == num_n_ch) {
			printf("\n Равное количество четных и нечетных \n");
		}
		else {
			printf("\n Нечетных больше \n");
		}
		break;
	}
	case 3: {
		char buffer;
		
		int ind = 0;
		FILE *fp;
		fopen_s(&fp, "file1.txt", "r");
		FILE *fp_2; 
		fopen_s(&fp_2, "file2.txt", "w+");
		if (fp != NULL) {
			fseek(fp, 0, SEEK_SET);
			fseek(fp_2, 0, SEEK_SET);
			while (fscanf_s(fp, "%s", &buffer) != -1) {
				fscanf_s(fp, "%s", &buffer);
				fprintf(fp_2, "%s", buffer);
				ind++;
				fseek(fp, ind, SEEK_SET);
				fseek(fp_2, ind, SEEK_SET);
			}
		fclose(fp);
		fclose(fp_2);

		}
		else {
			printf("Не удалось открыть файл");
		}
		
		break;
	}
	case 4: {
		char buffer;

		int ind = 0;
		FILE *fp;
		fopen_s(&fp, "file1.txt", "r");
		FILE *fp_2;
		fopen_s(&fp_2, "file2.txt", "w+");
		if (fp != NULL) {
			fseek(fp, 0, SEEK_SET);
			fseek(fp_2, 0, SEEK_SET);
			while (fscanf_s(fp, "%s", &buffer) != -1) {
				fscanf_s(fp, "%s", &buffer);
				fprintf(fp_2, "%s", buffer);
				ind++;
				fseek(fp, ind, SEEK_SET);
				fseek(fp_2, ind, SEEK_SET);
			}
			fclose(fp);
			fclose(fp_2);

		}
		else {
			printf("Не удалось открыть файл");
		}

		break;

	}
	case 5: {

	}
	case 6: {

	}
	default: {
		printf("Нету такого :(");
		break;
	}
	}
	system("pause");
	return 0;
}