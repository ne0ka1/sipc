#pragma once

#include "ASTExpr.h"

/*! \brief Class for array of statements i.e. [3 of 5]
 */

class ASTArrayOfExpr : public ASTExpr {
  std::vector<std::shared_ptr<ASTExpr>> ELEMENTS = {};

public:
  ASTArrayOfExpr(std::vector<std::shared_ptr<ASTExpr>> ELEMENTS);
  void accept(ASTVisitor *visitor) override;
  std::vector<ASTExpr *> getElements() const;
  std::vector<std::shared_ptr<ASTNode>> getChildren() override;
  llvm::Value *codegen() override;

protected:
  std::ostream &print(std::ostream &out) const override;
};