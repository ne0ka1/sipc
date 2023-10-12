#include "ASTArrayExpr.h"
#include "ASTVisitor.h"
#include "ASTinternal.h"

ASTArrayExpr::ASTArrayExpr(
    std::vector<std::unique_ptr<ASTExpr>> ELEMENTS, bool implicit) {
  this->implicit = implicit;

  for (auto &element : ELEMENTS) {
    std::shared_ptr<ASTExpr> e = std::move(ELEMENTS);
    this->ELEMENTS.push_back(std::move(e));
  }
}


void ASTArrayExpr::accept(ASTVisitor *visitor) {
  if (visitor->visit(this)) {
    for (auto &elem : rawRefs(ELEMENTS)) {
      elem->accept(visitor);
    }
  }
  visitor->endVisit(this);
}

std::ostream &ASTArrayExpr::print(std::ostream &out) const {
  out << "[";
  if (ELEMENTS.empty()) {
    out << "]";
    return out;
  }
  if (implicit) {
    out << *ELEMENTS[0] << " of " << *ELEMENTS[1];
  } else {
    bool skip = true;
    for (auto &elem : rawRefs(ELEMENTS)) {
      if (skip) {
        skip = false;
        out << *elem;
        continue;
      }
      out << ", " << *elem;
    }
  }
  out << "]";
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