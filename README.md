![image](https://github.com/ilopez-r/resources/blob/main/covers/cover-so_long-bonus.png?raw=true)

## Subject
This is the [subject](https://github.com/ilopez-r/resources/blob/main/subjects/02_so_long.en.pdf) for this project.

## Introduction

Welcome to the 42 So_Long project! This project is part of the curriculum at 42 and focuses on creating a 2D game using the MinilibX, a simple graphic library provided by 42. So_Long is a game where the player navigates through a map, collects items, and avoids obstacles to reach the goal.

<h2>Objective</h2>
The objective of the So_Long project is to develop a fully functional game that incorporates various game elements, such as map rendering, player movement, collision detection, item collection, and win/lose conditions. By completing this project, you will enhance your understanding of game development concepts and gain practical experience in using the MinilibX library.

<h2>Features</h2>
Map Rendering
So_Long allows you to load and render game maps stored in a specific format, typically a file with a .ber extension. The map consists of different tiles representing walls, paths, collectible items, the player's starting position, and the exit. The MinilibX library provides functions to render graphical elements on the screen, enabling you to display the map with the appropriate textures and colors.

<h2>Player Movement</h2>
The player can move in four directions: up, down, left, and right, within the bounds of the map. By handling keyboard inputs, you can update the player's position on the screen accordingly. The MinilibX library provides functions to capture key events and perform actions based on the pressed keys.

<h2>Collision Detection</h2>
To ensure the player doesn't move through walls or outside the boundaries of the map, collision detection is implemented. The game checks if the player's desired movement will result in a collision with a wall or if the player has reached the exit. If a collision is detected, the player's movement is restricted.

<h2>Item Collection</h2>
Throughout the map, there may be collectible items that the player can interact with. When the player reaches a tile containing an item, it is collected, and the player's score is incremented. This feature adds an additional layer of gameplay and encourages exploration.

<h2>Win/Lose Conditions </h2>
The win condition is achieved when the player successfully reaches the exit tile. In contrast, the lose condition can be triggered by specific events, such as colliding with enemies or running out of lives. Implementing win and lose conditions adds a sense of challenge and completion to the game.

<h2>Installation</h2>
To install and run the So_Long project, follow these steps:

Clone the project repository: 
			
			git clone https://github.com/ilopez-r/so_long.git
Navigate to the project directory: 
			
					cd so_long
Compile the project using the provided Makefile: 
<br/>			

					make bonus
Run the game executable: 
<br/>			

				./so_long_bonus maps/mapbonus.ber
			
<br/>
