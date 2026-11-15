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
|-----|--------|
| `A` / `D` | Steer left / right |
| `W` / `S` | Speed up / slow down |
| `Esc` | Quit the race |
| `1`, `2`, `3`, `y`, `n` ... | Choose options in menus |

## How it works

- The track is stored as a `vector<string>`. Each frame the game prints a window of this vector, moving it down one line at a time, which gives the feeling of driving forward.
- The car is drawn at a fixed height and moved sideways using console cursor positioning (`SetConsoleCursorPosition`). Its colour is set with `SetConsoleTextAttribute`.
- Keys are read with `GetAsyncKeyState`, so steering and speed react while a key is held down.
- Audio uses SFML (`sf::Music` and `sf::SoundBuffer`).
- Results are written to a text file with `fstream`.

## Requirements

- Windows (the code uses `Windows.h`, `conio.h` and the Windows console API)
- Visual Studio with the C++ desktop workload (project uses C++20)
- [SFML](https://www.sfml-dev.org/), audio module only (`sfml-system`, `sfml-audio`)
- The sound files: `F1soundtrackext.ogg`, `F1Mexican.ogg`, `F1Theme.ogg`, `race-start.ogg`, `f1_engine_sound.ogg`

## Build and run

1. Open `myGame.slnx` in Visual Studio.
2. Make sure SFML's include and lib folders are set up for the project (they are in `include/` and `lib/` in this repo).
3. Put the sound files next to the executable and update the file paths in `myGame.cpp`, because they are currently written as absolute paths on my computer.
4. Build and run (F5).

## Known limitations

- File paths for sounds and `records.txt` are hardcoded and need changing to run on another machine.
- The game is one procedural source file; all functions and the track data live in `myGame.cpp`.
- There is a single track and no opponents. A race is a timed lap.
- Entries in `records.txt` are not separated by a newline yet.

## Ideas for next steps

- Load files using paths relative to the executable
- Split the code into separate files and classes (`Car`, `Track`, `Menu`, `RecordsManager`)
- Add obstacles or opponent cars, a leaderboard screen and more tracks
