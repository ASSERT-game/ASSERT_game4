<p align="center">
  <img height="200" src="https://github.com/ASSERT-game/ASSERT_game4/blob/main/assets/tittle_c.png" />
</p>

# Summary

Fourth repo in the ASSERT_game line, where I try bring to existence an entire game. This one is the most complete in terms of being a fully fledged game (you can find the other games I have tried to make [here](https://github.com/ASSERT-game)). I coded all the game and created all the assets myself using [Aseprite](https://www.aseprite.org/), you can find more about the development in the [Technology Section](#technology-used). 

# Installation

The game can currently be exerperinced on most major browsers (Chrome, Safari, Firefox) and is being hosted on one of my own [GitHub Pages](https://pages.github.com/). The game was made to be [playable](https://mrcolour.github.io/blaster/) on the phone and so I encourage you to also try it on the phone. Most of the development was play tested on desktop however and I found it to be more challanging and fun with ***mouse and keyboard***. 

[[Play the game](https://mrcolour.github.io/Mympheus/)]<br>
[[GitHub Page Repo](https://github.com/MrColour/mrcolour.github.io)]

### From Source files
If you are computer savy you can also build the sources if you want. My method of building is using this [Makefile](https://github.com/ASSERT-game/ASSERT_game4/blob/main/Makefile) (`make all` or `make run`) but I suspect it would only works on MacOs with [make](https://en.wikipedia.org/wiki/Make_(software)) and [brew](https://brew.sh/) installed (and subsequently SDL2, sdl2_image, and SDL2_ttf installed using brew). I believe that it would be simply a matter of bieng able to find SDL2, SDL2_image, and SDL2_ttf libraries for your environment and bieng able to link with those libraries (and if you have [make](https://en.wikipedia.org/wiki/Make_(software)) working on your system then it would mean you just have to change [this line](https://github.com/ASSERT-game/ASSERT_game4/blob/e703f2d2eb15e079fd7e0f55e56d56a2541be068/Makefile#L11) hopefully).

If you build the sources it may or may work with gamepad controllers such as Xbox controllers. I had it working with Xbox controllers on MacOs using [360Controller](https://github.com/360Controller/360Controller) ([download link](https://github.com/360Controller/360Controller/releases/tag/v1.0.0-alpha.6)). It is substainally more difficult but I did it mainly out of curiosity and on a whim because I simply could (coded the controller code because [this](https://github.com/ASSERT-game/pacman_v2))

# Game
_Mympheus and the Dawnlit Grotto_ is a click based game. Unlock new abilities giving you new ways to destroy enemy waves in increasing difficulty. Statagize in this wave shooter choosing the right ability but be quick to switch and continue destroying slimes. But be warned the enemy will also throw at you new enemy types and make it hard for you to manage the action. Will you be able beat all the levels and collect the gems?

<p align="center">
	
https://user-images.githubusercontent.com/41839667/132979861-ea342277-8f59-4a27-9eee-6a8c5a887fd3.mp4
	
</p>

## Controls
The game was devloped to be playable on phone and offers simple controls for just tapping and clicking. But it can also be controlled with a mouse and keyboard. Use the number keys (1,2,3,4) or A,S,D,F to switch abilities. You can use your ability by left clicking or spacebar. Aim with your mouse. Controls are easy, but the game lacks a tutorial. 

## More
If you are looking for a challenge, I have beaten each level without losing health (although with some update changes I have to reverify this, but I think most of them are). You can also try to get the best times for the levels. I haven't fully made the scoring system, and it doens't do anything (it is determined by a constant multiplied by the total combo at the moment).

At the moment I am trying to wrap up the project and am looking for feedback to see if anyone finds glaring issues. I won't be adding too much, but I did once have an inventory system and a few other abilities (pierce, whirlwind, heal) that I could add. Depending on what others think I might add some way to support the project. That would be enough incentive to continue developing the game.

# Technology Used

### [SDL2](https://www.libsdl.org/)
A lot of the heavy lifting comes from SDL2 providing the libraries to interact with different drivers and the OS. Using this library makes it in thoery portable to many different environments. The only external headers come from here (I don't even include [Standard C headers](https://en.wikipedia.org/wiki/C_standard_library)). This allows me to focus on the part of programing a game insted of toying with drivers and specifications. Really cool stuff!

I use [SDL2_image](https://www.libsdl.org/projects/SDL_image/) to read the PNG assets into the game.<br>
I also use [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/) for some text found in the game. (found [this](https://www.libsdl.org/projects/SDL_ttf/) cool pixel monospace font)

### [SDLX](https://github.com/MrColour/SDL_2D_init)
SDLX is a custom library that I wrote that makes the creation of 2d games easier for me. A lot of the functions are wrappers for SDL calls to make development faster and in the way I wanted. The library also provides some sort of 'API' functionality that dictates how certain systems function ([buttons](https://github.com/ASSERT-game/ASSERT_game4/blob/main/src/SDLX/SDLX_button_loop.c), [gameinput](https://github.com/ASSERT-game/ASSERT_game4/blob/main/includes/SDLX/SDLX_structs.h#L128), [sprites](https://github.com/ASSERT-game/ASSERT_game4/blob/main/includes/SDLX/SDLX_structs.h#L38), [rendering](https://github.com/ASSERT-game/ASSERT_game4/blob/main/src/SDLX/SDLX_render_queue.c), [etc](https://github.com/ASSERT-game/ASSERT_game4/tree/main/src/SDLX)). I have continued to add functionality to this library by creating the some of games found [here](https://github.com/ASSERT-game) but a lot of things are still lacking. But tools are useful to make and have!

### [Aseprite](https://www.aseprite.org/)
I created all of the assets using [Aseprite](https://www.aseprite.org/). For some time the background image for the main menu was a PNG I found on Google, but other than that I don't believe I used external PNG's. I did find references to emulate but I handmade all the assets myelf on the [Aseprite](https://www.aseprite.org/). Animation was done using the frames on Aseprite and then converting that into a big long PNG sprite sheet. Overall I am suprised that the game looks and feels this good.

### [Emscripten](https://emscripten.org/)
Emscripten allows you to magically compile C code to run on browsers. Once set up it is very easy to port the project to the web. Thanks to only using SDL the project simply just works with Emscripten and is already supported. However SDL2_ttf will fail unless you use `emmc version 2.0.10` (ttf was imlemented later on in development and was on the fence with just manually creating text to PNGs). [Emscripten](https://emscripten.org/) allows me to share a [runable](https://mrcolour.github.io/blaster/) version of my code to many people without them having to worry about the problems of compiling, linking, installing etc. For that I am very thankful. 

# Contact

Got a burning question? Some feedback, maybe a bug? I'm figuring out how to do contacts. You can raise an issue on the repo and I will be sure to read it though haha! You can go [here](https://mrcolour.github.io/contact/) and send a message in the ***right hand side box*** and it will automagically make its way to my inbox!
