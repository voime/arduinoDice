/*
Arduino based DICE with touch sensor

Connect Capacitive touch sensor 1Mohm resistor send and recv pins
Connect 7 led pins 220ohm resistor to arduino digital pins.

dice_pins array

*0     *3
*1  *6 *4
*2     *5

Arvi Võime 2016
*/

#include <CapacitiveSensor.h>

// pins setup and creating objects

// Mega board testing
//int dice_pins[] = {22, 24, 26, 28, 30, 32, 34 };
//CapacitiveSensor cs = CapacitiveSensor(41,45);

// Arduino Pro mini
int dice_pins[] = {12, 11, 10, 6, 7, 8, 9 };
CapacitiveSensor cs = CapacitiveSensor(4,3);

int max_touch = 10; 

// for nice spinner
int spin_start = 250;
int spin_time;
int spin_step = 0;

boolean show_dice = false;

int value = 0;

void setup(){
  
}

void loop(){

    int touch =  cs.capacitiveSensor(30);
    
    if (touch > max_touch) {
      
      spin();
      value = random(1,7);
    
    } else {
    
      if (show_dice){
        spin_time = spin_start;
        dice(value);
      }
    
    }
    
    delay(10);

}

// nice spinner, if holding finger down
void spin()
{
  
  if (spin_time > 50){
    spin_time = spin_time - 20;
  } 
    
  if (spin_step==0){
    
    digitalWrite(dice_pins[0], HIGH);
    digitalWrite(dice_pins[1], LOW);
    digitalWrite(dice_pins[2], LOW);
    digitalWrite(dice_pins[3], LOW);
    digitalWrite(dice_pins[4], LOW);
    digitalWrite(dice_pins[5], HIGH);
    digitalWrite(dice_pins[6], LOW);    
    
    spin_step = 1;

  }else if (spin_step==1){
    digitalWrite(dice_pins[0], LOW);
    digitalWrite(dice_pins[1], HIGH);
    digitalWrite(dice_pins[2], LOW);
    digitalWrite(dice_pins[3], LOW);
    digitalWrite(dice_pins[4], HIGH);
    digitalWrite(dice_pins[5], LOW);
    digitalWrite(dice_pins[6], LOW);    
    
    spin_step = 2;

  }else if(spin_step==2){

    digitalWrite(dice_pins[0], LOW);
    digitalWrite(dice_pins[1], LOW);
    digitalWrite(dice_pins[2], HIGH);
    digitalWrite(dice_pins[3], HIGH);
    digitalWrite(dice_pins[4], LOW);
    digitalWrite(dice_pins[5], LOW);    
    digitalWrite(dice_pins[6], LOW);
    
    spin_step = 3;

  }else{

    digitalWrite(dice_pins[0], LOW);
    digitalWrite(dice_pins[1], LOW);
    digitalWrite(dice_pins[2], LOW);
    digitalWrite(dice_pins[3], LOW);
    digitalWrite(dice_pins[4], LOW);
    digitalWrite(dice_pins[5], LOW);
    digitalWrite(dice_pins[6], HIGH);
    spin_step=0;

  }

  delay(spin_time);
  
  show_dice = true;
  
}

// show rolled value on dice leds
void dice(int value){
  // reset leds

        digitalWrite(dice_pins[0], LOW);
        digitalWrite(dice_pins[1], LOW);
        digitalWrite(dice_pins[2], LOW);
        digitalWrite(dice_pins[3], LOW);
        digitalWrite(dice_pins[4], LOW);
        digitalWrite(dice_pins[5], LOW);
        digitalWrite(dice_pins[6], LOW); 

  delay(1000);
  
  switch(value) {
    case 1:
      digitalWrite(dice_pins[0], LOW);
      digitalWrite(dice_pins[1], LOW);
      digitalWrite(dice_pins[2], LOW);
      digitalWrite(dice_pins[3], LOW);
      digitalWrite(dice_pins[4], LOW);
      digitalWrite(dice_pins[5], LOW);
      digitalWrite(dice_pins[6], HIGH);
      break;
    case 2:
      digitalWrite(dice_pins[0], HIGH);
      digitalWrite(dice_pins[1], LOW);
      digitalWrite(dice_pins[2], LOW);
      digitalWrite(dice_pins[3], LOW);
      digitalWrite(dice_pins[4], LOW);
      digitalWrite(dice_pins[5], HIGH);
      digitalWrite(dice_pins[6], LOW);
      break;
    case 3:
      digitalWrite(dice_pins[0], HIGH);
      digitalWrite(dice_pins[1], LOW);
      digitalWrite(dice_pins[2], LOW);
      digitalWrite(dice_pins[3], LOW);
      digitalWrite(dice_pins[4], LOW);
      digitalWrite(dice_pins[5], HIGH);
      digitalWrite(dice_pins[6], HIGH);
      break;
    case 4:
      digitalWrite(dice_pins[0], HIGH);
      digitalWrite(dice_pins[1], LOW);
      digitalWrite(dice_pins[2], HIGH);
      digitalWrite(dice_pins[3], HIGH);
      digitalWrite(dice_pins[4], LOW);
      digitalWrite(dice_pins[5], HIGH);
      digitalWrite(dice_pins[6], LOW);
      break;
    case 5:
      digitalWrite(dice_pins[0], HIGH);
      digitalWrite(dice_pins[1], LOW);
      digitalWrite(dice_pins[2], HIGH);
      digitalWrite(dice_pins[3], HIGH);
      digitalWrite(dice_pins[4], LOW);
      digitalWrite(dice_pins[5], HIGH);
      digitalWrite(dice_pins[6], HIGH);
      break;
    case 6:
      digitalWrite(dice_pins[0], HIGH);
      digitalWrite(dice_pins[1], HIGH);
      digitalWrite(dice_pins[2], HIGH);
      digitalWrite(dice_pins[3], HIGH);
      digitalWrite(dice_pins[4], HIGH);
      digitalWrite(dice_pins[5], HIGH);
      digitalWrite(dice_pins[6], LOW);
      break;
    default:
      break;
  }

  show_dice = false;

}

