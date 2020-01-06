#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>

void delay(int millis) {
    while (millis-- > 0) {
        volatile int x = 5971;
        while (x-- > 0) {
            __asm("nop");
        }
    }
}

int main(void) {

    // GPIO structure for port initialization
    GPIO_InitTypeDef gpio_t;

    // enable clock on APB2
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,  ENABLE);

    // configure port A1 for driving an LED
    gpio_t.GPIO_Pin = GPIO_Pin_5;
    gpio_t.GPIO_Mode = GPIO_Mode_Out_PP;    // output push-pull mode
    gpio_t.GPIO_Speed = GPIO_Speed_50MHz;   // highest speed
    GPIO_Init(GPIOE, &gpio_t) ;             // initialize port
    GPIO_SetBits(GPIOE, GPIO_Pin_5);        // Turn LED0 Off

    // main loop
    while(1) {
        GPIO_SetBits(GPIOE, GPIO_Pin_5);    // turn the LED on
        delay(1800);
        GPIO_ResetBits(GPIOE, GPIO_Pin_5);  // turn the LED off
        delay(200);
    }
}
