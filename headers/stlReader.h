#pragma once
#include "Triangulation.h"
#include <string>

namespace IOOperation
{
    class StlReader
    {
    public:
        StlReader();
        ~StlReader();

        void read(const std::string& filePath, Geometry::Triangulation& triangulation);
    };
}