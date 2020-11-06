/** A test file for StackADTC
    Julie A. Adams
**/
#include <stdio.h>
#include "StackADTC.h"

int  main () 
{
  /* create multiple stacks */
  Stack stack1;
  Stack stack2, stack3;
  T item, top_item;
 
  Stack_create(&stack1, 10); //structure passed by reference
  Stack_push(&stack1, 10);
  Stack_top(&stack1, &item);
  printf("top of Stack1 %d\n\n", item);

  // Stack_push(&stack2, 10); // Forgot to create stack2
  Stack_create(&stack2, 5);

  //Stack_pop(&stack3, &item); // popped an empty stack

  Stack_push (&stack2, 10);
  Stack_push (&stack2, 20);
  Stack_top(&stack2, &top_item);
  printf("top of stack2: %d\n\n", top_item);

  /* Disaster due to aliasing!!! */
  Stack_top(&stack1, &top_item);
  printf("top of stack1: %d\n", top_item);
  stack1 = stack2;
  Stack_top(&stack1, &top_item);
  printf("top of stack1 after assingment: %d \n\n", top_item);

  Stack_pop (&stack2, &item);
  Stack_top (&stack2, &top_item);
  printf("top of stack2: %d\n", top_item);
  
  // Stack_destroy(&stack3); //Destroy uninitialized stack

  //Stack_destroy(&stack1);
  //Stack_destroy(&stack2);

}
  
