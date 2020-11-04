#include "machine.h"

std::pair<bool, bool>& CInfo::operator [](size_t i) {
        return info[i];
    }