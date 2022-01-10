#define _CRT_SECURE_NO_WARNINGS
/* ===============================================================================

22.01.05 숙제
 <학생 과목 처리 시뮬>
1. 학생 학번 0~10 까지 존재
2. 1명에 대한 정보는 A과목에 대한 점수(0~100), 연도(YYYY), 학기(1~2)   3가지
3. 학생을 구분하는 Key는 학번.
* 학번에 대한 구조체로 코딩
* 링크드 리스트 형식으로 구현
* 정보 추가시 학번 중복 확인 예외처리
* 입력할 정보 : 학번, 이름, 점수, 연도, 학기
* 기능 : 확인, 추가, 수정
* - 확인 시, 학생의 과목의 학기별 커서도 필요함

* 예시 )
[학번] [이름] [연도] [학기] [점수]
123 asdf 2022 1 100
>>

---
입력 >>
 ++ 포인트 : 구현보다는 포인터를 공부한다는 마음으로 코딩
 ++ 요약 : 구조체의 주소를 가지고 사용할 수 있는가 없는가 하는 것.
=============================================================================== */

// ( VS 보안설정 끄기 ) : 프로젝트 설정-> C/C++ -> 일반 -> SDL 검사 : 아니요 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
// 변수

/* 과목 A에 관한 정보 구조체 */
typedef struct info_a {
	int year;							// 년도
	int semester;						// 학기
	int score;							// 점수
	struct info_a* next_info;				// 해당 학생의 학기별 과목 A에 대한 커서
} Info_A;

/* 학생에 대한 정보 구조체 */
typedef struct student {
	char name[32];						// 학생 이름
	int id;								// 학생 ID
	struct student* next_student;		// 학생 에 대한 커서
	Info_A* info;						// 과목 A에 대한 커서
} Student;


// 함수
/* 학생 노드 생성 함수 */
Student* createStudent(int id, char * name) {
	Student* newStudent = (Student*)malloc(sizeof(Student));
	
	strcpy(newStudent->name, name);
	newStudent->id = id;
	newStudent->next_student = NULL;
	newStudent->info = NULL;

	return newStudent;
}

/* [학생] 입력 함수 */
void insertStudent(int id, char * name, Student * header) {
	Student* newStudent = createStudent(id, name);
	Student* cursor = header;
	// 커서를 이동시켜 새 입력 노드의 앞이 될 노드를 찾는다.
	while (cursor->next_student != NULL) {
		cursor = cursor->next_student;
	}
	// 커서에 다음 노드를 현재 노드로 바꾼다.
	cursor->next_student = newStudent;

}

/* [학생] 제거 함수 */
void deleteStudent(Student* recent, Student* header) {
	Student* cursor = header;
	// 헤더 노드일 경우 헤더 제거
	if (recent == header) {
		free(header);
		return 0;
	}

	// 제거할 노드의 앞 노드를 찾은 후, 앞노드의 다음노드를 현재노드의 다음노드로 바꾼다.
	while (cursor->next_student != recent) {
		cursor->next_student;
	}
	cursor->next_student = recent->next_student;
	// 현재 노드 삭제
	free(recent);
}

/* [학생] ID 탐색 함수
* PK인 Id를 이용하여 탐색한 후 해당 주소값 반환.
* 없을 시 -1 반환
*/
Student * researchID(int id, Student* header) {
	Student* cursor = header;
	// 하나하나 탐색
	while ((cursor->id != id) || (cursor->next_student != NULL)) {
		cursor = cursor->next_student;
	}
	// 해당아이디 있으면 해당 주소 반환
	if (cursor->id == id)
		return cursor;
	
	// 없으면 -1 반환
	else
		return -1;
	
}

/* [학생] 정보 수정 함수 */ 
void fixName(int id, char * name, Student * header) {
	Student* cursor = researchID(id, header);
	if (cursor == -1) {
		return -1;
	}
	strcpy(cursor->name, name);
}


/* [정보] 헤더 생성  함수 */
void createInfo(Student * student,int year, int semester, int score) {
	Info_A* newinfo_a;
	newinfo_a= (Info_A*)malloc(sizeof(Info_A));
	newinfo_a->year = year;
	newinfo_a->semester = semester;
	newinfo_a->score = score;
	newinfo_a->next_info = NULL;

	student->info = newinfo_a;
}

/* [정보] 생성 함수 */
void createAddInfo(Info_A* prevInfo, int year, int semester, int score) {
	Info_A* newinfo_a;
	newinfo_a = (Info_A*)malloc(sizeof(Info_A));
	newinfo_a->year = year;
	newinfo_a->semester = semester;
	newinfo_a->score = score;
	newinfo_a->next_info = prevInfo->next_info;
	prevInfo->next_info = newinfo_a;
}

