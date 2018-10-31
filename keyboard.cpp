#include "keyboard.hpp"

KeyboardDriver::KeyboardDriver(InterruptManager *manager)
: InterruptHandler(0x21, manager),
dataport(0x60),
commandport(0x64)
{
    while(commandport.Read() & 0x1)
        dataport.Read();
    commandport.Write(0xAE);  //activate intterupts
    commandport.Write(0x20);  // get current state
    uint8_t state = (dataport.Read() | 1) & ~0x10;
    commandport.Write(0x60); //set state
    dataport.Write(state);
    dataport.Write(0xF4);
}

KeyboardDriver::~KeyboardDriver()
{
}

void printf(char*);
void clear();
void getKeyInput(uint8_t key);
uint32_t KeyboardDriver::HandleInterrupt(uint32_t esp)
{

    uint8_t key = dataport.Read();
    char* foo = "KEYBOARD 0x00 ";
    char* hex = "0123456789ABCDEF";
    switch(key)
    {
        case 0xFA: break;

        case 0x45: case 0xC5: break;

        default:
            /*char* foo = "KEYBOARD 0x00 ";
            char* hex = "0123456789ABCDEF";
            foo[11] = hex[(key >> 4) & 0xF];
            foo[12] = hex[key & 0xF];
            clear();
            printf(foo); */

            getKeyInput(key);
            break;
    }


    return esp;
}