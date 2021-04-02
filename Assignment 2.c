/*          Created by Saad Abuzaid on 13th of Dec 2020 19:48;
                                          C with embedded systems Assignment 2                                                   */



#include "mbed.h"
#include "C12832.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "stm32f413h_discovery_ts.h"
#include "stm32f413h_discovery_lcd.h"
TS_StateTypeDef TS_State = { 0 };

C12832 lcd(SPI_MOSI, SPI_SCK, SPI_MISO, p8, p11);
int within(int goal, int guess, int n){                                         //Within function return 0 or 1 according to the inputs
    if( abs(goal-guess)<=n){
     return 1;
     }
    else
     return 0;
    }
int main(){
    BSP_LCD_Init();                                                             //intializing the touchpad
    if(BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize()) == TS_ERROR) {       // Throwing a message if there was an error intializing it
        printf("BSP_TS_Init error\n");
    }
    
    BSP_LCD_Clear(LCD_COLOR_WHITE);                                             //Set The background color
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);                                      //Set the text color
    BSP_LCD_DrawHLine(0,0,240);                                                 // Drawing Vertical & Horizontal lines with the specified coordinates
    BSP_LCD_DrawHLine(0,60,240);
    BSP_LCD_DrawHLine(0,120,240);
    BSP_LCD_DrawHLine(0,180,240);
    BSP_LCD_DrawHLine(0,239,240);
    BSP_LCD_DrawVLine(0,0,240);
    BSP_LCD_DrawVLine(80,0,240);
    BSP_LCD_DrawVLine(160,0,240);
    BSP_LCD_DrawVLine(239,0,240);
    BSP_LCD_DisplayChar(32, 22,'1');                                            //Set the number and letters in the touchpad with their coordinates
    BSP_LCD_DisplayChar(112, 22,'2');
    BSP_LCD_DisplayChar(192,22,'3');
    BSP_LCD_DisplayChar(32,85,'4');
    BSP_LCD_DisplayChar(112,85,'5');
    BSP_LCD_DisplayChar(192,85,'6');
    BSP_LCD_DisplayChar(32,145,'7');
    BSP_LCD_DisplayChar(112,145,'8');
    BSP_LCD_DisplayChar(192,145,'9');
    BSP_LCD_DisplayChar(32,202,'Y');
    BSP_LCD_DisplayChar(112,202,'0');
    BSP_LCD_DisplayChar(192,202,'C');
