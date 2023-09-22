#include "ExceptionContainsWhat.h"
#include "FrontEnd.h"
#include "ParseError.h"
#include "ParserHelper.h"

#include <catch2/catch_test_macros.hpp>


/*
Boolean type with constants true and false, unary operator not, and non-short 
circuiting binary operators and and or.
*/

// Boolean
TEST_CASE("SIP Parser: boolean test", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { var x;
                    x = (true == false);
                    return x; }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

// unary not
TEST_CASE("SIP Parser: unary not test", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { var x;
                    x = false;
                    return not x; }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

// or
TEST_CASE("SIP Parser: or test", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { var x, y;
                    y = true;
                    x = false;
                    return (x or y); }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

// and
TEST_CASE("SIP Parser: and test", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { var x, y;
                    y = true;
                    x = false; 
                    return (x and y); }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

// all
TEST_CASE("SIP Parser: all boolean test", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { return (true and not false or false and true); }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}
/*
Array type with constructors [E1, ..., En] and [E1 of E2], a unary prefix length
operator #, and a binary array element reference operator E1[E2]. Note that it is
permissable to have an empty array in the first of these type constructors, e.g., []; the
length of such an array is 0, i.e., #[] == 0
*/


TEST_CASE("SIP Parser: array regular construction test", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { var x; 
                    x = [1, 2, 3]; 
                    return x; }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: 2d array regular construction test", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { var x; 
                    x = [[1,2,3],[1,2,3]];
                    return x[0][0]; }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: array 'of' construction test", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { var x; 
                    x = [3 of 3]; 
                    return x; }
      main() { return [3 of [3 of 3]];}
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: array reference operator test", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { var x; 
                    x = [2,4,6]; 
                    return x[0]; }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

// array length 
TEST_CASE("SIP Parser: len of non-empty array test", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { var x; 
                    x = #[3]; 
                    return x; }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}


// empty array length 
TEST_CASE("SIP Parser: empty and len of empty array test", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { return []; }
      operators() { return #[]; }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}
 
/*
Arithmetic operators are extended with %, the modulo operator, and -, the arithmetic
negation operator.
*/
TEST_CASE("SIP Parser: mod test", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { var x; 
                    if (x == 0){
                      x = x % 2;
                    }
                    return x; }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: negation test", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators(x, y) { return -(x + y); }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

/*
Relational operators are extended with >=, <, and <= !=
*/

TEST_CASE("SIP Parser: relational operators", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { var a, b ,c;
                  a = 4;
                  b = 25;
                  c = a < b;
                  c = a <= b;
                  c = a >= b;
                  return c; }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}
TEST_CASE("SIP Parser: ternary conditional expression basic", "[SIP Parser]"){
  std::stringstream stream;
  stream << R"(
    main(x) { return x > 0 ? x: -x; }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: ternary expression nesting", "[SIP Parser]"){
  std::stringstream stream;
  stream << R"(
    foo(x, y) { return x > 0 ? y > 0 : y == 0 ? x : -x;}
    bar(x, y) { return x > 0 ? y > 0 ? y : - y : x;}
    baz(x, y) { return x > 0 ? x : y > 0 ? y : - y;}
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: increment and decrement", "[SIP Parser]"){
  std::stringstream stream;
  stream << R"(
      main() { var x; x++ ; x++ ; x-- ; return x; }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: iteration-style for statement", "[SIP Parser]"){
  std::stringstream stream;
  stream << R"(
      main (a, f){var i, s; s = 0; for (i : a) { s = s + f(i);} return s;}
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: range-style for statement", "[SIP Parser]"){
  std::stringstream stream;
  stream << R"(
      foo (a, b) { var i; i = 0; for (i : a .. b) { i = i + 1; } return i;}
      bar (a, b, c) {var i;  i = 0; for (i : a .. b by c) { i = i + 1;} return i;}
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

/************ The following are expected to fail parsing ************/
TEST_CASE("SIP Parser: false array no comma", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { var a;
                  a = [1 2];         
                  return a; }
    )";

  REQUIRE_FALSE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: false array multiple comma", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { var a;
                  a = [1, 2,,];         
                  return a; }
    )";

  REQUIRE_FALSE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: mod equals", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { var x, y ,z;
                  x = 3;
                  y = 3
                  z = 1;
                  z =% x;
                  z =% y;         
                  return z; }
    )";

  REQUIRE_FALSE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: false array 3 'of'", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { var a;
                  a = [1 of 2 of 3];         
                  return a; }
    )";

  REQUIRE_FALSE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: relational extra greater than sign", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { var a;
                  a = 3 >>= 3;         
                  return a; }
    )";

  REQUIRE_FALSE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: missing symbol in ternary expression", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      foo(x){ return x > 0 x : -x}
      main(x){ return x > 0 ? x -x}
    )";

  REQUIRE_FALSE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: surplus symbols in ternary expression", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      foo(x){return x > 0 ? ? x : -x}
      main(x){ return x > 0 ? x : : -x}
    )";

  REQUIRE_FALSE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: space in PLUSPLUS", "[SIP Lexer]") {
  std::stringstream stream;
  stream << R"(
      operators() { var x; x + + ; return x; }
    )";

  REQUIRE_FALSE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: increment is not expression", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { var x; (x ++)++ ; return x; }
    )";

  REQUIRE_FALSE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: bad iteration-style for statement", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      main(a, f){var i, s; s = 0; for (i a) { s = s + f(i);} return s;}
    )";

  REQUIRE_FALSE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: illegal operator in range-style for statement", "[SIP Lexer]") {
  std::stringstream stream;
  stream << R"(
      foo (a, b) { var i; i = 0; for (i : a ... b) { i = i + 1; } return i;}
    )";

  REQUIRE_FALSE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: bad range-style for statement", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      foo (a, b) { var i; i = 0; for (i : a .. ) { i = i + 1; } return i;}
    )";

  REQUIRE_FALSE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: another bad range-style for statement", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(
      foo (a, b) { var i; i = 0; for (i : a .. b by ) { i = i + 1; } return i;}
    )";

  REQUIRE_FALSE(ParserHelper::is_parsable(stream));
}


