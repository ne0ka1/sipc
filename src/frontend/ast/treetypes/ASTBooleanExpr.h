#pragma once

#include "ASTExpr.h"

/*! \brief Class for a Boolean expression.
 */
class ASTBooleanExpr : public ASTExpr {
  bool VAL;
  
public:
  ASTBooleanExpr(bool VAL) : VAL(VAL) {}
  bool getValue() const {return VAL; }
  void accept(ASTVisitor *visitor) override;
  llvm::Value *codegen() override;

protected:
  std::ostream &print(std::ostream &out) const override;
};
