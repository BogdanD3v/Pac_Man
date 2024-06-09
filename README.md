# Pac Man

Clone game of Pac Man.

## Gameplay

- Control Pac-Man using the `W`, `A`, `S`, and `D` keys:
  - `W` - Move Up
  - `A` - Move Left
  - `S` - Move Down
  - `D` - Move Right
- You have one life to complete the game.
- To win, collect all the points on the map.
- Avoid the ghosts! If a ghost catches you, it's game over.

## Installation Steps

1. Clone the repository:
    ```bash
    git clone https://github.com/BogdanD3v/pac-man.git
    ```
    This step downloads a copy of the project from GitHub to your local computer.

2. Navigate to the project directory:
    ```bash
    cd pac-man
    ```
    This step changes the current working directory to the `pac-man` project directory.

3. Configure the project in your IDE (e.g., Visual Studio):

    1. Open the project in Visual Studio.

    2. Change the path in the project properties:
        - Go to `Project` -> `Properties` -> `Configuration Properties` -> `C/C++` -> `General`.
        - In `Additional Include Directories`, add the path to `...\SFML-2.6.1\include`.

    3. Change the path for the Linker:
        - Go to `Project` -> `Properties` -> `Configuration Properties` -> `Linker` -> `General`.
        - In `Additional Library Directories`, add the path to `...\SFML-2.6.1\lib`.

    4. Change the path for the Debugger:
        - Go to `Project` -> `Properties` -> `Configuration Properties` -> `Debugging`.
        - In `Environment`, add `PATH=...\SFML-2.6.1\bin`.

4. Build and run the project:
    - In Visual Studio, select `Build` -> `Build Solution` to compile the project.
    - After compiling, select `Debug` -> `Start Debugging` or `Start Without Debugging` to run the game.

Your Pac-Man game should now run correctly.

## How to Play

1. Start the game by running the main script:
    ```bash
    python pacman.py
    ```
2. Use the `W`, `A`, `S`, and `D` keys to navigate Pac-Man through the maze.
3. Collect all the points while avoiding the ghosts to win the game.

## Contributing

Feel free to contribute to this project by submitting issues or pull requests. Any improvements or bug fixes are welcome!

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

Enjoy playing Pac-Man! If you have any questions or suggestions, please don't hesitate to reach out.
