#include "copyfile.h"
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void copyFile() {
        int id;
    // Open the input and output files
    //FILE* inputFile = fopen_s("input.txt", "rb", stdin);
    //FILE* outputFile = fopen_s("output.txt", "wb", stdout);

        FILE* inputFile;

        FILE* outputFile;

    if ((inputFile = fopen("input.dat", "r")) == NULL)
    {


        if (inputFile == NULL) {
            inputFile = fopen("input.dat", "w");
            if (inputFile == NULL) {
                printf("Error opening file %s for writing.\n");
                return;
            }
        }
        else {
            fclose(inputFile);
            inputFile = fopen("input.dat", "a");
            if (inputFile == NULL) {
                printf("Error opening file %s for appending.\n");
                return;
            }
        }
        printf(stderr, "Could not open file input.txt'.\n");
        exit(EXIT_FAILURE);
    }


    if ((outputFile = fopen("output.dat", "w")) == NULL)
    {
        printf(stderr, "Could not open file output.txt'.\n");
        exit(EXIT_FAILURE);
    }
    
    /*
// Copy the contents of the input file to the output file
char c;
while ((c = fgetc(inputFile)) != EOF) {
    fputc(c, outputFile);
}
*/

//Copy the contents of the input file to the output file
    char buffer[4096];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)) > 0) {
        fwrite(buffer, 1, bytesRead, outputFile);
    }


// Close the input and output files
fclose(inputFile);
fclose(outputFile);


}
