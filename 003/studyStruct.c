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

// 링크드리스트 (노드)예제
// - 노드, 생성, 삽입, 삭제
#ifdef TEST7
// 노드 구조체
struct Node{
	int data;				// 데이터
	struct Node * nextNode;	// 다음 노드 위치
};

struct Node* CreateNode(int data);
struct Node* InsertNode(struct Node * current, int data);
void DestoryNode(struct Node * destroy, struct Node *head);
void PrintNodeFrom(struct Node * from);

// main
int main(){
	struct Node* Node1 = CreateNode(100);
	struct Node* Node2 = InsertNode(Node1, 200);
	struct Node* Node3 = InsertNode(Node2, 300);
	
	/* Node 2 뒤에 Node4 넣기 */
	struct Node* Node4 = InsertNode(Node2, 400);
	PrintNodeFrom(Node1);
	return 0;
}

// 노드 생성 함수
struct Node* CreateNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->nextNode = NULL;
	return newNode;
}

// current Node 뒤에 노드를 새로 만들어 넣는 함수
struct Node* InsertNode(struct Node * current, int data){
	// current Node의 다음노드를 newNode의 다음 노드로 할 예정
	struct Node* after = current->nextNode;

	// 새로운 노드를 생성
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	// 새로운 노드에 값을 넣어준다.
	newNode->data = data;
	newNode->nextNode = after;

	// current Node의 다음노드는 newNode
	current->nextNode = newNode;

	return newNode;
}

// 선택된 노드 삭제 함수
// Head 노드부터 차례로 내려가서 destroy Node단까지 찾은 후 삭제처리
void DestoryNode(struct Node * destroy, struct Node *head){
	// 다음 노드를 가리킬 커서
	struct Node * cursor = head;

	// head Node를 파괴하려 한다면
	if(destroy == head){
		free(destroy);
		return;
	}

	// detroy앞에 있는 노드를 찾는 과정(head가 커서역할)
	// 만약 next가 NULL 이면 종료
	while(cursor){
		// 만일 cursor 다음 노드가 destroy 라면 next 가 destory 앞 노드라면
		if(cursor->nextNode == destroy){
			// destory 노드의 nextNode를 준다.
			cursor->nextNode = destroy->nextNode;
		}
		// next는 다음노드를 가리킨다.
		cursor = cursor->nextNode;
	}
	free(destroy);
}

void PrintNodeFrom(struct Node * from){
	// from 이 NULL일때 까지 출력
	while(from){
		printf("노드 데이터 :%d \n", from->data);
		from = from->nextNode;
	}
}

#endif

// 메모리 관련 함수1. memcpy
#ifdef TEST8
int main()
{
	char str[50] = "I love Chewing C hahaha"
	char str2[50];
	char str3[50];

	// 메모리 크기만큼 복사해주는 함수
	// - strcpy 대체제로 사용가
	// - 문자열길이 + 1  :  C는 문자열 뒤에 \0이 있어야 문자열로 인식하고, 항상있음
	memcpy(str2, str, strlen(str) + 1);
	memcpy(str3, "hello", 6);

	printf("%s \n", str);
	printf("%s \n", str2);
	printf("%s \n", str3);
}

#endif
