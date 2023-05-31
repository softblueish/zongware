# Zongware
Zongware is a lightweight SDL and C++ game engine that compiles alongside your game. It aims to provide a low-level and user-friendly alternative to complex game engine UIs, without requiring in-depth knowledge of computer graphics.

## Features
- Inspired by Arduino, Zongware utilizes the start() and loop() loop blocks by default to execute the game code.
- All source code is expected to be added under the game/ folder, with the main two blocks located in game/src/game.cpp.
- Window settings, vsync, and other configurations can be adjusted in game/headers/properties.hpp.

## Compiling
To compile the Zongware game engine and your game, follow these steps:
1. Navigate to the ``build`` directory``
2. Execute the following command:
```
make
```

This will compile the game engine and your game together into the same binary.

## Getting Started
To get started with Zongware, follow these steps:

1. Clone the Zongware repository to your local machine.
2. Open the ``game`` directory.
3. Add your game source code and assets to the appropriate folders.
4. Customize the window settings in ``game/headers/properties.hpp``.
5. Compile the game engine and your game using the make command.

## Resources
There are currently no resources as Zongware is still in development.

## Contribution
Contributions to Zongware are welcome! If you encounter any issues or have suggestions for improvement, feel free to open an issue or submit a pull request.

## License
Zongware is licensed under the **MIT License**. See the ``LICENSE`` file for more information.
