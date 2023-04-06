#include "addAppointment.h"
#include "printAppointmentmenu.h"

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

char* selectDoctor() {
    char doctor_choice;
    while (1) {
        printf("Please select a doctor:\n");
        printf("1. Dr. John Bratt\n");
        printf("2. Dr. Grish Patel\n");
        printf("3. Dr. Mary Waters\n");
        printf("Enter your choice (1-3): ");
        clearInputBuffer();
        doctor_choice = getchar();
        if (doctor_choice == '1' || doctor_choice == '2' || doctor_choice == '3') {
            break;
        }
        printf("Invalid input! Please select a valid doctor.\n");
    }
    clearInputBuffer();
    switch (doctor_choice) {
    case '1':
        return "Dr. John Bratt";
    case '2':
        return "Dr. Grish Patel";
    case '3':
        return "Dr. Mary Waters";
    }
}

// Function to generate a random patient ID
int generatePatientID() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int id = rand() % 100000; // Generate a random ID between 0 and 99999 => REQ-SYS-040
    return id;
}

void addAppointment(APPOINTMENT* newAppointment) {
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("The following days are the days in which the doctor is available:\n");
    for (int i = 0; i < 30; i++) {                  //loop was made to run through the 30 days of the month

        if (strcmp(newAppointment[i].Appointed, "False") == 0)         //this checks if day has an appointment and prints those that don't
        {
            printf("%d April, ", newAppointment[i].dayOfmonth);       //this prints the days without an appointment
        }

    }
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");


    int day;
    // Get day of the appointment
    printf("Enter the day of the appointment(Enter 0 to return to Menu): ");
    scanf("%d", &day);
    if (day < 1 || day > 30) {
        printf("Invalid input. Please enter a valid day (1-30): ");
        //clearInputBuffer();
    }
    else {

        if (day != 0) {
            if (strcmp(newAppointment[day - 1].Appointed, "False") == 0);
            // Get first name
            printf("Enter first name: ");
            scanf("%s", newAppointment[day - 1].firstName);

            // Get last name
            printf("Enter last name: ");
            scanf("%s", newAppointment[day - 1].lastName);

            //Generate a random ID for the patient
            newAppointment[day - 1].patientID = generatePatientID();

            // Select doctor
            char* selectedDoctor = selectDoctor();
            strcpy(newAppointment[day - 1].selectedDoctor, selectedDoctor);

            // Get gender
            printf("Enter gender (M/F): ");
            while (scanf("%s", newAppointment[day - 1].gender) != 1 || (strcmp(newAppointment[day - 1].gender, "M") != 0 && strcmp(newAppointment[day - 1].gender, "F") != 0)) {
                printf("Invalid input. Please enter a valid gender (M/F): ");
                clearInputBuffer();
            }

            // Get illness
            printf("Enter illness: ");
            scanf("%s", newAppointment[day - 1].illness);

            // Mark the day as booked
            strcpy(newAppointment[day - 1].Appointed, "True");

            // Print summary of the appointment
            printf("-------------------------------------------------\n");
            printf("Appointment booking was successful!!!\n");
            printf("Below is a summary of your appointment: \n\n");
            printf("Patient's First Name: %s\n", newAppointment[day - 1].firstName);
            printf("Patient's Last Name: %s\n", newAppointment[day - 1].lastName);
            printf("Patient's ID: %d\n", newAppointment[day - 1].patientID);
            printf("Gender (M stands for Male and F stands for Female): %s\n", newAppointment[day - 1].gender);
            printf("Illness: %s\n", newAppointment[day - 1].illness);
            printf("Doctor: %s\n", newAppointment[day - 1].selectedDoctor);
            printf("Appointment Day: %d\n", newAppointment[day - 1].dayOfmonth);
            printf("We look forward to seeing you on the %d-04-2023\n", newAppointment[day - 1].dayOfmonth);
            printf("-------------------------------------------------\n");
        }
        else {
            printAppointmentmenu();
        }

    }

}


