#include "ASTArrayOfExpr.h"
#include "ASTVisitor.h"
#include "ASTinternal.h"
// TODO: Fix Code and clean up code 
ASTArrayOfExpr::ASTArrayOfExpr(
    std::vector<std::shared_ptr<ASTExpr>> ELEMENTS) {
  for (auto &element : ELEMENTS) {
    std::shared_ptr<ASTExpr> e = std::move(ELEMENTS);
    this->ELEMENTS.push_back(std::move(e));
  }
}

std::vector<ASTExpr *> ASTArrayOfExpr::getElements() const {
  return rawRefs(ELEMENTS);
}

void ASTArrayOfExpr::accept(ASTVisitor *visitor) {
  if (visitor->visit(this)) {
    for (auto &elem : getElements()) {
      elem->accept(visitor);
    }
  }
  visitor->endVisit(this);
}

std::ostream &ASTArrayOfExpr::print(std::ostream &out) const {
  out << "[";
  out << *ELEMENTS[0] << " of " << *ELEMENTS[1];
  out << "]";
  return out;
}

// Get children
std::vector<std::shared_ptr<ASTNode>> ASTArrayOfExpr::getChildren() {
  std::vector<std::shared_ptr<ASTNode>> children;
  for (auto &elem : ELEMENTS) {
    children.push_back(elem);
  }
  return children;
}