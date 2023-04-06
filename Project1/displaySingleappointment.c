#include <stdio.h>
#include "displaySingleappointment.h"


void displaySingleappointment(APPOINTMENT* appointments) {
    int day;
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Enter the day of the appointment: ");
    scanf("%d", &day);

    // Check if appointment is booked for the specified day
    if (strcmp(appointments[day - 1].Appointed, "True") == 0) {
        printf("-------------------------------------------------\n");
        printf("Appointment details for %d-04-2023:\n\n", day);
        printf("Patient's First Name: %s\n", appointments[day - 1].firstName);
        printf("Patient's Last Name: %s\n", appointments[day - 1].lastName);
        printf("Patient's ID: %d\n", appointments[day - 1].patientID);
        printf("Gender (M stands for Male and F stands for Female): %s\n", appointments[day - 1].gender);
        printf("Illness: %s\n", appointments[day - 1].illness);
        printf("Doctor: %s\n", appointments[day - 1].selectedDoctor);
        printf("Appointment Day: %d-04-2023\n", appointments[day - 1].dayOfmonth);
        printf("-------------------------------------------------\n");
    }
    else {
        printf("No appointment booked for %d-04-2023.\n", day);
    }
}

