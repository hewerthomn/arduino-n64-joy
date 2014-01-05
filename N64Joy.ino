/*
* ----------------------------------------------------------------------------
* "THE BEER-WARE LICENSE" (Revision 42):
* <phk@FreeBSD.ORG> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
* ----------------------------------------------------------------------------
*
* N64 Controller attached to pin 2
*
* libs
* N64Controller    http://mbed.org/users/purplelion/code/N64Controller
*/

#include <N64Controller.h>

/* constants */
#define N64_PIN 2

// Controller
N64Controller joy (2);

/* setup */
void setup()
{
  Serial.begin(115200);
  
  joy.begin();
}

/* loop */
void loop()
{
  printButtons();
  delay(100);
}

void printButtons()
{
  joy.update();
  
  printButton(joy.button_D_up());
  printButton(joy.button_D_down());
  printButton(joy.button_D_left());
  printButton(joy.button_D_right());
  printButton(joy.button_Start());
  printButton(joy.button_A());
  printButton(joy.button_B());
  printButton(joy.button_Z());
  printButton(joy.button_L());
  printButton(joy.button_R());
  printButton(joy.button_C_up());
  printButton(joy.button_C_down());
  printButton(joy.button_C_left());
  printButton(joy.button_C_right());
  
  Serial.print(joy.axis_x());
  Serial.print(" ");  
  Serial.println(joy.axis_y());
}

void printButton(boolean pressed)
{
  if(pressed)
    Serial.print("1");
  else
    Serial.print("0");  
  Serial.print(" ");
}
