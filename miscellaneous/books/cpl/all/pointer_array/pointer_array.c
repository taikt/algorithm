int sub()
{
	return 0;
}

int change_array(int a[])
{
	a[0] = 5;
	return 0;
}

int change_array2(int* a)
{
	*a = 5;
	*(a+1)=4;
	return 0;
}

int change_int(int a)
{
	a	= 5;
	return 0;
}

int main()
{
    int a = 7;
	int arr[2] = {3,8};
	int * p; 
	// change to char* to check %p before and after
	// if char* p => after p++, p increase 1 byte (bfa03d38 -> bfa03d39)
	// if int* p => after p++, p increase 4 bytes (bfa03d38 -> bfa03d3c)
	// change_array(a) = change_array(&a[0]) = change_array(a+0)
	p=&a;
	printf("before %p\n",p);
	++p;
	//p++;
	printf("after %p %x %x\n",p,p, &p);
	
	printf("array before: %d %d\n", arr[0], arr[1]);
	//change_array(arr);
	change_array2(arr);
	printf("array after: %d %d\n", arr[0], arr[1]);
	// write strlen() in 2 ways: pass array and pointer of array name 
	// note: when a array name is passed to a function, what is passed is the
	// location of the initial element.
	
	printf("int before: %d\n", a);
	change_int(a);
	printf("int after: %d\n", a);
}