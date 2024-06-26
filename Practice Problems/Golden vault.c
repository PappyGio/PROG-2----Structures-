//* DI PA KO SURE ANI HAHAAHHAHAHAHAHA



#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//define goldenVault struct
struct GoldenVault{
    int Chest[5];
    float Gold[5];
};


//Function to initialize the goldenvault 

void initializeVault(struct GoldenVault *vault){
    //Initialize chest with even numbers starting from 2 to 10 
    for(int i = 0; i < 5; i++){
        vault ->Chest[i] = 2  + (i*2);
    }

    //initialize gold balances
    float initialBalance[] = {10.50, 150.60, 160.00,240.00,555.00};
    for(int i = 0; i < 5; i++){
        vault->Gold[i]=initialBalance[i];
    }
}

//Function to find and return indices of chest with even Gold contents
void getLuckyChests(struct GoldenVault *vault){
    printf("Lucky chest with even gold amounts: \n");
    for(int i = 0; i < 5; i++){
        if((int)vault->Gold[i] % 2 == 0){
            printf("Chest %d: %.2f Gold\n", vault->Chest[i], vault->Gold[i]);
        }
    }
}


//Function to inquire the balance of the given chest number 
void inquireChest(struct GoldenVault *vault, int chestNumber){
    for(int i = 0; i < 5; i++){
        if(vault->Chest[i] == chestNumber){
            printf("Balance of Chest %d: %.2f Gold\n", chestNumber, vault->Gold[i]);
            return;
        }
    }
    printf("Chest %d is invalid.\n", chestNumber);
}

//Function to deposit gold into a given chest 
void depositGold(struct GoldenVault *vault, int chestNumber, float amount){
    if(amount <= 0){
        printf("Deposit amount must be positive.\n");
        return;
    }
    for(int i = 0; i < 5; i++){
        if(vault->Chest[i]==chestNumber){
            vault->Gold[i] += amount;
            printf("Deposited %.2f Gold into chest %d. New Balance: %2.f Gold\n", amount,chestNumber,vault->Gold[i]);
            return;
        }
    }
    printf("Chest %d is invalid. \n", chestNumber);
}

//Function to withdraw Gold from a given chest 

void withdrawGold(struct GoldenVault *vault, int chestNumber, float amount){
    if(amount <= 0){
        printf("Withdrawal amount must be positive.\n");
        return;
    }
    for(int i = 0; i < 5; i++){
        if(vault->Chest[i] == chestNumber){
            if(vault->Gold[i] >= amount){
                vault->Gold[i] -=amount;
                printf("Withdrew %.2f Gold from Chest %d. New balance: %.2f Gold\n", amount, chestNumber, vault->Gold[i]);
            }else{
                printf("Insufficient balance in Chest %d.\n", chestNumber);
            }
            return;
        }
    }
    printf("Chest %d is invalid. \n", chestNumber);
}


//Function to sort chests by their gold balances using bubble sort 
void sortVaultByGold(struct GoldenVault *vault){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4 - 1; j++){
            if(vault->Gold[j] > vault ->Gold[j+1]){
                //Swap Gold 
                float tempGold = vault->Gold[j];
                vault->Gold[j] = vault->Gold[j+1];
                vault->Gold[j+1] = tempGold;
                //Swap chest
                int tempChest = vault->Chest[j];
                vault->Chest[j] = vault->Chest[j+1];
                vault->Chest[j+1] = tempChest;
            }
        }
    }
}

//Main function 
int main(){
    struct GoldenVault vault;
    initializeVault(&vault);


    //Retrieve and inquire about chests 
    int chestNumbersToInquire[] = {4,3,6,12};
    printf("Inquire about chest balances:\n");
    for(int i = 0; i <4; i++){
        inquireChest(&vault, chestNumbersToInquire[i]);
    }

    //Handle deposit transactions
    printf("\nDeposit transactions:\n");
        depositGold(&vault, 4, -5);
    depositGold(&vault, 8, 300);
    depositGold(&vault, 11, 17);

    // Handle withdrawal transactions
    printf("\nWithdrawal transactions:\n");
    withdrawGold(&vault, 10, 300);
    withdrawGold(&vault, 2, 100);
    withdrawGold(&vault, 4, -7);
    withdrawGold(&vault, 3, 10);

    // Retrieve and print lucky chests
    printf("\n");
    getLuckyChests(&vault);

    // Sort the vault by gold balances
    printf("\nSorting the vault by gold balances:\n");
    sortVaultByGold(&vault);
    for (int i = 0; i < 5; i++) {
        printf("Chest %d: %.2f Gold\n", vault.Chest[i], vault.Gold[i]);
    }
    return 0;
}