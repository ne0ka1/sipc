#pragma once

#include "ASTExpr.h"

/*! \brief Class for a negative expression
*/

class ASTNegExpr : public ASTExpr {
   std::shared_ptr<ASTExpr> VALUE;

public:
    std::vector<std::shared_ptr<ASTNode>> getChildren() override;
    ASTNegExpr(std::shared_ptr<ASTExpr> VALUE) : VALUE(VALUE) {}
    ASTExpr *getArg() const { return VALUE.get(); }
    void accept(ASTVisitor *visitor) override;
    llvm::Value *codegen() override;
protected:
    std::ostream& print(std::ostream &out) const override;
};