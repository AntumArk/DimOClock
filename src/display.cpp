#include "display.h"

// Adafruit_HT1632 display = Adafruit_HT1632(HT_DATA, HT_WR, HT_CS);
// Adafruit_HT1632 display2 = Adafruit_HT1632(HT_DATA, HT_WR, HT_CS2);

Adafruit_HT1632LEDMatrix matrix = Adafruit_HT1632LEDMatrix(HT_DATA, HT_WR, HT_CS, HT_CS2);
void setupDisplay() {
    Serial.print("Setting up display... ");
  matrix.begin(ADA_HT1632_COMMON_16NMOS);
  matrix.fillScreen();
  delay(500);
  matrix.clearScreen();
  matrix.setTextWrap(false);

    // display.begin(ADA_HT1632_COMMON_16NMOS);
    // display2.begin(ADA_HT1632_COMMON_16NMOS);
  
    // delay(500);
    // display.clearScreen();
    // display2.clearScreen();
    Serial.println();
}

Adafruit_HT1632LEDMatrix getDisplay() {
    return matrix;
}

void setPixelAt(int x, int y) {
    drawPixelAt(x, y, true);
}

void clrPixelAt(int x, int y) {
    drawPixelAt(x, y, false);
}

void drawPixelAt(int x, int y, bool set) {
    if (set) {
        matrix.setPixel(x,y);
        // for (int i = 0; i < 7; i++)
        // {
        //     for (int j = 0; j < 8; j++)
        //     {
        //         matrix.setPixel(1,j);
        //     }
            
        // }
        
    } else {
        matrix.clrPixel(x,y);
    }
}

int pixelAt(int x, int y) {
    if (y<=7) y=7-y;
    if (y>7) y=7-y+(TOTAL_HEIGHT);
    return (x*TOTAL_HEIGHT +y);
}

void drawChar3x5(int x, int y, int index) {
    int offset = index*FONT_3X5_BYTES_PER_CHAR;
    int font_w = 3;
    int font_h = 5;

    for (int w=0; w<font_w; w++) {
        for (int h=0; h<font_h; h++) {
            drawPixelAt(x+w, y+h,  (FONT_3X5[offset+h] & 1<<(font_w-1-w))  );
        }
    }
}

void drawChar5x10(int x, int y, int index) {
    int offset = index*FONT_5X10_BYTES_PER_CHAR;
    int font_w = 5;
    int font_h = 10;

    for (int w=0; w<font_w; w++) {
        for (int h=0; h<font_h; h++) {
            drawPixelAt(x+w, y+h,  (FONT_5X10[offset+h] & 1<<(font_w-1-w))  );
        }
    }
}
void drawChar12x16(int x, int y, int index) {
    int offset = index*FONT_12X16_BYTES_PER_CHAR;
    int font_w = 12;
    int font_h = 16;

    for (int w=0; w<font_w; w++) {
        for (int h=0; h<font_h; h++) {
            drawPixelAt(x+w, y+h,  (FONT_12X16[offset+h] & 1<<(font_w-1-w))  );
        }
    }
}
