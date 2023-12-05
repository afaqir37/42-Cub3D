# 42-Cub3D
### <ins>My First RayCaster with miniLibX</ins>
- Summary: This project is inspired by the world-famous Wolfenstein 3D game, which
was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to
make a dynamic view inside a maze, in which you’ll have to find your way.
---
### <ins>What is Ray Casting ?</ins>
- Ray casting is a technique used in computer graphics, computer vision, and physics simulations to simlate the behavior of rays of light or other types of rays as they interact with objects in a virtual environment. It involves tracing the path of rays as they travel from an origin point, often a virtual camera or light source, and detrermining how they interact iwth the objects in the scene.
- In the context of computer graphics, ray casting is commonly used for rendring realistic images by simulating the path of light rays as they travel through a scene. It helps determined the color and intensity of light reaching the carmea by considering factors such as reflection, refraction, and shading.
- The basic process of ray casting involves casting a ray from the camera or light source into the scene, determining the first object the ray interesect with, and then calculating the interaction between the ray and the object. This interaction can include determining the color of the object, considering lighting conditions, and calculating shadows and reflections.
- Ray clasing can be contrasted with other rendering techniques such as raseterization, which involves projecting objects onto a 2D plane and determining the color of pixles based on the projeted geometry. Ray tracing, a more advanced technique, builds upon ray casting by simlating the paths of rays more comprehensively, including effects like global illumination and realistic reflections.
##### **Ray-Casting**
- Rays are cast and traced in groups. In a 320x200 display resolution a ray-caster races only 320 rays.
- Fast rendering
- Resulting image is not very realistic
- a viable option for real-time rendering
##### **Ray-Tracing**
- Each ray is traced separately, so each point (usually a pixel) is traced by one single ray.
- In a 320x200 display resolution a ray-tracer needs to trace 64,000 rays.
- Slow rendering
- Resulting image is exteremly realistic.
- Not a viable option for real-time rendering.
### <ins>Ray-Casting Limitations</ins>
- Walls are always perpendicular (90 angle) with the floor.
- Floor is always flat.
- Walls are made of cubes that have the same size (square grid only).
---
- Raycasting feels like cheating, and as a lazy programmer, I love it. You get the immersion of a 3D environment without many of the complexities of "real 3D" to slow you down. For example, raycasts run in constant time, so you can load up a massive world and it will just work, without optimization, as quickly as a tiny world. Levels are defined as simple grids rather than as trees of polygon meshes, so you can dive right in without a 3D modeling background or mathematics PhD.

