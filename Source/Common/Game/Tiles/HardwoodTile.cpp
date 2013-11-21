#include "HardwoodTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


HardwoodTile::HardwoodTile(const char* textureName) : Tile(TileTypeBrick, textureName, true)
{

}

HardwoodTile::~HardwoodTile()
{

}

const char* HardwoodTile::getType()
{
    return TILE_HARDWOOD_TYPE;
}
