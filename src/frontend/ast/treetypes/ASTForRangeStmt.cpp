#include "ASTForRangeStmt.h"
#include "ASTVisitor.h"

void ASTForRangeStmt::accept(ASTVisitor *visitor) {
  if (visitor->visit(this)) {
    getCounter()->accept(visitor);
    getBegin()->accept(visitor);
    getEnd()->accept(visitor);
    if (getStep() != nullptr) {
      getStep()->accept(visitor);
    }
    getBody()->accept(visitor);
  }
  visitor->endVisit(this);
}

std::ostream &ASTForRangeStmt::print(std::ostream &out) const {
  out << "for (" << *getCounter() << ": " << *getBegin() << ".." << *getEnd();
  if (getStep() != nullptr) {
    out << " by " << *getStep();
  }
  out << ")" << *getBody();
  return out;
}

std::vector<std::shared_ptr<ASTNode>> ASTForRangeStmt::getChildren() {
  std::vector<std::shared_ptr<ASTNode>> children;

  children.push_back(COUNTER);
  children.push_back(BEGIN);
  children.push_back(END);
  if (getStep() != nullptr) {
    children.push_back(STEP);
  }
  children.push_back(BODY)

  return children;
}
