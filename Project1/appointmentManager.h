#pragma once
#pragma once

#define MAXSTRLEN 100
#define DAYSINMONTH 30

typedef struct Appointment {    //REQ-SYS-030 – The project uses struct 
    char Appointed[MAXSTRLEN];
    char firstName[MAXSTRLEN];
    char lastName[MAXSTRLEN];
    char gender[MAXSTRLEN];
    char illness[MAXSTRLEN];
    char selectedDoctor[MAXSTRLEN];
    int patientID;
    int dayOfmonth;
} APPOINTMENT;

