//
// Created by liam on 5/18/16.
//

#ifndef INC_3DGAMEENGINE_MATH_H
#define INC_3DGAMEENGINE_MATH_H

#include <math.h>
#include <string>
#include <iostream>

#define ToRadian(x) (float)(((x) * M_PI / 180.0f))
#define ToDegree(x) (float)(((x) * 180.0f / M_PI))

class Vector2
{
public:
    Vector2(float x, float y)
    {
        m_x = x;
        m_y = y;
    }

    Vector2 operator+(const Vector2& a)
    {
        return Vector2(m_x + a.GetX(), m_y + a.GetY());
    }

    Vector2 operator-(const Vector2& a)
    {
        return Vector2(m_x - a.GetX(), m_y - a.GetY());
    }

    Vector2 operator*(float a)
    {
        return Vector2(a * this->GetX(), a * this->GetY());
    }

    Vector2& operator=(const Vector2& a)
    {
        if(this == &a)
            return  *this;

        m_x = a.GetX();
        m_y = a.GetY();

        return *this;
    }

    float LengthSquared()
    {
        return this->GetX() * this->GetX() + this->GetY() * this->GetY();
    }

    float Length()
    {
        return sqrtf(LengthSquared());
    }

    float Dot(Vector2 a)
    {
        return m_x * a.GetX() + m_y * a.GetY();
    }

    Vector2 Normalize()
    {
        return *this * (1 / Length());
    }

    Vector2 Rotate(float angle)
    {
        ToRadian(angle);

        float cosine = cos(angle);
        float sine   = sin(angle);

        return *new Vector2(this->GetX() * cosine - this->m_y * sine,
                             this->GetX() * sine + this->GetY() * cosine);
    }

    std::string& ToString()
    {
        std::cout << "(" << m_x << ", " << m_y << ")" << std::endl;
    }


    float GetX() const { return m_x; }
    float GetY() const { return m_y; }

    void SetX(float x) { m_x = x; }
    void SetY(float y) { m_y = y; }

private:
    float m_x;
    float m_y;
};

class Vector3
{
public:
    Vector3(float x, float y, float z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    Vector3 operator+(const Vector3& a)
    {
        return Vector3(m_x + a.GetX(), m_y + a.GetY(), m_z + a.GetZ());
    }

    Vector3 operator-(const Vector3& a)
    {
        return Vector3(m_x - a.GetX(), m_y - a.GetY(), m_z - a.GetZ());
    }

    Vector3 operator*(float a)
    {
        return Vector3(a * this->GetX(), a * this->GetY(), a * this->GetZ());
    }

    Vector3& operator=(const Vector3& a)
    {
        if(this == &a)
            return  *this;

        m_x = a.GetX();
        m_y = a.GetY();
        m_z = a.GetZ();

        return *this;
    }

    float LengthSquared()
    {
        return this->GetX() * this->GetX() + this->GetY() * this->GetY() + this->GetZ() * this->GetZ();
    }

    float Length()
    {
        return sqrtf(LengthSquared());
    }

    float Dot(Vector3 a)
    {
        return m_x * a.GetX() + m_y * a.GetY() + m_z * a.GetZ();
    }

    Vector3 Cross(Vector3 a)
    {
        float x = m_y * a.GetZ() - m_z * a.GetY();
        float y = m_z * a.GetX() - m_x * a.GetZ();
        float z = m_x * a.GetY() - m_y * a.GetX();

        return Vector3(x, y, z);
    }

    Vector3 Normalize()
    {
        return *this * (1 / Length());
    }

    Vector3 Zero()
    {
        return *new Vector3(0.0f, 0.0f, 0.0f);
    }

    Vector3 Rotate(float alpha, float beta, float gamma);


    std::string& ToString()
    {
        std::cout << "(" << m_x << ", " << m_y << ", " << m_z << ")" << std::endl;
    }


    float GetX() const { return m_x; }
    float GetY() const { return m_y; }
    float GetZ() const { return m_z; }

    void SetX(float x) { m_x = x; }
    void SetY(float y) { m_y = y; }
    void SetZ(float z) { m_z = z; }

private:
    float m_x;
    float m_y;
    float m_z;
};

class Matrix4
{
public:
    Matrix4()
    {

    }

    float m_m[4][4];

    Matrix4 Indentity()
    {
        m_m[0][0] = 1; m_m[0][1] = 0; m_m[0][2] = 0; m_m[0][3] = 0;
        m_m[1][0] = 0; m_m[1][1] = 1; m_m[1][2] = 0; m_m[1][3] = 0;
        m_m[2][0] = 0; m_m[2][1] = 0; m_m[2][2] = 1; m_m[2][3] = 0;
        m_m[3][0] = 0; m_m[3][1] = 0; m_m[3][2] = 0; m_m[3][3] = 1;
    }

    Matrix4 operator*(Matrix4 a)
    {
        Matrix4 b = *new Matrix4();

        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                b.SetIndex(i, j, m_m[i][0] * a.GetIndex(0, j) +
                                 m_m[i][1] * a.GetIndex(1, j) +
                                 m_m[i][2] * a.GetIndex(2, j) +
                                 m_m[i][3] * a.GetIndex(3, j));
            }
        }

        return b;
    }

    float Det();

    float GetIndex(int i, int j) { return m_m[i][j]; }

    void SetIndex(int i, int j, float value) { m_m[i][j] = value; }

    ~Matrix4()
    {

    }
private:
};

#endif //INC_3DGAMEENGINE_MATH_H
