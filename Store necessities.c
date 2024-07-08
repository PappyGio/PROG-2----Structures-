//NOT FINAL CODEEEEEEEEEEE



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "problem.h"

// void expiredProductRemoval(/*Appropriate Parameters*/ ){
void expiredProductRemoval(storeInventory *store, date currentDate){

/* Write the code for the function here */
    int i, j;
    
    store->expiredInventory.product = (productInfo*)malloc(sizeof(productInfo) * store->currentInventory.inventoryCount);
    
    for(i = 0; i < store->currentInventory.inventoryCount; i++){
        if((store->currentInventory.product[i].expiryDate.month <= currentDate.month && 
        store->currentInventory.product[i].expiryDate.year <= currentDate.year)){
            store->expiredInventory.product[store->expiredInventory.inventoryCount++] = store->currentInventory.product[i];
            
            for(j = i; j < store->currentInventory.inventoryCount; j++){
                store->currentInventory.product[j] = store->currentInventory.product[j + 1];
            }
            store->currentInventory.inventoryCount--;
            i = -1;
        }
        
    }
    
    store->currentInventory.inventoryCost = 0;
    for(i = 0; i < store->currentInventory.inventoryCount; i++){
        store->currentInventory.inventoryCost = store->currentInventory.inventoryCost + (store->currentInventory.product[i].price * store->currentInventory.product[i].quantity);
    }
    
    store->expiredInventory.inventoryCost = 0;
    for(i = 0; i < store->expiredInventory.inventoryCount; i++){
        store->expiredInventory.inventoryCost = store->expiredInventory.inventoryCost + (store->expiredInventory.product[i].price * store->expiredInventory.product[i].quantity);
    }
    
}
