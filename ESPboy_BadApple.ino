#include <Arduboy2.h>
#include "bitmaps.h"

#define FRAME_RATE 10

#define ARRAY_LEN(a) (sizeof(a) / sizeof((a)[0]))

// make an instance of the Arduboy2 class used for many functions
Arduboy2 arduboy;

#define ARDBITMAP_SBUF arduboy.getBuffer()
#include <ArdBitmap.h>
ArdBitmap<WIDTH, HEIGHT> ardbitmap;

uint16_t frames = ARRAY_LEN(OUT);
unsigned long counter = 0;

void setup() {
	arduboy.begin();
	arduboy.setFrameRate(FRAME_RATE);
}

void loop() {
  delay(0);
	if (!(arduboy.nextFrame()))
		return;

	arduboy.clear();

	ardbitmap.drawCompressed(WIDTH / 2, HEIGHT / 2, OUT[counter % frames], WHITE, ALIGN_CENTER, MIRROR_NONE);

	arduboy.display();

	counter++;

}
