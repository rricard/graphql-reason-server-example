let typeDefs = Query.typeDef ^ " " ^ Example.typeDef;

let resolvers = {"Query": Query.resolvers, "Example": Example.resolvers};

let schema = GraphQLTools.makeExecutableSchema {"typeDefs": typeDefs, "resolvers": resolvers};
