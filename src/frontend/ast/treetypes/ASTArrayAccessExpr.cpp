#include "ASTArrayAccessExpr.h"
#include "ASTVisitor.h"

void ASTArrayAccessExpr::accept(ASTVisitor *visitor) {
  if (visitor->visit(this)) {
    getArray()->accept(visitor);
    getIndex()->accept(visitor);
  }
  visitor->endVisit(this);
}

std::ostream &ASTArrayAccessExpr::print(std::ostream &out) const {
  return out << *getArray() << "[" << *getIndex() << "]";
}

std::vector<std::shared_ptr<ASTNode>> ASTArrayAccessExpr::getChildren() {
  std::vector<std::shared_ptr<ASTNode>> children;
  children.push_back(ARRAY);
  children.push_back(IDX);
  return children;
}