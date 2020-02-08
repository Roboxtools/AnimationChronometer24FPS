#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

#define BUTTON_A 31
#define BUTTON_B 30
#define BUTTON_C 27

static const unsigned char PROGMEM logo_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);
  digitalWrite(BUTTON_A, HIGH);  
  digitalWrite(BUTTON_B, HIGH);
  digitalWrite(BUTTON_C, HIGH);
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(200); // Pause for 2 seconds
}


void loop() {
    testdrawstyles();
}

int fps=42;
double jorframesc = 0;
double jorframes = 0;
double jorseconds = 0;
double jorminutes = 0;
void testdrawstyles(void) {
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
    // Draw white text
  display.setCursor(0,0);   
  display.setTextColor(BLACK, WHITE); // Start at top-left corner
  display.println(F(" FPS TIMER "));
  
/*  
  display.setCursor(70,0); 
  display.setTextColor(WHITE);    
  display.println(F("00:00:00"));  
  display.setTextSize(3);             // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.println("000000");
*/

  display.display();
  delay(200);
  

if(digitalRead(BUTTON_B) == LOW){
  display.clearDisplay();
  
double jorframesc = 0;
double jorframes = 0;
double jorseconds = 0;
double jorminutes = 0;

  while(digitalRead(BUTTON_C) == HIGH)
  {
//  c = millis();

  //clock
  jorframes++;
  jorframesc++;
  delay(fps);
  if(jorframes >=24){
    jorframes = 0;
    jorseconds++;
    if(jorseconds >=60){
       jorseconds = 0;
       jorminutes++; 
       if(jorminutes >=60){
          jorminutes = 0;  
    } 
    }
  };  

//title
  display.setTextSize(1);   
  display.setCursor(0,0);   
  display.setTextColor(BLACK, WHITE); 
  display.println(F(" FPS TIMER "));

// top timer 
  display.setTextColor(WHITE);

  display.setCursor(73,0); 
  int imm = jorminutes;
  static char strOut[3];
  if (imm >= 0 && imm < 10) {
    sprintf(strOut, "%02d", imm);
    display.println(strOut);  
  } else {
    display.println(imm);  
  }

  display.setCursor(84,0);
  display.println(":");

  display.setCursor(90,0); 
  int ims=jorseconds;
  static char strOut2[3];
  if (ims >= 0 && ims < 10) {
    sprintf(strOut2, "%02d", ims);
    display.println(strOut2); 
  } else {
    display.println(ims); 
  }

  display.setCursor(102,0);
  display.println(":");
       
  display.setCursor(108,0); 
  int imf=jorframes;
  static char strOut3[3];
  if (imf >= 0 && imf < 10) {
    sprintf(strOut3, "%02d", imf);
    display.println(strOut3);      
  } else {
    display.println(imf);      
  }

  display.println(""); 

//bottom timer
  
  display.setTextSize(2);          
  display.setTextColor(WHITE);
  int is=jorframesc;
  display.println("F:");
  display.setTextSize(3);
  display.setCursor(24,10); 
  display.print(is);
  display.display();
  display.clearDisplay();  
  }


if(digitalRead(BUTTON_C) == LOW){
  while(digitalRead(BUTTON_B) == HIGH){
      display.clearDisplay();  
      display.setTextSize(1);   
      display.setCursor(0,0);   
      display.setTextColor(BLACK, WHITE); // Start at top-left corner
      display.println(F(" FPS TIMER "));
      
// top timer 
  display.setTextColor(WHITE);

  display.setCursor(73,0); 
  int imm = jorminutes;
  static char strOut[3];
  if (imm >= 0 && imm < 10) {
    sprintf(strOut, "%02d", imm);
    display.println(strOut);  
  } else {
    display.println(imm);  
  }

  display.setCursor(84,0);
  display.println(":");

  display.setCursor(90,0); 
  int ims=jorseconds;
  static char strOut2[3];
  if (ims >= 0 && ims < 10) {
    sprintf(strOut2, "%02d", ims);
    display.println(strOut2); 
  } else {
    display.println(ims); 
  }

  display.setCursor(102,0);
  display.println(":");
       
  display.setCursor(108,0); 
  int imf=jorframes;
  static char strOut3[3];
  if (imf >= 0 && imf < 10) {
    sprintf(strOut3, "%02d", imf);
    display.println(strOut3);      
  } else {
    display.println(imf);      
  }

  display.println(""); 
//bottom timer
  
  display.setTextSize(2);          
  display.setTextColor(WHITE);
  int is=jorframesc;
  display.println("F:");
  display.setTextSize(3);
  display.setCursor(24,10); 
  display.print(is);
  display.display();
  delay(200);
      }
  }

/*
if(digitalRead(BUTTON_A) == LOW){
  if(digitalRead(BUTTON_B) == HIGH){
      display.clearDisplay();  
      display.setTextSize(1);   
      display.setCursor(0,0);   
      display.setTextColor(BLACK, WHITE); // Start at top-left corner
      display.println(F(" FPS TIMER"));
      
      //bottom timer
      display.setTextSize(2);          
      display.setTextColor(WHITE);
      int fps=30;
      display.println("FPS:");
      display.setTextSize(3);
      display.setCursor(35,10); 
      display.print(is);
      display.display();
      delay(200);
      }
  }

*/
}



}
