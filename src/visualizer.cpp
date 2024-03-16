#include "stdafx.h"
#include "visualizer.h"
#include "openGLWindow.h"
#include "PathGenerator.h"
#include "StlReader.h"

Visualizer::Visualizer(QWindow* parent) : QMainWindow(nullptr)
{
    setupUi();
}

Visualizer::~Visualizer()
{

}

void Visualizer::setupUi() 
{
    resize(600, 600);
    mCentralGrid = new QGridLayout(this);

    mReadFileButton = new QPushButton("Read STL file", this);
    mCentralGrid->addWidget(mReadFileButton, 2, 2);
    
    mRenderer = new OpenGLWindow(QColor(1,1,1), this);
    mCentralGrid->addWidget(mRenderer, 1, 0, 1, 0);

    mWidget = new QWidget(this);
    mWidget->setLayout(mCentralGrid);

    // signal slot connection
    connect(mReadFileButton, &QPushButton::clicked, this, &Visualizer::onLoadReadFileButtonClicked);

    setCentralWidget(mWidget);
    setWindowTitle(QCoreApplication::translate("Visualiser", "Water flow Path Generator", nullptr));
}


 // reads stl file and calls setTriangulation method
void Visualizer::onLoadReadFileButtonClicked()
{
    Geometry::Triangulation triangulationObj;
    IOOperation::StlReader reader;
    reader.read("resources/terrain.stl", triangulationObj);

    // Find the water flow path
    PathGenerating::PathGenerator pathFinder(triangulationObj);
    std::vector<Geometry::Point3D> waterPath = pathFinder.createWaterPath();

    // Pass the water flow path to the OpenGLWindow for rendering
    mRenderer->setData(triangulationObj.uniquePoints(), waterPath);
}