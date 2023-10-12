#pragma once

#include "ASTExpr.h"

/*! \brief Class for array subscript 
 */

class ASTArraySubscriptExpr : public ASTExpr {
  std::shared_ptr<ASTExpr> ARRAY;
  std::shared_ptr<ASTExpr> IDX;

public:
  std::vector<std::shared_ptr<ASTNode>> getChildren() override;
  ASTArraySubscriptExpr(std::unique_ptr<ASTExpr> ARRAY,
                        std::unique_ptr<ASTExpr> IDX)
      : ARRAY(std::move(ARRAY)), IDX(std::move(IDX)) {}
  ASTExpr *getArray() const { return ARRAY.get(); }
  ASTExpr *getIndex() const { return IDX.get(); }
  void accept(ASTVisitor *visitor) override;
  llvm::Value *codegen() override;

protected:
  std::ostream &print(std::ostream &out) const override;
};