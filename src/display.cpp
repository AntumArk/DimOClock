#include "display.h"

Adafruit_HT1632 display = Adafruit_HT1632(HT_DATA, HT_WR, HT_CS);
Adafruit_HT1632 display2 = Adafruit_HT1632(HT_DATA, HT_WR, HT_CS2);

void setupDisplay() {
    Serial.print("Setting up display... ");
    //CS pin should be LOW if you want to write things to a panel.
    display.begin(ADA_HT1632_COMMON_16NMOS);

    //digitalWrite(HT_CS2,1);
    for (int y=0; y<TOTAL_HEIGHT; y++) {
        for (int x=0; x<TOTAL_WIDTH; x++) {
            setPixelAt(x, y,0);
            delay(5);
            display.writeScreen();
        }
    }
    delay(500);
    display.clearScreen();
    Serial.println();
    Serial.print("Setting up display2... ");
    //CS pin should be LOW if you want to write things to a panel.
    display2.begin(ADA_HT1632_COMMON_16NMOS);
    
    //digitalWrite(HT_CS2,1);
    for (int y=0; y<TOTAL_HEIGHT; y++) {
        for (int x=0; x<TOTAL_WIDTH; x++) {
            setPixelAt(x, y,1);
            delay(5);
            display2.writeScreen();
        }
    }
    delay(500);
    display2.clearScreen();
    Serial.println();
}

Adafruit_HT1632 getDisplay() {
    return display;
}
Adafruit_HT1632 getDisplay2() {
    return display2;
}
void setPixelAt(int x, int y,int screen) {
    drawPixelAt(x, y, true,screen);
}

void clrPixelAt(int x, int y,int screen) {
    drawPixelAt(x, y, false,screen);
}

void drawPixelAt(int x, int y, bool set,int screen) {
    switch (screen)
    {
    case 0:
    {
        if (set)
        {
            display.setPixel(pixelAt(x, y));
           // Serial.println("drawing on screen1");
        }
        else
        {
            display.clrPixel(pixelAt(x, y));
        }
    }
    break;
    case 1:
    {
        if (set)
        {
            display2.setPixel(pixelAt(x, y));
             // Serial.println("drawing on screen2");
        }
        else
        {
            display2.clrPixel(pixelAt(x, y));
        }
    }
    break;
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
           // drawPixelAt(x+w, y+h,  (FONT_3X5[offset+h] & 1<<(font_w-1-w))  );
        }
    }
}

void drawChar5x10(int x, int y, int index) {
    int offset = index*FONT_5X10_BYTES_PER_CHAR;
    int font_w = 5;
    int font_h = 10;

    for (int w=0; w<font_w; w++) {
        for (int h=0; h<font_h; h++) {
            //drawPixelAt(x+w, y+h,  (FONT_5X10[offset+h] & 1<<(font_w-1-w))  );
        }
    }
}
void drawChar12x16(int x, int y, int index,int sreen) {
    int offset = index*FONT_12X16_BYTES_PER_CHAR;
    int font_w = 12;
    int font_h = 16;

    for (int w=0; w<font_w; w++) {
        for (int h=0; h<font_h; h++) {
            
            drawPixelAt(x+w, y+h,  (FONT_12X16[offset+h] & 1<<(font_w-1-w)) ,sreen );
           
            
        }
    }

     //drawPixelAt(x, y,  1,sreen );
}
