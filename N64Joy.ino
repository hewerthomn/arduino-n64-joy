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
* N64Controller    http://pothos.blogsport.eu/files/2012/03/N64Controller.zip
*/

#include <N64Controller.h>

/* constants */
#define N64_PIN 2

/* Controller instance */
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
  
  printButton(joy.button_D_up());   // 1
  printButton(joy.button_D_down()); // 2
  printButton(joy.button_D_left()); // 3
  printButton(joy.button_D_right());// 4
  printButton(joy.button_Start());  // 5
  printButton(joy.button_A());      // 6
  printButton(joy.button_B());      // 7
  printButton(joy.button_Z());      // 8
  printButton(joy.button_L());      // 9
  printButton(joy.button_R());      // 10
  printButton(joy.button_C_up());   // 11
  printButton(joy.button_C_down()); // 12
  printButton(joy.button_C_left()); // 13
  printButton(joy.button_C_right());// 14
  
  Serial.print(joy.axis_x());  // 15
  Serial.print(" ");  
  Serial.println(joy.axis_y()); // 16
}

void printButton(boolean pressed)
{
  if(pressed)
    Serial.print("1");
  else
    Serial.print("0");  
  Serial.print(" ");
}
