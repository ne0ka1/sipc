# Solution3

## Weeding Pass
We added a new assignability checking logic to support array access expression, i.e. `a[n]` should be assginable.

## Type System
We added two TipTypes: `TipBool` and `TipArray` to support Boolean values and array constructs.
[Here: How we implemented TipArray.]

## Type Constraints
In `TypeConstraintVisitor.cpp`, we first modified the type constraints of `while` and `if` statements so that the conditions are type Bool.
[Here: type constraints for array]
We added type constraints for boolean expression, and/or/not expressions so that the arguments and results are all type Bool; we added type constraints for postfix statements so that the argument is type Int, t.
We also added type constraints for ternary expressions so that the condition is type Bool, and the alternative expressions are of the same type.
Finally, we added type constraints for for loop statements.
The iterator-style for loop statement is a little tricky, where we require that the iterable be of type array, and the iterator be of the same type as the element of array.

After that, we extended `TypeConstraintCollectTest.cpp` to test those newly added or modified type constraints.
