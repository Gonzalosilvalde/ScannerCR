#include <stdio.h>



#define MAX_STUDENTS 3
#define MAX_SUBJECTS 3

struct Student {
    char name[50];
    int id;
    float grades[MAX_SUBJECTS];
    float average;
};

void calculateAverage(struct Student *student) {
    float sum = 0;
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        sum += student1->grades[i];
    }
    student->average = sum / MAX_SUBJECTS;
}

int main() {
    struct Student students[MAX_STUDENTS];

    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter id of student %d: ", i + 1);
        scanf("%d", &students[i].id);

        printf("Enter grades for student %d:\n", i + 1);
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("Enter grade for subject %d: ", j + 1);
            scanf("%f", &students[i].grades[j]);
        }

        calculateAverage(&students[i]);
    }

    printf("\n\nDisplaying Information:\n\n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Name: %s\n", students[i].name);
        printf("ID: %d\n", students[i].id);
        printf("Grades: ");
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("%.2f ", students[i].grades[j]);
        }
        printf("\nAverage: %.2f\n\n", students[i].average);
    }

    return 0;
}