/* [정보] 탐색 함수 
* 해당 ID에서 해당 년도와 학기를 찾아주는 함수
* - 찾으면			: info 주소
* - 찾는 값 없으면	: -1
* - id자체가 없으면	: -2 
*/
Info_A* researchInfo(int id, int year, int semester, Student * header) {
	Student* student_cursor = researchID(id, header);
	if (student_cursor == -1) {
		return -2;
	}
	Info_A* cursor = student_cursor->info;
	
	// Info 에서 year과 semester이 같은 값이 나오면, 해당 info주소값 리턴 후 break;
	while (cursor->next_info != NULL) {
		if (cursor->year == year) {
			if (cursor->semester == semester) {
				return cursor;
			}
		}
	}
	// 안나올 경우 return -1;
	return -1;
}

/* [정보] 해당 정보의 앞 정보 유무 확인 함수 
* 해당 정보의 앞정보가 있는지 확인하는 함수이다.
* 앞 정보 : 이전년도, 이전학기
* 리턴값
* - ID가 없으면				: -1
* - Info가 없으면			: -2
* - 커저 중에서 헤더라면	: -3
* - 앞Info 찾았을 시		: 앞 Info 주소
*/
Info_A* checkPrevInfo(int id, int year, int semester, Student* header) {
	// 해당 아이디의 커서를 찾는다.
	Student * student_cursor = researchID(id, header);
	if (student_cursor == -1) {
		return -1;
	}
	// Info의 Head Cursor 지정
	Info_A* cursor = student_cursor->info;
	if (cursor == NULL) {
		return -2;
	}
	// 커서 중에서 헤더커서라면?( 뒤에값 존재 안함 )
	if (cursor->next_info == NULL) {
		return -3;
	}
	while (cursor->next_info->year != year) {
		while (cursor->next_info->semester != semester) {
			if (cursor->next_info->year == semester) {
				return cursor;
			}
			cursor = cursor->next_info;
		}
		cursor = cursor->next_info;
	}
}

/* [정보] 해당 정보의 다음 정보 유무 확인 함수
* 해당 정보의 다음 정보가 있는지 확인하는 함수이다.
* 다음 정보 : 다음학기, 다음년도
*/
Info_A * checkNextInfo(int id, int year, int semester, Student* header) {
	// 해당 아이디의 커서를 찾는다.
	Student* student_cursor = researchID(id, header);
	if (student_cursor == -1) {
		return -1;
	}
	// Info의 Head Cursor 지정
	Info_A* cursor = student_cursor->info;
	if (cursor == NULL) {
		return -2;
	}

	// 해당하는 다음 정보가 있으면 그 다음을 가리키는 주소 리턴
	while (cursor->semester != semester) {
		while (cursor->year != year) {
			if (cursor->year == year) {
				return cursor->next_info;
			}
			cursor = cursor->next_info;
		}
		cursor = cursor->next_info;
	}
}

/* [정보] 입력(추가) 함수 */
void insertInfo(int id, int year, int semester, int score, Student* header) {
	// 해당 Info가 이미 있는지 확인
	Info_A* info = researchInfo(id, year, semester, header);
	if (info == -1) {
		// 없으면 생성
		// - 새로운 Info 생성
		createAddInfo(researchID(id, header), year, semester, score);
	}
	else if(info == -2){
		// 새 Info가 헤더라면? : Info가 없는 상태
		// // - 새로운 Info 생성
		createInfo(researchID(id, header), year, semester, score);
		// - 새로 만든 Info
		info = researchInfo(id, year, semester, header);
	}
	else {
		// 찾는 Info가 있다면
		info->semester = semester;
		info->score = score;
		info->year = year;
	}
}

/* [정보] 제거 함수  
* 해당 정보 값 없음 : -1
* 해당 ID 없음 : -1
* 정상 제거 : 리턴없음
*/
void deleteInfo(int id, int year, int semester, Student* header) {
	Info_A* info = researchInfo(id, year, semester, header);
	if (info == -1 || info == -2) {
		return -1;
	}
	Student* ID = researchID(id, header);
	if (ID == -1) {
		return -2;
	}

	// 앞 노드 찾아서 다음노드 바꾸기
	Info_A * prev_info = ID->info;
	while (prev_info->next_info != info) {
		prev_info = prev_info;
	}
	prev_info->next_info = info->next_info;
	
	// 메모리 해제
	free(info);
}

/* 해당 과목 ID 전체 출력 */
void printID(Student* header) {
	Student* cursor = header;
	puts("[학번]\t[이름]");
	while (cursor->next_student != NULL) {
		printf("[%d]\t[%s]\n",cursor->id,cursor->name);
		cursor = cursor->next_student;
	}
	puts("--<끝>--");
}

