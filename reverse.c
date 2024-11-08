#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>                 //importing libraries


void message_printer(const char *msg) {      //Function for printing errors and messages
    fprintf(stderr, "%s\n", msg);
    exit(1);
}



int main(int arg_counter, char *arg_select[]) {                 //defining main method, with future arguments

    FILE *inF = stdin;               //input variable, can be used for making manual input or for opening an input file, set to manual input
    FILE *outF = stdout;             //output variable, set to print the content by default, can be changed to a file
    char **lines_array = NULL;       //variable for storing the input lines
    size_t lines_counter = 0, lines_c = 10;        //Line counter. line capacity is also set for optimization (to be fixed)
    char *line = NULL;               //variable for single line initialization
    size_t length = 0;                  //variable for determining the length of the line, acts as a buffer size
    long read;                        //read variable, for reading the lines
    
    
    



    //creating if-conditions for each program run use case 
    

    if (arg_counter >= 2) {         //open input file in case if at least 1 argument provided

        

        inF = fopen(arg_select[1], "r");  
       


    } 

    //there's no condition for 0 arguments: do nothing in case of no arguments provided, keep the variables set to srdin & stdout


    if (arg_counter == 3) {              //open output file in case if 2 arguments provided

     //Checking if input and output files are different (part of the "Assumptions and Errors")

    if (strcmp(arg_select[1], arg_select[2]) == 0) {         //Using strcmp to compare    

            fclose(inF);  //closing the input file

            message_printer("Input and output file must differ");   //using universal function to print the error

            exit(1);   //exiting with error code
        }
       
        


        outF = fopen(arg_select[2], "w");
        
    }











    


    lines_array = malloc(lines_c * sizeof(char *));   //Allocating memory for the array
    
        


    //Creating a while loop for reading the lines, adding each line to array
        
    while ((read = getline(&line, &length, inF)) != -1) {

        //Adding handling for large input files("Assumptions and errors")
        
        if (lines_counter >= lines_c) {  //Checking of line count exceeds the line capacity
            lines_c *= 4;   // multiply the capacity x4 in case if it's exceeded

            lines_array = realloc(lines_array, lines_c * sizeof(char *));  //Reallocate the memory for the array
            

        }
        
        lines_array[lines_counter++] = strdup(line);  //add the line to the array

    }
    






    // Printing the lines using for-loop
    for (long i = lines_counter - 1; i >= 0; i--) {
        

        fprintf(outF, "%s", lines_array[i]);  //printing

        free(lines_array[i]);    //Freeing the array
    }
    








    free(lines_array);   //Freeing the array
    free(line);       //Freeing the line variable
    return 0;    //returning the function
    
    
    
}





