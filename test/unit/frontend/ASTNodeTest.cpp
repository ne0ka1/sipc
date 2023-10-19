#include "ASTHelper.h"
#include "AST.h"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>
#include "ASTVisitor.h"
class RecordPostPrint : public ASTVisitor {
public:
std::vector<std::string> postPrintStrings;
void record(ASTNode * element) {
std::stringstream s; s << *element; postPrintStrings.push_back(s.str());
}
void endVisit(ASTProgram * element) { record(element); }
void endVisit(ASTFunction * element) { record(element); }
void endVisit(ASTNumberExpr * element) { record(element); }
void endVisit(ASTVariableExpr * element) { record(element); }
// New --- 
void endVisit(ASTArrayAccessExpr * element) { record(element); }
void endVisit(ASTArrayExpr * element) { record(element); }
void endVisit(ASTArrayLengthExpr * element) { record(element); }
void endVisit(ASTArrayOfExpr * element) { record(element); }
void endVisit(ASTBooleanExpr * element) { record(element); }
void endVisit(ASTNotExpr * element) { record(element); }
void endVisit(ASTNegExpr * element) { record(element); }
void endVisit(ASTTernaryExpr * element) { record(element); }
void endVisit(ASTPostfixStmt * element) { record(element); }
void endVisit(ASTForIteratorStmt * element) { record(element); }
void endVisit(ASTForRangeStmt * element) { record(element); }

void endVisit(ASTBinaryExpr * element) { record(element); }
void endVisit(ASTInputExpr * element) { record(element); }
void endVisit(ASTFunAppExpr * element) { record(element); }
void endVisit(ASTAllocExpr * element) { record(element); }
void endVisit(ASTRefExpr * element) { record(element); }
void endVisit(ASTDeRefExpr * element) { record(element); }
void endVisit(ASTNullExpr * element) { record(element); }
void endVisit(ASTFieldExpr * element) { record(element); }
void endVisit(ASTRecordExpr * element) { record(element); }
void endVisit(ASTAccessExpr * element) { record(element); }
void endVisit(ASTDeclNode * element) { record(element); }
void endVisit(ASTDeclStmt * element) { record(element); }
void endVisit(ASTAssignStmt * element) { record(element); }
void endVisit(ASTWhileStmt * element) { record(element); }
void endVisit(ASTIfStmt * element) { record(element); }
void endVisit(ASTOutputStmt * element) { record(element); }
void endVisit(ASTReturnStmt * element) { record(element); }
void endVisit(ASTErrorStmt * element) { record(element); }
void endVisit(ASTBlockStmt * element) { record(element); }
};
// Helper function that checks for raw node pointer in list
bool contains(std::vector<std::shared_ptr<ASTNode>> nodeList, ASTNode * nodeP) {
bool found = false;
for (auto & sharedNodeP : nodeList) {
if (sharedNodeP.get() == nodeP) {
found = true;
break;
}
}
return found;
}
TEST_CASE("ASTNodeTest: ASTAssign", "[ASTNode]") {
auto rhs = std::make_unique<ASTNumberExpr>(42);
auto lhs = std::make_unique<ASTVariableExpr>("x");
// Record the raw pointers for these values because rhs and lhs will not be
// usable after the call to the constructor below. This is because of the
// move semantics associated with unique pointers, i.e., after the move the
// locals rhs and lhs are nullptrs
auto rhsValue = rhs.get();
auto lhsValue = lhs.get();
auto assign = std::make_unique<ASTAssignStmt>(std::move(lhs), std::move(rhs));
// Test Print Method
std::stringstream nodePrintStream;
nodePrintStream << *assign;
REQUIRE(nodePrintStream.str() == "x = 42;");
// Test getters
REQUIRE(rhsValue == assign->getRHS());
REQUIRE(lhsValue == assign->getLHS());
// Test getChildren
auto children = assign->getChildren();
REQUIRE(children.size() == 2);
REQUIRE(contains(children, rhsValue));
REQUIRE(contains(children, lhsValue));
// Test accept
RecordPostPrint visitor;
assign->accept(&visitor);
std::string expected[] = { "x", "42", "x = 42;" };
for (int i=0; i < 3; i++) {
REQUIRE(visitor.postPrintStrings[i] == expected[i]);
}
}

TEST_CASE("ASTNodeTest: ASTBoolean", "[ASTNode]") {
auto true_expr = std::make_unique<ASTBooleanExpr>(true);
auto false_expr = std::make_unique<ASTBooleanExpr>(false);
// Test Print Method
// true
std::stringstream nodePrintStream;
nodePrintStream << *true_expr;
REQUIRE(nodePrintStream.str() == "true");
// false
std::stringstream nodePrintStream2;

nodePrintStream2 << *false_expr;
REQUIRE(nodePrintStream2.str() == "false");
// Test getters
REQUIRE(true == true_expr->getValue());
REQUIRE(false == false_expr->getValue());
// Test accept
RecordPostPrint visitor1;
RecordPostPrint visitor2;
true_expr->accept(&visitor1);
false_expr->accept(&visitor2);
std::string expected1 = "true";
std::string expected2 = "false";
REQUIRE(visitor1.postPrintStrings[0] == expected1);
REQUIRE(visitor2.postPrintStrings[0] == expected2);
}

