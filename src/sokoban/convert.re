let convertCodeToKind : string => Types.kind = fun code => switch code {
  | "#" => Wall
  | "@" => Player
  | "$" => Box
  | "." => Goal
  | "+" => PlayerOnGoal
  | "*" => BoxOnGoal
  | _ =>  Space
};

let convertTextRowToEntities : int => string => Types.puzzle = fun y textRow => {
  let codeArray = Js_string.split "" textRow;
  let codeList = Array.to_list codeArray;
  let cellKindOrderForRow = List.map convertCodeToKind codeList;
  let getEntitiesForCoordinate : int => Types.kind => list Types.entity = fun x kind => switch kind {
    | PlayerOnGoal => [{ kind: Player, position: { x, y } }, { kind: Goal, position: { x, y } }]
    | BoxOnGoal => [{ kind: Box, position: { x, y } }, { kind: Goal, position: { x, y } }]
    | _ => [{
      kind,
      position: {
        x,
        y
      }
    }]
  };
  let entitiesByCoordinate = List.mapi getEntitiesForCoordinate cellKindOrderForRow;
  List.flatten entitiesByCoordinate;
};

let convertTextToPuzzle : string => Types.puzzle = fun text => {
  let textRowArray = Js_string.split "\n" text;
  let textRowList = Array.to_list textRowArray;
  let rows = List.mapi convertTextRowToEntities textRowList;
  List.flatten rows;
};

let test = convertTextToPuzzle {|
  xxxx
  x  x
  xxxx
|};