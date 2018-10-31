#ifndef GALOS_KEYLAYOUTDE_HPP
#define GALOS_KEYLAYOUTDE_HPP
#include "types.hpp"
class keyLayoutDE {
public:
    static int8_t* keyLayout[256];
    void addKeyMapping(uint8_t keycode, int8_t *value);
    keyLayoutDE();
    ~keyLayoutDE();


};
#endif //GALOS_KEYLAYOUTDE_HPP
