#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc, free 를 위한 라이브러리
#include <windows.h>

// stack
// function : push, pop, size, isEmpty
// stack size 10
// push pop function에서 현재 size에 따른 예외처리
// stack은 배열로 선언하고 선언위치는 main함수 내부

#define UC unsigned char

// 함수
void push(UC*, int); void pop(UC*, int ); void size(UC* , int); void isEmpty(UC*, int);
// 전역변수


// Main 문
int main() {
	int input = 0;
	printf(" 원하는 스택사이즈 입력 : ");
	scanf("%d", &input);
	// TODO : 예외처리
	int sizeOfArray = input;
	UC* stack = (UC*)malloc(input * sizeof(UC));// 스택 선언
	printf("%d", sizeOfArray);
	input = 0;
	int i = 0;
	// 초기화 해주는게 안정적이다.
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
		printf(" 입력 란 >> ");
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
	// 숫자 입력 란
	int num = 0;
	printf(" 삽입할 숫자를 입력하세요 >> ");
	scanf("%d", &num);

	// 사이즈 체크
	int stackSize = sizeOfArray;
	// 앞에서부터 빈값 있는지 확인후 값 넣기
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
	
	// 사이즈 체크
	int stackSize = sizeOfArray;

	// 뒤에서 부터 빈값 있나 보기
	int i = 0;
	for (i = stackSize - 1; i >= 0; i--) {
		// 지우고 띄워주기
		if (stack[i] != NULL) {
			printf(" Delte >> %d ", (int)stack[i]);
			stack[i] = NULL;
			break;
		}
	}
}

void size(UC* stack, int sizeOfArray) {
	printf("[SIZE]");
	// 사이즈 체크
	int stackSize = sizeOfArray;

	// 앞에서부터 끝까지 빈 값 있을때 까지 카운트 후 출력
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
	// 사이즈 체크
	int stackSize = sizeOfArray;

	// 뒤에서 부터 앞까지 빈값있나 체크
	int i = 0;
	for (i = stackSize-1; i >= 0; i--) {
		if (stack[i] != NULL) {
			printf(" 값이 있음 ");
			break;
		}
		else if (i == 0) {
			printf(" 값이 없음 ");
		}
	}
}
