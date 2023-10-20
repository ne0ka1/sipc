# Solution 2

## AST
We added new subtypes of ASTNodes including `ASTArrayExpr`,`ASTArrayOfExpr` `ASTNotExpr`, `ASTForRangeStmt`, etc.
In project 1, we wrote one rule for two types of array expressions and one rule for two types of for-loop statements.
When constructing ASTNodes, however, we found it easier and clearer to separate two types in grammar file, for otherwise we would need a lot of extra logic to distinguish them in one ASTNode.
So we have `ASTForRangeStmt` and `ASTForIteratorStmt` for two kinds of for-loop statements.
For the arrays, we decided to split the `ASTArrayExpr` and the `ASTArrayOfExpr` to two nodes. To allow nesting the `ASTArrayExpr` takes a list of expressions while the `ASTArrayOfExpr` takes in only two. `ASTArrayExpr` handles the negative array.
To avoid problems with negation and subtraction we removed `negNumber` from the TIP.g4 file just used `negExpr` since numbers would be inputed as expressions. Since `negExpr` and `notExpr` return two different types we didn't combine them into a single Unary expression. On the other hand, we decided to include or/and in the binary expressions since both of them take left and right expessions.

In `ASTForRangeStmt`, the step is optional; we used function overloading in C++ to deal with different number of arguments, and then added logic to detect whether the step is `nullptr` in getter and printer methods.

For ASTNodeTest, we wrote tests for all new subtypes of ASTNodes.
A tricky thing is how to deal with `codegen()` method, since it is required to build the ASTNodes in the unit test but we don't implement this functionality in the frontend stage.
We could have wrote and used those `MockASTNodes`in `ASTNodeHelpers`, but for development efficiency we use a workaround in this stage:
```c++
llvm::Value *codegen() override {return nullptr;}
```
We directly implemented this in all ASTNodes so that this won't cause errors for now.
In later stage of project (say deliverable4) we will delete `return nullptr;` and implement the real `codegen()` methods.

## AST Visitor
We extended the visitor by adding new visit and endvisit functions for each new node.
## AST Builder
We extended `ASTBuilder.h` and `ASTBuilder.cpp` to build ASTNodes from antlr4 generated contexts.
In `visitForRangeStmt`, we need to check whether step exists (since it's optional) and we achieve this by checking `ctx->expr().size()` before visiting the optional step expression.

## Pretty Printer
We extended `PrettyPrinter.h` and `PrettyPrinter.cpp`.
For for-loop statements, just as in while statements, we need to override `visit` method as well -- to increase the indentation, and then decrease the indentation after visiting their body statements in `endVisit` method.
This way, the body of for-loop statements will be indented as desired. For arrays we checked for nesting and if they could be empty.

We then extended `PrettyPrinterTest.cpp` to test the prettyprinters for newly added ASTNodes.
