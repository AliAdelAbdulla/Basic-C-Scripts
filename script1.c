//Final Project - Task 1
//Ali Abdulla A00786, Mariam Hussein A00039
//American University of Bahrain
//COSC372L - Operating Systems Lab
//December 20, 2022

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1024

int main(void)
{
    // Allocate memory for input
    char input[MAX_INPUT_SIZE];
    
    // Prompt user to input data
    printf("Input data: ");
    
    // Read input using fgets
    if (fgets(input, MAX_INPUT_SIZE, stdin) != NULL) {
        printf("The inputted data is: %s", input);
    }
    
    return 0;
}
