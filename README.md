push_swap's objective is to sort data on a stack with a limited set of instructions, aiming for the lowest possible 
number of actions.

Game Rules:
The game involves two stacks, named “a” and “b.”

Stack “a” contains a random number of positive or negative integers without duplicates.

Stack “b” starts empty.

The goal is to sort the numbers in ascending order on stack “a.”
  
Available Operations:

    sa: Swap the first two elements at the top of stack “a.”
    
    sb: Swap the first two elements at the top of stack “b.”
    
    ss: Perform sa and sb simultaneously.
    
    pa: Push the first element from stack “b” to stack “a.”
    
    pb: Push the first element from stack “a” to stack “b.”
    
    ra: Rotate all elements of stack “a” upward (first element becomes last).
    
    rb: Rotate all elements of stack “b” upward (first element becomes last).
    
    rr: Perform ra and rb simultaneously.
    
    rra: Reverse rotate all elements of stack “a” downward (last element becomes first).
    
    rrb: Reverse rotate all elements of stack “b” downward (last element becomes first).
    
    rrr: Perform rra and rrb simultaneously.
