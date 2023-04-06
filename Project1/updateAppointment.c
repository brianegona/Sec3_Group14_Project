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
    printf("Enter the day of the appointment you wish to update: ");
    scanf("%d", &day);

    int i;
    for (i = 0; i < 30; i++) {
        if (appointmentArr[i].dayOfmonth == day) {
            printf("Appointment found! Please enter new details:\n");

            // Prompt the user to update appointment details using dynamic allocation
            char* firstName = (char*)malloc(sizeof(char) * MAXSTRLEN);
            printf("Enter first name: ");
            scanf("%s", firstName);
            strcpy(appointmentArr[i].firstName, firstName);
            free(firstName);        //REQ-SYS-050

            char* lastName = (char*)malloc(sizeof(char) * MAXSTRLEN);
            printf("Enter last name: ");
            scanf("%s", lastName);
            strcpy(appointmentArr[i].lastName, lastName);
            free(lastName);         //REQ-SYS-050

            char* gender = (char*)malloc(sizeof(char) * MAXSTRLEN);
            printf("Enter gender (M/F): ");
            while (scanf("%s", gender) != 1 || (strcmp(gender, "M") != 0 && strcmp(gender, "F") != 0)) {
                printf("Invalid input. Please enter a valid gender (M/F): ");
                clearInputBuffer();
            }
            strcpy(appointmentArr[i].gender, gender);
            free(gender);           //REQ-SYS-050

            char* illness = (char*)malloc(sizeof(char) * MAXSTRLEN);
            printf("Enter illness: ");
            scanf("%s", illness);
            strcpy(appointmentArr[i].illness, illness);
            free(illness);          //REQ-SYS-050

            char* selectedDoctor = selectDoctor();
            strcpy(appointmentArr[i].selectedDoctor, selectedDoctor);


            printf("-------------------------------------------------\n");
            printf("Appointment updated successfully!\n");
            printf("Below is a summary of your appointment: \n\n");
            printf("Patient's First Name: %s\n", appointmentArr[day - 1].firstName);
            printf("Patient's Last Name: %s\n", appointmentArr[day - 1].lastName);
            printf("Patient's ID: %d\n", appointmentArr[day - 1].patientID);
            printf("Gender (M stands for Male and F stands for Female): %s\n", appointmentArr[day - 1].gender);
            printf("Illness: %s\n", appointmentArr[day - 1].illness);
            printf("Doctor: %s\n", appointmentArr[day - 1].selectedDoctor);
            printf("Appointment Day: %d\n", appointmentArr[day - 1].dayOfmonth);
            printf("We look forward to seeing you on the %d-04-2023\n", appointmentArr[day - 1].dayOfmonth);
            printf("-------------------------------------------------\n");
            break;
        }
    }

    if (i == DAYSINMONTH) {
        printf("Appointment not found!\n");
    }
}

