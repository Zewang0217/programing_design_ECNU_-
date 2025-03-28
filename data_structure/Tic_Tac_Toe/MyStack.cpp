#include "MyStack.h"

template<class Stack_entry>
Error_code MyStack<Stack_entry>::push(const Stack_entry &item)
/*
Pre:  None.
Post: If the Stack is not full, item is added to the top
      of the Stack.  If the Stack is full,
      an Error_code of overflow is returned and the Stack is left unchanged.
*/
{
   Error_code outcome = success;
   if (count >= maxstack)
      outcome = overflow;
   else
      entry[count++] = item;
   return outcome;
}

template<class Stack_entry>
Error_code MyStack<Stack_entry>::pop()
/*
Pre:  None.
Post: If the Stack is not empty, the top of
      the Stack is removed.  If the Stack
      is empty, an Error_code of underflow is returned.
*/

{
   Error_code outcome = success;
   if (count == 0)
      outcome = underflow;
   else --count;
   return outcome;
}


template<class Stack_entry>
Error_code MyStack<Stack_entry>::top(Stack_entry &item) const
/*
Pre:  None.
Post: If the Stack is not empty, the top of
      the Stack is returned in item.  If the Stack
      is empty an Error_code of underflow is returned.
*/

{  
   Error_code outcome = success;
   if (count == 0)
      outcome = underflow;
   else
      item = entry[count - 1];
   return outcome;
}

template<class Stack_entry>
bool MyStack<Stack_entry>::empty() const //can't modify data of class, can't call fuc without const
/*
Pre:  None.
Post: If the Stack is empty, true is returned.
      Otherwise false is returned.
*/

{
   bool outcome = true;
   if (count > 0) outcome = false;
   return outcome;
}

template<class Stack_entry>
MyStack<Stack_entry>::MyStack()
/*
Pre:  None.
Post: The stack is initialized to be empty.
*/
{
   count = 0;
}

