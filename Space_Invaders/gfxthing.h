/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
// pthing.hpp - Base PEG GUI object class definition.
//
// Author: Kenneth G. Maxwell
//
// Copyright (c) 1997-2000 Swell Software 
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

#ifndef _GFXTHING_
#define _GFXTHING_

#include <Adafruit_GFX.h>

class GfxThing
{
    friend class Adafruit_GFX;
 
    public:

        GfxThing(int16_t w, int16_t h);  //Width and Height
        virtual ~GfxThing();
        virtual void Draw(void);
        virtual void Add(GfxThing *Who);
        virtual GfxThing *Remove(GfxThing *Who);
        virtual void DrawChildren(void);

        GfxThing *Parent (void) const {return mpParent;}
        GfxThing *First (void) const {return mpFirst;}
        GfxThing *Next (void) const {return mpNext;}
        GfxThing *Previous(void) const {return mpPrev;}

        static Adafruit_GFX *GFX() {return mpGfx;}

        // ------------------------------------------------------
        // Wrappers for calling Adafruit_GFX functions:
        // ------------------------------------------------------

        inline void drawLine(int16_t wXStart, int16_t wYStart,
            int16_t wXEnd, int16_t wYEnd, const uint16_t &Color)
        {
		//drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color)
                GFX()->drawLine(wXStart, wYStart, wXEnd, wYEnd, Color);
        }

        inline void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
        {
		//drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
                GFX()->drawRect(x, y, w, h, color);
        }

        inline void drawBitmap(int16_t x, int16_t y, uint8_t *bitmap,int16_t w, int16_t h, uint16_t color)
        {
		// drawBitmap(int16_t x, int16_t y, uint8_t *bitmap,int16_t w, int16_t h, uint16_t color)
                GFX()->drawBitmap(x, y, bitmap, w, h, color);
        }

        inline void print(const String & )
        {
			// calls to class print::size_t print(const String &);
			// ultimately calls  Adafruit_GFX::write(uint8_t c) 
            //GFX()->print(String);
        }
		
       static void SetScreenPtr(Adafruit_GFX *ps) {mpGfx = ps;}

    protected:

        GfxThing *mpParent;
        GfxThing *mpFirst;
        GfxThing *mpNext;
        GfxThing *mpPrev;

        static Adafruit_GFX *mpGfx;

};

#endif

// End of file


