#pragma once
#include "Point3D.h"
#include "Triangle.h"

namespace Geometry
{
    class Triangulation
    {
    public:
        Triangulation();
        ~Triangulation();

        std::vector<Geometry::Point3D> uniquePoints() const;
        std::vector<Geometry::Triangle> triangles() const;
        void addUniquePoint(const Geometry::Point3D inPoint);
        void addTriangle(const Geometry::Triangle inTriangle);

    private:
        std::vector<Geometry::Point3D> mUniquePoints;
        std::vector<Geometry::Triangle> mTriangles;
    };
}