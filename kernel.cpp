#include "types.hpp"
#include "gdt.hpp"
#include "interrupts.hpp"
typedef void (*constructor());
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors(){
    for(constructor* i = &start_ctors; i != end_ctors; i++)
    {
        (*i)();
    }
}

void printf(int8_t * str)
{
    uint16_t* VideoMemory = (uint16_t *)0xb8000;
    static uint8_t x = 0 , y = 0;
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
    }
}
void clear(){
    uint16_t* VideoMemory = (uint16_t *)0xb8000;
    for(int8_t y2 = 0 ; y2<25;y2++){
        for(int8_t x2=0;x2<80;x2++){
            VideoMemory[80*y2+x2] = (VideoMemory[80*y2+x2] & 0xFF00) | ' ';
        }
    }
}



extern "C" void kernelMain(void* multiboot_structure, uint32_t magicnumber)
{
    clear();
    printf("Hello World!\n");
    printf("This is a Test\n");
    printf("This is a Test\n\n");
    GlobalDescriptorTable gdt;
    InterruptManager interrupts(0x20, &gdt);
    interrupts.Activate();

    while(1){

    }
}