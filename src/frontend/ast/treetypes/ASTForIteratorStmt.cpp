#include "ASTForIteratorStmt.h"
#include "ASTVisitor.h"

void ASTForIteratorStmt::accept(ASTVisitor *visitor) {
  if (visitor->visit(this)) {
    getElement()->accept(visitor);
    getArray()->accept(visitor);
    getBody()->accept(visitor);
  }
  visitor->endVisit(this);
}

std::ostream &ASTForIteratorStmt::print(std::ostream &out) const {
  out << "for (" << *getElement() << ": " << *getArray() << ")";
  out << *getBody();
  return out;
}

std::vector<std::shared_ptr<ASTNode>> ASTForIteratorStmt::getChildren() {
  std::vector<std::shared_ptr<ASTNode>> children;

  children.push_back(ELEM);
  children.push_back(ARRAY);
  children.push_back(BODY);

  return children;
}
