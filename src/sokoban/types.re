type position = {
  x : int,
  y : int
};

type kind =
  | Player 
  | Box 
  | Wall 
  | Goal
  | PlayerOnGoal
  | BoxOnGoal
  | Space;

type entity = { kind, position };

type puzzle = list entity;

type axis =
  | X 
  | Y;

type direction =
  | Minus
  | Plus;

type move = {
  axis,
  direction
};

type playState = {
  puzzle,
  moves : list move
}