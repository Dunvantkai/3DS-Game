/*
	Hello World example made by Aurelio Mannara for libctru
	This code was modified for the last time on: 12/12/2014 21:00 UTC+1
*/

#include <3ds.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);

	// Main loop
	while (aptMainLoop())
	{
		hidScanInput();//Scan all the inputs. This should be done once for each frame
		touchPosition touch;
		hidTouchRead(&touch);
		printf("\x1b[1;0HX coordinate: %i       ",touch.px);
		printf("\x1b[2;0HY coordinate: %i       ",touch.py);
		printf("\x1b[30;16HPress Start to exit.");

		u32 kHeld = hidKeysHeld();

		if (kHeld & KEY_TOUCH) 
			printf("\x1b[3;0HIs Active: True ");
		else
			printf("\x1b[3;0HIs Active: False");

		u32 kDown = hidKeysDown();
		if (kDown & KEY_START) break; // break in order to return to hbmenu

		
		gfxFlushBuffers();// Flush and swap framebuffers
		gfxSwapBuffers();

		gspWaitForVBlank();//Wait for VBlank
	}

	gfxExit();
	return 0;
}