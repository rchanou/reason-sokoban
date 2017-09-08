type optionalDefault;
external castToDefault : 'a => optionalDefault = "%identity";

type mstTypeDef = | Array mstTypeDef | Boolean | Compose | Date | Enumeration | Frozen | Identifier | Late | Literal | Map 
  | Maybe | Model string modelDef | Null | Number | Optional mstTypeDef optionalDefault | Reference | Refinement | String | Undefined | Union
and modelDef = list (string, mstTypeDef);

external types : Js.t {..} = "types" [@@bs.val] [@@bs.module "mobx-state-tree"];
external read : Js.t {..} => string => 'a = "" [@@bs.get_index];
external swap : Js.t {..} => string => 'a => unit = "" [@@bs.set_index];
external create : 'a => initial::Js.t {..}? => Js.t {..} = "" [@@bs.send];
external autorun : (unit => unit) => unit = "autorun" [@@bs.val] [@@bs.module "mobx"];
external addActions : 'a => 'b => 'a = "actions" [@@bs.send]; 

let rec reifyType typeDef => switch typeDef {
  | Array typeDef => {
    let itemType = reifyType typeDef;
    types##array itemType;
  }
  | Boolean => types##boolean
  | Model name def => { 
    let schema = Js.Obj.empty ();
    for i in 0 to (List.length def - 1){
      let (key, mType) = List.nth def i;
      let reifiedType = reifyType mType;
      swap schema key reifiedType;
    };
    types##model name schema;
  }
  
  | Number => types##number
  | Optional typeDef default => {
    let itemType = reifyType typeDef;
    types##optional itemType default;
  }
  | String => types##string
};

let numberType = reifyType Number;
let arrayOfNumberDef = Array Number;

let defaultAgeDef = Optional Number (castToDefault 0);
let personDef = Model "Person" [("name", String), ("age", Optional Number (castToDefault 3))]; 

let personType = reifyType personDef;
let defActions = fun self => {
  "setName": fun value => { 
    self##name #= value;
  }
};
let personTypeWithActions = addActions personType defActions;

let personStore = create personTypeWithActions initial::{ "name": "Garum", "age": 21 };

let log () => {
  Js.log personStore##name;
};
autorun log;

let logAge () => {
  Js.log personStore##age;
};
autorun logAge;

personStore##setName "Habib";



/* let personType = modelType "Person" { "age": numberType };  */