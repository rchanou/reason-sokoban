let component = ReasonReact.statelessComponent "Sokoban";

let make _children => {
  ...component,
  render: fun _self => {
    <div> (ReasonReact.stringToElement "we burn") </div>
  }
}