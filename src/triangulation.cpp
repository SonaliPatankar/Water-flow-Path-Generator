#include "stdafx.h"
#include "Point3D.h"
#include "Triangle.h"
#include "Triangulation.h"

Geometry::Triangulation::Triangulation() {}

Geometry::Triangulation::~Triangulation() {}

// vector for storing unique points
std::vector<Geometry::Point3D> Geometry::Triangulation::uniquePoints() const
{
    return mUniquePoints;
}

// vector for storing triangles
std::vector<Geometry::Triangle> Geometry::Triangulation::triangles() const
{
    return mTriangles;
}

// adds a point to mUniquePoints vector
void Geometry::Triangulation::addUniquePoint(const Geometry::Point3D inPoint)
{
    mUniquePoints.push_back(inPoint);
}

// adds a triangle to mTriangles vector
void Geometry::Triangulation::addTriangle(const Geometry::Triangle inTriangle)
{
    mTriangles.push_back(inTriangle);
}
