#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "appointmentManager.h"
#include "printAppointmentmenu.h"
#include "addAppointment.h"
#include "displaySingleappointment.h"
#include "exitAppointmentmanager.h"
#include "deleteappointment.h"
#include "updateappointment.h"
#include "Searchforanappointment.h"
#include "displayAllappointments.h"
#include "displayDoctorsappointmentHistory.h"
#include "displayDoctorsdiagnostics.h"
#include "copyFile.h"

//REQ-SYS-001 – Our general project has 4 independent modules 
int size = sizeof(APPOINTMENT);

int main(int argc, char* argv[])    //REQ-SYS-020 – The main was written as int main(int argc, char *argv) 
{
   

    APPOINTMENT appointments[30];

    for (int i = 0; i < 30; i++) {
        appointments[i].dayOfmonth = i + 1;
        strcpy(appointments[i].Appointed, "False");
        appointments[i].patientID = rand() % 10000; // generate a random patient ID
        strcpy(appointments[i].firstName, "");
        strcpy(appointments[i].lastName, "");
        strcpy(appointments[i].gender, "");
        strcpy(appointments[i].illness, "");
        strcpy(appointments[i].selectedDoctor, "");
    }

    bool loopcondition = true;

    int option = 0;

    printWelcome();
    printAppointmentmenu();

    do {

        printf("Enter an option for the above list: ", option);
        scanf_s("%d", &option);
        // check for command line argument
        if (argc > 1) {
            option = atoi(argv[1]);
        }
        else {
            printf("Usage: %s <option>\n", argv[0]);
            
            switch (option) {
            case 1:
                // add new appointment
                addAppointment(appointments);
                break;
            case 2:
                deleteAppointment(appointments);
                // delete existing appointment
                break;
            case 3:
                updateAppointment(appointments);
                // update existing appointment
                break;
            case 4:
                // display single appointment
                displaySingleappointment(appointments);
                break;
            case 5:
                // display all appointments
                displayAllappointments(appointments);
                break;
            case 6:
                // display doctor’s diagnostic report
                displayDoctorsdiagnostics(appointments);
                break;
            case 7:
                // display doctor appointment history with patients
                displayDoctorsappointmentHistory(appointments);
                break;
            case 8:
                // search for an appointment
                searchAppointment(appointments);
                break;
            case 9:
                // exit program
                copyFile();//copyFile is called just before the progrm is exited
                exitAppointmentmanager();
                break;
            default:
                printf("Invalid option was picked, please pick an option form 1-9.\n");
                break;
            }
            printAppointmentmenu();
        }
    } while (loopcondition);
    return 0;
}
