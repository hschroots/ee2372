#include <stdio.h> //printf, scanf, fopen, fclose
#include <stdlib.h> //malloc, free, atexit, exit
#include <string.h> //memcpy, strcpy


char * filename;
FILE * data_file;

void printreverse(float data[], size_t size)
{
	printf("Printing data values in reverse order\n");
	for( int i = size-1; i >= 0; i-- )
	{
		printf("%.3f\n", data[i]);
	}
}

int binread()
{
	printf("Opening file %s\n", filename);
	data_file = fopen(filename, "rb");

	if(data_file != NULL)
	{
		float * float_data;
		int num_data_vals = 0;

		size_t num_read = fread(&num_data_vals, sizeof(int), 1, data_file);

		if(num_read != 0)
		{
			printf("Reading %d floats from the data file\n", num_data_vals);

			float_data = (float*)malloc(num_data_vals);
		
			num_read = fread(float_data, sizeof(float), num_data_vals, data_file);
			
			if( num_read != 0 )
				printreverse(float_data, num_data_vals);
		}
		else
			printf("Unable to read file\n");	
	}
	else
	{
		printf("Unable to open data file\n");
		return 1;
	}

	return 0;
}


void parseargs(int argc, char ** argv)
{
	char * input_arg_ptr = argv[1];

	//+1 for null terminating char
	int len = strlen(input_arg_ptr) + 1;
	filename = (char*)malloc(len);

	strncpy(filename, input_arg_ptr, len);
}

int main(int argc, char ** argv)
{
	if( argc < 2 ) {
		printf("Usage: binread.out <filename>\n");
		return 1;
	}
	
	parseargs(argc, argv);

	data_file = NULL;
	int err = binread();
	if( err != 0 )
		return 1;
	return 0;	
}
