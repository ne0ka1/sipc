#pragma once

#include "ASTExpr.h"
#include "ASTStmt.h"

/*! \brief Class for range-style for loop statement.
 */
class ASTForRangeStmt : public ASTStmt {
  std::shared_ptr<ASTExpr> COUNTER, BEGIN, END, STEP;
  std::shared_ptr<ASTStmt> BODY;

public:
  std::vector<std::shared_ptr<ASTNode>> getChildren() override;
  ASTForRangeStmt(std::shared_ptr<ASTExpr> COUNTER, std::shared_ptr<ASTExpr> BEGIN,
            std::shared_ptr<ASTExpr> END, std::shared_ptr<ASTExpr> STEP,
            std::shared_ptr<ASTStmt> BODY)
    : COUNTER(COUNTER), BEGIN(BEGIN), END(END), STEP(STEP), BODY(BODY) {}
  ASTExpr *getCounter() const { return COUNTER.get(); }
  ASTExpr *getBegin() const { return BEGIN.get(); }
  ASTExpr *getEnd() const { return END.get(); }

  /*! \fn getStep
   * \return Step Expression if it exists and nullptr otherwise.
   */
  ASTExpr *getStep() const { return STEP.get(); }

  ASTStmt *getBody() const { return BODY.get(); }
  void accept(ASTVisitor *visitor) override;
  llvm::Value *codegen() override;

protected:
  std::ostream &print(std::ostream &out) const override;
};
