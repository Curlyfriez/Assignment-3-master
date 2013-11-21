
#include "FireTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


FireTile::FireTile(const char* textureName) : Tile(TileTypeBrick, textureName, true)
{

}

FireTile::~FireTile()
{

}

const char* FireTile::getType()
{
    return TILE_FIRE_TYPE;
}
