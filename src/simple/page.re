type actions = 
  |Add;

type state = { count: int };

let component = ReasonReact.reducerComponent "Greeting";

let make ::name _children => {
  {
    ...component,
    initialState: fun () => {count:0},
    reducer: fun action state => 
    switch action {
      | Add => ReasonReact.Update {count:  state.count + 1}
    },
    render: fun {state, reduce} => {
      let count = state.count;
      let greeting = {j|Hello $name, You've clicked the button $count times(s) foo!|j};
      <button onClick=(reduce (fun _ => Add))> (ReasonReact.stringToElement greeting) </button>
    }
  }
};
