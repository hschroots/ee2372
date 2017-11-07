#include <stdio.h>

const int ARRAY_SIZE = 20;

double arrmin(double array[])
{
	double min_val = array[0];
	for( int i = 1; i < ARRAY_SIZE; i++)
	{
		if(array[i] < min_val)
			min_val = array[i];
	}
	return min_val;
}

double arrmax(double array[])
{

	double max_val = array[0];
	for( int i = 1; i < ARRAY_SIZE; i++)
	{
		if(array[i] > min_val)
			max_val = array[i];
	}
	return max_val;
}

double arraver(double array[])
{

	double sum = 0;
	for(int i=0; i < ARRAY_SIZE; i++)
		sum+=array[i];
	return sum/ARRAY_SIZE;

}

void arrstats(double array[])
{
	double min_val = arrmin(array);
	double max_val = arrmax(array);
	double avr_val = arraver(array);

	printf("Array min: %lf\n", min_val);
	printf("Array max: %lf\n", max_val);
	printf("Array average: %lf\n", avr_val);
}

int main(void)
{
	double num_array[ARRAY_SIZE];
	
	printf("Please enter up to %d double floats\n", ARRAY_SIZE);


	int input_idx = 0;
	while(scanf("%lf",num_array[input_idx]))
	{
		input_idx++;
		if(input_idx >= ARRAY_SIZE)
			break;
	}
	arrstats(num_array);

	return 0;
}
