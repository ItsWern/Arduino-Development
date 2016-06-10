/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
// GfxBitmap
//
// Author: Werner R. Schipper
//
// Copyright (c) 2016  
//              All Rights Reserved.
//
// Unauthorized redistribution of this source code, in whole or part,
// without the express written permission of Swell Software
// is strictly prohibited.
//
// Notes:
//
// This class identifies the base functionality inherited by all GUI objects.
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
#include <Adafruit_GFX.h>
#include "gfxthing.h"
#include "gfxbitmap.h"


GfxBitmap::GfxBitmap(int16_t w, int16_t h, uint8_t *bitmap, uint16_t color) :
			GfxThing(w, h)
{
	mpBitmap = bitmap;
	mpColor = color;
}


/*----------------------- PUBLIC METHOD ------------------------------------*/
// doAction - Do what ever this thing needs to do
/*--------------------------------------------------------------------------*/
void GfxBitmap::doAction()
{
  //drawBitmap(int16_t x, int16_t y, uint8_t *bitmap,int16_t w, int16_t h, uint16_t color)
	drawBitmap(xPos, yPos, mpBitmap, 8, 8, mpColor);
}