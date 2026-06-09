#include <stdio.h>
#include "esp_system.h"
#include "owgl.h"
extern "C" void app_main(void){
    init();
    test();
    while(true);
}