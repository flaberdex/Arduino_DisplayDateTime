////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///              //              //              //    //////    //    //////    //              ////////  ////////              ///
///              //              //              //    //////    //    //////    //              //////     ///////              ///
////////    ///////    ////////////     ///////////    //////    //    //////    ///////    /////////          ////////      ///////
////////    ///////    ////////////     ///////////    //////    //    //////    ///////    ///////              //////      ///////
////////    ///////              //     ///////////              //    //////    ///////    ///////     ////     //////      ///////
////////    ///////              //     ///////////              //              ///////    ///////     ////     //////      ///////
////////    ///////    ////////////     ///////////    //////    ///////    ////////////    ///////              //////      ///////
////////    ///////    ////////////     ///////////    //////    ///////    ////////////    ///////     ////     //////      ///////
////////    ///////              //     ///////////    //////    ///////    ////////////    ///////     ////     //              ///
////////    ///////              //              //    //////    ///////    ////////////    ///////     ////     //              ///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <LiquidCrystal.h>                      //Import the LCD Library
#include <DS1307RTC.h>                          //Import the RTC Library
#include <Time.h>                               //Import the Time Library
#include <Wire.h>                               //Import the Wire Library

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);         //Declare the Pins for LCD
tmElements_t tm;                                //Bring in commands from the Time|RTC Library

void setup() {                                  //Start Setup
  lcd.begin(20, 4);                             //Declare the dimensions of the Character LCD
  lcd.setCursor(0, 0);                          //Bring LCD cursor to Column 1 Row 1
  lcd.print("    Current Time");                //Print the title for time
  lcd.setCursor(0, 2);                          //Bring LCD cursor to Column 2 Row 3
  lcd.print("        Date");                    //Print the title for date
}                                               //End Setup

void printDigits(int digits) {                  //Setting up so that it adds a zero before a single digit
  if (digits < 10)                              //If the hour/minute/second is only one digit
    lcd.print('0');                             //Then display "0"
    lcd.print(digits);                          //After the zero, display the actual single digit
}
   
  
void loop() {                                   //Defining a loop
  if (RTC.read(tm)) {                           //If the Arduino can read something from the RTC
    lcd.setCursor(0, 1);                        //Then move the LCD cursor to the second line
    lcd.print("      ");                        //Add some space for the formatting (centered)
    printDigits(tm.Hour);                       //Print the hour
    lcd.print(":");                             //Print a colon to separate the hour and the minute
    printDigits(tm.Minute);                     //Print the minute
    lcd.print(":");                             //Print a colon to separate the minute and the second
    printDigits(tm.Second);                     //Print the second
    lcd.setCursor(0, 3);                        //Set the LCD cursor to the forth line
    lcd.print("     ");                         //Add some space for the formatting (centered)
    printDigits(tm.Month);                      //Print the month
    lcd.print("/");                             //Add a slash to separate the month and the day
    printDigits(tm.Day);                        //Print the day
    lcd.print("/");                             //Add a slash to separate the day and the year
    lcd.print(tmYearToCalendar(tm.Year));       //Print the year
  }                                             //End of the loop
}                                               //End of the sketch
