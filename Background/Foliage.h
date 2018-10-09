#ifndef FOLIAGE_H_INCLUDED
#define FOLIAGE_H_INCLUDED

#include"Prop.h"

class Foliage : public Prop
{
public:
    Foliage(sf::Texture& texture);
    void setRect() override;
private:

};

#endif // FOLIAGE_H_INCLUDED
