typedef struct stack_t *  sstack;

/**
 * Type for individual stack entry
 */
struct stack_entry {
  char *data;
  struct stack_entry *next;
};

/**
 * Type for stack instance
 */
struct stack_t
{
  struct stack_entry *head;
  size_t stackSize;
};

/**
 * Create a new stack instance
 */
sstack newStack(void)
{
  sstack stack = malloc(sizeof *stack);
  if (stack)
  {
    stack->head = NULL;
    stack->stackSize = 0;
  }
  return stack;
}

/**
 * Make a copy of the string to be stored (assumes  
 * strdup() or similar functionality is not
 * available
 */
char *copyString(char *str)
{
  char *tmp = malloc(strlen(str) + 1);
  if (tmp)
    strcpy(tmp, str);
  return tmp;
}

/**
 * Push a value onto the stack
 */
void push(sstack theStack, char *value)
{
  struct stack_entry *entry = malloc(sizeof *entry); 
  if (entry)
  {
    entry->data = copyString(value);
    entry->next = theStack->head;
    theStack->head = entry;
    theStack->stackSize++;
  }
  else
  {
    // handle error here
  }
}

/**
 * Get the value at the top of the stack
 */
char *top(sstack theStack)
{
  if (theStack && theStack->head)
    return theStack->head->data;
  else
    return NULL;
}

/**
 * Pop the top element from the stack; this deletes both 
 * the stack entry and the string it points to
 */
char *pop(sstack theStack)
{
  char *ret = top(theStack);
  if (theStack->head != NULL)
  {
    struct stack_entry *tmp = theStack->head;
    theStack->head = theStack->head->next;
    theStack->stackSize--;
  }
  return ret;
}

// /**
//  * Clear all elements from the stack
//  */
// void clear (sstack theStack)
// {
//   while (theStack->head != NULL)
//     pop(theStack);
// }

// /**
//  * Destroy a stack instance
//  */
// void destroyStack(sstack *theStack)
// {
//   clear(*theStack);
//   free(*theStack);
//   *theStack = NULL;
// }