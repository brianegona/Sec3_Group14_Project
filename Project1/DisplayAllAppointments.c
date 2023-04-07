#include "DisplayAllAppointments.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


void displayAllappointments(APPOINTMENT* appointments) {
    printf("All Appointments:\n");

    int i;
    printf("----------------------------------------------------------------------------------------------\n");
    for (i = 0; i < DAYSINMONTH; i++) {
        if (strcmp(appointments[i].Appointed, "True") == 0) {
            printf("Patient ID: %d\n", appointments[i].patientID);
            printf("First Name: %s\n", appointments[i].firstName);
            printf("Last Name: %s\n", appointments[i].lastName);
            printf("Gender: %s\n", appointments[i].gender);
            printf("Illness: %s\n", appointments[i].illness);
            printf("Selected Doctor: %s\n", appointments[i].selectedDoctor);
            printf("Appointment Date: %d-04-2023\n\n", appointments[i].dayOfmonth);
        }
    }
    printf("----------------------------------------------------------------------------------------------\n");

}