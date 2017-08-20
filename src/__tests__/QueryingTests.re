open Jest;

open ExpectJs;

let () =
  describe
    "Query.firstExample"
    (
      fun () =>
        testPromise
          "returns a capitalized name"
          (
            fun () =>
              GraphQL.run Schema.schema "{ firstExample { name } }" |>
              Js.Promise.then_ (
                fun execResult =>
                  Js.Promise.resolve (
                    expect execResult##data##firstExample##name |> toEqual "FIRST EXAMPLE"
                  )
              )
          )
    );
