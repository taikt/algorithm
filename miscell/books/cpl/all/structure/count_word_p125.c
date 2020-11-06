#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD			100

// binary tree 
struct tnode {  
	char *word; // point to text
	int count; // number of occurences
	struct tnode *left; // left child
	struct tnode *right; // right child
};

struct tnode	*addtree (struct tnode *p, char *w);
void		treeprint (struct tnode *p);
int 		getword (char *word, int lim);

int main (int argc, char *argv[])

{
	struct tnode	*root;
	char		word[MAXWORD];

	/* Keywords are not inserted in the binary tree. */

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
		root = addtree(root, word);

	treeprint(root);

	return 0;
}

struct tnode	*talloc (void);
char		*_strdup (char *s);

struct tnode *addtree (struct tnode *p, char *w)
{
	int	cond;

	if (p == NULL) {

		p = talloc();
		p->word = _strdup(w);
		p->count = 1;
		p->left = p->right = NULL;

	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++; // repeated word
	else if (cond <0)
		p->left = addtree(p->left, w);
	else 
		p->right = addtree(p->right, w);

	return p;
}

struct tnode *talloc (void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *_strdup (char *s)
{
	char	*p;

	if ((p = (char *) malloc(strlen(s) + 1)) != NULL)
		strcpy(p, s);

	return p;
}

void treeprint (struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%d %s\n",p->count, p->word);
		treeprint(p->right);
	}
}

int	getch (void);
void	ungetch (int c);

/* See exercise 6-1 for a description of the updated getword() function. */

int getword (char *word, int lim)
{
    int	c, d;
	char	*w = word;

    while (isspace(c = getch()))
	;
	
	if (c != EOF)
		*w++ = c;
		if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	
	for ( ; --lim > 0; w++)
	if (!isalnum(*w = getch())) {
	ungetch(*w);
	break;
	}
	*w = '\0';
	
	return word[0];	
}

#define BUFSIZE 100

char    buf[BUFSIZE];
int     bufp = 0;

int getch (void)
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch (int c)
{
    if (bufp >= BUFSIZE)
		printf("Error: Too many characters!\n");
	else
		buf[bufp++] = c;
}