int guess;                                                                      //initialise guess that stores the user guess
srand((unsigned)time(0));                                                       
int goal= rand()%30 +1;                                                         //Setting the random number up to 30
int button;                                                                     // int to store in, and intermediate between touchpad and int guess
int i=0;                                                                        // to set out of limits with only 2 digits stored
int cord=0;                                                                     //to locate the guess num in specified coords
int tries=1;                                                                     //prints the secret number on first row
printf("What's ur guess?\n");                                                   // asks for the guess on serial output

    while (1) {          
        lcd.locate(0,0);                                                        //locates the coordintates of upcoming lcd.printf
        lcd.printf("The secret number:%d\n", goal);                             //while loop for the touchpad
        BSP_TS_GetState(&TS_State);                                             //gets the state
        
        if(TS_State.touchDetected) {                                            //if a touch was detected
            uint16_t x = TS_State.touchX[0];                                   //x coord of touched area
            uint16_t y = TS_State.touchY[0];                                   //y coord of touched area
            
            lcd.locate(cord,8);                                                 //locates the user guesses with coords(cord,8)
            cord+=5;                                                            //increment cord with 5
            
            if(x<=80 && y<60){                                                  //if button 1 pressed
                 button*=10;                                                    //multiplies the first digit by 10 to move it one digit to the left
                button+=1;                                                      //adds the value itself
                lcd.printf("1");                                                //prints 1 on the lcd screen
                i++;                                                            //increment i with 1 to keep in limits of 2 digits max
            }
            else if( x <= 160 && y <= 60){                                      //if button 2 pressed
               button*=10;                                                      //multiplies the first digit by 10 to move it one digit to the left
                button+=2;                                                      //adds the value itself
              lcd.printf("2");                                                  //prints 2 on the lcd screen
                i++;                                                            //increments i with 1 to keep it within the limit of 2 digits
            }
            
            else if(x<=240 && y<=60){                                           //if button 3 is pressed
                button*=10;                                                     //multiplies the first digit by 10 to move it one digit to the left
                button+=3;                                                      //adds 3 to button
               lcd.printf("3");                                                 //prints 3 on the lcd screen
                i++;                                                            //increments i to keep the input within the limit of 2 digits
            }
            else if(x<=80 && y<=120){                                           //if button 4 is pressed
                 button*=10;                                                    ////multiplies the first digit by 10 to move it one digit to the left
                button+=4;                                                      //adds the number itself to button
               lcd.printf("4");                                                 //prints 4 on the lcd screen
                i++;                                                            // increments i with one to keep the guess within the limit of 2 digits
            }
            else if(x<=160 && y<=120){                                          //if button 5 is pressed
                button*=10;                                                     //multiplies the first digit by 10 to move it one digit to the left
                button+=5;                                                      // adds 5 to int button
               lcd.printf("5");                                                 //prints 5 on the lcd
                i++;                                                            //increment i with one to keep theinput within 2 digits limit
            }
            else if(x<=240 && y<=120){                                          //if button 5 is pressed
                button*=10;                                                     //multiplies the first digit by 10 to move it one digit to the left
                button+=6;                                                      //adds 6 to int button
               lcd.printf("6");                                                 //prints 6 on the lcd
                i++;                                                            //increment i with one to keep the input within 2 digits limit
            }
            else if(x<=80 && y<=180){                                           //if button 6 is pressed
              button*=10;                                                       //multiplies the first digit by 10 to move it one digit to the left
                button+=7;                                                      //adds 7 to int button
               lcd.printf("7");                                                 //prints 7 on the lcd
                i++;                                                            //increments i with one to keep the input within 2 digits limit
            }
            else if(x<=160 && y<=180){                                          //if button 8 is pressed
                button*=10;                                                     //multiplies the first digit by 10 to move it one digit to the left
                button+=8;                                                      //adds 8 to int button
               lcd.printf("8");                                                 // prints 8 on the lcd
                i++;                                                            //increment i with one to keep the input within 2 digits limit
            }
            else if(x<=240 && y<=180){                                          //if button 9 is pressed
             button*=10;                                                        //multiplies the first digit by 10 to move it one digit to the left
            button+=9;                                                          //adds 9 to int button
                lcd.printf("9");                                                //prints 9 to the lcd
                i++;                                                            //increment i with one to keep the input within 2 digits limit
            }
            
            else if(x<=80 && y<=240){                                           //if button Y is pressed to submit the guess
                printf("%d\n",button);                                          // prints the value of button on the serial output
                guess=button;                                                   //assign the value stored in button to guess
            if(guess==goal){                                                    //checks if goal is equal to the guess
                printf("NJ! Your score is %d after %d tries\n",(100-(tries*2)),tries);                                            
                lcd.cls();
                
                    for (i = -20; i < 5; i++) {                                     //scrolling YOU GOT IT RIGHT
                        lcd.locate(37, i);
                        lcd.printf("YOU GOT IT");
                        lcd.locate(50, i + 12);
                        lcd.printf("RIGHT");
                        wait(0.2);
                        lcd.printf("YOU GOT IT");
                        lcd.locate(50, i + 12);
                        lcd.printf("RIGHT");
                        i = i + 1;
                        lcd.cls();
                      }
                        lcd.locate(37, i);
                        lcd.printf("YOU GOT IT");
                        lcd.locate(50, i + 12);
                        lcd.printf("RIGHT");
                        
                        break;                                                  //breaks out of the while loop
                    }
                    else if(i==0){
                        lcd.cls();
                        lcd.printf("Enter an input");
                        wait(1);
                        lcd.cls();
                        printf("You should enter an input\n");    
                    }
                        
                    else if(within(goal, guess, 3)){                            // checks if guess is within goal by 3
                        printf("you are within the right answer by 3 \n");      
                        i=0;                                                    //reset 0 to reassign two digits
                        tries++;
                    }
                    else{                                                       
                        printf("you are more than 3 away from the right answer!\n");
                        i=0;    
                        tries++;
                    }
                    button=0;  
                    lcd.cls();                                                //reset button's value incase it's wrong 
                    } 
            else if(x<=160 && y<=240){                                          //if button 0 is pressed
               button*=10;                                                      
                button+=0;
                lcd.printf("0");
                i++;                                    
            }
            else if(x<=240 && y<=240){                                          //if button C is pressed to clear
               button=0;
                printf("\n cleared\n");
                i=0;
                lcd.cls();
            }
            if(i>2){                                                            //if more than 2 digits inputted
                    printf("Out of limit\n");
                    button=0;
                    lcd.cls();
                    lcd.printf("OUT OF 2 DIGITS LIMIT");
                    wait(0.5);
                    lcd.cls();
                    i=0;
                    
            }
            wait(0.5);
            
        }
        
        
    }
    
}
