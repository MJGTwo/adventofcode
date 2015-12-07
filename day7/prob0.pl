:- [read_line].


fact(and(X,Y,Z)) --> [X, "AND", Y, "->", Z].
fact(assign(X,Y)) --> [Y,"->", X].
fact(or(X,Y,Z)) --> [X, "OR", Y, "->", Z ].
fact(not(X,Y)) --> ["Not", X, "->", Y].
fact(lshift(X,Y,Z))--> [X, "LSHIFT", Y, "->", Z].
fact(rshift(X,Y,Z))--> [X, "RSHIFT", Y, "->", Z].


calc((Z = (X/\Y)) ,and(X,Y,Z)).
calc((X = Y)      ,assign(X,Y) ).
calc((Z = (X\/Y)) ,or(X,Y,Z)).
calc((Y = \X)     ,not(X,Y)).
calc((Z =(X << Y)),lshift(X,Y,Z)).
calc((Z =(X >> Y)),rshift(X,Y,Z)).


query(question(Q)) --> [Q,'?'].
tell(write(Q)):-  question(Q).




parse(Input) :- phrase(fact(Fact), Input), calc(Statement,Fact),assert(Statement).
parse(Input) :- phrase(query(Q), Input), tell(Q).

loop :- read_line(Sent),parse(Sent), nl, loop.
