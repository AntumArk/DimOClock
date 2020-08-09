#ifndef FONT_3x5_H
#define FONT_3x5_H

#define FONT_3X5_BYTES_PER_CHAR 5

static char FONT_3X5 [] = {
    0b111, 0b101, 0b101, 0b101, 0b111, // 0
    0b001, 0b011, 0b001, 0b001, 0b001, // 1
    0b111, 0b001, 0b111, 0b100, 0b111, // 2
    0b111, 0b001, 0b111, 0b001, 0b111, // 3
    0b101, 0b101, 0b111, 0b001, 0b001, // 4
    0b111, 0b100, 0b111, 0b001, 0b111, // 5
    0b111, 0b100, 0b111, 0b101, 0b111, // 6
    0b111, 0b001, 0b001, 0b001, 0b001, // 7
    0b111, 0b101, 0b111, 0b101, 0b111, // 8
    0b111, 0b101, 0b111, 0b001, 0b111, // 9
    0b111, 0b101, 0b111, 0b101, 0b101, // a
    0b110, 0b101, 0b110, 0b101, 0b110, // b
    0b111, 0b100, 0b100, 0b100, 0b111, // c
    0b110, 0b101, 0b101, 0b101, 0b110, // d
    0b111, 0b100, 0b110, 0b100, 0b111, // e
    0b111, 0b100, 0b110, 0b100, 0b100, // f
    0b000, 0b000, 0b000, 0b000, 0b010, // .
    0b000, 0b010, 0b000, 0b010, 0b000, // :
    0b000, 0b000, 0b111, 0b000, 0b000, // -
    0b000, 0b010, 0b111, 0b010, 0b000, // +
    0b111, 0b010, 0b010, 0b010, 0b010, // T
};

#define FONT_3X5_DOT   16
#define FONT_3X5_COLON 17
#define FONT_3X5_MINUS 18
#define FONT_3X5_PLUS  19
#define FONT_3X5_T     20

#endif // FONT_3x5_H