#pragma once

#include "ASTExpr.h"

/*! \brief Class for array 
 */

class ASTArrayExpr : public ASTExpr {
  bool implicit;
  std::vector<std::shared_ptr<ASTExpr>> ELEMENTS = {};

public:
  ASTArrayExpr(std::vector<std::unique_ptr<ASTExpr>> ELEMENTS,
                          bool implicit);
  void accept(ASTVisitor *visitor) override;
  std::vector<ASTExpr *> getElements() const;
  bool isImplicit() const { return implicit; }
  std::vector<std::shared_ptr<ASTNode>> getChildren() override;
  llvm::Value *codegen() override;

protected:
  std::ostream &print(std::ostream &out) const override;
};