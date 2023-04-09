//Module 2 - Appointment manager module
//Developer for this function = Micheal
#include "updateAppointment.h"
#include "addAppointment.h"
#include "printAppointmentmenu.h"

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void updateAppointment(APPOINTMENT* appointmentArr) {
    int day;
    printf("\nEnter the day of the appointment you wish to update: ");
    scanf("%d", &day);

    if (day < 1 || day > 30) {
        printf("-------------------------------------------------\n");
        printf("Invalid input. Please enter a valid day (1-30): ");
        printf("-------------------------------------------------\n");
        return;
    }
    if (strcmp(appointmentArr[day - 1].Appointed, "False") == 0) {
        printf("-------------------------------------------------\n");
        printf("There is no appointment on this day.\n");
        printf("-------------------------------------------------\n");
        return;
    }
    printf("-------------------------------------------------\n");
    printf("The current details of the appointment are:\n");
    printf("Patient's First Name: %s\n", appointmentArr[day - 1].firstName);
    printf("Patient's Last Name: %s\n", appointmentArr[day - 1].lastName);
    printf("Patient's ID: %d\n", appointmentArr[day - 1].patientID);
    printf("Gender (M stands for Male and F stands for Female): %s\n", appointmentArr[day - 1].gender);
    printf("Illness: %s\n", appointmentArr[day - 1].illness);
    printf("Doctor: %s\n", appointmentArr[day - 1].selectedDoctor);
    printf("Appointment Day: %d\n", appointmentArr[day - 1].dayOfmonth);
    printf("-------------------------------------------------\n");

    printf("\nEnter the updated details below:\n");
    int i = day - 1;
    // Prompt the user to update appointment details using dynamic allocation => REQ-SYS-050
    char* firstName = (char*)malloc(sizeof(char) * MAXSTRLEN);
    printf("Enter first name: ");
    scanf("%s", firstName);
    strcpy(appointmentArr[i].firstName, firstName); //strcpy is used to copy the contents of firstName to appointmentArr[i].firstName.

    char* lastName = (char*)malloc(sizeof(char) * MAXSTRLEN);
    printf("Enter last name: ");
    scanf("%s", lastName);
    strcpy(appointmentArr[day - 1].lastName, lastName);

    char* gender = (char*)malloc(sizeof(char) * MAXSTRLEN);
    printf("Enter gender (M/F): ");
    while (scanf("%s", gender) != 1 || (strcmp(gender, "M") != 0 && strcmp(gender, "F") != 0)) {
        printf("Invalid input. Please enter a valid gender (M/F): ");
        clearInputBuffer();
    }
    strcpy(appointmentArr[day - 1].gender, gender);

    char* illness = (char*)malloc(sizeof(char) * MAXSTRLEN);
    printf("Enter illness: ");
    scanf("%s", illness);
    strcpy(appointmentArr[day - 1].illness, illness);

    char* selectedDoctor = selectDoctor();
    strcpy(appointmentArr[day - 1].selectedDoctor, selectedDoctor);

    printf("-------------------------------------------------\n");
    printf("Appointment updated successfully!\n");
    printf("Below is a summary of your appointment: \n\n");
    printf("Patient's First Name: %s\n", appointmentArr[i].firstName);
    printf("Patient's Last Name: %s\n", appointmentArr[i].lastName);
    printf("Patient's ID: %d\n", appointmentArr[day - 1].patientID);
    printf("Gender (M stands for Male and F stands for Female): %s\n", appointmentArr[i].gender);
    printf("Illness: %s\n", appointmentArr[i].illness);
    printf("Doctor: %s\n", appointmentArr[i].selectedDoctor);
    printf("Appointment Day: %d\n", appointmentArr[day - 1].dayOfmonth);
    printf("We look forward to seeing you on the %d-04-2023\n", appointmentArr[day - 1].dayOfmonth);
    printf("-------------------------------------------------\n");

}