#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
char fName[50];
char lName[50];
char MI;
}Fullname;

//complete the structure for the mage's profile below
typedef struct {
  Fullname name;
  int level;
  char uniqueSpell[50];
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

int factorial(int n) 
{
    //Optional Function, you may integrate the math into the functions below if you prefer.
    if(n <= 1) // should not include numbers less than 1
    {
        return 1;
    }   
    
    return n * factorial(n - 1);
}

void getMana(Mage* mage) 
{
    int i;
    int vowels = 0;
    
    char isVowel[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    
    for(int i = 0; mage->uniqueSpell[i] != '\0'; i++)
    {
        char c = tolower(mage->uniqueSpell[i]);
    
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            vowels++;
        }
    }

    // printf("\nVowel: %d", vowels);
    
    mage->level = factorial(vowels);
}

void eligibleMage(MageCollege* college) 
{
    int i;
    int eligibleCount = 0;
    
    for(i = 0; i < college->count; i++)
    {
        if(college->students[i].level >= college->range.minMana && college->students[i].level <= college->range.maxMana)
        {
            college->students[eligibleCount++] = college->students[i];
        }
    }
    
    college->count = eligibleCount;
}

int compareMages(void* a, void* b)
{
    Mage* mageA = (Mage*)a;
    Mage* mageB = (Mage*)b;
    
    if (mageB->level != mageA->level)
        return mageB->level - mageA->level;

    return ((Mage*)a - (Mage*)b);
}

void PipersList(MageCollege* college) 
{
    int i;
    
    qsort(college->students, college->count, sizeof(Mage), compareMages);
    
    printf("\n ===DUELING MAGES===\n");

    for(i = 0; i < college->count; i++) 
    {
        printf("Mage: %s %c %s \n- Mana Level: %d \n- Deciphered Spell: %s\n\n", 
        college->students[i].name.fName, college->students[i].name.MI, 
        college->students[i].name.lName, college->students[i].level, 
        college->students[i].uniqueSpell); 
    }
}

int main() 
{
    int i;

    //Psst hey, here's the key.. good luck -Your friend, Piper
    int key = -4;
    MageCollege college; // The empty college yet to be populated with mages
    
    college.students = NULL;
    college.count = 0;
    
    //Hmmm... the part below is missing something.. how peculiar
    printf("Input Lowest Mana Acceptable:" );
    scanf("%d",&college.range.minMana);
    
    printf("\nInput Highest Mana Acceptable:" );
    scanf("%d",&college.range.maxMana);
    
    //Why does it feel so empty here.. a trick of the code?
    enrollMages(&college);
    
    for(i = 0; i < college.count; i++)
    {
        Decipher(college.students[i].uniqueSpell, key);
        getMana(&college.students[i]);
    }

    eligibleMage(&college);

    PipersList(&college);
    
    free(college.students);

    return 0;
}
