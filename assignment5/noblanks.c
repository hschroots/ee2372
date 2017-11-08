#include <stdio.h>

const int MAX_CHARS = 4096; //4096 chars x 1 byte per char = 4KB!

void noblanks(char * str)
{
	printf("The string before:\n");
	printf("%s\n", str);

	char * iter = str;
	int offset = 0;

	while(*iter != '\n')
	{
		if(*iter == ' ')
			offset++;
		iter++;
		*(iter-offset) = *iter;
	}
	iter -= offset;
	while( *iter != '\n')
		*iter++ = '\n';	
	
	printf("The string after:\n");
	printf("%s\n", str);
	fflush(stdout);
}

int main(void)
{
	char input[MAX_CHARS];
	//fill the array with new line characters
	for( int i = 0; i < MAX_CHARS; i++ )
		input[i] = '\n';

	printf("Enter a string with spaces. Press Enter to quit-->\n");
	
	while( scanf("%[^\n]%*c", input) ) {

		printf("Removing all the spaces from the string\n");
		noblanks(input);
		
		printf("\n\nEnter a string with spaces. Press Enter to quit-->\n");
	}

	printf("\n\nEnd of program\n");
	return 0;
}
