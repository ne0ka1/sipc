#pragma once

#include "ASTExpr.h"

/*! \brief Class for the array length
*/

class ASTArrayLengthExpr : public ASTExpr {
    std::shared_ptr<ASTExpr> ARRAY;

public:
    std::vector<std::shared_ptr<ASTNode>> getChildren() override;
    ASTArrayLengthExpr(std::shared_ptr<ASTExpr> ARRAY) : ARRAY(ARRAY) {}
    ASTExpr * getArray() const { return ARRAY.get(); }
    void accept(ASTVisitor * visitor) override;
    llvm::Value *codegen() override;
protected:
    std::ostream& print(std::ostream &out) const override;
};