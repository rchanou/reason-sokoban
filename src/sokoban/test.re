/* let what = [%bs.obj {
  val soup = "po";
  pub joe = "aaa";
  pub clap x => x;
}];

let fua = what#joe;

let huh : Js.t {..} = {"la":"la"};

/* let convert : string => string [@bs.unwrap] = fun x => x ^ "tab"; */

Js.log what;
Js.log fua;
Js.log huh;

let a = [1,2,3];
let len = List.length a;
let doShit () => {
  let jsObj = [%bs.obj {}];
  for i in 0 to (len - 1){
    let what = List.nth a i;
    Js.log what;
  }
};
doShit ();

let humble = fun x => {
  x##name #= "fluff";
};*/