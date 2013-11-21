
#ifndef BRICK_TILE_H
#define BRICK_TILE_H
#pragma once
#include "Tile.h"


class BrickTile : public Tile
{
public:
	BrickTile(const char* textureName = RES_TILE_BRICK);
	virtual ~BrickTile();
  
    //Return the type of the tile
    const char* getType();
};

#endif
