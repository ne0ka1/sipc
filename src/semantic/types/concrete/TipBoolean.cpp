#include "TipBoolean.h"
#include "TipTypeVisitor.h"

#include <string>

TipBoolean::TipBoolean() { }

bool TipBoolean::operator==(const TipType &other) const {
    auto otherTipBoolean = dynamic_cast<TipBoolean const *>(&other);
    if(!otherTipBoolean) {
        return false;
    }

    return true;
}

bool TipBoolean::operator!=(const TipType &other) const {
    return !(*this == other);
}

std::ostream &TipBoolean::print(std::ostream &out) const {
    out << std::string("boolean");
    return out;
} 

void TipBoolean::accept(TipTypeVisitor * visitor) {
  visitor->visit(this);
  visitor->endVisit(this);
}