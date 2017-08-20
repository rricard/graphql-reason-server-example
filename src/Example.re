type t = {
  id: string,
  name: string
};

let example1 = {id: "1", name: "first example"};

let example2 = {id: "2", name: "second example"};

let example3 = {id: "3", name: "third example"};

let getId e => e.id;

let getName e =>
  Js.Promise.resolve e.name |>
  Js.Promise.then_ (fun name => Js.Promise.resolve (Js.String.toUpperCase name));

let typeDef = "type Example { id: ID!, name: String! }";

let resolvers = {"id": getId, "name": getName};
