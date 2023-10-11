#pragma once

#include "ASTExpr.h"

/*! \brief Base class not not node
 */
class ASTNotExpr : public ASTExpr {
  std::string OP;
  std::shared_ptr<ASTExpr> EXPR;

public:
  std::vector<std::shared_ptr<ASTNode>> getChildren() override;
  ASTNotExpr(const std::string &OP, std::shared_ptr<ASTExpr> EXPR)
      : OP(OP), EXPR(EXPR) {}
  std::string getOp() const { return EXPR; }
  ASTExpr *getEXPR() const { return RIGHT.get(); }
  void accept(ASTVisitor *visitor) override;
  llvm::Value *codegen() override;

protected:
  std::ostream &print(std::ostream &out) const override;
};