/* These tests checks for operator precedence.
 * They access the parse tree and ensure that the higher precedence
 * operator is nested more deeply than the lower precedence operator.
 */

// mod parse tree
TEST_CASE("SIP Parser: negation has higher precedence than modulo", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(main() { return -3 % 10; })"; 
  std::string expected = "(expr (expr - 3) % (expr 10))";
  std::string tree = ParserHelper::parsetree(stream);
  REQUIRE(tree.find(expected) != std::string::npos);
}
// bool parse tree, not, or, and 
TEST_CASE("SIP Parser: not, and, or precedence", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(main() { return not false or true and false; })"; 
  std::string expected = "(expr (expr not (expr false)) or (expr (expr true) and (expr false)))";
  std::string tree = ParserHelper::parsetree(stream);
  REQUIRE(tree.find(expected) != std::string::npos);
}

// relational operator precedence 
TEST_CASE("SIP Parser: relationalExpr precedence", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(main() { return 3 <= 2 and 3 >= 1 == true; })"; 
  // (3<=2) and (3>=1 == true)
  std::string expected = "(expr (expr (expr 3) <= (expr 2)) and (expr (expr (expr 3) >= (expr 1)) == (expr true)))";
  std::string tree = ParserHelper::parsetree(stream);
  REQUIRE(tree.find(expected) != std::string::npos);
}

// negation precedence 
TEST_CASE("SIP Parser: negation precedence and relationalExpr", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(main() { return -3 < 2; })"; 
  std::string expected = "(expr (expr - 3) < (expr 2))";
  std::string tree = ParserHelper::parsetree(stream);
  REQUIRE(tree.find(expected) != std::string::npos);
}

// regular array
TEST_CASE("SIP Parser: mainArray multi element array", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(main() { return [0,1,2]; })"; 
  std::string expected = "(expr [ (expr 0) , (expr 1) , (expr 2) ])";
  std::string tree = ParserHelper::parsetree(stream);
  REQUIRE(tree.find(expected) != std::string::npos);
}

// empty array
TEST_CASE("SIP Parser: len empty array", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(main() { return #[] == 0; })"; 
  std::string expected = "(expr (expr # (expr [ ])) == (expr 0))";
  std::string tree = ParserHelper::parsetree(stream);
  REQUIRE(tree.find(expected) != std::string::npos);
}

// of array 
TEST_CASE("SIP Parser: ofArray multi element array", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(main() { return [3 of 3]; })"; 
  std::string expected = "(expr [ (expr 3) of (expr 3) ])";
  std::string tree = ParserHelper::parsetree(stream);
  REQUIRE(tree.find(expected) != std::string::npos);
}
// len of array
TEST_CASE("SIP Parser: lenOfArray on mainArray higher than not true", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(main() { return #[4 of 4] > 1 == not true; })"; 
  std::string expected = "(expr (expr (expr # (expr [ (expr 4) of (expr 4) ])) > (expr 1)) == (expr not (expr true)))";
  std::string tree = ParserHelper::parsetree(stream);
  REQUIRE(tree.find(expected) != std::string::npos);
}
// array ref
TEST_CASE("SIP Parser: arrayRef on mainArray", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(main() { var x; x = [1,2,3]; return x[0];})"; 
  std::string expected = "(expr (expr x) [ (expr 0) ])";
  std::string tree = ParserHelper::parsetree(stream);
  REQUIRE(tree.find(expected) != std::string::npos);
}

// field ref
TEST_CASE("SIP Parser: arrayRef is higher in precedence in field select", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(main() { var a,r,f1;
                        a = [f1];
                        r = {f1:0};
                        return r.a[0];
                      }
              )"; 
  std::string expected = "(expr (expr (expr r) . a) [ (expr 0) ])";
  std::string tree = ParserHelper::parsetree(stream);
  REQUIRE(tree.find(expected) != std::string::npos);
}

// negation field ref
TEST_CASE("SIP Parser: field select is higher in precedence than negation", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(main() { var f1;
                        return {f1:-1};
                      }
              )"; 
  std::string expected = "(expr (recordExpr { (fieldExpr f1 : (expr - 1)) }))";
  std::string tree = ParserHelper::parsetree(stream);
  REQUIRE(tree.find(expected) != std::string::npos);
}

TEST_CASE("SIP Parser: OR higher precedence than ternary question mark", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(main(x) { return x > 0 or x == 0 ? x : -x; })";
  std::string expected = "(expr (expr (expr (expr x) > (expr 0)) or (expr (expr x) == (expr 0))) ? (expr x) : (expr - (expr x)))";
  std::string tree = ParserHelper::parsetree(stream);
  REQUIRE(tree.find(expected) != std::string::npos);
}

TEST_CASE("SIP Parser: OR higher precedence than ternary colon", "[SIP Parser]") {
  std::stringstream stream;
  stream << R"(main(x, y, z) { return x > 0 ? y > 0 or z > 0 : y < 0; })";
  std::string expected = "(expr (expr (expr x) > (expr 0)) ? (expr (expr (expr y) > (expr 0)) or (expr (expr z) > (expr 0))) : (expr (expr y) < (expr 0)))";
  std::string tree = ParserHelper::parsetree(stream);
  REQUIRE(tree.find(expected) != std::string::npos);
}

