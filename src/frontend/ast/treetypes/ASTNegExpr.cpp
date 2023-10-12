#include "ASTNegExpr.h"
#include "ASTVisitor.h"

void ASTNegExpr::accept(ASTVisitor *visitor) {
  if (visitor->visit(this)) {
    getNeg()->accept(visitor);
  }
  visitor->endVisit(this);
}

std::ostream &ASTNegExpr::print(std::ostream &out) const {
  out << "(-" << *getNeg() << ")";
  return out;
}

std::vector<std::shared_ptr<ASTNode>> ASTNegExpr::getChildren() {
  std::vector<std::shared_ptr<ASTNode>> children;
  children.push_back(NEG);
  return children;
}
