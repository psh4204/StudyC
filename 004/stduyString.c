#define _CRT_SECURE_NO_WARNINGS // strtok 보안문제 있음.
#include <stdio.h>
// strtok이용해보기
// strtok( 문자열 , 구분자 ) // 문자열에서 구분자까지 커서가 이동하여 구분자를 NULL로 변환
// - 이때 반환형은 문자열 주소
// strtok( NULL, 구분자 ) // 이전에 strtok때 사용된 NULL 주소를 시작 커서로 둔다. 그리고 strtok진행
// - 정말 특이하다.
#include <string.h>
#include <stdlib.h>
typedef struct data {
	char* s; //문자열공간
	int num;
} DATA;

int main() {
	DATA data;
	char str[50];
	char* ptr;
	int num = 0;
	int i = 0;

	printf("문자열 숫자 : ");
	gets(str);
	ptr = strtok(str, " ,._-");

	while (*ptr != NULL) {
		switch (i) {
		case 0 : 
			data.s = ptr;
			printf("%s \n", data.s);
			break;
		case 1 :
			// 문자 1 은 int 31.
			// 문자형숫자를 숫자형로 바꾸고싶으면 atoi()
			// 숫자형를 문자형숫자로 바꾸고싶으면 itoa()
			// 숫자형을 문자형숫자로 바꾸고싶으념 sprintf()
			// - 문자열은 주소값만 가지고 쓰이는 친구.(\0이 있는지는 컴파일러가 알아서 봄)
			data.num = atoi(ptr);
			printf("%d \n", data.num);
			break;
		}
		ptr = strtok(NULL, " ,.-");
		i++;
	}

	return 0;
}
