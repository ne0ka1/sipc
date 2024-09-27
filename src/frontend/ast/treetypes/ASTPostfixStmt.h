#pragma once

#include "ASTExpr.h"
#include "ASTStmt.h"

/*! \brief Class for an output statement.
 */
class ASTPostfixStmt : public ASTStmt {
  std::string OP;
  std::shared_ptr<ASTExpr> ARG;

public:
  std::vector<std::shared_ptr<ASTNode>> getChildren() override;
  ASTPostfixStmt(const std::string &OP, std::shared_ptr<ASTExpr> ARG) : OP(OP), ARG(ARG) {}
  std::string getOp() const { return OP; }
  ASTExpr *getArg() const { return ARG.get(); }
  void accept(ASTVisitor *visitor) override;
  llvm::Value *codegen() override;

protected:
  std::ostream &print(std::ostream &out) const override;
};
