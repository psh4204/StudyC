#include <stdio.h>
#include <stdlib.h>

#define TEST4

// 구조체 예제1
#ifdef TEST1
// const : 상수
char copy_str(char *dest, const char *src);

struct Books{
	char name[30];
	char auth[30];
	char publ[30];
	int borrowed;
};

int main(){
	struct Books Harry2;
	
	// '구조체 멤버변수'에 '문자열 상수' 넣기.
	copy_str(Harry2.name, "Harry Potter");
	copy_str(Harry2.auth, "J.K");
	copy_str(Harry2.publ, "Scholastic");

	puts("-------- Harry2 --------");
	printf("책이름 : %s, \n", Harry2.name);
	printf("저자 : %s \n", Harry2.auth);
	printf("출판사 : %s \n", Harry2.publ);
	

	return 0;
}

char copy_str(char *dest, const char *src){
	// 문자열 상수에 문자가 NULL이 나올때 까지 반복
	while (*src){
		// 구조체 멤버에 문자가 하나씩 들어간다.
		*dest = *src;
		// 각 주소들을 한칸씩 움직인다.
		src++;
		dest++;
	}
	// 구조체 멤버변수를 문자열화 하려고 마지막 NULL 삽입
	*dest = '\0';
	
	// 함수 정상 종료, 인자 존재함
	return 1;
}

#endif

// 구조체 포인터 예제1
#ifdef TEST2
/*

* 포인터는 포인터다.
* 구조체 형으로 포인터를 선언한 거여서,
그 구조체에 맞는 주소그릇이 하나 생긴것. 그게 전부
* (*구조체포인터변수).멤버 = 구조체포인터변수 -> 멤버

*/
struct test {
	int a, b;
};

int main(){
	struct test st;
	struct test *ptr;

	ptr = &st;

	(*ptr).a = 1;
	ptr->b = 2;

	printf("st의 a 멤버 : %d \n", st.a);
	printf("st의 b 멤버 : %d \n", st.b);

	return 0;
}

#endif


// 구조체 포인터 예제2
#ifdef TEST3
struct TEST{
	int c;
};

int main()
{
	struct TEST t;
	struct TEST *pt = &t;

	(*pt).c = 0; // pt->c = 0

	printf("t.c : %d \n", t.c);

	return 0;
}
#endif


// 구조체 포인터 예제3
#ifdef TEST4
struct TEST{
	int c;
	int *pointer;
};

int main()
{
	struct TEST t;
	struct TEST *pt = &t;
	int i = 0;

	// t의 멤버 pointer가 i를 가리키게 한다.
	pt->pointer = &i;

	i = 3;
	// -> 가 * 보다 우선순위가 높기 때문에 가능한 코드
	// *(pt->pointer)
	printf("i : %d \n", *pt->pointer);

	return 0;
}
#endif
