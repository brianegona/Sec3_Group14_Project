#include "displayDoctorsappointmentHistory.h"
#include <stdio.h>
#include <stdlib.h>

void displayDoctorsappointmentHistory(APPOINTMENT* appointments){   //REQ-SYS-070 - data storage and manipulation shall us pointers
    // define bit masks for each doctor
    //REQ-SYS-080 - data processing using bit manipulation
    const int DR_JOHN_BRATT = 1 << 0;   // bit 0
    const int DR_GRISH_PATEL = 1 << 1;  // bit 1
    const int DR_MARY_WATERS = 1 << 2;  // bit 2

    // initialize counters for each doctor
    int countJohnBratt = 0;
    int countGrishPatel = 0;
    int countMaryWaters = 0;

    // define arrays for each doctor's appointment days
    int johnBrattDays[30] = { 0 };
    int grishPatelDays[30] = { 0 };
    int maryWatersDays[30] = { 0 };

    // loop through appointments and count appointments for each doctor
    for (int i = 0; i < 30; i++) {
        if (strcmp(appointments[i].selectedDoctor, "Dr. John Bratt") == 0) {
            countJohnBratt++;
            johnBrattDays[i] = 1;
        }
        else if (strcmp(appointments[i].selectedDoctor, "Dr. Grish Patel") == 0) {
            countGrishPatel++;
            grishPatelDays[i] = 1;
        }
        else if (strcmp(appointments[i].selectedDoctor, "Dr. Mary Waters") == 0) {
            countMaryWaters++;
            maryWatersDays[i] = 1;
        }
    }

    // print appointment history for each doctor
    printf("Appointment history for Dr. John Bratt:\n");
    printf("Total appointments: %d\n", countJohnBratt);
    printf("Days of appointments: ");
    for (int i = 0; i < 30; i++) {
        if (johnBrattDays[i] == 1) {
            printf("%d-04-2023,  ", i + 1);
        }
    }
    printf("\n*************************************************************************************************\n\n");

    printf("Appointment history for Dr. Grish Patel:\n");
    printf("Total appointments: %d\n", countGrishPatel);
    printf("Days of appointments: ");
    for (int i = 0; i < 30; i++) {
        if (grishPatelDays[i] == 1) {
            printf("%d-04-2023, ", i + 1);
        }
    }
    printf("\n*************************************************************************************************\n\n");

    printf("Appointment history for Dr. Mary Waters:\n");
    printf("Total appointments: %d\n", countMaryWaters);
    printf("Days of appointments: ");
    for (int i = 0; i < 30; i++) {
        if (maryWatersDays[i] == 1) {
            printf("%d-04-2023, ", i + 1);
        }
    }
    printf("\n*************************************************************************************************\n\n");
}



