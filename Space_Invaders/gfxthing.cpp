/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
// thing.cpp - Base GUI object class definition.
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
#include "GfxThing.h"


Adafruit_GFX *GfxThing::mpGfx;

/*--------------------------------------------------------------------------*/
GfxThing::GfxThing(int16_t w, int16_t h) :
    mpParent(NULL),
    mpFirst(NULL),
    mpNext(NULL)

{
}

/*--------------------------------------------------------------------------*/
// Destructor- Remove and delete any children.
/*--------------------------------------------------------------------------*/
GfxThing::~GfxThing()
{
    while (mpFirst)
    {
        GfxThing *DelPtr = mpFirst;
        mpFirst = DelPtr->mpNext;
        delete DelPtr;
    }
}


/*----------------------- PUBLIC METHOD ------------------------------------*/
// Add- Add a child to the list
/*--------------------------------------------------------------------------*/
void GfxThing::Add(GfxThing *What)
{

    What->mpParent = this;
    What->mpNext = mpFirst;
	mpFirst->mpPrev = this;
    What->mpPrev = NULL;

}


/*----------------------- PUBLIC METHOD ------------------------------------*/
// Remove- Remove a child from the list
/*--------------------------------------------------------------------------*/
GfxThing *GfxThing::Remove(GfxThing *What)
{
 
    GfxThing *pParent = What->mpParent;

    if (!pParent)
    {
        return NULL;
    }
    if (pParent != this)
    {
        pParent = pParent->Remove(What);
        return pParent;
    }

    GfxThing *Current = mpFirst;
    GfxThing *Last = Current;

    while(Current)
    {
        if (Current == What)
        {
             if (Current == mpFirst)
            {
                mpFirst = Current->mpNext;
                if (mpFirst)
                {
                    mpFirst->mpPrev = NULL;
                }
            }
            else
            {
                Last->mpNext = Current->mpNext;
                if (Last->mpNext)
                {
                    Last->mpNext->mpPrev = Last;
                }
            }
            Current->mpParent = NULL;
            Current->mpNext = NULL;
            Current->mpPrev = NULL;

            return(Current);
        }
        Last = Current;
        Current = Last->mpNext;
    }
    return NULL;
}


/*--------------------------------------------------------------------------*/
// The base draw item simply instructs all children to draw themselves.
/*--------------------------------------------------------------------------*/
void GfxThing::Draw(void)
{
        DrawChildren();
}


/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
void GfxThing::DrawChildren(void)
{
    // draw the first last, so that it comes out on top on top:

    if (!mpFirst)
    {
        return;
    }

    GfxThing *pCurrent = mpFirst;

    while(pCurrent->mpNext)
    {
        pCurrent = pCurrent->mpNext;
    }

    while(pCurrent)
    {
        {
            pCurrent->Draw();
        }
        pCurrent = pCurrent->mpPrev;
    }
}



// End of file


