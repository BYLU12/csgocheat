#pragma once

class Vec2D {

public:
    float x, y;
    Vec2D() {
        x = 0;
        y = 0;
    }

    Vec2D(float x1, float y1) {
        x = x1;
        y = y1;
    }

    Vec2D(const Vec2D& vec);
    Vec2D operator+(const Vec2D& vec);
    Vec2D& operator+=(const Vec2D& vec);
    Vec2D operator-(const Vec2D& vec);
    Vec2D& operator-=(const Vec2D& vec);
    Vec2D operator*(float value);
    Vec2D& operator*=(float value);
    Vec2D operator/(float value);
    Vec2D& operator/=(float value);
    Vec2D& operator=(const Vec2D& vec);
    float DotProduct(const Vec2D& vec);
    Vec2D CrossProduct(const Vec2D& vec);
    float Magnitude();
    Vec2D Normalization();
    float Square();
    float Distance(const Vec2D& vec);
};