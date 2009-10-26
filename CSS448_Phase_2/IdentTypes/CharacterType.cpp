#include "Character.h"

CharacterType::CharacterType(const string& name) : IdentRecord(name) {
}

CharacterType::~CharacterType(void) {
}

void CharacterType::display(int depth)const {
  printIndent(depth);
  //TODO
}
