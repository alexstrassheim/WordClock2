//
// 113 112 111 110 109 108 107 106 105 104 103
//  92  93  94  95  96  97  98  99 100 101 102
//  91  90  89  88  87  86  85  84  83  82  81
//  70  71  72  73  74  75  76  77  78  79  80
//  69  68  67  66  65  64  63  62  61  60  59
//  48  49  50  51  52  53  54  55  56  57  58
//  47  46  45  44  43  42  41  40  39  38  37
//  26  27  28  29  30  31  32  33  34  35  36
//  25  24  23  22  21  20  19  18  17  16  15
//   4   5   6   7   8   9  10  11  12  13  14
//                 3   2   1   0
//

#ifndef WClock_h
#define WClock_h

#include <FastLED.h>

/*
 * Turn debugging on or off
 */
#define WClock_DEBUG

/*
 * Define where DEBUG output will be printed
 */
#define DEBUG_PRINTER Serial

#ifdef WClock_DEBUG
    #define DEBUG_PRINT(...) { DEBUG_PRINTER.print(__VA_ARGS__); }
    #define DEBUG_PRINTLN(...) { DEBUG_PRINTER.println(__VA_ARGS__); }
#else
    #define DEBUG_PRINT(...) {}
    #define DEBUG_PRINTLN(...) {}
#endif

/*
 * Number of used LEDs for WordClock
 */
#define LED_PIN         10
#define NUM_LEDS        114
#define COLOR_ORDER     GRB
#define CHIPSET         WS2811
#define BRIGHTNESS      88

class WClock {
    public:
        // WClock(int LED_PIN, int NUM_LEDS);
        void begin(void);
        void drawHeart();
        void drawMatrix();
        void resetAndBlack();

        uint16_t XY( uint8_t y, uint8_t x);
        void setLed(int row, int col, boolean on);
        void updateDisplay(boolean previousframe[11][11], boolean frame[11][11]);
        void addWordToFrame(const int theword[3], boolean frame[11][11]);

        void showTime(int hours, int minutes, int seconds);
        void setB(int val);
    private:
        CRGB leds[NUM_LEDS];
        boolean frame[11][11];
        boolean prevframe[11][11];
        const uint8_t kMatrixWidth = 11;
        const uint8_t kMatrixHeight = 11;

        int hours = 0, minutes = 0, seconds = 0;

        // Wörter
        // Format: { column index, start index, length }
        const int w_funk[3] =       {3, 3, 4};

        const int w_es[3] =         {0, 0, 2};
        const int w_ist[3] =        {0, 3, 3};
        const int w_vor[3] =        {3, 0, 3};
        const int w_nach[3] =       {3, 7, 4};
        const int w_uhr[3] =        {9, 8, 3};

        const int w_hours[13][3] = {
            {5, 2, 3 }, // Ein
            {5, 2, 4 }, // Eins
            {5, 0, 4}, // Zwei
            {6, 2, 4}, // Drei
            {7, 7, 4}, // Vier
            {6, 7 ,4}, // Fünf
            {9, 1, 5}, // Sechs
            {5, 5, 6}, // Sieben
            {8, 1, 4 }, // Acht
            {7, 3, 4}, // Neun
            {8, 5, 4}, // Zehn
            {7, 0, 3}, // Elf
            {4, 5, 5}, // Zwölf
        };
        const int w_minutes[10][3] = {
            {0, 7 ,4}, // Fünf
            {1, 0, 4}, // Zehn
            {1, 4, 7}, // Zwanzig
            {2, 0, 11}, // Dreiviertel
            {2, 4, 7}, // Viertel
            {4, 0, 4}, // Halb
            {10, 0, 1}, // eins
            {10, 0, 2}, // zwei
            {10, 0, 3}, // drei
            {10, 0, 4} // vier
        };
};

#endif

