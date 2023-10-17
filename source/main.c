#include <stdio.h>
#include <string.h>
#include <3ds.h>

int main()
{
  //Variables
  bool msgPrinted = false;

  // Initializations
  
  srvInit();        // services
  aptInit();        // applets
  hidInit();    // input
  gfxInitDefault(); // graphics
  consoleInit(GFX_TOP, NULL); // Console on top screen
  gfxSet3D(false);  // stereoscopy (true == on / false == off)
  u32 kDown;        // keys down
  u32 kHeld;        // keys pressed
  u32 kUp;          // keys up
  u8* fbTopLeft;    // top left screen's framebuffer
  u8* fbTopRight;   // top right screen's framebuffer
  u8* fbBottom;     // bottom screen's framebuffer

  printf("Why so sad Smealum? We can haz 3DS homebrew!");

	printf("\x1b[21;16HPress Start to exit.");

    
  // Main loop
  while (aptMainLoop())
  {

    // Wait for next frame
    gspWaitForVBlank();

    // Read which buttons are currently pressed or not
    hidScanInput();
    kDown = hidKeysDown();
    kHeld = hidKeysHeld();
    kUp = hidKeysUp();

    // If START button is pressed, break loop and quit
    if (kDown & KEY_START){
      break;
    }

    
    // Reset framebuffers
    /*
    fbTopLeft = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
    fbTopRight = gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, NULL, NULL);
    fbBottom = gfxGetFramebuffer(GFX_BOTTOM, 0, NULL, NULL);
    memset(fbTopLeft, 0, 240 * 400 * 3);
    memset(fbTopRight, 0, 240 * 400 * 3);
    memset(fbBottom, 0, 240 * 320 * 3);
    */


    /** Your code starts here **/
    
    
    
    /** End of your code **/

    
    // Flush and swap framebuffers
    gfxFlushBuffers();
    gfxSwapBuffers();

    //Wait for VBlank
		gspWaitForVBlank();
  }

  // Exit
  gfxExit();
  hidExit();
  aptExit();
  srvExit();

  // Return to hbmenu
  return 0;
}