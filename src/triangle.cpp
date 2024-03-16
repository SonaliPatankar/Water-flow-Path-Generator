#include "stdafx.h"
#include "Triangle.h"

Geometry::Triangle::Triangle() : mV1(0), mV2(0), mV3(0) {}
Geometry::Triangle::Triangle(const int inV1, const int inV2, const int inV3) : mV1(inV1), mV2(inV2), mV3(inV3) {}
Geometry::Triangle::~Triangle() {}

int Geometry::Triangle::v1() const
{
    return mV1;
}

int Geometry::Triangle::v2() const
{
    return mV2;
}

int Geometry::Triangle::v3() const
{
    return mV3;
}

void Geometry::Triangle::setV1(int inV1)
{
    mV1 = inV1;
}

void Geometry::Triangle::setV2(int inV2)
{
    mV2 = inV2;
}

void Geometry::Triangle::setV3(int inV3)
{
    mV3 = inV3;
}
