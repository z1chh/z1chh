# Projects

Here are some of the projects that I enjoyed doing.

## [Colosseum](https://github.com/z1chh/AI-Agent) (Python)
For this project, I designed an agent that uses AI to play a game of Colosseum ([rules here](https://github.com/z1chh/z1chh/tree/main/Projects/Colosseum%20-%20AI%20Agent#game-rules)).

My [agent](https://github.com/z1chh/AI-Agent/blob/main/agents/ai_agent.py) uses the Monte-Carlo Tree Search algorithm that I implemented. By default, it has [two](https://github.com/z1chh/AI-Agent/blob/main/agents/ai_agent.py#L49) (2) seconds to compute the next move to play.

This algorithm is implemented in the following files:
* [GameState.py](https://github.com/z1chh/AI-Agent/blob/main/agents/monte_carlo/GameState.py)
* [MCTNode.py](https://github.com/z1chh/AI-Agent/blob/main/agents/monte_carlo/MCTNode.py)
* [MCTree.py](https://github.com/z1chh/AI-Agent/blob/main/agents/monte_carlo/MCTree.py)

### Game State
The GameState class captures the current state of the game, which includes the board, the walls placed, the position of each player, among other uselful information.

### Monte-Carlo Tree Node
The MCTNode class represents a node in the Monte-Carlo tree. It contains the game state, its child nodes, and other information. The complete algorithm can be computed from one node since it contains its children (selection, expansion, simulation and back-propagation).

### Monte-Carlo Tree
The MCTree class represents the whole tree that is used for the Monte-Carlo tree search algorithm. It provides a method to run the algorithm on the root node and choose the best move to compute next.

## [Machine Learning](https://github.com/z1chh/Hepatitis-and-Messidor-Machine-Learning) (Python)
For this project, I implemented the K-Nearest-Neighbours algorithm and the Decision Trees algorithm from scratch (without importing any librairies other than numPy and pandas).

To test the algorithms, I imported two datasets that I first cleaned and organized. Then, I ran the two algorithms multiple times, whilst modifying the parameters to test the efficiency. Some parameters that I played with were:
* KNN vs Decision Tree
* Different K-values
* Maximum Tree Depth
* Distance and Cost Functions

## [Birthing Facilities System](https://github.com/z1chh/Birthing-Facilities-System) (SQL & Java)
For this project, I designed an Entity-Relationship model to organize the entities and their attributes, and the relations between entity sets. I then implemented a relational translation. Once this was done, I created the tables and populated them with data (code in the [Tables](https://github.com/z1chh/Birthing-Facilities-System/tree/main/Tables) folder). Finally, I wrote a JDBC program for midwives to interact with the system and perform many actions.

## [Brick Breaker Game](https://github.com/z1chh/Brick-Breaker-Game) (Assembly)

For this project, I used Intel Assembly (.286) to interact with the graphics card and build a brick breaker game.

The game uses a main loop in which each iteration corresponds to the ball moving by one pixel. Each iteration looks for user input and in-game collisions, and acts accordingly.
