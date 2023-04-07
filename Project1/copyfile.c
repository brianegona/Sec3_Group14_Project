#include "copyfile.h"
#include <stdio.h>

void copyFile() {
    // Open the output file
    FILE* outputFile = fopen("Hospital data.txt", "w"); //REQ-SYS-060 – CopyFile() used function fopen()

    // Open the input file
    FILE* inputFile = fopen(__FILE__, "r");


    // Copy the contents of the input file to the output file
    char c;
    while ((c = fgetc(inputFile)) != EOF) {
        fputc(c, outputFile);
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);
}
