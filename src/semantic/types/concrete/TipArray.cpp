#include "TipArray.h"
#include "TipTypeVisitor.h"
#include <sstream>

TipArray::TipArray(std::shared_ptr<TipType> array)
    : TipCons(std::move(std::vector<std::shared_ptr<TipType>>{array})) {
}

bool TipArray::operator==(const TipType &other) const {
  auto otherTipArray = dynamic_cast<const TipArray *>(&other);
  if (!otherTipArray) {
    return false;
  }

  return *arguments.front() == *otherTipArr->arguments.front();
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
  out << "[]" << *arguments.front();
  return out;
}