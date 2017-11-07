//This function swaps two pointers
//At the end of this function, the left_ptr
//will be pointing to what the right_ptr was pointing to
//and the right_ptr will be pointing to what the left_ptr
//was pointing to
void swap(double * left_ptr, double * right_ptr)
{
	double * tmp_ptr;

	tmp_ptr = left_ptr;
	left_ptr = right_ptr;
	right_ptr = tmp_ptr;

}

void dsort(double * first_ptr, double * middle_ptr, double * last_ptr)
{

	if( *first_ptr < *middle_ptr)
		//do nothing
	else
		swap(first_ptr, middle_ptr);
	
	if( *first_ptr < *last_ptr )
		//do nothing
	else
		swap(first_ptr, last_ptr);
	//After these 2 if-else blocks we are guaranteed
	//that first_ptr is pointing to the smallest element
	
	if( *middle_ptr < *last_ptr )
		//do nothing
	else
		swap(middle_ptr, last_ptr);
	//After this we are guaranteed that the pointers are in order
}


int main(void)
{
	//Can also be delcared as
	//double first, middle, last;
	double first;
	double middle;
	double last;

	printf("Enter 3 double floats in any order");

	scanf( "%lf", first);
	scanf( "%lf", middle);
	scanf( "%lf", last);

	//The "&" symbol tell the compiler that we are sending
	//the address of these variables, not their values
	dsort( &first, &middle, &last );

	return 0;
}
