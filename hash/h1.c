//https://www.cs.cmu.edu/~adamchik/15-121/lectures/Hashing/hashing.html
//http://algs4.cs.princeton.edu/34hash/

// note: use link list to avoid colision (same hash code)
// objects with same hash code will put to a linked list
// hashcode:
// s.charAt(0) * 31^(n-1) + s.charAt(1) * 31^(n-2) + ... + s.charAt(n-1)
// hashcode -> module(M=31) -> index
// hashtable: mapping between object and index

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBUCKET 1000
#define MULTIPLIER 31
#define MAXLEN 100

typedef struct _wordrec
{
	char* word;
	unsigned long count;
	struct wordrec* next;
} wordrec;

#if 0
wordrec* walloc(const char* str)
{
	wordrec* p = (wordrec*) malloc(sizeof(wordrec));
	if (p!= NULL)
	{
		p->count = 0;
		p->word = strdup(str);
		p->next = NULL;
	}
	return p;
}
#endif

wordrec* table[MAXLEN];

unsigned long hashstring(const char* str)
{
	unsigned long hash = 0;
	while (*str)
	{
		hash = hash*MULTIPLIER + *str;
		str++;
	}
	
	return hash % MAXBUCKET;
}

wordrec* lookup(const char *str, int create)
{
	unsigned long hash = hashstring(str);
	printf("str=%s, hash=%ld\n", str, hash);
	wordrec* wp = table[hash];

#if 1	
	wordrec* curr = NULL;
	for (curr= wp; curr!= NULL; curr=curr->next)
	if (strcmp(curr->word, str) == 0)
		return curr;
#endif
	//if (wp != NULL) return wp;
	if (create)
	{
		curr = (wordrec*)malloc(sizeof(wordrec));
		curr->word = strdup(str);
		curr->count = 0;
		
		curr->next = table[hash];
		table[hash] = curr;
	}
	
	return curr;
}

void clearable()
{
	wordrec* wp = NULL;
	wordrec* p = NULL; 
	int i =0;
	for (i=0; i<MAXBUCKET; i++)
	{
		wp = table[i];
		while (wp)
		{
			p = wp;
			wp = wp->next;
			free(p->word);
			free(p);
		}
	}
}

int main(int argc, char* argv[])
{
	FILE* fp = fopen("book.txt","r");
	char word[1024];
	wordrec* wp = NULL;
	int i =0;
	
	memset(table, 0, sizeof(table));
	printf("create hashing\n");
	while (1)
	{
		if (fscanf(fp, "%s", word) != 1)
		break;
		wp = lookup(word, 1);
		wp->count++;
	}
	fclose(fp);
	
	printf("\nhash table:\n");
	for (i =0; i< MAXBUCKET; i++)
	{
		for (wp=table[i]; wp!= NULL; wp=wp->next)
		{
			printf("table %d:%s->%ld\n", i, wp->word, wp->count);
		}
	}
	
	clearable();
	return 0;
}



