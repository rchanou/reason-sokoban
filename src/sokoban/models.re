
let coordinate = Mst.model "Coordinate" { "x": Mst.number, "y": Mst.number };
/* let entity = Mst.model "Entity" { "coordinate": coordinate, "kind": } */

let actionsDef = fun self => {
  "setName": fun value => { 
    self##name #= value;
  }
};

let testModel = Mst.model "Test" { "name": Mst.string };
let testModelWithActions = Mst.actions testModel actionsDef;
let testStore = Mst.create testModelWithActions initial::{ "name": "Jak" };

Js.log testStore##name;
testStore##setName "Soph";
Js.log testStore##name;