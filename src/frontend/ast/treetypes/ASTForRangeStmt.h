#pragma once

#include "ASTExpr.h"
#include "ASTStmt.h"

/*! \brief Class for if-then-else.
 */
class ASTIfStmt : public ASTStmt {
  std::shared_ptr<ASTExpr> COUNTER, BEGIN, END, STEP;
  std::shared_ptr<ASTStmt> BODY;

public:
  std::vector<std::shared_ptr<ASTNode>> getChildren() override;
  ASTIfStmt(std::shared_ptr<ASTExpr> COUNTER, std::shared_ptr<ASTExpr> BEGIN,
            std::shared_ptr<ASTExpr> END, std::shared_ptr<ASTExpr> STEP,
            std::shared_ptr<ASTStmt> BODY)
      : COND(COND), THEN(THEN), ELSE(ELSE) {}
  ASTExpr *getCounter() const { return COUNTER.get(); }
  ASTExpr *getBEGIN() const { return BEGIN.get(); }
  ASTExpr *getEND() const { return END.get(); }

  /*! \fn getStep
   * \return Step Expression if it exists and nullptr otherwise.
   */
  ASTExpr *getStep() const { return STEP.get(); }

  ASTExpr *getBody() const { return BODY.get(); }
  void accept(ASTVisitor *visitor) override;
  llvm::Value *codegen() override;

protected:
  std::ostream &print(std::ostream &out) const override;
};
