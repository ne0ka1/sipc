#include "ASTPostfixStmt.h"
#include "ASTVisitor.h"

void ASTPostfixStmt::accept(ASTVisitor *visitor) {
  if (visitor->visit(this)) {
    getArg()->accept(visitor);
  }
  visitor->endVisit(this);
}

std::ostream &ASTPostfixStmt::print(std::ostream &out) const {
  out << *getArg() << getOp() << ";";
  return out;
}

std::vector<std::shared_ptr<ASTNode>> ASTPostfixStmt::getChildren() {
  std::vector<std::shared_ptr<ASTNode>> children;
  children.push_back(ARG);
  return children;
}
