#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

/* The functions available are found in .h, although these functions are available does not mean,
they are needed to be used in the actual solution. Most functions are used during the initial population of the list and can be ignored, but again are available if you see fit. */

/* display() and populateSchoolList() is really the only required function you need to call in the actual solution */

team findTeam(char schoolInput[],char sportInput[],schoolList totalList){
    int i, j;
    
    team group;
    studentInfo temp;
    
    for(i = 0; i < totalList.schoolCount - 1; i++){
        for(j = 0; j < totalList.schoolCount - i - 1; j++){
            if(totalList.schoolList[j].game.rank < totalList.schoolList[j + 1].game.rank){
                temp = totalList.schoolList[j];
                totalList.schoolList[j] =  totalList.schoolList[j + 1];
                totalList.schoolList[j + 1] = temp;
            }
        }
    }
    
    group.teamMembers = (studentInfo*)malloc(sizeof(studentInfo) * totalList.schoolCount);
    
    group.count = 0;
    for(i = 0; i < totalList.schoolCount; i++){
        if(strcmp(schoolInput, totalList.schoolList[i].school) == 0 &&
        strcmp(sportInput, totalList.schoolList[i].game.esport) == 0){
            if(group.count < 6){
                group.teamMembers[group.count++] = totalList.schoolList[i];
                strcpy(group.teamDepartment, schoolInput);
                strcpy(group.game, sportInput);
            }
        }
        else{
            strcpy(group.teamDepartment, schoolInput);
            strcpy(group.game, sportInput);
        }
    }
    return group;
}

int main(){
	schoolList totalList; //Refers to the list of all students interested in
                          //joining the tournament

	team foundTeam; //Refers to the team found based on the given criteria of
                    //school and choice of game

    char schoolInput[20];
	char sportInput[20];

	populateSchoolList(&totalList);

	printf("===Find Teams!===");
	printf("\nInput School: ");
	scanf(" %s",schoolInput);
	printf("Input Sport: ");
	scanf(" %s",sportInput);


    /* Proper function call to findTeam */
    foundTeam = findTeam(schoolInput, sportInput, totalList);

	display(foundTeam);
	return 0;
}
