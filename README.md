# so_long 🎮🗺️

Welcome to the `so_long` project! 🚀 This is a 2D maze game project from 42 School where you navigate through a maze, collect items, and reach the exit. This project uses the `mlx42` library for handling graphics and user input.

## Project Overview 🌟

`so_long` is a simple 2D game where the goal is to navigate through a maze, collect items, and reach the exit. The game is rendered using the `mlx42` library, and the maze is designed using a map file with a specific format.

### Features 🔧

- **Maze Navigation:** Move through the maze using keyboard controls.
- **Item Collection:** Collect items scattered throughout the maze.
- **Exit:** Reach the exit to complete the level.
- **Graphics:** Rendered using `mlx42` for a graphical interface.

## Installation 💻

1. **Clone the Repository:**

    ```bash
    git clone https://github.com/yourusername/so_long.git
    cd so_long
    ```

2. **Install `mlx42`:**

   - Follow the [mlx42 installation guide](https://github.com/42School/minilibx42) to set up `mlx42`. You may need to install some dependencies as well.

3. **Compile the Code:**

    ```bash
    make all
    ```

## Usage 🚀

1. **Run the Game:**

    ```bash
    ./so_long map.ber
    ```

   Replace `map.ber` with the path to your map file.

2. **Controls:**

    - **W** - Move Up
    - **A** - Move Left
    - **S** - Move Down
    - **D** - Move Right
    - **ESC** - Exit the game

## Map File Format 🗺️

The game uses a map file with the `.ber` extension. The map file format must follow these rules:

- **Characters:**
  - `1` - Wall
  - `0` - Empty space
  - `P` - Player starting position
  - `E` - Exit
  - `C` - Collectible item

- **Map Constraints:**
  - The map must be surrounded by walls (`1`).
  - The map must contain exactly one player (`P`), one exit (`E`), and at least one collectible (`C`).

## Example Map

Here is an example of a valid map file:
111111
1P0C01
1C0C01
1E00001
111111

## Screenshoots

## Happy Coding! 🚀🎉


 
