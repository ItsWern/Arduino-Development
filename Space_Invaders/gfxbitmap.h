/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
// gfxthing.h
//
// Author: Werner R. Schipper
//
// Copyright (c) 2016 Pretty Big Software 
//              All Rights Reserved.
//
// Unauthorized redistribution of this source code, in whole or part,
// without the express written permission of Swell Software
// is strictly prohibited.
//
// Notes:
// In the application, to create a display specific instance:     
//    Adafruit_GFX *gfxDisplay;
//    gfxDisplay = new <DISPLAY_CLASS>('params');
//    GfxThing::SetScreenPtr(gfxDisplay);
// This class identifies the base functionality inherited by all GUI objects.
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/

#ifndef _GFXBITMAP_
#define _GFXBITMAP_


class GfxBitmap : public GfxThing
{
    public:
	   
	   GfxBitmap(int16_t w, int16_t h, uint8_t *bitmap, uint16_t color);  //Width and Height and bitmap
	   virtual ~GfxBitmap() {}
	   void doAction(void);
			
	protected:
	
	uint8_t *mpBitmap;
	uint16_t mpColor;
	int16_t xPos, yPos;
};
#endif