# Not a pokewalker project

## Goal

Reproduce the functionality of a pokewalker without splitting hairs

Based off of the work of https://dmitry.gr/?r=05.Projects&proj=28.%20pokewalker

The pokewalker is, at its most basic,  an overgrown pedometer. A user can "upload" a pokemon from the companion games, and take it on a "walk", or return it from the walker to the game. Walking earns points, which can be used to play minigames and earn up to 3 additional pokemon and items each. 

## Top level feature domains
Logic \
Graphics \
Sound \
Comms \
EPROM \
The literal hardware configuration of the device

## Programmers Guide

![](https://github.com/jscottr557/not-a-pokewalker/blob/master/docs/Pokewalker.drawio_4.png)

If I were a better software engineer then this project wouldn't be organized like a bowl of spaghetti. Start in logic/driving_loop.cpp and follow the calls down the rabbit hole. 

Interrupts "call" in the following order:
		Interrupt signal -> ISR -> driving loop -> respective handler -> state machine ->* subroutine step

What follows is a list of misc. rules and other possibly important facts
 - Transitions:
	  - Set up initial graphical environments
	  - Change the device state and cursor position

 - Subroutines 		
	 - "Update" graphics set up by transitions 		
	 - Modify & save subroutine data (which may or may not change device behavior)
	 - SHOULD NOT CONTAIN USER INTERACTIVE LOOPS i.e. they must be "iterative" in the same style at strtok, very probably local variables should be static
		 - this stipulation does not rule out
   blocking with a semaphore or freeRTOS notifications
      - Return a subroutine_status_t notifying the state machine of progress

	Idea behind invalid() is to notify of an invalid input: beep if volume up, flash the screen(?) otherwise

	Inventory cursor always starts at 0, will need to do some context calculations to determine what is selected

Realistically speaking, a better way to architect this project is to treat each handler like a task, that way blocking with a prompt can be more atomic rather than device wide, but im too lazy to re implement and I'm just going to hack it together for now

If you'd like HyperDisplay to stop throwing warnings at you so you can actually see your mistakes, delete the "#warning" in HyperDisplay.h and use #pragmas to control diagnostic behavior in HyperDisplay_ILI9163C.cpp (see https://stackoverflow.com/questions/3378560/how-to-disable-gcc-warnings-for-a-few-lines-of-code)
