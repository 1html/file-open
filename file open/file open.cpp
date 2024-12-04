#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct Student {
    char id[20];      // �й�
    char name[50];    // �̸�
    char address[100];// �ּ�
    char phone[15];   // ��ȭ��ȣ
    int major[3];     // ���� ����
    int elective[3];  // ���� ����
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
    snprintf(filename, sizeof(filename), "%s.txt", student->name); // �̸� ��� ���ϸ� ����

    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("%s ������ �� �� �����ϴ�.\n", filename);
        return;
    }

    // �й�, �̸� �� ���Ͽ� ������ ����
    fprintf(file, "�й�: %s\n", student->id);
    fprintf(file, "�̸�: %s\n", student->name);
    fprintf(file, "�ּ�: %s\n", student->address);
    fprintf(file, "��ȭ��ȣ: %s\n", student->phone);

    char majorGrades[3], electiveGrades[3];
    for (int i = 0; i < 3; i++) {
        majorGrades[i] = getGrade(student->major[i]);
        electiveGrades[i] = getGrade(student->elective[i]);
    }

    fprintf(file, "���� ���� �� ����: %d(%c), %d(%c), %d(%c)\n",
        student->major[0], majorGrades[0],
        student->major[1], majorGrades[1],
        student->major[2], majorGrades[2]);

    fprintf(file, "���� ���� �� ����: %d(%c), %d(%c), %d(%c)\n",
        student->elective[0], electiveGrades[0],
        student->elective[1], electiveGrades[1],
        student->elective[2], electiveGrades[2]);

    float gpa = calculateGPA(majorGrades, electiveGrades);
    fprintf(file, "��ü GPA (����): %.2f\n", gpa);

    fclose(file);
}

void displayStudentDataFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("����� �ƴմϴ�.\n");
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
        {"20221397", "��ö��", "����� ������", "010-1234-5678", {85, 90, 95}, {80, 85, 88}},
        {"20231398", "�̿���", "�λ�� �ؿ�뱸", "010-8765-4321", {78, 85, 80}, {75, 80, 79}},
        {"20211399", "�ڹμ�", "�뱸�� �߱�", "010-1111-2222", {92, 88, 91}, {81, 77, 80}},
        {"20231400", "�ּ���", "��õ�� ������", "010-3333-4444", {85, 89, 87}, {78, 82, 81}},
        {"20241401", "������", "������ ����", "010-5555-6666", {83, 86, 88}, {79, 81, 84}},
        {"20231402", "������", "���ֽ� �ϱ�", "010-7777-8888", {90, 91, 89}, {85, 88, 87}},
        {"20241403", "���Ѱ�", "���� ����", "010-9999-0000", {75, 80, 77}, {70, 75, 78}},
        {"20221404", "�̼���", "��⵵ ������", "010-1234-5670", {82, 88, 84}, {81, 76, 79}},
        {"20221405", "��ξ�", "���ֵ� ���ֽ�", "010-5555-0000", {88, 90, 85}, {83, 84, 80}},
        {"20221406", "�ڼ�ȣ", "���ϵ� ���׽�", "010-1111-3333", {91, 87, 89}, {78, 82, 80}},
        {"20221407", "������", "���󳲵� ������", "010-4444-5555", {86, 90, 85}, {77, 80, 79}},
        {"20221408", "������", "��û�ϵ� û�ֽ�", "010-6666-7777", {84, 85, 87}, {82, 78, 80}},
        {"20221409", "�̵���", "������ ��õ��", "010-8888-9999", {79, 81, 83}, {75, 80, 78}},
        {"20221410", "������", "��⵵ ������", "010-1010-2020", {88, 89, 86}, {83, 79, 82}},
        {"20221411", "������", "����ϵ� ���ֽ�", "010-3030-4040", {90, 92, 91}, {85, 88, 87}},
        {"20211412", "������", "��󳲵� â����", "010-5050-6060", {87, 85, 83}, {80, 78, 82}},
        {"20221413", "������", "����� ���ʱ�", "010-7070-8080", {91, 93, 90}, {86, 87, 85}},
        {"20221414", "�̼���", "��õ�� ������", "010-9090-1010", {80, 85, 82}, {79, 76, 78}},
        {"20221415", "������", "�λ�� �ϱ�", "010-1212-3434", {85, 87, 88}, {81, 82, 83}},
        {"20221416", "������", "������ �߱�", "010-5656-7878", {88, 84, 86}, {80, 79, 81}},
        {"20221417", "������", "���ֽ� ����", "010-9090-1212", {89, 90, 91}, {85, 84, 83}},
        {"20221418", "������", "���ϵ� ���ֽ�", "010-4545-6767", {80, 82, 81}, {78, 75, 79}},
        {"20221419", "�ڼ���", "��û���� �ƻ��", "010-8888-3333", {83, 85, 84}, {81, 82, 80}},
        {"20221420", "������", "���ֵ� ��������", "010-2121-3434", {78, 79, 80}, {76, 78, 75}},
        {"20221421", "�ֹ���", "����� ���ϱ�", "010-7878-9090", {85, 87, 89}, {80, 79, 78}},
        {"20221422", "�̽ÿ�", "�뱸�� ����", "010-6060-7070", {88, 85, 87}, {79, 81, 82}},
        {"20221423", "���ٺ�", "��⵵ ����", "010-2323-4545", {82, 83, 84}, {78, 77, 80}},
        {"20221424", "�ѵ���", "���� ����", "010-1111-5656", {90, 92, 89}, {85, 88, 87}},
        {"20221425", "������", "�λ�� ���ϱ�", "010-4444-2323", {87, 86, 85}, {80, 78, 81}},
        {"20221426", "����ȣ", "���󳲵� ������", "010-9999-1212", {82, 81, 83}, {77, 76, 78}}
    };

    // ��� �л� ������ ���Ϸ� ����
    for (int i = 0; i < studentCount; i++) {
        saveStudentDataToFile(&students[i]);
    }

    char searchName[50];
    char continueChoice[10];
    do {
        printf("\n��ȸ�� �л��� �̸��� �Է��ϼ���: ");
        scanf("%s", searchName);

        char filename[60];
        snprintf(filename, sizeof(filename), "%s.txt", searchName); // �̸� ��� ���ϸ� ����
        printf("\n%s �л��� ����:\n", searchName);
        displayStudentDataFromFile(filename);

        printf("\n�� ��ȸ�Ͻðڽ��ϱ�? (y/n): ");
        scanf("%s", continueChoice);
    } while (strcmp(continueChoice, "y") == 0);

    printf("���α׷��� �����մϴ�.\n");

    return 0;
}
