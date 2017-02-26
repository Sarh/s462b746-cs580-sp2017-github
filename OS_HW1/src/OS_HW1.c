/*
 ============================================================================
 Name        : OS_HW1.c
 Author      : Sarah Hall, s462b746
 Version     :
 Copyright   : GNU
 Description : Programming Assignment 1, due 9/14/2016, takes commands from cli and using fork(), wait() calls displays the Collatz conjecture in motion
 ============================================================================
 */

#include <stdio.h>
#include <unistd.h> // brings in the fork() command
#include <sys/wait.h> // for wait
#include <stdlib.h> // atoi lib call

int main(int argc, char **argv) {
	int input;
	int output;
	int i = 2;


	/*** Error checking to make sure that just the executable and input integer passed ***/
	if(argc != 2){
		fprintf(stderr, "Usage: %s <integer value> \n", argv[0]);
		return 1;
	}
	input = atoi(argv[1]);

	/** Need to provide error checking on the input **/
    if(input < 1 || input > 500000){
    	fprintf(stderr, "Usage: %s <integer value greater than 0 and less than 500,001>  \n", argv[0]);
    	return 1;

    }
    printf("%s%d%s", "The pid for this process (the parent) is ", (int)getpid(), ".\n");

	output = input;
	if(!fork()){ // the below is handled by the child
		printf("%s%d%s%d%s", "This process is handled by the child ", (int)getpid(), ". The parent id is ", (int)getppid(), ".\n\n");
		printf("%d%s", input, ", ");

		do{
			if((output & 1) == 0){ // input is even
				output = output / 2;
			} else { //input is odd
				output = 3*output+1;
			}
			printf("%d", output);
			if(i % 10 == 0 || output == 1){
				puts("");
			} else {
				printf("%s", ", ");
			}
			i++;
		}  while(output != 1);


	} else {
		wait(NULL); // wait for child to end
	}




	return EXIT_SUCCESS;
}

