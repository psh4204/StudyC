#include <stdio.h>
#include <stdlib.h>

#define TEST5

// 구조체 안의 구조체
#ifdef TEST1
struct employee{
	int age;
	int salary;
};

struct company{
	struct employee data;
	char name[10];
};

// char배열에 문자열상수 입력 함수
char copy_str(char * dest, const char * src);

int main(){
	struct company Kim;

	copy_str(Kim.name, "Baby");
	Kim.data.age = 31;
	Kim.data.salary = 3000000;

	printf("Kim's name : %s\n", Kim.name);
	printf("Kim's age : %d \n", Kim.data.age);
	printf("Kim's salary : %d/year",Kim.data.salary);

	return 0;
}

// char배열에 문자열상수 입력 함수
char copy_str(char * dest, const char * src){
	while(*src){
		*dest = *src;
		dest++;
		src++;
	}
	*dest = NULL;
	
	return 1;
}

#endif

// 구조체를 리턴하는 함수
#ifdef TEST2
struct AA function(int k);
struct AA{
	int i;
};

int main(){
	struct AA a;
	a = function(10);
	printf("a.i : %d: \n",a.i);

	return 0;
}

struct AA function(int k){
	struct AA A;
	A.i = k;
	return A;
}

#endif

// 구조체 변수의 정의 방법1
#ifdef TEST3

char copy_str(char * dest, char *src);
int Print_Obj_Status(struct obj OBJ);
struct obj{
	char name[20];
	int x,y;
} Ball;

int main(){
	Ball.x = 3;
	Ball.y = 4;
	copy_str(Ball.name, "RED BALL");

	Print_Obj_Status(Ball);

	return 0;
}

int Print_Obj_Status(struct obj OBJ){
	printf("Location of %s \n", OBJ.name);
	printf("(%d , %d) \n", OBJ.x , OBJ.y);

	return 0 ;
}

char copy_str(char *dest, char * src){
	while(*src){
		*dest = *src;
		dest++;
		src++;
	}
	*dest = NULL;
	
	return 1;
}
#endif 


// 구조체 변수의 정의 방법2
#ifdef TEST4

int Print_Status(struct HUMAN human);
struct HUMAN{
	int age;
	int height;
	int weight;
	int gender;
};

int main(){
	// 이런식으로도 초기화 가능
	struct HUMAN Adam = {31, 182,75, 0};
	struct HUMAN Eve = {27, 166, 48, 1};

	Print_Status(Adam);
	Print_Status(Eve);
}

int Print_Status(struct HUMAN human){
  if (human.gender == 0) {
    printf("MALE \n");
  } else {
    printf("FEMALE \n");
  }

  printf("AGE : %d / Height : %d / Weight : %d \n", human.age, human.height,
         human.weight);

  if (human.gender == 0 && human.height >= 180) {
    printf("HE IS A WINNER!! \n");
  } else if (human.gender == 0 && human.height < 180) {
    printf("HE IS A LOSER!! \n");
  }

  printf("------------------------------------------- \n");
	return 0;
}

#endif 

// Enum1
#ifdef TEST5
// enum에 값들을 초기화 없이 넣으면 0부터 차례로 번호가 주어진다.
int Print_Status(struct HUMAN human);
enum { RED = 3, BLUE, WHITE = 3, BLACK };

int main(){
	int palette = BLACK;
	switch(palette){
	case RED:
		printf("palette : RED %d\n", RED);
		break;
	case BLUE:
		printf("palette : BLUE %d\n", BLUE);
		break;
	}
}
#endif 

#ifdef TEST3
#include <string.h> // 문자열 관련 기본 라이브러리
int main(){
	char str1[20] = {"hi"};
	char str2[20] = {"hello every1"};
	char str3[20] = {"hi"};

	// 문자열 검사
	if(!strcmp(str1, str2)){
		printf("%s and %s equal \n", str1, str2);
	} else{
		printf("%s and %s is NOT equal\n", str1, str2);
	}
	if(!strcmp(str1, str3)){
		printf("%s and %s equal \n", str1, str3);
	} else{
		printf("%s and %s is NOT equal\n", str1, str3);
	}

	return 0;
}
#endif

// 구조체 동적할당
#ifdef TEST6
struct Something {
	int a,b;
};

int main(){
	struct Something *arr;
	int size, i;

	printf("원하시는 구조체 배열 크기 : ");
	scanf("%d", &size);

	arr = (struct Something *)malloc(sizeof(struct Something)* size);

	for(i = 0; i< size; i++){
		printf("arr[%d].a : ", i);
		scanf("%d", &arr[i].a);
		printf("arr[%d].b : ", i);
		scanf("%d", &arr[i].b);
	}

	for(i = 0; i<size; i++){
		printf("arr[%d].a : %d, arr[%d].b : %d \n", i, arr[i].a,i, arr[i].b);
	}

	free(arr);
}

#endif
