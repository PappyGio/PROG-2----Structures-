#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
	int id;
	char name[50];
	float price;
}Product;


typedef struct{
	Product products[12];
	int count;
}GobuShop;


//Function prototypes

void initializeShop(GobuShop *shop);
void populateShop(GobuShop *shop);
void displayProducts(GobuShop *shop);
void sortByPrice(GobuShop *shop);
void sortByName(GobuShop *shop);
void sortById(GobuShop *shop);



int main(){
	GobuShop Shop;
	
	
	//Initialize Gobu shop 
	initializeShop(&Shop);
	
	//Populate shop
	populateShop(&Shop);
	
	//Sort and display the products by price
	printf("Productts sorted by Price:\n");
	sortByPrice(&Shop);
	displayProducts(&Shop);
	
	//Sort and display the products by products 
	
	printf("\nProducts sorted by Name:\n");
	sortByName(&Shop);
	displayProducts(&Shop);
	
	return 0;
}

//Function call time 

//Function to initialize shop 

void intializeShop(GobuShop *shop){
	shop->count = 0;
}


void populateShop(GobuShop *shop){
	shop->products[0] = (Product){1, "Sword", 12.00};
	shop->products[1] = (Product){2, "HealthPotion", 50.00};
	shop->products[2] = (Product){3, "PlateMail", 120.50};
	shop->products[3] = (Product){4, "MagicAmulet", 75.00};
	shop->products[4] = (Product){5, "Arrows", 3.20};
	shop->products[5] = (Product){7, "ScaleMall", 120.00};
	shop->products[6] = (Product){8, "LongBow", 10.00};
	shop->count = 7;
	
	}
	
	
//Function to display the details of the product 

void displayProducts(GobuShop *shop){
	for(int i = 0; i < shop->count; i++){
		printf("ID: %03d - Name: %s - Price: %.2f\n", shop->products[i].id, shop->products[i].name, shop->products[i].price);
	}
}

//sort the products in Gobu shop by price in ascending order 

void sortByPrice(GobuShop *shop){
	for(int i = 0; i <shop->count - 1; i++){
		for(int j = 0; j <shop->count - i- 1; j++){
			if(shop->products[j].price > shop->products[j + 1].price){
				Product temp = shop->products[j];
				shop->products[j] = shop->products[j+1];
				shop->products[j+1] = temp;
			}
		}
	}
}

//Function to sort the products in gobu shop by name in alphabetical 

void sortByName(GobuShop *shop){
	for(int i = 0; i <shop->count - 1; i++){
		for(int j = 0; j <shop->count - i- 1; j++){
			if(strcmp(shop->products[j].name, shop->products[j + 1].name) > 0){
				Product temp = shop->products[j];
				shop->products[j] = shop->products[j+1];
				shop->products[j+1] = temp;
			}
		}
	}
} 


//Function to sort the products gobu shop id in descending order 

void sortByid(GobuShop *shop){
	for(int i = 0; i < shop->count-1; i++){
		for(int j =0; i <shop->count - i - 1; i++){
			if(shop->products[j].id < shop->products[j+1].id){
				Product temp = shop->products[j];
				shop->products[j] = shop->products[j + 1];
				shop->products[j+1] = temp;
			}
		}
	}
}
