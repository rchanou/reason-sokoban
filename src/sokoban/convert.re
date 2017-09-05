let convertCodeToKind : string => Types.kind = fun code => {
  switch code {
    | "x" => Wall
    | _ =>  Space
  };
};

let convertTextRowToEntities : int => string => Types.puzzle = fun y textRow => {
  let codeArray = Js_string.split "" textRow;
  let codeList = Array.to_list codeArray;
  let rowSpriteList = List.map convertCodeToKind codeList;
  let formEntity : int => Types.kind => Types.entity = fun x kind => {
    kind,
    position: {
      x,
      y
    }
  };
  List.mapi formEntity rowSpriteList;
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