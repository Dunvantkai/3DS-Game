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
		touchPosition touch; //makes touch the touch touchPosition
		hidTouchRead(&touch);
		printf("\x1b[1;0HX coordinate: %i       ",touch.px);//px finds the x pixel
		printf("\x1b[2;0HY coordinate: %i       ",touch.py);

		u32 kHeld = hidKeysHeld(); //finds the held keys

		if (kHeld & KEY_TOUCH) 
			printf("\x1b[3;0HIs Active: True ");
		else
			printf("\x1b[3;0HIs Active: False");

		u32 kDown = hidKeysDown(); //finds the pressed down keys
		if (kDown & KEY_START) break; // break in order to return to hbmenu

		
		gfxFlushBuffers();// Flush and swap framebuffers
		gfxSwapBuffers();

		gspWaitForVBlank();//Wait for next blank screen
	}

	gfxExit();
	return 0;
}