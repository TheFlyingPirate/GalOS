#include "keyLayoutDE.hpp"
int8_t* keyLayoutDE::keyLayout[256];
void keyLayoutDE::addKeyMapping(uint8_t keycode, int8_t* value) {
    keyLayout[keycode] = value;
}

keyLayoutDE::~keyLayoutDE() {

}
keyLayoutDE::keyLayoutDE() {
    for(uint8_t i = 0; i<255; i++){
        addKeyMapping(i,0);
    }
    addKeyMapping(0x29, "^");
    addKeyMapping(0x02, "1");
    addKeyMapping(0x03, "2");
    addKeyMapping(0x04, "3");
    addKeyMapping(0x05, "4");
    addKeyMapping(0x06, "5");
    addKeyMapping(0x07, "6");
    addKeyMapping(0x08, "7");
    addKeyMapping(0x09, "8");
    addKeyMapping(0x0A, "9");
    addKeyMapping(0x0B, "0");
    addKeyMapping(0x0C, "?"); //ß
    addKeyMapping(0x0D, 0); //´
    addKeyMapping(0x0C, 0); //BackSpace
    addKeyMapping(0x10, "Q");
    addKeyMapping(0x11, "W");
    addKeyMapping(0x12, "E");
    addKeyMapping(0x13, "R");
    addKeyMapping(0x14, "T");
    addKeyMapping(0x15, "Z");
    addKeyMapping(0x16, "U");
    addKeyMapping(0x17, "I");
    addKeyMapping(0x18, "O");
    addKeyMapping(0x19, "P");
    addKeyMapping(0x1A, 0); //Ü
    addKeyMapping(0x1B, "*");
    addKeyMapping(0x1C, "\n");
    addKeyMapping(0x1E, "A");
    addKeyMapping(0x1F, "S");
    addKeyMapping(0x20, "D");
    addKeyMapping(0x21, "F");
    addKeyMapping(0x22, "G");
    addKeyMapping(0x23, "H");
    addKeyMapping(0x24, "J");
    addKeyMapping(0x25, "K");
    addKeyMapping(0x26, "L");
    addKeyMapping(0x27, 0); //Ö
    addKeyMapping(0x28, 0);//Ä
    addKeyMapping(0x2B, "#");
    addKeyMapping(0x2C, "Y");
    addKeyMapping(0x2D, "X");
    addKeyMapping(0x2E, "C");
    addKeyMapping(0x2F, "V");
    addKeyMapping(0x30, "B");
    addKeyMapping(0x31, "N");
    addKeyMapping(0x32, "M");
    addKeyMapping(0x33, ",");
    addKeyMapping(0x34, ".");
    addKeyMapping(0x35,"-");
    addKeyMapping(0x39," ");
    addKeyMapping(0x56,">");
}