#include "src/all.c"
#include <stdio.h>
/*
To compile this C code with the following command,
Make sure this file is named "micro_main.c", the output stays "micro_main.dll"
and you are executing the command in the folder "microcontroller_simulator_3.3"
(For WINDOWS/Linux/macOS)
    x86_64-w64-mingw32-gcc -shared -o micro_main.dll micro_main.c

*/

/*
|   This is where you write the code for the microcontroller simulation.
|   "all.h" includes many functions, check that file for more detail.
*/

__declspec(dllexport) void* main(void* p)
{
    // Initialize here.
    RGBLED_Init();
    BTN_Init();
    SWT_Init();
    
    int num, value = 0;

    while(1){
        // Your code goes here.

        value = SWT_GetValue(0);

        if(BTN_GetValue('c')){
            RGBLED_SetValue(200*value,60,255*(1-value));
        }
        else{
            RGBLED_SetValue(255,255,255*value);
        }
    }
}