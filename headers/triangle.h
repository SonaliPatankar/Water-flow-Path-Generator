#pragma once
#include "Point3D.h"

namespace Geometry
{
    class Triangle
    {
    public:
        Triangle();
        Triangle(const int inV1, const int inV2, const int inV3);
        ~Triangle();

        int v1() const;
        int v2() const;
        int v3() const;

        void setV1(int inV1);
        void setV2(int inV2);
        void setV3(int inV3);

    private:
        int mV1;
        int mV2;
        int mV3;
    };
}
