#include"Prop.h"

Prop::Prop(sf::Texture& texture, const sf::Vector2f& size, float speed)
:m_texture(&texture), m_speed(speed), m_deleteFlag(false), m_rng(std::time(nullptr))
{
    m_body.setSize(size);
    setRect();
}

void Prop::draw(sf::RenderTarget& render)
{
    render.draw(m_body);
}

void Prop::update(float dt)
{
    m_body.move(-m_speed * dt, 0);
    if(m_body.getPosition().x < -512.0f)
        m_deleteFlag = true;
}

void Prop::setRect()
{
    m_body.setTexture(m_texture);
}

bool Prop::hasDeleteFlag() const
{
    return m_deleteFlag;
}
