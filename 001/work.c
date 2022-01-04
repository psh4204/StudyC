#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc, free �� ���� ���̺귯��
#include <windows.h>

// stack
// function : push, pop, size, isEmpty
// stack size 10
// push pop function���� ���� size�� ���� ����ó��
// stack�� �迭�� �����ϰ� ������ġ�� main�Լ� ����

#define UC unsigned char

// �Լ�
void push(UC*, int); void pop(UC*, int ); void size(UC* , int); void isEmpty(UC*, int);
// ��������


// Main ��
int main() {
	int input = 0;
	printf(" ���ϴ� ���û����� �Է� : ");
	scanf("%d", &input);
	// TODO : ����ó��
	int sizeOfArray = input;
	UC* stack = (UC*)malloc(input * sizeof(UC));// ���� ����
	printf("%d", sizeOfArray);
	input = 0;
	int i = 0;
	// �ʱ�ȭ ���ִ°� �������̴�.
	for (i = 0; i < sizeOfArray; i++) {
		stack[i] = NULL;
	}


	// GUI
	while (1) {
		puts(" ");
		puts(" 1. push");
		puts(" 2. pop");
		puts(" 3. size");
		puts(" 4. isEmpty");
		puts(" 5. close \n");
		for (i = sizeOfArray-1 ; i >= 0 ; i--) {
			if(stack[i] == NULL)
				printf(" [  ]");
			else 			
				printf(" [%d]", stack[i]);
		}
		puts("\n\n");
		printf(" �Է� �� >> ");
		scanf("%d", &input);
		switch (input) {
		case 1: system("cls"); push(stack, sizeOfArray); break;
		case 2: system("cls"); pop(stack, sizeOfArray); break;
		case 3: system("cls"); size(stack, sizeOfArray); break;
		case 4: system("cls"); isEmpty(stack, sizeOfArray); break;
		case 5: system("cls"); free(stack, sizeOfArray);  return 0;
		default: system("cls"); continue;
		}
	}

	free(stack);
	return 0;
}


void push(UC* stack, int sizeOfArray) {
	printf("[PUSH]");
	// ���� �Է� ��
	int num = 0;
	printf(" ������ ���ڸ� �Է��ϼ��� >> ");
	scanf("%d", &num);

	// ������ üũ
	int stackSize = sizeOfArray;
	// �տ������� �� �ִ��� Ȯ���� �� �ֱ�
	int i = 0;
	for (i = 0; i < stackSize; i++) {
		if (stack[i] == NULL) {
			stack[i] = (UC)num;
			break;
		}
	}
}

void pop(UC* stack, int sizeOfArray) {
	printf("[POP]");
	
	// ������ üũ
	int stackSize = sizeOfArray;

	// �ڿ��� ���� �� �ֳ� ����
	int i = 0;
	for (i = stackSize - 1; i >= 0; i--) {
		// ����� ����ֱ�
		if (stack[i] != NULL) {
			printf(" Delte >> %d ", (int)stack[i]);
			stack[i] = NULL;
			break;
		}
	}
}

void size(UC* stack, int sizeOfArray) {
	printf("[SIZE]");
	// ������ üũ
	int stackSize = sizeOfArray;

	// �տ������� ������ �� �� ������ ���� ī��Ʈ �� ���
	int i = 0;
	for (i = 0; i < stackSize; i++) {
		if (stack[i] == NULL) {
			break;
		}
	}
	printf(" Stack Size >> %d", i);

}

void isEmpty(UC* stack, int sizeOfArray) {
	printf("[isEmpty]");
	// ������ üũ
	int stackSize = sizeOfArray;

	// �ڿ��� ���� �ձ��� ���ֳ� üũ
	int i = 0;
	for (i = stackSize-1; i >= 0; i--) {
		if (stack[i] != NULL) {
			printf(" ���� ���� ");
			break;
		}
		else if (i == 0) {
			printf(" ���� ���� ");
		}
	}
}
