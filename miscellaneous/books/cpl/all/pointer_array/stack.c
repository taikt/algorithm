//int a =5;
//char *p=&a;
char *p;

int pop(void)
{
   return *p--;
}

int push(int val)
{
	*p++ = val;
}

int main()
{
	p = malloc(1);
    printf("p=%x\n",p);
	push('2');
	push('5');
	push('8');

	printf("p=%x\n",p);
	printf("%c\n",pop());
	printf("p=%x\n",p);
	printf("%c\n",pop()); 
	printf("%c\n",pop()); 
}

