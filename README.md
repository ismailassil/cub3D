# Cub3D

Cub3D is a graphical project in the 42 curriculum, inspired by the classic first-person shooter, Wolfenstein 3D. The goal of this project is to create a simple 3D game using ray-casting techniques. It's an introduction to the world of computer graphics and game development, allowing students to explore the concepts of ray-casting, textures, and basic game mechanics.
Features

- Ray-casting: Implemented a ray-casting engine to simulate a 3D perspective from a 2D map.
- Textures: Applied textures to walls to enhance the visual experience.
- Basic Movement: Implemented basic movement and collision detection.
- Mini-map: Included a mini-map to give a bird's eye view of the map.
- Configurable: Game settings and map layout are easily configurable via a .cub file.

# Controls

    W/A/S/D: Move forward/left/backward/right
    Left Arrow/Right Arrow: Rotate the camera view
    ESC: Exit the game

# Configuration

The game uses `.cub` files for map configuration. A basic `.cub` file includes:

- Map layout: Represents walls and open spaces
- Textures: Paths to wall textures
- Player starting position: Initial position and orientation of the player
- Floor and Ceiling colors: Configurable RGB values

```text
NO ./textures/wall_north.xpm
SO ./textures/wall_south.xpm
WE ./textures/wall_west.xpm
EA ./textures/wall_east.xpm

F 220,100,0
C 225,30,0

1111111111
1000000001
1011111001
100P000001
1111111111
```


### Useful Resources

<div style="display: flex; justify-content: center; align-items: center; height: 100vh;">
  <a target="_blank" href="https://github-readme-medium-recent-article.vercel.app/medium/@ismailassil/0">
    <img src="https://github-readme-medium-recent-article.vercel.app/medium/@ismailassil/0" alt="Ray-Casting Article by Ismail ASSIL" style="display: block;">
  </a>
</div>
