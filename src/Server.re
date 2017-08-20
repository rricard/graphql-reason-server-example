let port = 8080;

external bodyParserJson : unit => Express.Middleware.t = "json" [@@bs.module "body-parser"];

let () = {
  let app = Express.App.make ();
  Express.App.use app (bodyParserJson ());
  let graphqlMiddleware = ApolloServerExpress.createGraphQLExpressMiddleware Schema.schema;
  let graphiqlMiddleware = ApolloServerExpress.createGraphiQLExpressMiddleware "/graphql";
  Express.App.useOnPath app graphqlMiddleware path::"/graphql";
  Express.App.useOnPath app graphiqlMiddleware path::"/graphiql";
  Express.App.listen app ::port;
  Js.log ("GraphiQL available at http://localhost:" ^ string_of_int port ^ "/graphiql")
};
