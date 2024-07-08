//not yet finish HAAHAHAHAHAHAHA



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10


typedef struct{
    char fName[50];
    char lName[50];
    char middleInitial;
}name;

typedef struct{
    name studentName;
    int idNum;
    int studentGrades[3];
}studentDetail;



typedef struct{
    studentDetail student[MAX];
    int count;
}classRecord;

typedef struct{
	classRecord classList;
	classRecord examRetake[3];
}classResults;

void populate(classRecord *,int);
studentDetail addStudent(char *fName,char *lName,char mi,int idNum,int grades[5]);
void checkExams(classResults *results);

int main(){
	int i=0;
	int classCount;
    classResults results;
    results.classList.count=0;
   
    results.examRetake[0].count=0;
    results.examRetake[1].count=0;
    results.examRetake[2].count=0;
    
    printf("Input Number of Students in Class:" );
    scanf("%d",&classCount);
    
      /*CODE TO FIRST CHECK IF CLASS SIZE IS CORRECT*/
        if(classCount > 10){
            printf("Maximum Number of Students per Class is only 10");
            return 0;
        }
      /*FUNCTION CALL TO POPULATE THE ARRAY*/
        populate(&results.classList, classCount);
      /*FUNCTION CALL TO CHECK WHO NEEDS TO RETAKE WHICH EXAMS*/
        checkExams(&results);
      /*DISPLAY*/
	
	int end = 0;
	    printf("Retakers Needed for Exam 1:");
	    if(results.examRetake[0].count == 0){
            printf("No Retakers for Exam 1\n\n");
        }else{
            for(i = 0; i < results.examRetake[0].count && end != 1; i++){
                if(results.examRetake[0].count == classCount){
                    printf("All Students Have to Retake Exam 1");
                    end = 1;
                }
                
                if(end == 0){
                    printf("%s ", results.examRetake[0].student[i].studentName.fName);
                }
            }
            printf("\n\n");
        }
        
    end = 0;
        printf("Retakers Needed for Exam 2:");
	    if(results.examRetake[1].count == 0){
            printf("No Retakers for Exam 2\n\n");
        }else{
            for(i = 0; i < results.examRetake[1].count && end != 1; i++){
                if(results.examRetake[1].count == classCount){
                    printf("All Students Have to Retake Exam 2");
                    end = 1;
                }
                
                if(end == 0){
                    printf("%s ", results.examRetake[1].student[i].studentName.fName);
                }
            }
            printf("\n\n");
        }
        
    end = 0;
        printf("Retakers Needed for Exam 3:");
	    if(results.examRetake[2].count == 0){
            printf("No Retakers for Exam 3");
        }else{
            for(i = 0; i < results.examRetake[2].count && end != 1; i++){
                if(results.examRetake[2].count == classCount){
                    printf("All Students Have to Retake Exam 3");
                    end = 1;
                }
                
                if(end == 0){
                    printf("%s ", results.examRetake[2].student[i].studentName.fName);
                }
            }
        }
}

void checkExams(classResults *results){
    //WRITE CODE TO CHECK WHO NEEDS TO RETAKE WHICH EXAMS
    int i, j;
    int studentCount1 = 0;
    int studentCount2 = 0;
    int studentCount3 = 0;
    
    
    for(i = 0; i < results->classList.count; i++){
        if(results->classList.student[i].studentGrades[0] < 60){
          results->examRetake[0].student[studentCount1++] = results->classList.student[i];
          results->examRetake[0].count++;
        }
        if(results->classList.student[i].studentGrades[1] < 60){
          results->examRetake[1].student[studentCount2++] = results->classList.student[i];
          results->examRetake[1].count++;
        }
        if(results->classList.student[i].studentGrades[2] < 60){
          results->examRetake[2].student[studentCount3++] = results->classList.student[i];
          results->examRetake[2].count++;
        }
    }
}

void populate(classRecord *record,int classCount){
	int i=0;
	int x=0;
	char fName[50];
	char lName[50];
	char MI;
	int idNum;
	int grades[3];
	for(i=0;i<classCount;i++){
	printf("===STUDENT %d===\n\n",i+1);

    //CONTINUE CODE TO POPULATE STUDENTS HERE
	printf("Input First Name: ");
	scanf("%s", fName);
	
	printf("Input Last Name: ");
	scanf("%s", lName);
	
	printf("Input Middle Initial: ");
	scanf(" %c", &MI);
	
	printf("Input ID Number: ");
	scanf("%d", &idNum);
	
	printf("Input Exam Score %d: ", 1);
	scanf("%d", &grades[0]);
	
	printf("Input Exam Score %d: ", 2);
	scanf("%d", &grades[1]);
	
	printf("Input Exam Score %d: ", 3);
	scanf("%d", &grades[2]);
	
	record->student[i]=addStudent(fName, lName, MI, idNum, grades);
	record->count++;
	}
}

studentDetail addStudent(char *fName,char *lName,char mi,int idNum,int grades[3]){
	int i=0;
	
    studentDetail details;

    details.studentName.middleInitial=mi;
    strcpy(details.studentName.fName,fName);
    strcpy(details.studentName.lName,lName);   

    details.idNum=idNum;

	for(i=0;i<3;i++){
		 details.studentGrades[i]=grades[i];
	}
   
    return details;
}
