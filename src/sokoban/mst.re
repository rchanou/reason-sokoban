type mstModelType;
type mstOptionalType;
type mstStringType;
type mstStore;

external mstOptional : mstOptionalType = "optional" [@@bs.scope "types"] [@@bs.module "mobx-state-tree"];

external mstString : mstStringType = "string" [@@bs.scope "types"] [@@bs.module "mobx-state-tree"];

external mstModel : string => Js.t {..} => mstModelType = "model" [@@bs.scope "types"] [@@bs.module "mobx-state-tree"];

external create : mstModelType => mstStore = "" [@@bs.send];

let testModel = mstModel "Coordinate" { "name": mstString };

let testStore = create testModel;