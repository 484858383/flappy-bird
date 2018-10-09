#ifndef BUILDING_H_INCLUDED
#define BUILDING_H_INCLUDED

#include"Prop.h"

class Building : public Prop
{
public:
    Building(sf::Texture& texture);
    void setRect() override;
private:

};

#endif // BUILDING_H_INCLUDED
