#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#define MAX 20;
#define bracket1Rate 0.10
#define bracket2Rate 0.15
#define bracket3Rate 0.20

employeeRecord populate(int);
employeeInfo newEmployee(int,int,int,name);
name addName(char [],char[],char);
// void taxBracketSeparation(companyRecord *);
void taxBracketSeparation(companyRecord *);


int main(){
    companyRecord companyLists;
    companyRecord copyList;
    int i=0;
    int employeeInitialCount=0;


    printf("Input how many employees: ");
    scanf("%d",&employeeInitialCount);

    companyLists.employeeList=populate(employeeInitialCount);

    taxBracketSeparation(&companyLists);


	display(companyLists);


}


void taxBracketSeparation(companyRecord *companyList){
    /* This function will separate all employees from the employeeList and add them into their appropriate Tax Bracket based on their Gross Pay. After which calculate their Take Home pay based on their tax bracket rate. The function will take in a companyRecord pointer and will not return anything. */


    	//WRITE CODE TO SEPARATE EMPLOYEE LIST INTO PROPER TAX BRACKETS AND THEN
        //CALCULATE THEIR TAKE HOME PAY
        
        
        
        
        // printf("%d", companyList->employeeList.employees[0].grossSalary);
        
        // companyRecord *copyList;
        
        
        // copyList->bracket1.employees = (employeeInfo*)malloc(sizeof(employeeInfo) * companyList->employeeList.count);
        // copyList->bracket2.employees = (employeeInfo*)malloc(sizeof(employeeInfo) * companyList->employeeList.count);
        // copyList->bracket3.employees = (employeeInfo*)malloc(sizeof(employeeInfo) * companyList->employeeList.count);
        
        // employeeRecord *br1 = (employeeRecord*)malloc(sizeof(employeeRecord) * companyList->employeeList.count);
        // employeeRecord *br2 = (employeeRecord*)malloc(sizeof(employeeRecord) * companyList->employeeList.count);
        // employeeRecord *br3 = (employeeRecord*)malloc(sizeof(employeeRecord) * companyList->employeeList.count);
        
        // companyList->bracket1 = companyList->employeeList;
        // companyList->bracket2 = companyList->employeeList;
        // companyList->bracket3 = companyList->employeeList;
        
        // printf("%s\n", companyList->employeeList.employees[i].empName.fName);
        
        int i;
        int br1 = 0;
        int br2 = 0;
        int br3 = 0;
        int j;

        
        companyList->bracket1.employees = (employeeInfo*)malloc(sizeof(employeeInfo) * companyList->employeeList.count);
        companyList->bracket2.employees = (employeeInfo*)malloc(sizeof(employeeInfo) * companyList->employeeList.count);
        companyList->bracket3.employees = (employeeInfo*)malloc(sizeof(employeeInfo) * companyList->employeeList.count);
        
        companyList->bracket1.count = 0;
        companyList->bracket2.count = 0;
        companyList->bracket3.count = 0;
        
        for(i = 0; i < companyList->employeeList.count; i++){
            
            companyList->bracket1.employees[i].takeHomeSalary = 0;
            companyList->bracket2.employees[i].takeHomeSalary = 0;
            companyList->bracket3.employees[i].takeHomeSalary = 0;

            if(companyList->employeeList.employees[i].grossSalary <= 14999){
                companyList->bracket1.employees[companyList->bracket1.count] = companyList->employeeList.employees[i];
                companyList->bracket1.employees[companyList->bracket1.count++].takeHomeSalary = (float)companyList->employeeList.employees[i].grossSalary - ((float)companyList->employeeList.employees[i].grossSalary * bracket1Rate);

                
            }else if(companyList->employeeList.employees[i].grossSalary >= 15000 &&
            companyList->employeeList.employees[i].grossSalary <= 25999){
                companyList->bracket2.employees[companyList->bracket2.count] = companyList->employeeList.employees[i];
                companyList->bracket2.employees[companyList->bracket2.count++].takeHomeSalary = (float)companyList->employeeList.employees[i].grossSalary - ((float)companyList->employeeList.employees[i].grossSalary * bracket2Rate);


            }else if(companyList->employeeList.employees[i].grossSalary >= 26000){
                // companyList->bracket3 = companyList->employeeList;
                // companyList->employeeList = companyList->bracket3;
                companyList->bracket3.employees[companyList->bracket3.count] = companyList->employeeList.employees[i];
                companyList->bracket3.employees[companyList->bracket3.count++].takeHomeSalary = (float)companyList->employeeList.employees[i].grossSalary - ((float)companyList->employeeList.employees[i].grossSalary * bracket3Rate);

            }
        }
        
        
        
        // tally = 0;
        // for(i = 0; i < companyList->employeeList.count; i++){
        //     printf("%.2f\n", companyList->bracket2.employees[i].takeHomeSalary);
        // }
        
        // companyList->bracket1 = companyList->bracket1;
        // companyList->bracket2 = companyList->bracket2;
        // companyList->bracket3 = companyList->bracket3;
        
        // companyList->bracket1 = copyList->bracket1;
        // companyList->bracket2 = copyList->bracket2;
        // companyList->bracket3 = copyList->bracket3;
        
        // copyList->bracket1 = companyList->bracket1;
        // copyList->bracket2 = companyList->bracket2;
        // copyList->bracket3 = companyList->bracket3;
        
        // printf("%s\n", companyList->bracket3.employees[0].empName.fName);
        
}


employeeRecord populate(int count){

    /* This function will take in a count of how many employees to add, and return an employeeRecord */

    employeeRecord list;

	//Statement to allocate memory for an Array of Employees.
    list.employees=malloc(sizeof(employeeInfo)*count);
    int i=0;
    int idNum;
    int rate;
    int hrsWorked;
    char fName[20];
    char lName[20];
    char MI;

    for(i=0;i<count;i++){
    	printf("\n\n===EMPLOYEE %d===\n\n",i+1);

        //Write Code to Ask users for Input
        printf("Input First Name: ");
        scanf("%s", fName);
        
        printf("Input Last Name: ");
        scanf("%s", lName);
        
        printf("Input Middle Initial: ");
        scanf(" %c", &MI);
        
        printf("Input Id Number: ");
        scanf("%d", &idNum);
        
        printf("Input Rate: ");
        scanf("%d", &rate);
        
        printf("Input Hours Worked: ");
        scanf("%d", &hrsWorked);
        
    	list.employees[i]=newEmployee(idNum, rate, hrsWorked, addName(fName, lName, MI));
    	list.count++;

    	if(i==count-1){
    		printf("\n===============\n\n");
		}
	}

    return list;

}
employeeInfo newEmployee(int idNum,int rate,int hrsWorked,name employeeName){
    employeeInfo newEmp;

    newEmp.empName=employeeName;
    newEmp.idNum=idNum;
    newEmp.rate=rate;
    newEmp.hrsWorked=hrsWorked;

    //Write Code to Calculate grossSalary;
    newEmp.grossSalary = 0;
    newEmp.grossSalary = newEmp.grossSalary + (newEmp.rate * newEmp.hrsWorked);

    return newEmp;

}
name addName(char fName[],char lName[],char MI){

    /* This function takes in 2 Strings and a Character, it will then populate a new name structure variable based on the parameters passed towards this function and aim to return it back to the calling function */

    name employeeName;

    strcpy(employeeName.fName,fName);
    strcpy(employeeName.lName,lName);
    employeeName.MI=MI;

    return employeeName;

}
