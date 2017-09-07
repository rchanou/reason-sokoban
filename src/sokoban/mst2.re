
type mstType = | Array mstType | Boolean | Compose | Date | Enumeration | Frozen | Identifier | Late | Literal | Map 
  | Maybe | Model string modelDef | Null | Number | Optional mstType | Reference | Refinement | String | Undefined | Union
and modelDef = list (string, mstType);

external types : Js.t {..} = "types" [@@bs.val] [@@bs.module "mobx-state-tree"];
external model : string => Js.t {..} => 'a = "model" [@@bs.scope "types"] [@@bs.module "mobx-state-tree"];
external read : Js.t {..} => string => 'a = "" [@@bs.get_index];
external swap : Js.t {..} => string => 'a => unit = "" [@@bs.set_index];

external create : 'a => initial::Js.t {..}? => Js.t {..} = "" [@@bs.send];

let rec getType mstVariant => switch mstVariant {
  | Array mstType => {
    let itemType = getType mstType;
    types##array itemType;
  }
  | Number => types##number
  | Model name def => { 
    let schema = Js.Obj.empty ();
    for i in 0 to (List.length def - 1){
      let (key, mType) = List.nth def i;
      let reifiedType = getType mType;
      swap schema key reifiedType;
    };
    types##model name schema;
  }
  | String => types##string
};

let numberType = getType Number;
let arrayOfNumberDef = Array Number;
/* let arrayOfNumberType = getType arrayOfNumberDef; */

 let personDef = Model "Person" [("name", String)]; 

let personType = getType personDef;

let personStore = create personType initial::{ "name": "Garum" };


/* let personType = modelType "Person" { "age": numberType };  */