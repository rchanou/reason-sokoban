const mst = require("mobx-state-tree");
const mobx = require("mobx");

const { types } = mst;
const { autorun } = mobx;

const person = types
  .model("Person", { name: types.string, age: types.number })
  .actions(self => ({
    setName(val) {
      self.name = val;
      return val + "what";
    }
  }));

const joe = person.create({ name: "Joe Schmo", age: 31 });

autorun(() => console.log(joe.name));

joe.setName("Sophie");
