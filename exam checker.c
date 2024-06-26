/*

EXAM CHECKER 
SAME SA MIDTERM EXAM CODECHUM BUT I MADE IT INTO A STRUCT 
NOT SURE AHAHHAHAHAA


NOTE: NO HEADER FILE HEHEHHEEH
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 10 // Maximum number of questions in the exam

// Define a structure to hold each student's information
typedef struct {
    char firstName[50];
    char lastName[50];
    char middleInitial;
    char studentAnswer[MAX + 1];
    int studentScore;
} studentResults;

// Define a structure to hold the class record
typedef struct {
    studentResults *record;
    int count;
} classRecord;

// Function declarations
void populate(classRecord *, int);
void checkExams(const char[], classRecord *);
void display(classRecord);

int main() {
    const char answerKey[] = "TTTFFTTFTF"; // Answer key for the exam
    classRecord examRecords;
    int classCount;

    examRecords.count = 0; // Initialize the count of students to 0

    // Prompt for the number of students in the class
    printf("How many students in the class? ");
    if (scanf("%d", &classCount) != 1 || classCount <= 0) {
        printf("Class count has to be a positive integer greater than 0.\n");
        return 1;
    }

    // Allocate memory for the student records
    examRecords.record = (studentResults *)malloc(classCount * sizeof(studentResults));
    if (examRecords.record == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Populate the student records with input data
    populate(&examRecords, classCount);
    // Check the exams and calculate the scores
    checkExams(answerKey, &examRecords);
    // Display the results
    display(examRecords);

    // Free allocated memory
    free(examRecords.record);
    return 0;
}

// Function to check exams and calculate the scores
void checkExams(const char answerKey[], classRecord *examRecord) {
    for (int i = 0; i < examRecord->count; i++) {
        examRecord->record[i].studentScore = 0;
        for (int j = 0; j < MAX; j++) {
            if (examRecord->record[i].studentAnswer[j] == answerKey[j]) {
                examRecord->record[i].studentScore++;
            }
        }
    }
}

// Function to populate the student records
void populate(classRecord *examRecord, int classCount) {
    char fName[50];
    char lName[50];
    char MI;
    char studentAnswer[MAX + 1];

    for (int i = 0; i < classCount; i++) {
        printf("===STUDENT %d===\n", i + 1);

        // Input student details
        printf("Input First Name: ");
        scanf("%s", fName);

        printf("Input Last Name: ");
        scanf("%s", lName);

        printf("Input Middle Initial: ");
        scanf(" %c", &MI);

        printf("Input Students Answer [10]: ");
        scanf("%s", studentAnswer);

        // Validate the length of student answers
        if (strlen(studentAnswer) != MAX) {
            printf("Invalid input. Answers must be exactly 10 characters long.\n");
            i--;
            continue;
        }

        // Create a student record and populate it with input data
        studentResults student;
        strcpy(student.firstName, fName);
        strcpy(student.lastName, lName);
        student.middleInitial = MI;
        strcpy(student.studentAnswer, studentAnswer);
        student.studentScore = 0;

        // Add the student record to the class record
        examRecord->record[i] = student;
        examRecord->count++;
    }
}

// Function to display the exam results
void display(classRecord examRecords) {
    printf("\n===EXAM RESULTS===\n");
    for (int i = 0; i < examRecords.count; i++) {
        printf("Student %d: %s %c. %s - Score: %d\n", i + 1, 
                examRecords.record[i].firstName, 
                examRecords.record[i].middleInitial, 
                examRecords.record[i].lastName, 
                examRecords.record[i].studentScore);
    }
}
