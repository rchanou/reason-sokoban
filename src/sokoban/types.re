type position = {
  x : int,
  y : int
};

type kind =
  | Player 
  | Box 
  | Wall 
  | Target
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

type game = {
  puzzle,
  moves : list move
}