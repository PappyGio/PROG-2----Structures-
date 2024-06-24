/*
Same with shopping cart problem but now optimize with structures

Will optimize it soon  

*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_CART_ITEMS 100

typedef struct{
    char name[50];
    int quantity;
    float price;
}Item;

typedef struct{
    Item items[MAX_CART_ITEMS];
    int size;
}Inventory;

typedef struct{
    Item items[MAX_CART_ITEMS];
    int size;
}Cart;


//Display menu function 

//display menu function 
void displayMenu() {
    printf("\nWELCOME TO GIO SARI SARI STORE\n");
    printf("\nMenu:\n");
    printf("1. Display Stock\n");
    printf("2. Update Stock Quantity\n");
    printf("3. Change Item Price\n");
    printf("4. Add Items to Cart\n");
    printf("5. View Cart\n");
    printf("6. Remove Item from Cart\n");
    printf("7. Proceed to Checkout\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}

//Function to display stock horizontally
void displayStock(Inventory *inventory){
    printf("\nIndex\tNames\t\t\tQuantities\t\tPrices\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < inventory->size; i++) {
        printf("%d\t%s\t\t%d\t\t$%.2f\n", i + 1, inventory->items[i].name, inventory->items[i].quantity, inventory->items[i].price);
    }
}

//Function to update stock quantity
// Function to update stock quantity
void updateStock(Inventory *inventory, int index, int newQuantity) {
    if (index >= 1 && index <= inventory->size) {
        inventory->items[index-1].quantity = newQuantity;
        printf("Quantity of %s updated to %d.\n",inventory->items[index-1]. name, newQuantity);
    } else {
        printf("Invalid index.\n");
    }
}


// Function to change the price of an item
void changePrice(Inventory *inventory, int index, float newPrice) {
    if (index >= 1 && index <= inventory->size) {
        inventory->items[index - 1].price = newPrice;
        printf("Price of %s updated to $%.2f.\n", inventory->items[index - 1].name, newPrice);
    } else {
        printf("Invalid index.\n");
    }
}

// Function to add multiple items to the cart
void addMultipleToCart(Cart *cart, Inventory *inventory, char itemNames[][50], int quantities[], int numItems) {
    for (int i = 0; i < numItems; i++) {
        for (int j = 0; j < cart->size; j++) {
            if (strcmp(cart->items[j].name, itemNames[i]) == 0) {
                cart->items[j].quantity += quantities[i];
                printf("Increased quantity of %s to %d.\n", itemNames[i], cart->items[j].quantity);
                goto nextItem;
            }
        }
        if (cart->size < MAX_CART_ITEMS) {
            for (int k = 0; k < inventory->size; k++) {
                if (strcmp(inventory->items[k].name, itemNames[i]) == 0) {
                    strcpy(cart->items[cart->size].name, itemNames[i]);
                    cart->items[cart->size].quantity = quantities[i];
                    cart->items[cart->size].price = inventory->items[k].price;
                    cart->size++;
                    printf("Added %d of %s to the cart.\n", quantities[i], itemNames[i]);
                    break;
                }
            }
        } else {
            printf("Cart is full. Cannot add more items.\n");
            return;
        }
        nextItem:;
    }
}


// Function to remove item from cart
void removeFromCart(Cart *cart, int index) {
    if (index >= 1 && index <= cart->size) {
        for (int i = index - 1; i < cart->size - 1; i++) {
          cart->items[i] = cart-> items[i + 1];
        }
        cart->size--;
        printf("Item removed from the cart.\n");
    } else {
        printf("Invalid index.\n");
    }
}

// Function to display cart contents horizontally and calculate total cost
void viewCart(Cart *cart) {
    printf("\nCart Contents:\n");
    printf("Index\tNames\t\t\tQuantities\t\tPrices\n");
    printf("-----------------------------------------------------------\n");
    
    float totalCost = 0.0;
    for (int i = 0; i < cart->size; i++) {
        printf("%d\t%s\t\t%d\t\t$%.2f\n", i + 1, cart->items[i].name, cart->items[i].quantity, cart->items[i].price);
    }
    printf("\nTotal Cost: $%.2f\n", totalCost);
}


// Function to checkout and update stock
void checkout(Inventory *inventory, Cart *cart) {
    if (cart->size == 0) {
        printf("Your cart is empty. Nothing to checkout.\n");
        return;
    }

    float totalCost = 0.0;
    for (int i = 0; i < cart->size; i++) {
        totalCost += cart->items[i].quantity * cart->items[i].price;
    }

    printf("\nTotal Cost: $%.2f\n", totalCost);

    char confirm;
    printf("Do you want to proceed with the checkout? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        printf("Checkout successful. Thank you for your purchase!\n");

        // Update the stock quantities
        for (int i = 0; i < cart->size; i++) {
            for (int j = 0; j < inventory->size; j++) {
                if (strcmp(inventory->items[j].name, cart->items[i].name) == 0) {
                    if (inventory->items[j].quantity >= cart->items[i].quantity) { // Ensure stock is sufficient
                        inventory->items[j].quantity -= cart->items[i].quantity;
                        break;
                    } else {
                        printf("Not enough stock for %s. Cannot complete purchase.\n", cart->items[i].name);
                        return;
                    }
                }
            }
        }

        cart->size = 0;  // Clear the cart

        // Display remaining stock quantities
        printf("\nRemaining Stock:\n");
        displayStock(inventory);
    } else {
        printf("Checkout cancelled.\n");
    }
}

int main() {
    Inventory inventory = {
        .items = {
            {"Milk Choc", 60, 12.00},
            {"Dark Choc", 42, 25.00},
            {"Mint Chocolate", 29, 20.00},
            {"White Choc", 60, 15.00},
            {"Peanut Choc", 38, 8.00}
        },
        .size = 5
    };

    Cart cart = { .size = 0 };

    char choice;
    while (1) {
        displayMenu();
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                displayStock(&inventory);
                break;
            case '2': {
                int index, newQuantity;
                printf("Enter the index of the item you want to update: ");
                scanf("%d", &index);
                if (index >= 1 && index <= inventory.size) {
                    printf("Enter the new quantity for %s: ", inventory.items[index - 1].name);
                    scanf("%d", &newQuantity);
                    updateStock(&inventory, index, newQuantity);
                } else {
                    printf("Invalid index.\n");
                }
                break;
            }
            case '3': {
                int index;
                float newPrice;
                printf("Enter the index of the item whose price you want to update: ");
                scanf("%d", &index);
                if (index >= 1 && index <= inventory.size) {
                    printf("Enter the new price for %s: ", inventory.items[index - 1].name);
                    scanf("%f", &newPrice);
                    changePrice(&inventory, index, newPrice);
                } else {
                    printf("Invalid index.\n");
                }
                break;
            }
            case '4': {
                int numItems;
                printf("How many different items do you want to add to the cart? ");
                scanf("%d", &numItems);

                char itemNames[numItems][50];
                int quantities[numItems];

                for (int i = 0; i < numItems; i++) {
                    int cartIndex;
                    printf("Enter the index of the item you want to add to the cart: ");
                    scanf("%d", &cartIndex);
                    if (cartIndex >= 1 && cartIndex <= inventory.size) {
                        printf("Enter the quantity for %s to add to the cart: ", inventory.items[cartIndex - 1].name);
                        scanf("%d", &quantities[i]);
                        strcpy(itemNames[i], inventory.items[cartIndex - 1].name);
                    } else {
                        printf("Invalid index. Skipping this item.\n");
                        i--;
                    }
                }
                addMultipleToCart(&cart, &inventory, itemNames, quantities, numItems);
                break;
            }
            case '5':
                viewCart(&cart);
                break;
            case '6': {
                int removeIndex;
                printf("Enter the index of the item you want to remove from the cart: ");
                scanf("%d", &removeIndex);
                removeFromCart(&cart, removeIndex);
                break;
            }
            case '7':
                checkout(&inventory, &cart);
                break;
            case '8':
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
}

