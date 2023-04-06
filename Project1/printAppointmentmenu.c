#include "printAppointmentmenu.h"
#include <stdio.h>

void printWelcome() {

	printf(" -------------------------------------------------------------\n");
	printf("|                                                             |\n");
	printf("|    WELCOME TO GRANDRIVER HOSPITAL APPOINTMENT MANAGER       |\n");
	printf("|                                                             |\n");
	printf(" -------------------------------------------------------------\n");

}

void printAppointmentmenu() {

	printf("Below are the services this appointment manager gives you access to:\n");
	printf("1.) Add a new appointment\n");
	printf("2.) Delete an existing appointment\n");
	printf("3.) Update an existing appointment\n");
	printf("4.) Display single appointment\n");
	printf("5.) Displays all appointments\n");
	printf("6.) Display doctors diagnostic report for appointed patients\n");
	printf("7.) Doctor appointment history with patients\n");
	printf("8.) Search for an appointment\n");
	printf("9.) Exit appointment manager and save data\n");

}
