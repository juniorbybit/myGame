# myGame – ASCII Racing Game

A single-player racing game for the Windows console, written in C++. The track, the car and every menu are drawn with text characters, and the game has its own soundtrack and engine sound.

## Features

- Menu with play, settings and exit options
- Choice of car colour (yellow, blue, red, purple, orange, light navy) and a nickname, with a preview of your car before the race
- Race start with a 3-2-1-GO countdown sound and ASCII countdown numbers
- A long ASCII track with straights, curves and a finish line
- Steering and speed control in real time (keyboard polling)
- Background music with three soundtracks to choose from in Settings, plus an engine sound during the race
- Every finished race is saved to `records.txt` with the date, nickname and finishing time

## Controls

| Key | Action |
| --- | --- |
| A / D | Steer left / right |
| W / S | Speed up / slow down |
| Esc | Quit the race |
| 1, 2, 3, y, n ... | Choose options in menus |

## How it works

- The track is stored as a `vector<string>`. Each frame the game prints a window of this vector, moving it down one line at a time, which gives the feeling of driving forward.
- The car is drawn at a fixed height and moved sideways using console cursor positioning (`SetConsoleCursorPosition`). Its colour is set with `SetConsoleTextAttribute`.
- Keys are read with `GetAsyncKeyState`, so steering and speed react while a key is held down.
- Audio uses SFML (`sf::Music` and `sf::SoundBuffer`).
- Results are appended to a text file with `fstream`, one entry per race.

## Requirements

- Windows (the code uses `Windows.h`, `conio.h` and the Windows console API)
- Visual Studio with the C++ desktop workload (project uses C++20)
- SFML, audio module only (`sfml-system`, `sfml-audio`); the headers and libraries are in `include/` and `lib/` in this repository
- Five sound files in `.ogg` format (see below)

## Build and run

1. Open `myGame.slnx` in Visual Studio.
2. Make sure SFML's `include` and `lib` folders are set up for the project.
3. Create an `assets` folder next to `myGame.cpp` (`myGame/assets/`) and add the sound files listed below. The code loads them with relative paths such as `assets\f1_engine_sound.ogg`.
4. Build and run (F5). Race results are saved to `records.txt` in the working directory.

### Sound files

The soundtracks are not included in this repository because they are copyrighted. The game expects these file names in the `assets` folder; you can use any `.ogg` audio you like under the same names:

- `F1soundtrackext.ogg`, `F1Mexican.ogg`, `F1Theme.ogg` (the three menu soundtracks)
- `race-start.ogg` (countdown sound)
- `f1_engine_sound.ogg` (engine sound during the race)

If a file is missing the game still runs and prints an error message instead of playing that sound.

## Known limitations

- The game is one procedural source file; all functions and the track data live in `myGame.cpp`.
- There is a single track and no opponents. A race is a timed lap.
- Windows only, because of the console API.

## Ideas for next steps

- Split the code into separate files and classes (`Car`, `Track`, `Menu`, `RecordsManager`)
- Add obstacles or opponent cars, a leaderboard screen and more tracks
- Read the best times back from `records.txt` and show them in the menu
