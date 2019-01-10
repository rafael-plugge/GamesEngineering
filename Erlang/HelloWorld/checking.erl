-module(checking).
-export([main/0]).

main() ->
    P1 = {person, {height, 10}, {gender, male}},
    P2 = {person, {height, 10}, {gender, male}},
    element(3, P1) == element(3, P2).