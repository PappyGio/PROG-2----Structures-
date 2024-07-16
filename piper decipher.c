/*
1.) Pre-made Helper Functions:

Decipher(char* , int) : Function that deciphers a text given the correct Key
enrollMages(MageCollege*) : Function that populates MageCollege
 

Task:

Create the missing structure for Fullname which should contain the fName, MI, and lName of the Mage
Create the missing structure for the Mage which should contain the name, level, and uniqueSpell variables.
Create the function getMana( ) to determine the mana level of each Mage by solving for the factorial of vowels in their Deciphered unique spell.
Create the function eligibleMage( ) to determine who are invited to participate in the duels by creating a list of Mages who are within a certain range of mana level (the range is user input)
Create the function PipersList( ) which prints the sorted list of mages who are in the tournament along with their unique spell. The list has to be sorted by mana level in descending order.
 

Note: The functions are sequential, you will not be able to complete the other without first completing the previous function.
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"



 //factorial() {
    //Optional Function, you may integrate the math into the functions below if you prefer.

int factorial(int n){
    int fact = 1;
    for(int i =1; i <=n; i++){
        fact *= i;
    }
    return fact;
}
void getMana(MageCollege *college, int num) {
    
    int i;
    int count = 0;
    int len = strlen(college->students[num].uniqueSpell);
    for(i = 0; i <len; ++i){
        if(college->students[num].uniqueSpell[i] == 'a'||
        college->students[num].uniqueSpell[i] == 'e'||
        college->students[num].uniqueSpell[i] == 'i'||
        college->students[num].uniqueSpell[i] == 'o'||
        college->students[num].uniqueSpell[i] == 'u'||
        college->students[num].uniqueSpell[i] == 'A'||
        college->students[num].uniqueSpell[i] == 'E'||
        college->students[num].uniqueSpell[i] == 'I'||
        college->students[num].uniqueSpell[i] == 'O'||
        college->students[num].uniqueSpell[i] == 'U'){
            count++;
        }
    }
college->students[num].level = factorial(count);
}

Mage* eligibleMage(MageCollege* college, int *newCount){
    int i,j,max;
    Mage temp;
    
    
    Mage* coolMages = (Mage*)malloc(sizeof(Mage)*college->count);
    
    for(i = 0; i <college->count;++i){
        if(college->students[i].level >= college->range.minMana && college->students[i].level <=college->range.maxMana){
            coolMages[*newCount] = college->students[i];
            (*newCount)++;
        }
    }
    
    for(i=0;i<*newCount;++i){
        max = i;
        for(j = i+1;j<*newCount;++j){
            if(coolMages[j].level > coolMages[max].level){
                max = j;
            }
        }
        
        if(max!= i){
            temp = coolMages[i];
            coolMages[i] = coolMages[max];
            coolMages[max] = temp;
        }
    }
    
    return coolMages;
}


void PipersList(Mage *coolMages, int key, int newCount) {


    printf("\n ===DUELING MAGES===\n");
    for (int i = 0; i <newCount ; i++) {


        printf("Mage: %s %c %s \n- Mana Level: %d \n- Deciphered Spell: %s\n\n", coolMages[i].name.fName, 
        coolMages[i].name.MI, 
        coolMages[i].name.lName, 
        coolMages[i].level,
        coolMages[i].uniqueSpell);
    }
}

int main() {

    // Psst hey, here's the key.. good luck -Your friend, Piper
    int key = -4;
    MageCollege college; // The empty college yet to be populated with mages
    int newCount = 0;

    //Hmmm... the part below is missing something.. how peculiar
    printf("Input Lowest Mana Acceptable:" );
    scanf("%d",&college.range.minMana);
    printf("\nInput Highest Mana Acceptable:" );
    scanf("%d",&college.range.maxMana);


    //Why does it feel so empty here.. a trick of the code?
   enrollMages(&college);
   int i;
   for(i = 0; i < college.count; ++i){
       Decipher(college.students[i].uniqueSpell, key);
       getMana(&college, i);
   }
   Mage *catcher = eligibleMage(&college, &newCount);
   PipersList(catcher, key, newCount);
   
   
   free(catcher);

    return 0;
}

//functions.h

/*
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

//complete the structure for the name of the mage below
typedef struct {
char fName[50];
char MI;
char lName[50];

}Fullname;

//complete the structure for the mage's profile below
typedef struct {
Fullname name;
int level;
char uniqueSpell[100];
}Mage;


typedef struct {
    int minMana;
    int maxMana;
} Duel;

typedef struct School {
    Mage* students;
    int count;
    Duel range;
} MageCollege;

void Decipher(char *message, int key);
void enrollMages(MageCollege* college);

#endif
*/
