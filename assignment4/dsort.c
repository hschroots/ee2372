#include <stdio.h>

//This function swaps two pointers
//At the end of this function, the left_ptr
//will be pointing to what the right_ptr was pointing to
//and the right_ptr will be pointing to what the left_ptr
//was pointing to
void swap(double ** left_ptr, double ** right_ptr)
{
	double * tmp_ptr;

	tmp_ptr = *left_ptr;
	//printf("tmp should now be pointing to the same thing left_ptr is pointing to: ");
	//printf("tmp address: %p, left_ptr address: %p\n", tmp_ptr, *left_ptr);
	*left_ptr = *right_ptr;
	//printf("left should now be pointing to the same thing right_ptr is pointing to: ");
	//printf("left address: %p, right_ptr address: %p\n", *left_ptr, *right_ptr);
	*right_ptr = tmp_ptr;
	//printf("right should now be pointing to the same thing tmp_ptr is pointing to: ");
	//printf("right address: %p, tmp_ptr address: %p\n", *right_ptr, tmp_ptr);
}

void dsort(double * first_ptr, double * middle_ptr, double * last_ptr)
{
	if( *first_ptr < *middle_ptr)
		;//do nothing
	else
		swap(&first_ptr, &middle_ptr);
	
	if( *first_ptr < *last_ptr )
		;//do nothing
	else
	{
		swap(&first_ptr, &last_ptr);
		//Check to see if the new first_ptr
		//is smaller than the middle_ptr
		if( *first_ptr < *middle_ptr )
			; //do nothing
		else
			swap(&first_ptr, &middle_ptr);
	}
	//After these 2 if-else blocks we are guaranteed
	//that first_ptr is pointing to the smallest element
	
	if( *middle_ptr < *last_ptr )
		;//do nothing
	else
		swap(&middle_ptr, &last_ptr);
	//After this we are guaranteed that the pointers are in order

	//print the values of the pointers. This requires us to dereference them
	printf("The smallest value is: %lf\n", *first_ptr);
	printf("The middle value is: %lf\n", *middle_ptr);
	printf("The largest value is: %lf\n", *last_ptr);
}


void swaptest()
{
	double val1 = 3.14;
	double val2 = 5.67;

	double * first = &val1;
	printf("first:%p\n", first);

	double * second = &val2;
	printf("second:%p\n", second);

	double * first_cpy = first;
	double * second_cpy = second;
	printf("first_cpy:%p\n", first_cpy);
	printf("second_cpy:%p\n", second_cpy);

	swap(&first, &second);

	printf("------- AFTER SWAP ---------\n");

	
	printf("first:%p\n", first);
	printf("second:%p\n", second);
	printf("first_cpy:%p\n", first_cpy);
	printf("second_cpy:%p\n", second_cpy);

	if(first_cpy == first)
		printf("swap failed for first pointer\n");
	if(second_cpy == second)
		printf("swap failed for second pointer\n");
}

int main(void)
{
	//swaptest();

	//Can also be delcared as
	//double first, middle, last;
	double first;
	double middle;
	double last;

	printf("Enter 3 double floats in any order\n");

	scanf( "%lf", &first);
	scanf( "%lf", &middle);
	scanf( "%lf", &last);

	//The "&" symbol tell the compiler that we are sending
	//the address of these variables, not their values
	dsort( &first, &middle, &last );

	return 0;
}
