#include "ASTArrayExpr.h"
#include "ASTVisitor.h"
#include "ASTinternal.h"
ASTArrayExpr::ASTArrayExpr(
  std::vector<std::shared_ptr<ASTExpr>> ELEMENTS) {
  for (auto &element : ELEMENTS) {
    std::shared_ptr<ASTExpr> e = std::move(ELEMENTS);
    this->ELEMENTS.push_back(std::move(e));
  }
}

std::vector<ASTExpr *> ASTArrayExpr::getElements() const {
  return rawRefs(ELEMENTS);
}


void ASTArrayExpr::accept(ASTVisitor *visitor) {
  if (visitor->visit(this)) {
    for (auto &elem : getElements()) {
      elem->accept(visitor);
    }
  }
  visitor->endVisit(this);
}

std::ostream &ASTArrayExpr::print(std::ostream &out) const {
  out << "["; // [
  if (ELEMENTS.empty()) {
    out << "]"; // return []
    return out;
  }
  bool skip = true;
  for (auto &elem : getElements()) {
    if (skip) { // [e1
    skip = false;
    out << *elem;
    continue;
    }else{ // [e1, e2
    out << ", " << *elem;
    }
  }
  out << "]"; // [e1(, e_n)*] or // [e1]
  return out;
}

// Get children
std::vector<std::shared_ptr<ASTNode>> ASTArrayExpr::getChildren() {
  std::vector<std::shared_ptr<ASTNode>> children;
  for (auto &elem : ELEMENTS) {
    children.push_back(elem);
  }
  return children;
}