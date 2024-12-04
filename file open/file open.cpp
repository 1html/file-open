#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct Student {
    char id[20];      // 학번
    char name[50];    // 이름
    char address[100];// 주소
    char phone[15];   // 전화번호
    int major[3];     // 전공 점수
    int elective[3];  // 교양 점수
};

char getGrade(int score) {
    if (score >= 90) return 'A';
    else if (score >= 80) return 'B';
    else if (score >= 70) return 'C';
    else if (score >= 60) return 'D';
    else return 'F';
}

float gradeToPoint(char grade) {
    switch (grade) {
    case 'A': return 4.5;
    case 'B': return 3.5;
    case 'C': return 2.5;
    case 'D': return 1.5;
    case 'F': return 0.0;
    default: return 0.0;
    }
}

float calculateGPA(char majorGrades[], char electiveGrades[]) {
    float totalPoints = 0.0;
    for (int i = 0; i < 3; i++) {
        totalPoints += gradeToPoint(majorGrades[i]);
        totalPoints += gradeToPoint(electiveGrades[i]);
    }
    return totalPoints / 6;
}

void saveStudentDataToFile(struct Student* student) {
    char filename[60];
    snprintf(filename, sizeof(filename), "%s.txt", student->name); // 이름 기반 파일명 생성

    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("%s 파일을 열 수 없습니다.\n", filename);
        return;
    }

    // 학번, 이름 등 파일에 데이터 저장
    fprintf(file, "학번: %s\n", student->id);
    fprintf(file, "이름: %s\n", student->name);
    fprintf(file, "주소: %s\n", student->address);
    fprintf(file, "전화번호: %s\n", student->phone);

    char majorGrades[3], electiveGrades[3];
    for (int i = 0; i < 3; i++) {
        majorGrades[i] = getGrade(student->major[i]);
        electiveGrades[i] = getGrade(student->elective[i]);
    }

    fprintf(file, "전공 점수 및 학점: %d(%c), %d(%c), %d(%c)\n",
        student->major[0], majorGrades[0],
        student->major[1], majorGrades[1],
        student->major[2], majorGrades[2]);

    fprintf(file, "교양 점수 및 학점: %d(%c), %d(%c), %d(%c)\n",
        student->elective[0], electiveGrades[0],
        student->elective[1], electiveGrades[1],
        student->elective[2], electiveGrades[2]);

    float gpa = calculateGPA(majorGrades, electiveGrades);
    fprintf(file, "전체 GPA (학점): %.2f\n", gpa);

    fclose(file);
}

void displayStudentDataFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("멤버가 아닙니다.\n");
        return;
    }

    char line[150];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
}

int main() {
    int studentCount = 30;
    struct Student students[30] = {
        {"20221397", "김철수", "서울시 강남구", "010-1234-5678", {85, 90, 95}, {80, 85, 88}},
        {"20231398", "이영희", "부산시 해운대구", "010-8765-4321", {78, 85, 80}, {75, 80, 79}},
        {"20211399", "박민수", "대구시 중구", "010-1111-2222", {92, 88, 91}, {81, 77, 80}},
        {"20231400", "최수민", "인천시 연수구", "010-3333-4444", {85, 89, 87}, {78, 82, 81}},
        {"20241401", "정다은", "대전시 서구", "010-5555-6666", {83, 86, 88}, {79, 81, 84}},
        {"20231402", "한지민", "광주시 북구", "010-7777-8888", {90, 91, 89}, {85, 88, 87}},
        {"20241403", "강한결", "울산시 남구", "010-9999-0000", {75, 80, 77}, {70, 75, 78}},
        {"20221404", "이소윤", "경기도 수원시", "010-1234-5670", {82, 88, 84}, {81, 76, 79}},
        {"20221405", "김민아", "제주도 제주시", "010-5555-0000", {88, 90, 85}, {83, 84, 80}},
        {"20221406", "박성호", "경상북도 포항시", "010-1111-3333", {91, 87, 89}, {78, 82, 80}},
        {"20221407", "조유진", "전라남도 여수시", "010-4444-5555", {86, 90, 85}, {77, 80, 79}},
        {"20221408", "서진우", "충청북도 청주시", "010-6666-7777", {84, 85, 87}, {82, 78, 80}},
        {"20221409", "이도윤", "강원도 춘천시", "010-8888-9999", {79, 81, 83}, {75, 80, 78}},
        {"20221410", "윤서준", "경기도 성남시", "010-1010-2020", {88, 89, 86}, {83, 79, 82}},
        {"20221411", "최은서", "전라북도 전주시", "010-3030-4040", {90, 92, 91}, {85, 88, 87}},
        {"20211412", "김하준", "경상남도 창원시", "010-5050-6060", {87, 85, 83}, {80, 78, 82}},
        {"20221413", "박은찬", "서울시 서초구", "010-7070-8080", {91, 93, 90}, {86, 87, 85}},
        {"20221414", "이서현", "인천시 남동구", "010-9090-1010", {80, 85, 82}, {79, 76, 78}},
        {"20221415", "정현우", "부산시 북구", "010-1212-3434", {85, 87, 88}, {81, 82, 83}},
        {"20221416", "한유정", "대전시 중구", "010-5656-7878", {88, 84, 86}, {80, 79, 81}},
        {"20221417", "조은서", "광주시 동구", "010-9090-1212", {89, 90, 91}, {85, 84, 83}},
        {"20221418", "강이준", "경상북도 경주시", "010-4545-6767", {80, 82, 81}, {78, 75, 79}},
        {"20221419", "박서영", "충청남도 아산시", "010-8888-3333", {83, 85, 84}, {81, 82, 80}},
        {"20221420", "김지훈", "제주도 서귀포시", "010-2121-3434", {78, 79, 80}, {76, 78, 75}},
        {"20221421", "최민준", "서울시 강북구", "010-7878-9090", {85, 87, 89}, {80, 79, 78}},
        {"20221422", "이시우", "대구시 동구", "010-6060-7070", {88, 85, 87}, {79, 81, 82}},
        {"20221423", "정다빈", "경기도 고양시", "010-2323-4545", {82, 83, 84}, {78, 77, 80}},
        {"20221424", "한도훈", "울산시 동구", "010-1111-5656", {90, 92, 89}, {85, 88, 87}},
        {"20221425", "박현서", "부산시 사하구", "010-4444-2323", {87, 86, 85}, {80, 78, 81}},
        {"20221426", "이준호", "전라남도 목포시", "010-9999-1212", {82, 81, 83}, {77, 76, 78}}
    };

    // 모든 학생 데이터 파일로 저장
    for (int i = 0; i < studentCount; i++) {
        saveStudentDataToFile(&students[i]);
    }

    char searchName[50];
    char continueChoice[10];
    do {
        printf("\n조회할 학생의 이름을 입력하세요: ");
        scanf("%s", searchName);

        char filename[60];
        snprintf(filename, sizeof(filename), "%s.txt", searchName); // 이름 기반 파일명 생성
        printf("\n%s 학생의 정보:\n", searchName);
        displayStudentDataFromFile(filename);

        printf("\n더 조회하시겠습니까? (y/n): ");
        scanf("%s", continueChoice);
    } while (strcmp(continueChoice, "y") == 0);

    printf("프로그램을 종료합니다.\n");

    return 0;
}
