#include "stdafx.h"
#include "terrainData.h"

TemporaryStorage::TerrainData::TerrainData()
{
    //mVertexBuffer.create();
}
TemporaryStorage::TerrainData::~TerrainData()
{
    //mVertexBuffer.destroy();
}


std::vector<double> TemporaryStorage::TerrainData::triangulationToVertices(const Geometry::Triangulation& triangulationObj)
{
    std::vector<Geometry::Point3D> points = triangulationObj.uniquePoints();
    std::vector<Geometry::Triangle> triangles = triangulationObj.triangles();

    std::vector<double> vertices;

    // iterating each triangle from traingles vector to write points
    for (const auto& triangle : triangles)
    {
        vertices.push_back(points[triangle.v1()].x());
        vertices.push_back(points[triangle.v1()].y());
        vertices.push_back(points[triangle.v1()].z());

        vertices.push_back(points[triangle.v2()].x());
        vertices.push_back(points[triangle.v2()].y());
        vertices.push_back(points[triangle.v2()].z());

        vertices.push_back(points[triangle.v3()].x());
        vertices.push_back(points[triangle.v3()].y());
        vertices.push_back(points[triangle.v3()].z());
    }
    return vertices;
}