#include "block.hpp"

bool Block::empty() {
    return heros.empty();
}

int Block::heroCount() {
    return heros.size();
}
