#ifndef GALOS_KEYBOARD_HPP
#define GALOS_KEYBOARD_HPP

#include "types.hpp"
#include "interrupts.hpp"
#include "port.hpp"

class KeyboardDriver : public InterruptHandler
{
    Port8Bit dataport;
    Port8Bit commandport;
public:
    KeyboardDriver(InterruptManager* manager);
    ~KeyboardDriver();
    virtual uint32_t HandleInterrupt(uint32_t esp);

};

#endif //GALOS_KEYBOARD_HPP
