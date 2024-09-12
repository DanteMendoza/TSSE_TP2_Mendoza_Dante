#include "src/DriverLed.h"
#include "C:/Users/dmendoza/.local/share/gem/ruby/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


static uint16_t virtual_led;



void setUp(void)

{

   DriverLed_Create(&virtual_led);

}





void test_All_Led_Initialice_Off(void)

{

   uint16_t virtual_led = 0xFFFF;



   DriverLed_Create(&virtual_led);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((virtual_led)), (

  ((void *)0)

  ), (UNITY_UINT)(17), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOn_Led(void)

{

   DriverLed_TurnOn(12);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0800)), (UNITY_INT)(UNITY_INT16)((virtual_led)), (

  ((void *)0)

  ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TunrOn_and_TurnOff_led(void)

{

   DriverLed_TurnOn(1);

   DriverLed_TurnOff(1);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((virtual_led)), (

  ((void *)0)

  ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TunrOn_and_TurnOff_some_led(void)

{

   DriverLed_TurnOn(8);

   DriverLed_TurnOn(9);

   DriverLed_TurnOff(8);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0100)), (UNITY_INT)(UNITY_INT16)((virtual_led)), (

  ((void *)0)

  ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOn_all_leds(void)

{

   DriverLed_TurnOnAll();

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((virtual_led)), (

  ((void *)0)

  ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOff_all_leds(void)

{

   DriverLed_TurnOffAll();

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((virtual_led)), (

  ((void *)0)

  ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_HEX16);

}





void test_Led_dont_affect_the_rest(void)

{

   DriverLed_TurnOnAll();

   DriverLed_TurnOff(9);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFEFF)), (UNITY_INT)(UNITY_INT16)((virtual_led)), (

  ((void *)0)

  ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_HEX16);

}





void test_Read_state_led_on(void)

{

   do {if (!(DriverLed_ReadStateOn(12))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(69)));}} while(0);

   DriverLed_TurnOn(12);

   do {if ((DriverLed_ReadStateOn(12))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(71)));}} while(0);

}





void test_Read_state_led_off(void)

{

   do {if ((DriverLed_ReadStateOff(5))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(77)));}} while(0);

   DriverLed_TurnOn(5);

   do {if (!(DriverLed_ReadStateOff(5))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(79)));}} while(0);

}





void test_Lower_and_upper_bound(void)

{

   DriverLed_TurnOn(1);

   DriverLed_TurnOn(16);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0X8001)), (UNITY_INT)(UNITY_INT16)((virtual_led)), (

  ((void *)0)

  ), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_HEX16);

}





void test_Invalid_parameters_(void)

{

   DriverLed_TurnOn(-1);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0X0000)), (UNITY_INT)(UNITY_INT16)((virtual_led)), (

  ((void *)0)

  ), (UNITY_UINT)(94), UNITY_DISPLAY_STYLE_HEX16);

   DriverLed_TurnOn(0);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0X0000)), (UNITY_INT)(UNITY_INT16)((virtual_led)), (

  ((void *)0)

  ), (UNITY_UINT)(96), UNITY_DISPLAY_STYLE_HEX16);

   DriverLed_TurnOn(17);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0X0000)), (UNITY_INT)(UNITY_INT16)((virtual_led)), (

  ((void *)0)

  ), (UNITY_UINT)(98), UNITY_DISPLAY_STYLE_HEX16);

   DriverLed_TurnOn(3141);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0X0000)), (UNITY_INT)(UNITY_INT16)((virtual_led)), (

  ((void *)0)

  ), (UNITY_UINT)(100), UNITY_DISPLAY_STYLE_HEX16);

}
