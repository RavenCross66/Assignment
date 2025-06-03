# Assignment
This is a thing
Rules:
The game will play random sequences of light patterns that correspond to a button press combination. 

Each time you press the correct button input on the last beat of the sequence it will flash green and increase your score. 

The delay between beats is reduced a number of milliseconds equal to your current score.


If you reach a score of 100 you win the game.


If you fail to press the right inputs, or press them before the final beat, your score is reset to 0, and your delay is reset. It also flashes red to show this has happened.

Whenever a button is correctly pressed or the game is lost, the serial monitor will print information about the current score or your previous high score.

Sensors Used: Input // Output
Button 1 - Input = 1
Button 2 - Input = 2
Button 1 & 2 - Input = 3

Output:
If input == sequence
Score +1
New rand sequence
Delay -1
Else
Score = 0
Delay = 120
