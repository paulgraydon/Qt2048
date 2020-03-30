#ifndef TILE_H
#define TILE_H

#define VALUE_MULTIPLIER 2 // Define macro for tile value multiplication

class Tile
{
public:
    Tile(int initValue);
    Tile(const Tile& otherTile);

    int getValue() {return value;}
    void setValue(int newValue) {value = newValue;}
    void upgradeTile() {value *= VALUE_MULTIPLIER;}

private:
    int value;

};

#endif // TILE_H
