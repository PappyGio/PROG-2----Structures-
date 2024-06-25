#include<stdio.h>


//create struct for car data

 struct car{
	int car_id;
	char model[50];
	float rental;
};

int main(){
	//Array to hold 
	
	struct car cars[3];
	int num_days;
	
	//input data for three cars
	for(int i =0; i < 3; i++){
		printf("Enter  details for car %d:\n", i + 1);
		
		printf("Car id: ");
		scanf("%d", &cars[i].car_id);
		
		printf("Model: ");
		scanf("%s", &cars[i].model);
		
		
		printf("Rental rate per day: ");
		scanf("%f", &cars[i].rental);
		
		printf("\n");
		
	}
	
	//number of days of rent 
	printf("Enter the number of days for rental calculation: ");
	scanf("%d", &num_days);
	
	
	//calculate and display the total
	
	for(int i = 0; i < 3; i++){
		float total = cars[i].rental * num_days;
		printf("Total rental  cost for car ID %d (%s) for %d days is: %.2f\n", cars[i].car_id, cars[i].model, num_days, total);
	}
	return 0;
}


/*
Design a structure named "Car" to store details like car ID, model, and rental rate per day.
Write a C program to input data for three cars, calculate the total rental cost for a specified number of days, and display the results.
*/
