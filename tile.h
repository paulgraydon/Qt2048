#ifndef TILE_H
#define TILE_H

#define VALUE_MULTIPLIER 2 // Define macro for tile value multiplication

class Tile
{
public:
    Tile(int initValue) {value = initValue;}
    Tile(const Tile& otherTile) {value = otherTile.value;}

    int getValue() {return value;}
    void setValue(int newValue) {value = newValue;}
    void upgradeTile() {value *= VALUE_MULTIPLIER;}
    void setUpgradedThisMove(bool newBool) {this->upgradedThisMove = newBool;}
    bool getUpgradedThisMove() const {return this->upgradedThisMove;}

private:
    int value;
    bool upgradedThisMove; // This avoids multiple upgrades on a single move
};

#endif // TILE_H
