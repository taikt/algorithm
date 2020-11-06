// Copy t to s
void strcpy1(char *s, char *t) // wrong version
{
	// s, t is local variable, 
	// just copy pointer value, not content that pointer point to
	s = t;	
}

void strcpy2(char *s, char *t) // array subscript version
{
	int i = 0;
	while ((s[i] = t[i]) != '\0')
		i++;
}

void strcpy3(char *s, char *t) // pointer version 1
{
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}		
}

void strcpy4(char *s, char *t) // pointer version 2
{
	while ((*s++ = *t++) != '\0')
		;
}

void strcpy5(char *s, char *t) // pointer version 3
{
	while (*s++ = *t++)
		;
}

int main()
{
	char s[10] = {0};
	char t[10]="hello";
	
	char * p;
	p=&s;
	strcpy1(s,t);
	printf("pointer value/address=%x %x, 1st ele of arr=%x %x\n",p,p, &s[0], s);
	
}