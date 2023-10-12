#pragma once

#include "ASTExpr.h"

/*! \brief Class for a negative expression
*/

class ASTNegExpr : public ASTExpr {
   std::shared_ptr<ASTExpr> NEG;

public:
    std::vector<std::shared_ptr<ASTNode>> getChildren() override;
    ASTNegExpr(std::shared_ptr<ASTExpr> NEG) : NEG(NEG) {}
    ASTExpr * getNeg() const { return NEG.get(); }
    void accept(ASTVisitor * visitor) override;
    llvm::Value *codegen() override;
protected:
    std::ostream& print(std::ostream &out) const override;
};