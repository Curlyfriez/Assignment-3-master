
#include "BrickTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


BrickTile::BrickTile(const char* textureName) : Tile(TileTypeBrick, textureName, true)
{

}

BrickTile::~BrickTile()
{

}

const char* BrickTile::getType()
{
    return TILE_BRICK_TYPE;
}
