#ifndef ROUNDEDRECTANGLESHAPE_HPP
#define ROUNDEDRECTANGLESHAPE_HPP
#include <SFML/Graphics/Shape.hpp>

namespace sf
{
    class RoundedRectangleShape : public sf::Shape
    {
    public:
        explicit RoundedRectangleShape(const Vector2f& size = Vector2f(0, 0), float radius = 0, unsigned int cornerPointCount = 0);

        void setSize(const Vector2f& size);

        const Vector2f& getSize() const;

        void setCornersRadius(float radius);

        float getCornersRadius() const;

        void setCornerPointCount(unsigned int count);

        virtual std::size_t getPointCount() const;

        virtual sf::Vector2f getPoint(std::size_t index) const;

    private:
        Vector2f mySize;
        float myRadius;
        unsigned int myCornerPointCount;
    };
}

namespace sf
{
    RoundedRectangleShape::RoundedRectangleShape(const Vector2f& size, float radius, unsigned int cornerPointCount)
    {
        mySize = size;
        myRadius = radius;
        myCornerPointCount = cornerPointCount;
        update();
    }

    void RoundedRectangleShape::setSize(const Vector2f& size)
    {
        mySize = size;
        update();
    }

    const Vector2f& RoundedRectangleShape::getSize() const
    {
        return mySize;
    }

    void RoundedRectangleShape::setCornersRadius(float radius)
    {
        myRadius = radius;
        update();
    }

    float RoundedRectangleShape::getCornersRadius() const
    {
        return myRadius;
    }

    void RoundedRectangleShape::setCornerPointCount(unsigned int count)
    {
        myCornerPointCount = count;
        update();
    }

    std::size_t RoundedRectangleShape::getPointCount() const
    {
        return myCornerPointCount * 4;
    }

    sf::Vector2f RoundedRectangleShape::getPoint(std::size_t index) const
    {
        if (index >= myCornerPointCount * 4)
            return sf::Vector2f(0, 0);

        float deltaAngle = 90.0f / (myCornerPointCount - 1);
        sf::Vector2f center;
        unsigned int centerIndex = index / myCornerPointCount;
        static const float pi = 3.141592654f;

        switch (centerIndex)
        {
        case 0: center.x = mySize.x - myRadius; center.y = myRadius; break;
        case 1: center.x = myRadius; center.y = myRadius; break;
        case 2: center.x = myRadius; center.y = mySize.y - myRadius; break;
        case 3: center.x = mySize.x - myRadius; center.y = mySize.y - myRadius; break;
        }

        return sf::Vector2f(myRadius * cos(deltaAngle * (index - centerIndex) * pi / 180) + center.x,
            -myRadius * sin(deltaAngle * (index - centerIndex) * pi / 180) + center.y);
    }
}
#endif //ROUNDEDRECTANGLESHAPE_HPP