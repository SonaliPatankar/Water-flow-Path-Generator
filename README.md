# Water-flow-Path-Generator

This project aims to generate a path representing the maximum water flow on a terrain defined by an STL file.

## File Structure
-**pathGenerator.cpp**: This file contains the implementation of the waterflow path functionality. It likely includes algorithms for simulating water flow and determining the path of maximum flow.

-**stlReader.cpp**: This file includes the implementation for reading an STL file. It probably parses the STL file format to extract the geometry of the terrain.

-**OpenGLWindow.cpp**: Implementation of an OpenGL rendering window. This is likely used for visualizing the terrain and the water flow path.

-**Point3D.cpp**: Implementation of a 3D point class, which is used to represent vertices in the terrain geometry.

-**triangle.cpp**: Implementation of a triangle class, which represents triangles formed by vertices in the terrain geometry.

-**triangulation.cpp**: Implementation of a triangulation class. Triangulation may be necessary for certain algorithms used in water flow simulation or path generation.

-**visualizer.cpp**: Implementation of the GUI (Graphical User Interface) and user interaction. It probably provides controls for loading STL files, visualizing the terrain, adjusting simulation parameters, and displaying the generated water flow path.

## Usage
- Compile the source code files.
- Run the executable, which should launch the application.
- Load an STL file representing the terrain.
- Run the water flow simulation to generate the maximum flow path.
- Visualize the terrain and the water flow path.
- Interact with the GUI to adjust parameters or perform other actions as needed.

## Output

![water_path](https://github.com/SonaliPatankar/Water-flow-Path-Generator/assets/158050645/b06054c9-9149-4f40-b23b-e567fc5c907a)
