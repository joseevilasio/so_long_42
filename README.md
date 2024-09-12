# so_long
This project is a very small 2D game.

## About
This game is a project from the commom core at 42 Porto. The objective is to develop a 2D game using the Minilibx library, created by the school's students. This library simplifies interaction with the X-Window system, handling window management and rendering images on the screen.
The story revolves around a Brazilian capybara on a mission to rescue animals from Ash, a grumpy hunter who imprisons them in ball-shaped cages. The challenge is to save as many animals as possible and find a safe shelter. The player wins by collecting all the animals or more animals than Ash, but loses if Ash captures more animals or finds the player first.

Since the map is dynamic, I’ve used different tiles to make it more visually appealing, varying based on the position of the walls. The lower border is represented by a sea with a shark swimming (available only in bonus mode), while the other borders are made of trees. The central walls are stone, and the collectibles also change in bonus mode, featuring three different types.

The game features dynamic maps, allowing players to create their own levels as long as they follow these rules:

1. The map extension must be “.ber.”
2. Accepted map characters are:
- 1: Wall
- 0: Empty space
- P: Player
- E: Exit
- C: Collectibles
- A: Enemy (Ash)*
3. The map must allow the player to collect all items and reach the exit.
4. The map’s borders must always be made of 1 (walls).

## Build
To compile the library, simply use the makefile targets on the command line within the 'src' folder.

so_long
```
./src/make
```
or you can compile the bonus, with extra features.

so_long_bonus
```
./src/make bonus
```

## Usage
Let's play, you can use some maps available at maps.
First of all, compile and then run.

```
./so_long maps/42.ber
```
