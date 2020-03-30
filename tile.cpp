#include "tile.h"

Tile::Tile(int initValue)
{
    value = initValue;
}

Tile::Tile(const Tile& otherTile)
{
    value = otherTile.value;
}
