#pragma once

#include "ASTExpr.h"
#include "ASTStmt.h"

/*! \brief Class for iterator-style for loop statement.
 */
class ASTForIteratorStmt : public ASTStmt {
  std::shared_ptr<ASTExpr> ELEM, ARRAY;
  std::shared_ptr<ASTStmt> BODY;

public:
  std::vector<std::shared_ptr<ASTNode>> getChildren() override;
  ASTForIteratorStmt(std::shared_ptr<ASTExpr> ELEM, std::shared_ptr<ASTExpr> ARRAY,
            std::shared_ptr<ASTStmt> BODY)
    : ELEM(ELEM), ARRAY(ARRAY), BODY(BODY) {}

  ASTExpr *getElement() const { return ELEM.get(); }
  ASTExpr *getArray() const { return ARRAY.get(); }
  ASTStmt *getBody() const { return BODY.get(); }
  void accept(ASTVisitor *visitor) override;
  llvm::Value *codegen() override {return nullptr;};

protected:
  std::ostream &print(std::ostream &out) const override;
};
