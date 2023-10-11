#include "ASTNotExpr.h"
#include "ASTVisitor.h"

#include <iostream>

std::ostream &ASTNotExpr::print(std::ostream &out) const {
  out << getOp();
  if (getOp() == "not") {
    out << " ";
  }
  out << *getExpr();
  return out;
}

std::vector<std::shared_ptr<ASTNode>> ASTNotExpr::getChildren() {
  std::vector<std::shared_ptr<ASTNode>> children;
  children.push_back(EXPR);
  return children;
}