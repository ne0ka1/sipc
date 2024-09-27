#pragma once

#include "ASTExpr.h"

/*! \brief Class for array 
 */

class ASTArrayExpr : public ASTExpr {
  std::vector<std::shared_ptr<ASTExpr>> ELEMENTS = {};

public:
  ASTArrayExpr(std::vector<std::shared_ptr<ASTExpr>> ELEMENTS);
  void accept(ASTVisitor *visitor) override;
  std::vector<ASTExpr *> getElements() const;
  std::vector<std::shared_ptr<ASTNode>> getChildren() override;
  llvm::Value *codegen() override;
protected:
  std::ostream &print(std::ostream &out) const override;
};