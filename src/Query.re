let getFirstExample () => Example.example1;

let getExamples () => [|Example.example1, Example.example2, Example.example3|];

let typeDef = "type Query { examples: [Example!]!, firstExample: Example! }";

let resolvers = {"examples": getExamples, "firstExample": getFirstExample};
