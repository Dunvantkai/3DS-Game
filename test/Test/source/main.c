/*
	Hello World example made by Aurelio Mannara for libctru
	This code was modified for the last time on: 12/12/2014 21:00 UTC+1
*/

#include <3ds.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	gfxInitDefault();

	//Initialize console on top screen. Using NULL as the second argument tells the console library to use the internal console structure as current one
	consoleInit(GFX_TOP, NULL);

	//Move the cursor to row 15 and column 19 and then prints "Hello World!"
	//To move the cursor you have to print "\x1b[r;cH", where r and c are respectively
	//the row and column where you want your cursor to move
	//The top screen has 30 rows and 50 columns
	//The bottom screen has 30 rows and 40 columns
	//printf("\x1b[16;20HHello World!");

	printf("\x1b[30;16HPress Start to exit.");

	// Main loop
	while (aptMainLoop())
	{
		hidScanInput();//Scan all the inputs. This should be done once for each frame
		touchPosition touch;
		hidTouchRead(&touch);
		printf("\x1b[0;0HX coordinate: %i          ",touch.px);
		printf("\x1b[1;0HX coordinate: %i          ",touch.py);

		u32 kHeld = hidKeysHeld();

		if (kHeld & KEY_TOUCH) 
			printf("/x1b[2;0HIs Active: True");
		else
			printf("/x1b[2;0HIs Active: False");

		u32 kDown = hidKeysDown();
		if (kDown & KEY_START) break; // break in order to return to hbmenu

		
		gfxFlushBuffers();// Flush and swap framebuffers
		gfxSwapBuffers();

		gspWaitForVBlank();//Wait for VBlank
	}

	gfxExit();
	return 0;
}