/* 해당 ID 정보 전체 출력 */
void printInfo(Student* header, int id) {
	Student * cursor_id = researchID(id, header);
	if (cursor_id == -1) {
		return -1;
	}
	Info_A* cursor_info = cursor_id->info;
	puts("[학번]\t[이름]\t[연도]\[학기]\t[점수]");
	while (cursor_info->next_info != NULL) {
		printf("[%d]\t[%s]\t[%d]\t[%d]\t[%d]\n", cursor_id->id, cursor_id->name, cursor_info->year, cursor_info->semester, cursor_info->score);
		cursor_info = cursor_info->next_info;
	}
	puts("--<끝>--");
}

// Main문

/* 구조체 변수 생성 */
Student* list_header;

int main() {
	Student* cursor = NULL;
	char* ptr = NULL;
	char* cmd = NULL;
	char * name = NULL; 
	int id = 0; 
	int score = 0;
	int semester = 0;
	int year = 0;
	int i = 0;

	list_header = createStudent(0,"root");
	printf("[A과목에 대한 학생 점수리스트]");
	while (1) {
		printf("명령어 입력 > ");
		scanf("%s", cmd);
		if (strcmp(cmd,"help") == 0) {
			system("cls");
			printf("[HELP]\n");
			printf("--------------------\n");
			printf("ID 입력\t: inputID\n");
			printf("성적 입력\t: inputScore\n");
			printf("ID 삭제\t: deleteID\n");
			printf("성적 삭제\t: deleteScore\n");
			printf("ID 리스트 출력 : printID\n");
			printf("성적 리스트 출력 : printScore\n");
			printf("--------------------\n");
		}
		else if (strcmp(cmd, "inputID") == 0) {
			system("cls");
			printf("ID, 이름을 입력하시오>");
			puts("%s", cmd);
			ptr = strtok(cmd, " ,._ -");
			i = 0;
			while (* ptr != NULL) {
				switch (i) {
				case 0: 
					id = atoi(ptr);
					break;
				case 1:
					name = ptr;
					break;
				default:break;
				}
				ptr = strtok(NULL, " ,");
			}
			insertStudent(id, name, list_header);
		}
		else if (strcmp(cmd, "inputScore") == 0) {
			system("cls");
			printf("ID, 년도, 학기, 점수를 입력하시오>");
			puts("%s", cmd);
			ptr = strtok(cmd, " ,._ -");
			i = 0;
			while (*ptr != NULL) {
				switch (i) {
				case 0:
					id = atoi(ptr);
					break;
				case 1:
					year = ptr;
					break;
				case 2:
					semester = ptr;
					break;
				case 3:
					score = ptr;
					break;
				default:break;
				}
				ptr = strtok(NULL, " ,");
			}
			insertInfo(id, year, semester, score, list_header);
		}
		else if (strcmp(cmd, "deleteID") == 0) {
			system("cls");
			printf("삭제 할 ID 입력>");
			puts("%s", cmd);
			ptr = strtok(cmd, " ,._ -");
			i = 0;
			while (*ptr != NULL) {
				switch (i) {
				case 0:
					id = atoi(ptr);
					break;
				default:break;
				}
				ptr = strtok(NULL, " ,");
			}
			cursor = researchID(id, list_header);
			deleteStudent(cursor, list_header);
		}
		else if (strcmp(cmd, "deleteScore") == 0) {
			system("cls");
			printf("삭제할 ID, 년도, 학기 입력>");
			puts("%s", cmd);
			ptr = strtok(cmd, " ,._ -");
			i = 0;
			while (*ptr != NULL) {
				switch (i) {
				case 0:
					id = atoi(ptr);
					break;
				case 1:
					year = ptr;
					break;
				case 2:
					semester = ptr;
					break;
				default:break;
				}
				ptr = strtok(NULL, " ,");
			}
			deleteInfo(id, year, semester, list_header);
		}
		else if (strcmp(cmd, "printID") == 0) {
			system("cls");
			printID(list_header);
		}
		else if (strcmp(cmd, "printScore") == 0) {
			system("cls");
			printf("점수를 볼 ID 입력>");
			puts("%s", cmd);
			ptr = strtok(cmd, " ,._ -");
			i = 0;
			while (*ptr != NULL) {
				switch (i) {
				case 0:
					id = atoi(ptr);
					break;
				default:break;
				}
				ptr = strtok(NULL, " ,");
			}
			printInfo(list_header, id);
			
		}
		else {
			system("cls");
			printf("[HELP]\n");
			printf("--------------------\n");
			printf("ID 입력\t: inputID\n");
			printf("성적 입력\t: inputScore\n");
			printf("ID 삭제\t: deleteID\n");
			printf("성적 삭제\t: deleteScore\n");
			printf("ID 리스트 출력 : printID\n");
			printf("성적 리스트 출력 : printScore\n");
			printf("--------------------\n");
		}
	}
	return 0;
}
