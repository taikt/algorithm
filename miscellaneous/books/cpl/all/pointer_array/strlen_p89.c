/* strlen: return length of string s */
int strlen(char *s)
{
	int n;
	for (n = 0; *s != '\0'; s++)
	n++;
	return n;
}

int strlen(char *s)
{
	char *p = s;
	while (*p != '\0')
	p++;
	return p - s;
}

int main()
{
	char array[100] = "hello world";
	char *ptr ="hello world";
	
	printf("%d\n", strlen("hello world")); // string constant
	printf("%d\n",strlen(ptr));
	printf("%d\n",strlen(array));
	
	return 0;
}