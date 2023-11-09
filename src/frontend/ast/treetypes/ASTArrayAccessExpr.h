#pragma once

#include "ASTExpr.h"

/*! \brief Class for array access (i.e. [1,2,3][0]) 
 */

class ASTArrayAccessExpr : public ASTExpr {
  std::shared_ptr<ASTExpr> ARRAY;
  std::shared_ptr<ASTExpr> IDX;

public:
  std::vector<std::shared_ptr<ASTNode>> getChildren() override;
  ASTArrayAccessExpr(std::shared_ptr<ASTExpr> ARRAY,
                        std::shared_ptr<ASTExpr> IDX)
      : ARRAY(std::move(ARRAY)), IDX(std::move(IDX)) {}
  ASTExpr *getArray() const { return ARRAY.get(); }
  ASTExpr *getIndex() const { return IDX.get(); }
  void accept(ASTVisitor *visitor) override;
  llvm::Value *codegen() override;

protected:
  std::ostream &print(std::ostream &out) const override;
};