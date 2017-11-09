#include <stdio.h>

const int ARRAY_SIZE = 20;

double arrmin(double array[], int size)
{
	double min_val = array[0];
	for( int i = 1; i < size; i++) {
		if(array[i] < min_val)
			min_val = array[i];
	}
	return min_val;
}

double arrmax(double array[], int size)
{

	double max_val = array[0];
	for( int i = 1; i < size; i++ ) {
		if( array[i] > max_val )
			max_val = array[i];
	}
	return max_val;
}

double arraver(double array[], int size)
{

	double sum = 0;
	for(int i=0; i < size; i++)
		sum+=array[i];
	return sum/(double)size;

}

void arrstats(double array[], int size)
{
	double min_val = arrmin(array, size);
	double max_val = arrmax(array, size);
	double avr_val = arraver(array, size);

	printf("Array min: %lf\n", min_val);
	printf("Array max: %lf\n", max_val);
	printf("Array average: %lf\n", avr_val);
}

void fillarray(double array[], int size)
{
	for( int i = 0; i< size; i++ )
		array[i] = (double)i;
}

void testarrstats()
{
	double test_array[10];

	double expected_min = 0.0;
	double expected_max = 9.0;
	double expected_avr = 4.5;

	fillarray(test_array, 10);
	printf("-------Testing array stats----------\n");
	
	double min_val = arrmin(test_array, 10);
	double max_val = arrmax(test_array, 10);
	double avr_val = arraver(test_array, 10);
	
	if( min_val != expected_min )
		printf("ERROR: array min test failed\n");
	else
		printf("Array min test PASS\n");
	if( max_val != expected_max )
		printf("ERROR: array max test failed\n");
	else
		printf("Array max test PASS\n");
	if( avr_val != expected_avr )
		printf("ERROR: array average test failed\n");
	else
		printf("Array average test PASS\n");
	printf("-------Test Complete----------\n\n\n");
}

int main(void)
{
	//testarrstats();

	double num_array[ARRAY_SIZE];
	
	printf("Please enter up to %d double floats\n", ARRAY_SIZE);

	/*int input_idx = 0;
	while( scanf("%lf...", num_array) )
	{
		printf("blue\n");
		input_idx++;
		if(input_idx >= ARRAY_SIZE)
			break;
	}
	*/
	scanf("%lf", num_array);
	for(int i=0; i < ARRAY_SIZE; i++)
		printf("[%d] = %lf\n", i, num_array[i]);
	arrstats(num_array, ARRAY_SIZE);

	return 0;
}
