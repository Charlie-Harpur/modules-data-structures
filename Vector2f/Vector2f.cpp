#include "Vector2f.h"

Vector2f::Vector2f(): x(0), y(0) {}

Vector2f::Vector2f(const int &rX, const int &rY)
{
    x = rX;
    y = rY;
}

Vector2f::Vector2f(const Vector2f &rV)
{
    x = rV.x;
    y = rV.y;
}

Vector2f & Vector2f::operator=(const Vector2f &rV)
{
    if (this == &rV)
        return *this;

    x = rV.x;
    y = rV.y;
    return *this;
}

void Vector2f::normalize()
{
    if (x == 0 && y == 0)
        return;

    if (x == 0)
    {
        y = 1;
        return;
    }
    if (y == 0)
    {
        x = 1;
        return;
    }

    float magnitude = getMagnitude();
    x /= magnitude;
    y /= magnitude;
}

float Vector2f::getMagnitude() const
{
    if (x == 0)
        return y;
    if (y == 0)
        return x;

    float magnitude;

    magnitude = sqrt(x*x + y*y);
    return magnitude;
}

Vector2f Vector2f::getNormalized() const
{
    Vector2f normalizedVector(*this);
    normalizedVector.normalize();
    return normalizedVector;
}
