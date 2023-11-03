# Solution3

## Weeding Pass
We added a new assignability checking logic to support array access expression, i.e. `a[n]` should be assginable.

## Type System
We added two TipTypes: `TipBool` and `TipArray` to support Boolean values and array constructs.
for `TipArray` we created a two constructors, one that takes no parameters for the empty array and one that takes a type parameter. We then modified the equality operator and print to accommodate for empty and nonempty arrays. For `TipBoolean`, we copied the format of `TipRef` and adjusted the print for bool operators. We ran into some challenges with `TipArray` for our tests due to the columns and rows now aligning but adding the empty array constructor seemed to fix our problem for now. 

## Type Constraints
In `TypeConstraintVisitor.cpp`, we first modified the type constraints of `while` and `if` statements so that the conditions are type Bool.
For the contraints for the regular array we added a check to see if it was empty. If it is empty then we returned the empty constructor. If not we grabbed the type from one of the elements. For the alternate array we separated the input. The first value is the count and the second value would be the type. 
We added type constraints for boolean expression, and/or/not expressions so that the arguments and results are all type Bool; we added type constraints for postfix statements so that the argument is type Int, t.
We also added type constraints for ternary expressions so that the condition is type Bool, and the alternative expressions are of the same type.
Finally, we added type constraints for for loop statements.
The iterator-style for loop statement is a little tricky, where we require that the iterable be of type array, and the iterator be of the same type as the element of array.

After that, we extended `TypeConstraintCollectTest.cpp` to test those newly added or modified type constraints.
