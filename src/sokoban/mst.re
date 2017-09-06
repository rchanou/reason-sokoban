type mstModelType;
type mstOptionalType;
type mstStringType;
type mstStore;

external mstOptional : mstOptionalType = "optional" [@@bs.scope "types"] [@@bs.module "mobx-state-tree"];

external mstString : mstStringType = "string" [@@bs.scope "types"] [@@bs.module "mobx-state-tree"];

external mstModel : string => Js.t {..} => mstModelType = "model" [@@bs.scope "types"] [@@bs.module "mobx-state-tree"];

external mstViews : mstModelType => mstModelType = "views" [@@bs.send];

external mstActions : mstStore => 'a => mstStore = "actions" [@@bs.send];

external create : mstModelType => initial::Js.t {..}? => mstStore = "" [@@bs.send];

let testModel = mstModel "Coordinate" { "name": mstString };

let actionsDef = fun self => {
  "setName": fun value => { 
    self##name #= value;
  }
};

let testStore = create testModel initial::{ "name": "Jak" };
let testStoreWithActions = mstActions testStore actionsDef;

type element;
type document = Js.t {. wut : string, title : string, getElementById : (string => element) [@bs.meth] };
external document: document = "document" [@@bs.val];
let doc = document;
/* doc##getElementBy */
let firstTitle = ref document##title;
firstTitle := "yah";
Js.log !firstTitle;
Js.log (doc##getElementById "wut");