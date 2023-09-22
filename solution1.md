# Solution 1

## Boolean types and operators
We added keywords "true", "false", "and", "or", and "not".
We then added boolean expressions -- constant boolean values and boolean operators, and made sure they are at the right place according to the operator precedence.
Here, an alternative design is one expression rule like "expr op=(ADD | OR) expr" instead of two rules "expr AND expr" and "expr OR expr".
However, since "and" and "or" have different precedence levels, we chose to write separate rules.

Regarding test, we tested those new expressions and the precedence of boolean operators.
Specifically, we made sure "not" is lower in precedence than field select but higher than pointer dereference; "and" is lower than equality and "or" is lower than "and".
We achived this through checking the parse tree.

## Array

## Arithmetic operators extension

## Relational operators extension

## Ternary conditional expression
We added one expression rule specifying the ternary conditional grammar.
We tried to write something like this:
```
expr : ...
    | ternaryExpr #ternaryRule
ternaryExpr : expr '?' expr ':' expr
```
But it wouldn't work because this grammar would be indirectly left resursive.
In the end, we just wrote the ternary expression directly.

We tested the ternary expression with ternary expression nested in three possible parts.
We then made sure the precedence of ternary expressio is lower than logical "or".
Also, we wrote some badly written ternary expressions that would not parse, e.g. missing question mark or surplus colon.

## Increment and decrement statement
We added two keywords denoting "++" "--" and added one statement rule about increment and decrement statements.
We tested that this statement is parsable, and "+ +" wouldn't parse.
We also tested that increment/decrement should not be used as an expression.

## For loop
We added two keywords "for" and "by", and then added one "forStmt" statement rule specifying two kinds of for statements.
We used regular expression ('?' and '|') to express that there are two styles of for statements, and that the "by" part is optional.
One thing to notice is that the for range style for statement should be before the iteration style for statmenet in the regular expression, to give it a higher priority in matching.
Otherwise, the regular expression would match only "(for a : b)" part in  "(for a : b .. c)" and fail to recognize the range style for statement.

Regarding test, we made sure the syntactically right expressino is parsable, and those lexically or syntactially wrong (write "..." instead of "..", or missing steps after "by") do not parse.
