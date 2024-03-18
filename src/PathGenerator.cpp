#include "stdafx.h"
#include "PathGenerator.h"

#include<iostream>

PathGenerating::PathGenerator::PathGenerator()
{

}

PathGenerating::PathGenerator::PathGenerator(const Geometry::Triangulation& inTriangulation)
    : mTriangulation(inTriangulation)
{
    buildAdjacencyList();
}

PathGenerating::PathGenerator::~PathGenerator()
{

}

// creates adjacency list based on triangulation
void PathGenerating::PathGenerator::buildAdjacencyList()
{
    // initialize adjacency list with empty vectors for each unique point
    mAdjacencyList.resize(mTriangulation.uniquePoints().size());

    // iterate through each triangle to create adjacency list
    for (const auto& triangle : mTriangulation.triangles())
    {
        int index1 = triangle.v1();
        int index2 = triangle.v2();
        int index3 = triangle.v3();

        // add edges between the vertices of triangle
        mAdjacencyList[index1].push_back(index2);
        mAdjacencyList[index1].push_back(index3);
        mAdjacencyList[index2].push_back(index1);
        mAdjacencyList[index2].push_back(index3);
        mAdjacencyList[index3].push_back(index1);
        mAdjacencyList[index3].push_back(index2);
    }
}

// finds the highest point in triangulation
Geometry::Point3D PathGenerating::PathGenerator::findHighestPoint() const
{
    // start with first point as highest point
    Geometry::Point3D highestPoint = mTriangulation.uniquePoints().front();

    // iterate through all unique points to find the highest point
    for (const auto& point : mTriangulation.uniquePoints())
    {
        if (point.y() > highestPoint.y())
        {
            highestPoint = point;
        }
    }
    return highestPoint;
}

std::vector<Geometry::Point3D> PathGenerating::PathGenerator::findNeighbors(const Geometry::Point3D& point)
{
    std::vector<Geometry::Point3D> neighbors;

    // Find the index of the given point in the list of unique points
    int index = -1;
    for (size_t i = 0; i < mTriangulation.uniquePoints().size(); ++i) 
    {
        if (mTriangulation.uniquePoints()[i] == point)
        {
            index = static_cast<int>(i);
            break;
        }
    }

    // If the point was found, retrieve its neighbors from the adjacency list
    if (index != -1) 
    {
        for (int neighborIndex : mAdjacencyList[index]) 
        {
            if (neighborIndex >= 0 && neighborIndex < mTriangulation.uniquePoints().size()) 
            {
                neighbors.push_back(mTriangulation.uniquePoints()[neighborIndex]);
            }
        }
    }
    return neighbors;
}

Geometry::Point3D PathGenerating::PathGenerator::findPathFromPoint(const Geometry::Point3D& currentPoint)
{
    std::vector<Geometry::Point3D> neighbors = findNeighbors(currentPoint);
    Geometry::Point3D nextPoint = currentPoint;
    double lowestHeight = currentPoint.y();

    for (const auto& neighbor : neighbors) 
    {
        if (neighbor.y() < lowestHeight) 
        {
            lowestHeight = neighbor.y();
            nextPoint = neighbor;
        }
    }
    return nextPoint;
}

std::vector<Geometry::Point3D> PathGenerating::PathGenerator::createWaterPath()
{
    std::vector<Geometry::Point3D> waterFlowPath;
    Geometry::Point3D currentPoint = findHighestPoint();
    waterFlowPath.push_back(currentPoint);

    while (true) 
    {
        Geometry::Point3D nextPoint = findPathFromPoint(currentPoint);
        if (nextPoint.y() >= currentPoint.y()) {
            break; 
        }
        waterFlowPath.push_back(nextPoint);
        currentPoint = nextPoint;
    }

    return waterFlowPath;
}
