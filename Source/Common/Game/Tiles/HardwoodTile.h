
#ifndef BRICK_HARDWOOD_H
#define BRICK_HARDWOOD_H
#pragma once
#include "Tile.h"


class HardwoodTile : public Tile
{
public:
	HardwoodTile(const char* textureName = RES_TILE_HARDWOOD);
	virtual ~HardwoodTile();
  
    //Return the type of the tile
    const char* getType();
};

#endif
