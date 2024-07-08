// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define STRING_MAX 50
// #define LIST_MAX 10

// typedef struct {
//     int month;
//     int year;
// } currentDate;

// typedef struct {
//     int hireMonth;
//     int hireYear;
// } hiringDetails;

// typedef struct {
//     char fName[STRING_MAX];
// } empDetails;

// typedef struct {
//     hiringDetails dateOfHire;
//     empDetails employeeInfo;
// } employee;

// typedef struct {
//     employee employeeList[LIST_MAX];
//     int count;
// } employeeRecords;

// employee* getLoyalList(employeeRecords record, int *loyalListCount, currentDate currDate);

// void display(employee *loyalList, int loyalListCount);

// int main() {
//     employeeRecords record;
//     int employeeCount;
//     int loyalListCount = 0;
//     record.count = 0;
//     employee *loyalList;
//     currentDate date = {7, 2023}; // Change this date for different outputs
    
//     int i = 0;
//     printf("Input Number of Employees: ");
//     scanf("%d", &employeeCount);
    
//     printf("\nInput Details for Employees:\n");
//     for (i = 0; i < employeeCount; i++) {
//         printf("\n===Employee %d===\n", i + 1);
//         printf("Input First Name: ");
//         scanf("%s", record.employeeList[i].employeeInfo.fName);
//         printf("Input Month of Hire: ");
//         scanf("%d", &record.employeeList[i].dateOfHire.hireMonth);
//         printf("Input Year of Hire: ");
//         scanf("%d", &record.employeeList[i].dateOfHire.hireYear);
//         record.count++;
//     }
    
//     loyalList = getLoyalList(record, &loyalListCount, date);
    
//     display(loyalList, loyalListCount);
    
//     return 0;
// }

// employee* getLoyalList(employeeRecords record, int *loyalListCount, currentDate currDate) {
//     static employee loyalList[LIST_MAX];
//     *loyalListCount = 0;
    
//     for (int i = 0; i < record.count; i++) {
//         // Check if the employee has been with the company for 5 consecutive years
//         if (currDate.year - record.employeeList[i].dateOfHire.hireYear >= 5) {
//             // Additional check for exact 5 years in the same month or earlier
//             if (currDate.year - record.employeeList[i].dateOfHire.hireYear == 5) {
//                 if (record.employeeList[i].dateOfHire.hireMonth <= currDate.month) {
//                     loyalList[*loyalListCount] = record.employeeList[i];
//                     (*loyalListCount)++;
//                 }
//             } else { // More than 5 years
//                 loyalList[*loyalListCount] = record.employeeList[i];
//                 (*loyalListCount)++;
//             }
//         }
//     }
    
//     // Allocate exact memory for loyalList based on loyalListCount
//     employee *exactLoyalList = (employee*) malloc((*loyalListCount) * sizeof(employee));
//     if (exactLoyalList == NULL) {
//         printf("Memory allocation failed.\n");
//         exit(1);
//     }
//     memcpy(exactLoyalList, loyalList, (*loyalListCount) * sizeof(employee));
    
//     return exactLoyalList;
// }

// void display(employee *loyalList, int loyalListCount) {
//     if (loyalListCount > 0) {
//         printf("\nLoyal Employees List:\n");
//         for (int i = 0; i < loyalListCount; i++) {
//             printf("Name: %s -- Hire Date: %d-%d\n",
//                    loyalList[i].employeeInfo.fName,
//                    loyalList[i].dateOfHire.hireMonth,
//                    loyalList[i].dateOfHire.hireYear);
//         }
//     } else {
//         printf("\nThere are currently no Employees who have been with the company for 5 consecutive years.\n");
//     }
// }


