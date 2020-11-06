int main()
{
	//int a[100];
	//int *p =a;
	//p +=2;
	//printf("%d",p == &a[3] ? 1:0);
	
	int *p;
	*p=5;
	*p+=2;
     //*p = *p+2;
	printf("%d",*p);
}