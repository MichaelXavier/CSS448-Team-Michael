#include "CharacterType.h"

CharacterType::CharacterType(const string& name) : IdentRecord(name) {
}

CharacterType::~CharacterType(void) {
}

void CharacterType::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
  //TODO
}
