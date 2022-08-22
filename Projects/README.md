#Projects

Here are some of the projects that I enjoyed doing.

## Colosseum
I designed an agent that uses AI to play a game of Colosseum ([rules here](https://github.com/z1chh/z1chh/tree/main/Projects/Colosseum%20-%20AI%20Agent#game-rules)).

My [agent](https://github.com/z1chh/AI-Agent/blob/main/agents/ai_agent.py) uses the Monte-Carlo Tree Search algorithm that I implemented. By default, it has [two](https://github.com/z1chh/AI-Agent/blob/main/agents/ai_agent.py#L47) (2) seconds to compute the next move to play.

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
