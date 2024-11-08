#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>                 //importing libraries






int main(int argc, char *argv[]) {                 //defining main method, with future arguments

    FILE *inF = stdin;               //input variable, can be used for making manual input or for opening an input file, set to manual input
    FILE *outF = stdout;             //output variable, set to print the content by default, can be changed to a file
    char **lines_array = NULL;       //variable for storing the input lines
    size_t lines_counter = 0, lines_c = 10;        //Line counter. line capacity is also set for optimization (to be fixed)
    char *line = NULL;               //variable for single line initialization
    size_t length = 0;                  //variable for determining the length of the line
    long read;                        //read variable, for reading the lines
    


    lines_array = malloc(lines_c * sizeof(char *));   //Allocating memory for the array
    
        


    //Creating a while loop for reading the lines, adding each line to array
        
    while ((read = getline(&line, &length, inF)) != -1) {
        
        if (lines_counter >= lines_c) {
            lines_c *= 2;

            lines_array = realloc(lines_array, lines_c * sizeof(char *));
            

        }
        
        lines_array[lines_counter++] = strdup(line);     

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




