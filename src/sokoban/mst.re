type model;
type store;
type mst 'a = 'a;

external optional : mst (option 'a) = "optional" [@@bs.scope "types"] [@@bs.module "mobx-state-tree"];
external string : mst string = "string" [@@bs.scope "types"] [@@bs.module "mobx-state-tree"];
external number : mst float = "number" [@@bs.scope "types"] [@@bs.module "mobx-state-tree"];

external model : string => Js.t {..} => mst model = "model" [@@bs.scope "types"] [@@bs.module "mobx-state-tree"];

external views : mst model => mst model = "views" [@@bs.send];
external actions : mst model => 'a => mst model = "actions" [@@bs.send];

external create : mst model => initial::Js.t {..}? => Js.t {..} = "" [@@bs.send];