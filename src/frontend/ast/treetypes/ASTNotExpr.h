#pragma once

#include "ASTExpr.h"

/*! \brief Base class not not node
 */
class ASTNotExpr : public ASTExpr {
  std::string OP;
  std::shared_ptr<ASTExpr> Expr;

public:
  std::vector<std::shared_ptr<ASTNode>> getChildren() override;
  ASTNotExpr(const std::string &OP, std::shared_ptr<ASTExpr> Expr)
      : OP(OP), Expr(Expr) {}
  std::string getOp() const { return Expr; }
  ASTExpr *getExpr() const { return RIGHT.get(); }
  void accept(ASTVisitor *visitor) override;
  llvm::Value *codegen() override;

protected:
  std::ostream &print(std::ostream &out) const override;
};
