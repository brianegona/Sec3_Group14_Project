#include "deleteappointment.h"
#include "printAppointmentmenu.h"

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void deleteAppointment(APPOINTMENT* delete) {
    int deleteday = 0;								//variable to delete day was made and intitilized
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Please enter the appointment day that you wish to delete (press 0 to return to menu):");		//user is asked for day he wishes do delete appointment
    scanf("%d", &deleteday);

    if (deleteAppointment != 0) {
        if (!strncmp(delete[deleteday - 1].Appointed, "True", MAXSTRLEN)) {			//this checks if the day entered by user as an appointment
            printf("-------------------------------------------------\n");
            printf("Your appointment deletion was succesfull!!!\n");
            printf("Below is a Summary of your appointment deletion: \n\n");
            printf("Patient's First Name: %s\n", delete[deleteday - 1].firstName);
            printf("Patient's Last Name: %s\n", delete[deleteday - 1].lastName);
            printf("Patient's ID: %d\n", delete[deleteday - 1].patientID);
            printf("Gender (M stands for Male and F stands for Female): %s\n", delete[deleteday - 1].gender);
            printf("Illness: %s\n", delete[deleteday - 1].illness);
            printf("Doctor: %s\n", delete[deleteday - 1].selectedDoctor);
            printf("Appointment Day: %d\n", delete[deleteday - 1].dayOfmonth);
            printf("We look forward to seeing you on the %d-04-2023\n", delete[deleteday - 1].dayOfmonth);
            printf("-------------------------------------------------\n");

            //this deletes the appointments and returns them to how they were at the start(initialized)
            delete[deleteday].dayOfmonth = deleteday + 1;
            strncpy(delete[deleteday - 1].Appointed, "False", MAXSTRLEN);
            delete[deleteday].patientID = rand() % 10000;
            strncpy(delete[deleteday - 1].firstName, "", MAXSTRLEN);
            strncpy(delete[deleteday - 1].lastName, "", MAXSTRLEN);
            strncpy(delete[deleteday - 1].gender, "", MAXSTRLEN);
            strncpy(delete[deleteday - 1].illness, "", MAXSTRLEN);
            strncpy(delete[deleteday - 1].selectedDoctor, "", MAXSTRLEN);

        }

    }
    else {
        printAppointmentmenu();
    }

}


