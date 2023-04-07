#include "searchAappointment.h"
#include "printAppointmentmenu.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void printAppointment(APPOINTMENT appointment) {
    printf("Patient ID: %d\n", appointment.patientID);
    printf("First Name: %s\n", appointment.firstName);
    printf("Last Name: %s\n", appointment.lastName);
    printf("Gender(M stands for Male and F stands for Female): %s\n", appointment.gender);
    printf("Illness: %s\n", appointment.illness);
    printf("Selected Doctor: %s\n", appointment.selectedDoctor);
    printf("Appointment Date: %d-04-2023\n", appointment.dayOfmonth);
}


void searchAppointment(APPOINTMENT* appointmentArr) {
    int searchChoice;
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Please choose search option:\n");
    printf("1. Search by First Name\n");
    printf("2. Search by Last Name\n");
    printf("3. Search by Patient ID\n");
    scanf("%d", &searchChoice);
    clearInputBuffer();

    char searchName[20];
    int searchID;
    int i, found = 0;

    switch (searchChoice) {
    case 1:
        printf("Enter first name to search for: ");
        scanf("%s", searchName);

        for (i = 0; i < 30; i++) {
            if (strcmp(appointmentArr[i].firstName, searchName) == 0) {
                printf("----------------------------------------------------------------------------------------------\n");
                printf("Appointment was found!!!\n");
                printAppointment(appointmentArr[i]);

                found = 1;
            }
        }
        printf("----------------------------------------------------------------------------------------------\n");
        break;

    case 2:
        printf("Enter last name to search for: ");
        scanf("%s", searchName);

        for (i = 0; i < 30; i++) {
            if (strcmp(appointmentArr[i].lastName, searchName) == 0) {
                printf("----------------------------------------------------------------------------------------------\n");
                printf("Appointment was found!!!\n");
                printAppointment(appointmentArr[i]);
                found = 1;
            }
        }
        printf("----------------------------------------------------------------------------------------------\n");
        break;

    case 3:
        printf("Enter patient ID to search for: ");
        scanf("%d", &searchID);

        for (i = 0; i < 30; i++) {
            if (appointmentArr[i].patientID == searchID) {
                printf("----------------------------------------------------------------------------------------------\n");
                printf("Appointment was found!!!\n");
                printAppointment(appointmentArr[i]);
                found = 1;
                break;
            }
        }
        printf("----------------------------------------------------------------------------------------------\n");
        break;

    default:
        printf("Invalid choice!\n");
        return;
    }

    if (!found) {
        printf("Appointment not found!\n");
        printf("----------------------------------------------------------------------------------------------\n");
    }
}
