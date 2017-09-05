let convertCodeToCategory : string => Types.category = fun code => {
  switch code {
    | "x" => Wall
    | _ =>  Space
  };
};

let convertTextRowToEntities : int => string => Types.puzzle = fun y textRow => {
  let codeArray = Js_string.split "" textRow;
  let codeList = Array.to_list codeArray;
  let rowSpriteList = List.map convertCodeToCategory codeList;
  let formEntity : int => Types.category => Types.entity = fun x sprite => {
    category: sprite,
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