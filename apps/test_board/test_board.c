/* test_board: This is a simple test application that test the basic
 * features of board.h and time.h.
 * 
 * It blinks the green LED, but that is only visible if the USB
 * is connected because the green LED is powered from USB.
 * 
 * It turns on the yellow LED if and only if self power is present.
 * 
 * It turns on the red LED if and only if USB power is present.
 * 
 * Note that this app does NOT implement a USB interface, so it will
 * not be recognized by the Wixel Configuration Utility and you can
 * not get it in to bootloader mode using a USB command.  However, it
 * does call boardService(), so you can get it in to bootloader mode
 * by shorting P2_2 to 3V3 (3.3 V).
 */

#include <board.h>
#include <time.h>

void updateLeds()
{
    LED_GREEN(timeMs >> 9 & 1);     // Blink the Green LED (only visible w/ USB).
    LED_YELLOW(vinPowerPresent());  // Indicate VIN power with the yellow LED.
    LED_RED(usbPowerPresent());     // Indicate USB power with the red LED.
}

void main()
{
    systemInit();
    while(1)
    {
        boardService();
        updateLeds();
    }
}