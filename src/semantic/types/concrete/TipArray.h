#pragma once

#include "TipCons.h"
#include "TipType.h"

/*!
 * \class TipArray
 *
 * \brief Array representaion 
 */

class TipArray : public TipCons {
public:
  TipArray() = delete;
  TipArray(std::shared_ptr<TipType> array);

  bool operator==(const TipType &other) const override;
  bool operator!=(const TipType &other) const override;

  void accept(TipTypeVisitor *visitor) override;

protected:
  
  std::ostream &print(std::ostream &out) const override;
};