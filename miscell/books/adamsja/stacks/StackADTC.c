/** Stack Example ADT - A Data Hiding Stack
    Julie A. Adams
**/

#include <stdio.h>
#include <stdlib.h>
#include "StackADTC.h"

int Stack_create (Stack *s, size_t size) {
  s->stack_ = malloc (size * sizeof(T));
  s->top_ = 0;
  s->size_ = size;
  return s->stack_ == 0 ? -1 : 0;
}

void Stack_destroy (Stack *s)
{
  free ((void *) s->stack_);
  s->top_ = 0;
  s->size_ = 0;
  s->stack_ = 0;
}

void Stack_push (Stack *s, T item)
{
  s->stack_[s->top_] = item;
  s->top_++;
}

void Stack_pop (Stack *s, T *item)
{
  *item = s->stack_[--s->top_];
}

int Stack_top (Stack *s, T *item)
{
  *item = s->stack_[s->top_ - 1];

  return *item;
}
int Stack_is_empty (Stack *s)
{
  return s->top_ == 0;
}

int Stack_is_full (Stack *s)
{
  return s->top_ == s->size_;
}

