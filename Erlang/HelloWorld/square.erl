-module(square).
-export([square/1]).

square(0) -> 0;
square(X) when is_integer(X) ->
    X * X;
square(X) ->
    io:format("Cannot square ~p~n", [X]),
    error.