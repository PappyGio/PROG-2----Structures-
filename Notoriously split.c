/*
will optimize it soon 


some of it not mine kay nag patabang ko ug friend HAHAHAAHHA


practice coding from codechum

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

void display2(Creature *list, int count)
{
    int i;
    
    for(i=0;i<count;++i)
    {
        printf("Name: %s %c %s\n", list[i].name.fName, list[i].name.MI, list[i].name.lName);
        printf("-Gold: %d\n", list[i].gold);
        printf("-Level: %d\n\n", list[i].level);
    }
}

void display3(Creature *list, int count)
{
    int i;
    
    printf("Nobles to hunt:\n\n");
    for(i=0;i<count;++i)
    {
        printf("Name: %s %c %s\n", list[i].name.fName, list[i].name.MI, list[i].name.lName);
        printf("-Gold: %d\n", list[i].gold);
        printf("-Level: %d\n", list[i].level);
        printf("-Location: %s\n\n", list[i].location);
    }
}
void steal(Town *town) {
    
    int i,j, max;
    Creature temp;
    int newCount = 0;
    int newCount2 = 0;
    
    int count[4] = {0,0,0,0};
    
    Creature *list = (Creature*)malloc(sizeof(Creature)*town->count);
    
    for(i=0;i<town->count;++i)
    {
            list[newCount++] = town->persons[i];
    }
    
    for(i=0;i<newCount;++i)
    {
        if(strcmp(list[i].location, "Tavern")==0)
        {
            count[0] += list[i].gold;
        }
        else if(strcmp(list[i].location, "Stables")==0)
        {
            count[1] += list[i].gold;
        }
        else if(strcmp(list[i].location, "TownSquare")==0)
        {
            count[2] += list[i].gold;
        }
        else if(strcmp(list[i].location, "Castle")==0)
        {
            count[3] += list[i].gold;
        }
    }
    
    
    char *locations[] = {"Tavern","Stables","TownSquare","Castle"};
    max =0;
    for(i=1;i<4;++i)
    {
        if(count[i]>count[max]||count[i] == count[max] && strcmp(locations[i], locations[max])<0)
        {
            max = i;
        }
    }
    
    
    
    printf("Location with the most gold to steal: %s\n", locations[max]);
    printf("Total gold amount: %d\n", count[max]);
    
    Creature *filtered = (Creature*)malloc(sizeof(Creature)*newCount);
    
    for(i=0;i<newCount;++i)
    {
        if(strcmp(list[i].location, locations[max])==0)
        {
            filtered[newCount2++] = list[i];
        }
    }
    
     for(i=0;i<newCount2-1;++i)
    {
        int mix = i;
        for(j=i+1;j<newCount2;++j)
        {
            if(filtered[j].gold < filtered[mix].gold)
            {
                mix = j;
            }
        }
        
        if(mix!=i)
        {
            temp = filtered[i];
            filtered[i] = filtered[mix];
            filtered[mix] = temp;
        }
    }
    
    printf("Target Persons in %s:\n\n", locations[max]);
    
    display2(filtered, newCount2);
    
    
}



void fight(Town *town, int level) {
    
    int i,j, max;
    Creature temp;
    int newCount = 0;
    int newCount2 = 0;
    
    int count[4] = {0,0,0,0};
    
    Creature *list = (Creature*)malloc(sizeof(Creature)*town->count);
    
    for(i=0;i<town->count;++i)
    {
        if(town->persons[i].level < level)
        {
            list[newCount++] = town->persons[i];
        }
    }
    
    for(i=0;i<newCount;++i)
    {
        if(strcmp(list[i].location, "Tavern")==0)
        {
            count[0]++;
        }
        else if(strcmp(list[i].location, "Stables")==0)
        {
            count[1]++;
        }
        else if(strcmp(list[i].location, "TownSquare")==0)
        {
            count[2]++;
        }
        else if(strcmp(list[i].location, "Castle")==0)
        {
            count[3]++;
        }
    }
    
    
    char *locations[] = {"Tavern","Stables","TownSquare","Castle"};
    max =0;
    for(i=1;i<4;++i)
    {
        if(count[i]>count[max]||count[i] == count[max] && strcmp(locations[i], locations[max])<0)
        {
            max = i;
        }
    }
    
    
    
    printf("Location with the most fighters below Level %d: %s\n", level, locations[max]);
    printf("Target fighters count: %d\n", count[max]);
    
    Creature *filtered = (Creature*)malloc(sizeof(Creature)*count[max]);
    
    for(i=0;i<newCount;++i)
    {
        if(strcmp(list[i].location, locations[max])==0)
        {
            filtered[newCount2++] = list[i];
        }
    }
    
     for(i=0;i<newCount-1;++i)
    {
        int mix = i;
        for(j=i+1;j<newCount;++j)
        {
            if(filtered[j].level > filtered[mix].level)
            {
                mix = j;
            }
        }
        
        if(mix!=i)
        {
            temp = filtered[i];
            filtered[i] = filtered[mix];
            filtered[mix] = temp;
        }
    }
    
    printf("Persons in %s below Level %d:\n\n", locations[max], level);
    
    display2(filtered, newCount2);
    
    
}

void track(Town *town) {
    
    int i,j, max;
    Creature temp;
    int newCount = 0;
    
    Creature *List = (Creature*)malloc(sizeof(Creature));
    
    for(i=0;i<town->count;++i)
    {
        if(town->persons[i].name.MI == 'A'||
        town->persons[i].name.MI == 'E'||
        town->persons[i].name.MI == 'I'||
        town->persons[i].name.MI == 'O'||
        town->persons[i].name.MI == 'U')
        {
            List[newCount++] = town->persons[i];
        }
    }
    
    for(i=0;i<newCount-1;++i)
    {
        max = i;
        for(j=i+1;j<newCount;++j)
        {
            if(List[j].level > List[max].level)
            {
                max = j;
            }
        }
        
        if(max!=i)
        {
            temp = List[i];
            List[i] = List[max];
            List[max] = temp;
        }
    }
    
    
    display3(List, newCount);
}

void main (){

    char input[20];
    
    Town town;
    populateTown(&town);
    
    printf("Who are you today? (assassin, warrior, thief): ");
    scanf("%s", input);
    for (int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }
    if (strcmp(input, "assassin" )==0) {
        printf("\nHunting Nobles....\n\n");
        // Call function specific to assassin
        track(&town);
        
        
    } else if (strcmp(input, "warrior")==0) {
        printf("\nEager for a scrap...\n\n");
        int level;
        printf("So.. how tough are ya?: ");
        scanf("%d", &level);
        // Call function specific to warrior
        
        fight(&town, level);
    } else if (strcmp(input, "thief")==0) {
        printf("\nOoooh Shiny...\n\n");
        // Call function specific to thief
        
        steal(&town);
    } else {
        printf("Invalid role entered.\n");
        // Handle invalid input
    }



}
