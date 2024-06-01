# RayTracer 🖼️ 🖌️

This project is a simple raytracer that can render spheres with different materials and lighting. It is written in C++ and uses the SFML library for rendering.

## ✨ Features

- Primitives:
• Sphere
• Plane
• Cylinder
• Cone

- Transformations:
• Translation
• Rotation

- Light:
• Directional light
• Ambient light
• Drop shadows
• Multiple directional lights
• Colored lights


- Material:
• Flat color
• Refraction
• Reflection

- Scene configuration:
• Add primitives to scene
• Set up lighting
• Set up camera
• Anti-aliasing through supersampling

- Interface:
• Output to a PPM file
• Display the image during and after rendering
• Exit during and after generation

- Optimizations:
• Multithreading
• Space partitioning

## 🚀 Getting Started

### Compiling

To compile the project, run the following commands:

```bash
make
```

That will generate a binary called `raytracer`.

### Running

To run the project, use the following command:

```bash
./raytracer <config_file>
```

The `config_file` is a libconfig-format file that contains the scene configuration. You can find examples in the `configs` directory.

The program will output the rendered image to a file called `output.ppm`.
Image is also displayed during the rendering process.

This project will use all the CPU cores available to render the image faster.

## 📝 License

This project has no license. (yet and probably never)

## Contributors

- Adam Brutsaert 🐐
- Adam Cavillon <img src="https://cdn.discordapp.com/emojis/667325172646150147.gif?size=96&quality=lossless" width="16">
- Alexandre Barberis 🍍
- Yanis Zeghiche 🏎️
