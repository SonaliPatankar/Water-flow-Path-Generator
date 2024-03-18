#pragma once
#include "Triangulation.h"
#include <QOpenGLBuffer>

namespace TemporaryStorage
{
    class TerrainData
    {
    public:
        TerrainData();
        ~TerrainData();

        std::vector<double> triangulationToVertices(const Geometry::Triangulation& triangulation);     
    };
}