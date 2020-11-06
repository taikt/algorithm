/*
 *  https://stackoverflow.com/questions/9656161/why-regexec-of-c-does-not-match-this-pattern-but-match-of-javascript-works
 *  check matching pattern 
 *
 */

#include <assert.h>
#include <stdio.h>
#include <sys/types.h>
#include <regex.h>

int main(void) {
  int r;
  regex_t reg;
  regmatch_t match[2];
  char *line = "----------------------- Page 1-----------------------";

  regcomp(&reg, "[-]{23}[ ]*Page[ ]*([0-9]*)[-]{23}", REG_ICASE | REG_EXTENDED);
  /*                                ^------^ capture page number */
  r = regexec(&reg, line, 2, match, 0);
  if (r == 0) {
    printf("Match!\n");
    printf("0: [%.*s]\n", match[0].rm_eo - match[0].rm_so, line + match[0].rm_so);
    printf("1: [%.*s]\n", match[1].rm_eo - match[1].rm_so, line + match[1].rm_so);
  } else {
    printf("NO match!\n");
  }

  return 0;
}
