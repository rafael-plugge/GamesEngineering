-module(listings).
-export([printlist/1]).

printlist([]) -> empty;
printlist([Head | Rest]) ->
    io:format("~p~n", [Head]),
    printlist(Rest).
