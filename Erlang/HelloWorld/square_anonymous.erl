-module(square_anonymous).
-export([square/1]).

square(0) -> 0;
square(X) when is_integer(X) ->
    fun(Y) ->
        Y * Y
    end;
square(X) ->
    io:format("Cannot square ~p~n", [X]),
    error.