#pragma once
#include "Triangulation.h"
#include <queue>
#include <vector>
#include <limits>

namespace PathGenerating
{
    class PathGenerator
    {
    public:
        PathGenerator();
        PathGenerator(const Geometry::Triangulation& inTriangulation);
        ~PathGenerator();
        
        std::vector<Geometry::Point3D> createWaterPath();

    private:      
        void buildAdjacencyList();
        Geometry::Point3D findHighestPoint() const;
        std::vector<Geometry::Point3D> findNeighbors(const Geometry::Point3D& point);
        Geometry::Point3D findPathFromPoint(const Geometry::Point3D& currentPoint); 

        Geometry::Triangulation mTriangulation;
        std::vector<Geometry::Point3D> mWaterPath;
        std::vector<std::vector<int>> mAdjacencyList;
    };
}


      
