#include <math.h>

class Vector2f
{
    public:
        float x, y;

        Vector2f();
        Vector2f(const int &rX, const int &rY);
        Vector2f(const Vector2f &rV);
        Vector2f & operator=(const Vector2f &rV);

        //Vector2f & operator+(const Vector2f &rV);
        //Vector2f & operator-(const Vector2f &rV);
        //Vector2f & operator*(const Vector2f &rV);
        //Vector2f & operator/(const Vector2f &rV);

        void normalize();

        float getMagnitude() const;
        Vector2f getNormalized() const;
};
