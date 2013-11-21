
#ifndef FIRE_TILE_H
#define FIRE_TILE_H

#include "Tile.h"

class FireTile : public Tile
{
public:
	FireTile(const char* textureName = RES_TILE_FIRE);
	virtual ~FireTile();
  
    //Return the type of the tile
    const char* getType();
};

#endif
