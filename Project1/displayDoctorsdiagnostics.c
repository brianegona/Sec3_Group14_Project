#include "displaydoctorsdiagnostics.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

void printHeart() {
    

    printf("    ********      ********\n");
    printf("  ************  ************\n");
    printf("******************************\n");
    printf("******************************\n");
    printf(" *****************************\n");
    printf("  ***************************\n");
    printf("   ************************\n");
    printf("     ******************** \n");
    printf("      ******************\n");
    printf("        **************\n");
    printf("          **********\n");
    printf("            ******  \n");
    printf("              **  \n");

    printf("     DIAGNOSTIC REPORT!!!\n\n");
}

void displayDoctorsdiagnostics(APPOINTMENT* appointments) { //REQ-SYS-070 - data storage and manipulation shall us pointers
    printHeart();
    printf("----------------------------------------------------------------------------------------------------------------\n");
    
    int i = 0;
    printf("Diagnostic Reports for Dr. John Bratt:\n");
    //printf("*************************************************************************************************\n");
        for (i = 0; i < 30; i++) {
            if (strcmp(appointments[i].selectedDoctor, "Dr. John Bratt") == 0) {
                printf("Day of Test: %d-04-2023\n", appointments[i].dayOfmonth);
                printf("Patient ID: %d\n", appointments[i].patientID);
                printf("Patient Name: %s %s\n", appointments[i].firstName, appointments[i].lastName);
                printf("Chief Complaint: %s\n", appointments[i].illness);
                printf("Diagnostics: Based on the results of the lab test, it shows that the patient is diagnosed with %s\n", appointments[i].illness);
                printf("Treatment: The patient shall be given the adequate medicines for their illness in %s, and would be invited for another test in the next 7 days to see thier recovery progress\n\n", appointments[i].illness);
            }
        }
    printf("*************************************************************************************************\n\n");
  

    printf("Diagnostic Reports for Dr. Dr. Grish Patel:\n");
    //printf("*************************************************************************************************\n");
    for (int i = 0; i < 30; i++) {
        if (strcmp(appointments[i].selectedDoctor, "Dr. Grish Patel") == 0) {
            printf("Day of Test: %d-04-2023\n", appointments[i].dayOfmonth);
            printf("Patient ID: %d\n", appointments[i].patientID);
            printf("Patient Name: %s %s\n", appointments[i].firstName, appointments[i].lastName);
            printf("Chief Complaint: %s\n", appointments[i].illness);
            printf("Diagnostics: Based on the results of the lab test, it shows that the patient is diagnosed with %s\n", appointments[i].illness);
            printf("Treatment: The patient shall be given the adequate medicines for their illness in %s, and would be invited for another test in the next 7 days to see thier recovery progress\n\n", appointments[i].illness);
        }
    }
    printf("*************************************************************************************************\n\n");

    printf("Diagnostic Reports for Dr. Mary Waters:\n");
    
    for (int i = 0; i < 30; i++) {
        if (strcmp(appointments[i].selectedDoctor, "Dr. Mary Waters") == 0) {
            printf("Day of Test: %d-04-2023\n", appointments[i].dayOfmonth);
            printf("Patient ID: %d\n", appointments[i].patientID);
            printf("Patient Name: %s %s\n", appointments[i].firstName, appointments[i].lastName);
            printf("Chief Complaint: %s\n", appointments[i].illness);
            printf("Diagnostics: Based on the results of the lab test, it shows that the patient is diagnosed with %s\n", appointments[i].illness);
            printf("Treatment: The patient shall be given the adequate medicines for their illness in %s, and would be invited for another test in the next 7 days to see thier recovery progress\n\n", appointments[i].illness);
        }
    }
    printf("*************************************************************************************************\n");

    printf("----------------------------------------------------------------------------------------------------------------\n");

}


