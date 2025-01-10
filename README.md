# miniRT - Ray Tracing Engine

<p align="center">
<img width="1428" alt="minirt1" src="https://github.com/user-attachments/assets/d98fe339-23e5-4494-b580-bfb54c519167" />
</p>

## 📝 About

miniRT is a minimal ray tracing engine developed as part of the 42 School curriculum. This project serves as an introduction to the fascinating world of ray tracing and computer graphics, implementing fundamental concepts of computer-generated imagery.

## 🎯 Features

- Basic ray tracing implementation
- Support for multiple geometric primitives:
  - Spheres
  - Planes
  - Cylinders
  - Cones (bonus)
- Lighting effects:
  - Ambient lighting
  - Point lights
  - Shadows
  - Specular highlights
- Camera positioning and field of view control
- Scene parsing from configuration files
- Basic material properties

## 🛠️ Technologies Used

- C programming language
- MinilibX graphics library
- Mathematical concepts:
  - Vector operations
  - Matrix transformations
  - Ray-object intersections
  - Light calculations

## 🚀 Getting Started

### Prerequisites

- GCC compiler
- Make
- MinilibX library
- macOS or Linux operating system

### Installation

```bash
git clone git@github.com:IremOztimur/miniRT.git
make # For mandatory part
make bonus # For bonus features
```

### Usage

Run the mandatoryprogram with a scene file:
```bash
./miniRT scenes/mandatory/temple.rt
```

Run the bonus program with a scene file:
```bash
./miniRT scenes/bonus/snowman.rt
```

## 🎮 Controls

- `ESC` - Exit the program
- `W/A/S/D` - Move camera position
- `C/V` - Rotate camera

## 📁 Scene File Format

Scene files use the `.rt` extension and follow this format:

## Tutorials for this project

[Building a miniRT — 42 Project Part 1](https://medium.com/@iremoztimur/building-a-minirt-42-project-part-1-ae7a00aebdb9)\
[MiniRT Shading Algorithms — Part 2](https://medium.com/@iremoztimur/minirt-shading-algorithms-part-2-6c46e6d81fbd)