TEST_CASE("ASTNodeTest: ASTTernary", "[ASTNode]") {
auto cond_expr = std::make_shared<ASTBooleanExpr>(true);
auto then_expr = std::make_shared<ASTVariableExpr>("x");
auto else_expr = std::make_shared<ASTNumberExpr>(0);

auto ternary = std::make_shared<ASTTernaryExpr>(cond_expr, then_expr, else_expr);

// Test Print Method
std::stringstream nodePrintStream;
nodePrintStream << *ternary;
REQUIRE(nodePrintStream.str() == "true ? x : 0");
// Test getters
REQUIRE(cond_expr.get() == ternary->getCondition());
REQUIRE(then_expr.get() == ternary->getThen());
REQUIRE(else_expr.get() == ternary->getElse());
// Test getChildren
auto children = ternary->getChildren();
REQUIRE(children.size() == 3);
REQUIRE(contains(children, cond_expr.get()));
REQUIRE(contains(children, then_expr.get()));
REQUIRE(contains(children, else_expr.get()));

// Test accept
RecordPostPrint visitor;
ternary->accept(&visitor);
std::string expected[] = {"true", "x", "0", "true ? x : 0"};
for (int i=0; i < 4; i++){
REQUIRE(visitor.postPrintStrings[i] == expected[i]);
}
}

TEST_CASE("ASTNodeTest: ASTPostfixStmt", "[ASTNode]") {
auto arg = std::make_shared<ASTVariableExpr>("x");

auto postfixPlus = std::make_shared<ASTPostfixStmt>("++", arg);
auto postfixMinus = std::make_shared<ASTPostfixStmt>("--", arg);

// Test Print Method
std::stringstream nodePrintStream;
nodePrintStream << *postfixPlus;
REQUIRE(nodePrintStream.str() == "x++;");

// Test Print Method
std::stringstream nodePrintStream2;
nodePrintStream2 << *postfixMinus;
REQUIRE(nodePrintStream2.str() == "x--;");

// Test getters
REQUIRE(arg.get() == postfixPlus->getArg());
REQUIRE("++" == postfixPlus->getOp());
REQUIRE("--" == postfixMinus -> getOp());

// Test getChildren
auto children = postfixPlus->getChildren();
REQUIRE(children.size() == 1);
REQUIRE(contains(children, arg.get()));

// Test accept
RecordPostPrint visitor;
postfixPlus->accept(&visitor);
std::string expected[] = {"x", "x++;"};
for (int i=0; i < 2; i++){
REQUIRE(visitor.postPrintStrings[i] == expected[i]);
}
}


TEST_CASE("ASTNodeTest: ASTForRangeStmt", "[ASTNode]") {
auto counter = std::make_shared<ASTVariableExpr>("x");
auto begin = std::make_shared<ASTNumberExpr>(0);
auto end = std::make_shared<ASTNumberExpr>(4);
auto step = std::make_shared<ASTNumberExpr>(1);

auto body = std::make_shared<ASTPostfixStmt>("++", counter);
auto forrange = std::make_shared<ASTForRangeStmt>(counter, begin, end, step, body);
auto forrange_nostep = std::make_shared<ASTForRangeStmt>(counter, begin, end, body);

// Test Print Method
std::stringstream nodePrintStream;
nodePrintStream << *forrange;
REQUIRE(nodePrintStream.str() == "for (x : 0..4 by 1){ x++; }");
// Test getters
REQUIRE(counter.get() == forrange->getCounter());
REQUIRE(begin.get() == forrange->getBegin());
REQUIRE(end.get() == forrange->getEnd());
REQUIRE(step.get() == forrange->getStep());
REQUIRE(body.get() == forrange->getBody());
REQUIRE(nullptr == forrange_nostep->getStep());

// Test getChildren
auto children = forrange->getChildren();
REQUIRE(children.size() == 5);
REQUIRE(contains(children, counter.get()));
REQUIRE(contains(children, begin.get()));
REQUIRE(contains(children, end.get()));
REQUIRE(contains(children, step.get()));
REQUIRE(contains(children, body.get()));

// Test accept
RecordPostPrint visitor;
forrange->accept(&visitor);
std::string expected[] = {"x", "0", "4", "1", "x", "x++;", "for (x : 0..4 by 1){ x++; }"};
for (int i=0; i < 7; i++){
REQUIRE(visitor.postPrintStrings[i] == expected[i]);
}
}

TEST_CASE("ASTNodeTest: ASTForIteratorStmt", "[ASTNode]") {
auto elem = std::make_shared<ASTVariableExpr>("x");
auto fake_array = std::make_shared<ASTNumberExpr>(10);
auto body = std::make_shared<ASTPostfixStmt>("++", elem);
auto foriterator = std::make_shared<ASTForIteratorStmt>(elem, fake_array, body);

// Test Print Method
std::stringstream nodePrintStream;
nodePrintStream << *foriterator;
REQUIRE(nodePrintStream.str() == "for (x : 10){ x++; }");
// Test getters
REQUIRE(elem.get() == foriterator->getElement());
REQUIRE(fake_array.get() == foriterator->getArray());
REQUIRE(body.get() == foriterator->getBody());

// Test getChildren
auto children = foriterator->getChildren();
REQUIRE(children.size() == 3);
REQUIRE(contains(children, elem.get()));
REQUIRE(contains(children, fake_array.get()));
REQUIRE(contains(children, body.get()));

// Test accept
RecordPostPrint visitor;
foriterator->accept(&visitor);
std::string expected[] = {"x", "10", "x", "x++;", "for (x : 10){ x++; }"};
for (int i=0; i < 5; i++){
REQUIRE(visitor.postPrintStrings[i] == expected[i]);
}
}
