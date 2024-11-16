# Project 1: Warmup to C and Unix programming

**Authors**: Daniil Komov, Igor Zimarev

## Project Overview
For this mini-project, we made a simple C program which reverses lines of strings. The program works as a Unix utility and takes in lines of text as input (either manual input or through a file), then produces the lines in reversed order (either on screen or to output file).


## Usage
### Compiling
The reverse.c is the only codebase of the program. The program can be compiled with gcc using this command:
```bash
gcc -o reverse reverse.c
```
The repository already includes a compiled program.
### Running the Program
There are 3 ways to run the program:

**-0 arguments:**
```bash
./reverse
```
This command will run the program in manual input mode, after that it will be possible to write
as many lines as wished until the input is stopped (ctrl+D). The program will then print the
result on the screen.

**-1 argument:**

```bash
./reverse input.txt
```
This prompt will run the program in file input mode, it will open the input file, read the lines
and display the resulting reversing order on the screen. Paste input file name instead of
<input>.

**-2 arguments:**

```bash
./reverse input.txt output.txt
```
This prompt will run the program in file input/output mode, it will open the input file, read the
lines and write the resulting reversed order into the provided file (a new file will be created in
case an existing one is not found). Paste input file name instead of <input>, and output file
name instead of <output>

## Error Handling
- Input and output files have to be different, otherwise error will occur “Input and output file
must differ” .
- If the file is corrupt of unavailable, error will pop up “error: cannot open file ‘<file>’”.
- In case of internal memory allocation issue, a error message will appear “malloc failed”.


## Limitations
- The program has no line length or file size limitations, however, very large file may affect
system performance.



