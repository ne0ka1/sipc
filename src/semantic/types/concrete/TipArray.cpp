#include "TipArray.h"
#include "TipTypeVisitor.h"
#include <sstream>

TipArray::TipArray() {}

TipArray::TipArray(std::shared_ptr<TipType> array)
    : TipCons(std::move(std::vector<std::shared_ptr<TipType>>{array})) {
}

bool TipArray::operator==(const TipType &other) const {
  const auto otherTipArray = dynamic_cast<const TipArray *>(&other);
  if (!otherTipArray) {
    return false; 
  }

  // if empty
  if (arguments.empty() && otherTipArray->arguments.empty()) {
    return true;
  }

  // If both are not empty
  if (!arguments.empty() && !otherTipArray->arguments.empty()) {
    return *arguments.front() == *otherTipArray->arguments.front();
  }

  // If one is empty
  return false;
}

bool TipArray::operator!=(const TipType &other) const {
  return !(*this == other);
}

void TipArray::accept(TipTypeVisitor *visitor) {
  if (visitor->visit(this)) {
    for (auto a : arguments) {
      a->accept(visitor);
    }
  }
  visitor->endVisit(this);
}

std::ostream &TipArray::print(std::ostream &out) const {
  out << "[] " << *arguments.front();
  return out;
}