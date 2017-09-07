
type mstType = | Array mstType | Boolean | Compose | Date | Enumeration | Frozen | Identifier | Late | Literal | Map 
  | Maybe | Model string modelDef | Null | Number | Optional mstType | Reference | Refinement | String | Undefined | Union
and modelDef = list (string, mstType);

external types : Js.t {..} = "types" [@@bs.val] [@@bs.module "mobx-state-tree"];
external model : string => Js.t {..} => 'a = "model" [@@bs.scope "types"] [@@bs.module "mobx-state-tree"];

type js = Js.t {.};

let rec getType mstVariant => switch mstVariant {
  | Array mstType => {
    let itemType = getType mstType;
    types##array itemType;
  }
  | Number => types##number
  | Model name def => {
    let schema = [%bs.obj {}];
    types##model schema;
  }
};

let numberType = getType Number;
let arrayOfNumberDef = Array Number;
let arrayOfNumberType = getType arrayOfNumberDef;

let personSchema = [("name", String)];

let personType = getType (Model "Person" personSchema);

/* let personType = modelType "Person" { "age": numberType }; */