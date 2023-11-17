# Solution4

## Codegen
For this deliverable, we encountered some challenges from previous design choices for our `TipArray` class. Previously, if an array was empty, we would return an empty array. However, the array should've been an array of type array. To fix this problem, we modified the `TipArray` Class and removed the if statement in the print method that returns only an empty array. Then we changed the `ASTArrayExpr` constraints to return an array of type array if empty. After making these changes, we had to modify some of our old unit tests to reflect the new code. 
Once we fixed the array issue, we tackled the rest of the Codegen functions. We started by reviewing each SIP Extension Node and removing the `nullptr` return. 
Then we created functions in `CodeGenFunctions.cpp` for each class.

## Boolean and Binary
So we wouldn't have to change the if and while statements, we made `ASTBooleanExpr` return an integer. If we get true, we return one, but if we get false, we return zero. 
For `ASTBinaryExpr`, we modified it by adding: and, or, not, >=, <=, <, !=, and %. We case expressions that return boolean values to integers to reflect the changes of `ASTBooleanExpr`.

## Neg and Not
`ASTNegExpr` and `ASTNotExpr` have the same format; we check the Argument using `getArg`. 

## Arrays
however, upon creating the array tests, we learned that `arrayptr` holds type "i64*" when it's so the tests would crash because we expected a type "i64". To solve this issue, we used `Builder.CreatePtrToInt(arrayPtr, Type::getInt64Ty(TheContext))` to return a type "i64." Once we figured out this problem, we were able to finish the Codegen for the remaining Nodes that rely on the `ASTArrayExpr.` 

Another design choice we made for `ASTArrayExpr` was we stored the length of the array as the first value in memory. This design choice made `ASTArrayLengthExpr` trivial to create. `ASTArrayOfExpr` is also in the same format as `ASTArrayExpr,` except it contains a size and value variable determining its structure. 

`ASTArrayAccessExpr` was easier to implement because we stored the size as the first value. We created three branches—two for error and one for success. The error branches check if the given index is in bounds. Since we store the array size in memory, we must also increment the index by one to get the correct index value. 

For arrays, we tested out creating simple, nested, and empty arrays. We also tested out getting the size for each variation. 

## Ternary
The code generation for `ASTTernaryExpr` is somewhat similar to `ASTIfStmt` except that we use `Builder.CreateSelect` rather than block branching to select the "then" or "else" part.
Since the first argument for `CreateSelect` is a bool but the generated value for condition in ternary expression is a int64, we convert the condition to a bool by comparing non-equal to 0.

## For loops
In `ASTForIteratorStmt`, we create blocks for loop init, body, update, and exit.
Similar to `ASTWhileStmt`, a large part of the code are routines setting up the different blocks, establishing the insertion point, and letting other codegen functions do their work.
The no-rountine part of the code involves setting up an index for the array, comparing the index with array length in the header, assigning the array element and updating the index in the body.

`ASTForRangeStmt` is again similar, but here we have more blocks: init, test, body, update, and exit.
The reason is that update of the counter needs to be done after the loop body but before the range test.

## Postfix Statement
For `ASTPostfixStmt`, we generate l-value and r-value of the argument, and update the r-value using `CreateAdd` or `CreateSub` code according to the operator type.
Finally, we assign the updated r-value to the l-value via `Builder.CreateStore`.

## Testing
For tests, we created `.tip` files and `.tip.pppt` to generate the code and compare it with an expected output (types, structure, etc.) in the `siptests` directory. We modified the `run.sh` file to run our tests and check the differences. We also created a `run_system.sh` script in the home directory to make building and checking tests easier. 

To ensure our Codegen outputs the correct type and value, we created type checks for each test and checked the output using if and error. For example,`if ((firstValue() != 1)) error firstValue();` and `firstValue : () -> int.`
