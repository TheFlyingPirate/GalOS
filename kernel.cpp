#include "types.hpp"
#include "gdt.hpp"
#include "interrupts.hpp"
#include "keyboard.hpp"
#include "keyLayoutDE.hpp"
typedef void (*constructor());
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors(){
    for(constructor* i = &start_ctors; i != end_ctors; i++)
    {
        (*i)();
    }
}
uint8_t* xP;
uint8_t* yP;


void setCursor(uint8_t x, uint8_t y){
    *xP = x;
    *yP = y;
}
uint8_t* getCursorPos(){
    uint8_t rv[2];
    rv[0] = *xP;
    rv[1] = *yP;
    return rv;
};


void printf(int8_t * str)
{
    uint16_t* VideoMemory = (uint16_t *)0xb8000;
    static uint8_t x = 0 , y = 0;
    xP=&x;
    yP=&y;

    if(x >= 80){
        y++;
        x=0;
    }

    if(y >= 25){
        for(y = 0 ; y<25;y++){
            for(x=0;x<80;x++){
                VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | ' ';
            }
        }
        x=0;
        y=0;
    }
    for(int32_t i=0; str[i] != '\0'; ++i){
        switch (str[i]){
            case '\n':
                y++;
                x = 0;
                break;
            default:
                VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | str[i];
                x++;
                break;
        }


    }
}
void clear(){
    uint16_t* VideoMemory = (uint16_t *)0xb8000;
    *xP=0;
    *yP=0;
    for(int8_t y2 = 0 ; y2<25;y2++){
        for(int8_t x2=0;x2<80;x2++){
            VideoMemory[80*y2+x2] = (VideoMemory[80*y2+x2] & 0xFF00) | ' ';
        }
    }

}

keyLayoutDE* keyLayout;
void getKeyInput(uint8_t key){
    keyLayoutDE kl = *keyLayout;
    if(key<0x80){

      if(kl.keyLayout[key]!=0){
            printf(kl.keyLayout[key]);
      }else{
            char* foo = "KEYBOARD 0x00 ";
            char* hex = "0123456789ABCDEF";
            foo[11] = hex[(key >> 4) & 0xF];
            foo[12] = hex[key & 0xF];
            clear();
            printf(foo);
      }


    }

}

extern "C" void kernelMain(void* multiboot_structure, uint32_t magicnumber)
{

    keyLayoutDE kl;
    keyLayout = &kl;

    clear();
    printf("Hello World!\n");
    printf("This is a Test\n");
    setCursor(8,3);
    printf("This is a Test\n\n");
    GlobalDescriptorTable gdt;
    InterruptManager interrupts(0x20, &gdt);
    KeyboardDriver keyboard(&interrupts);

    interrupts.Activate();


    printf(kl.keyLayout[0x1E]);
   // clear();
    while(1){

    }
}