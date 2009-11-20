ArrayHelper::~ArrayHelper(void) {
  while (!ranges.empty()) {
    Range* range = ranges.pop();
    if (range != NULL) { 
      delete range; 
    }
  }
}

bool ArrayHelper::addRange(int lower; int upper) {
  if (!clean) { return false; }
  //Do not allow a range that goes in reverse
  if (lower < upper) {
    Range* range = new Range; 
    range->lower = lower;
    range->upper = upper;
    ranges.push(range);
  } else {
    clean = false; 
    cout << "Error: lower range bound greater than higher range bound." << endl;
    return false;
  }
}

bool ArrayHelper::sendToSt(STObject* st) {
  //TODO: check if clean, if so, set up an ArrayType and return st->insert()
}