/*
Sample output: 

Sample Output 1

Input Number of Employees:3

Input Details for Employees:


===Employee 1===
Input First Name: Patrick
Input Month of Hire: 08
Input Year of Hire: 2018


===Employee 2===
Input First Name: Ean
Input Month of Hire: 07
Input Year of Hire: 2018


===Employee 3===
Input First Name: Gran
Input Month of Hire: 12
Input Year of Hire: 2017
Loyal List:

Name: Ean -- Hire Date:7-2018
Name: Gran -- Hire Date:12-2017
Sample Output 2

Input Number of Employees:2

Input Details for Employees:


===Employee 1===
Input First Name: Josh
Input Month of Hire: 08
Input Year of Hire: 2018


===Employee 2===
Input First Name: John
Input Month of Hire: 09
Input Year of Hire: 2017
Loyal List:

Name: John -- Hire Date:9-2017
Sample Output 3

Input Number of Employees:3

Input Details for Employees:


===Employee 1===
Input First Name: Justin
Input Month of Hire: 08
Input Year of Hire: 2018


===Employee 2===
Input First Name: Dave
Input Month of Hire: 09
Input Year of Hire: 2020


===Employee 3===
Input First Name: Chris
Input Month of Hire: 10
Input Year of Hire: 2019
There are currently no Employees who are eligible for the reward.
main.c
*/






#include <stdio.h>
#include <stdlib.h>
#define STRING_MAX 50
#define LIST_MAX 10
typedef struct{
	int month;
	int year;
}currentDate;
typedef struct{
	int hireMonth;
	int hireYear;
}hiringDetails;

typedef struct{
	char fName[STRING_MAX];
}empDetails;

typedef struct{
	hiringDetails dateOfHire;
	empDetails employeeInfo;
}employee;

typedef struct{
	employee employeeList[LIST_MAX];
	int count;
}employeeRecords;

employee* getLoyalList(employeeRecords record,int *loyalListCount,currentDate currDate);

void display(employee *loyalList,int loyalListCount);
int main(){
	employeeRecords record;
	int employeeCount;
	int loyalListCount=0;
	record.count=0;
	employee *loyalList;
	currentDate date={07,2023};
	
	int i=0;
	printf("Input Number of Employees:" );
    scanf("%d",&employeeCount);
    
    printf("\nInput Details for Employees: \n");
    for(i=0;i<employeeCount;i++){
    	printf("\n\n===Employee %d===\n",i+1);
    	/*CODE FOR INPUTS*/
    	printf("Input First Name: ");
    	scanf("%s", record.employeeList[i].employeeInfo.fName);
    	
    	printf("Input Month of Hire: ");
    	scanf("%d", &record.employeeList[i].dateOfHire.hireMonth);
    	
    	printf("Input Year of Hire: ");
    	scanf("%d", &record.employeeList[i].dateOfHire.hireYear);
    	
    	record.count++;
	}
	
	loyalList=getLoyalList(record,&loyalListCount,date);
	
	display(loyalList, loyalListCount);
	
}

employee* getLoyalList(employeeRecords record,int *loyalListCount,currentDate currDate){
    /*CODE TO CREATE THE LOYAL LIST*/
    int i;
    employee *workers = (employee*)malloc(sizeof(employee) * record.count);
    int count = 0;
    
    for(i = 0; i < record.count; i++){
        if((record.employeeList[i].dateOfHire.hireMonth <= currDate.month && 
        record.employeeList[i].dateOfHire.hireYear <= (currDate.year - 5)) ||
        (record.employeeList[i].dateOfHire.hireMonth >= currDate.month && 
        record.employeeList[i].dateOfHire.hireYear <= (currDate.year - 6))){
            *loyalListCount += 1;
            workers[count++] = record.employeeList[i];
        }
    }
    
	
	return workers;
}

void display(employee *loyalList,int loyalListCount){
    /*CODE TO DISPLAY*/
    int i;
    
    if(loyalListCount == 0){
        printf("There are currently no Employees who are eligible for the reward.");
        return;
    }
    
    printf("Loyal List:\n\n");
    for(i = 0; i < loyalListCount; i++){
        printf("Name: %s -- ", loyalList[i].employeeInfo.fName);
        printf("Hire Date:%d-%d\n", loyalList[i].dateOfHire.hireMonth, 
        loyalList[i].dateOfHire.hireYear);
    }
}
