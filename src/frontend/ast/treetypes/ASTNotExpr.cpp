#include "ASTNotExpr.h"
#include "ASTVisitor.h"

void ASTNotExpr::accept(ASTVisitor *visitor) {
  if (visitor->visit(this)) {
    getPtr()->accept(visitor);
  }
  visitor->endVisit(this);
}

std::ostream &ASTNotExpr::print(std::ostream &out) const {
  out << "(not" << *getPtr() << ")";
  return out;
}

std::vector<std::shared_ptr<ASTNode>> ASTNotExpr::getChildren() {
  std::vector<std::shared_ptr<ASTNode>> children;
  children.push_back(PTR);
  return children;
}