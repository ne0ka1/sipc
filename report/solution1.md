# Solution 1

## Boolean types and operators
We added keywords "true", "false", "and", "or", and "not".
We then added boolean expressions -- constant boolean values and boolean operators, and made sure they are at the right place according to the operator precedence.
Here, an alternative design is one expression rule like "expr op=(AND | OR) expr" instead of two rules "expr AND expr" and "expr OR expr".
However, since "and" and "or" have different precedence levels, we chose to write separate rules.

Regarding test, we tested those new expressions and the precedence of boolean operators.
Specifically, we made sure "not" is lower in precedence than field select but higher than pointer dereferencing; "and" is lower than equality and "or" is lower than "and".
We achieved this by checking the parse tree.

## Array
We created three expressions for arrays: arrayAccess, lenOfArray, and arrayExpr. arrayAccess, which has the second highest precedence, is defined as (expr'[' expr ']'), and its goal is to grab the array index of an expression. lenOfArray is on a similar level of precedence as the prefix operators; lenofArray is denoted as '#'expr. Its goal is to get the size of an expression. Lastly, we have arrayExpr, arrayExpr is represented by ('[' (expr (',' expr)*)? ']' | '[' expr KOF expr ']'). For arrayExpr there are multiple ways a user can define an array. 
1. the array could be empty. Therefore, we handled it using '[' (expr (',' expr)*)? ']'. '()?' means that whatever is in the parenthesis is optional. 
2. [expr] or [expr,expr,...], We handle both cases with the same regex as the first. By default, if we go inside the optional case '()?', the array isn't empty, and we have a minimum of one expression. (',' expr)* says that we can have zero or more occurrences of a "',' expr" follow-up to our first expression.
3. [expr of expr], we handle an array initialized using 'of' by first creating a keyword called KOF ('of'). For the regex, we created '[' expr KOF expr '],' which is saying an expression followed by KOF, then another expression encapsulated by brackets will match.

Since all three cases accept expressions and are expressions themselves, all 3 of them allow array nesting.

For tests, we first created parsing tests. We checked if we tested all three methods of array initialization and list nesting. We also compared the precedence of items like arrayAccess to the precedence of field select since arrayAccess precedence should be higher.

## Arithmetic operators extension
We added the modulo and negation operators. We created an additional lexical element for modulo, while for negation, we reused the SUB lexical element. We added our modulus expression to our multiplicativeExpr (expr op=(MUL | DIV | MOD) expr) since multiplication, division, and modulus all have the same precedence. For negation, we created another expression called negExpr. Both are handled as prefix unary expressions; however, negExpr looks for an expr value (SUB expr) specifically as opposed to a NUMBER (SUB NUMBER). For tests, we tested parsability to see where our operators would pass and wouldn't. We also wrote tests for the negation of expressions.

## Relational operators extension
We added keywords ">=", "<", and "<=." First, we added the new comparator keywords to the lexicon; then, we added them to the relationalExpr by separating them with or statements `(expr op=(GE | GT | LE | LT) expr)` since they all have the same precedence level. For tests, we created parsability tests and a parse tree test to ensure relational expressions have left-to-right associativity.

## Ternary conditional expression
We added one expression rule specifying the ternary conditional grammar.
We tried to write something like this:
```
expr : ...
    | ternaryExpr #ternaryRule
ternaryExpr : expr '?' expr ':' expr
```
But it wouldn't work because this grammar would be indirectly left recursive.
In the end, we just wrote the ternary expression directly.

We tested the ternary expression with ternary expression nested in three possible parts.
We then made sure the precedence of ternary expression is lower than logical "or".
Also, we wrote some badly written ternary expressions that would not parse, e.g., missing question mark or surplus colon.

## Increment and decrement statement
We added two keywords denoting "++" "--" and added one statement rule about increment and decrement statements.
We tested that this statement is parsable, and "+ +" wouldn't parse.
We also tested that increment/decrement should not be used as an expression.

## For loop
We added two keywords "for" and "by", and then added one "forStmt" statement rule specifying two kinds of for statements.
We used regular expression ('?' and '|') to express that there are two styles of for statements, and that the "by" part is optional.
One thing to notice is that the for range style for statement should be before the iteration style for statement in the regular expression, to give it a higher priority in matching.
Otherwise, the regular expression would match only "(for a : b)" part in  "(for a : b .. c)" and fail to recognize the range style for statement.

Regarding test, we made sure the syntactically right expression is parsable, and those lexically or syntactically wrong (write "..." instead of "..", or missing steps after "by") do not parse.
