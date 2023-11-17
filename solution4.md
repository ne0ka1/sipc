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
For `ASTArrayExpr`, we ran into some challenges regarding the return value. Initially, we returned the `arrayptr`; however, upon creating the array tests, we learned that `arrayptr` holds type "i64*" when it's so the tests would crash because we expected a type "i64". To solve this issue, we used `Builder.CreatePtrToInt(arrayPtr, Type::getInt64Ty(TheContext))` to return a type "i64." Once we figured out this problem, we were able to finish the Codegen for the remaining Nodes that rely on the `ASTArrayExpr.` 

Another design choice we made for `ASTArrayExpr` was we stored the length of the array as the first value in memory. This design choice made `ASTArrayLengthExpr` trivial to create. `ASTArrayOfExpr` is also in the same format as `ASTArrayExpr,` except it contains a size and value variable determining its structure. 

`ASTArrayAccessExpr` was easier to implement because we stored the size as the first value. We created three branches—two for error and one for success. The error branches check if the given index is in bounds. Since we store the array size in memory, we must also increment the index by one to get the correct index value. 

For arrays, we tested out creating simple, nested, and empty arrays. We also tested out getting the size for each variation. 

## Testing
For tests, we created a directory called `siptests.` in this directory, we created `.tip` files and `.tip.pppt` to generate the code and compare it with an expected output (types, structure, etc.). We modified the `run.sh` file to run our tests and check the differences. We also created a `run_system.sh` script in the home directory to make building and checking tests easier. 

To ensure our Codegen outputs the correct type and value, we created type checks for each test and checked the output using if and error. For example,`if ((firstValue() != 1)) error firstValue();` and `firstValue : () -> int.`
