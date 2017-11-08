#include <stdio.h>

void charblock( char c, int num_print, int num_lines)
{
	for( int line = 0; line < num_lines; line++ ) {
		for( int print = 0; print < num_print; print++ ) {
			printf("%c", c);
		}
		printf("\n");
		fflush(stdout); //The printf buffer must be flushed
		//otherwise the next iteration of the loop will be 
		//printed before this newline character is printed
	}
}

int main(void)
{

	printf("Please type the character you wish to print\n");
	char c;
	scanf("%c", &c);

	printf("How many times would you like to print that character?\n");
	int num_print;
	scanf("%d", &num_print);
	
	printf("How many lines would you like to print?\n");
	int num_lines;
	scanf("%d", &num_lines);

	charblock(c, num_print, num_lines);
	
	return 0;
}
