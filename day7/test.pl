num(72).
num(507).
num(492).
num(114).
num(65412).
num(65079).
num(123).
num(456).



and(X, Y, Z):-
  num(X),
  num(Y),
  num(Z),
  Z =:= (X /\ Y).

or(X,Y,Z) :-
  num(X),
  num(Y),
  num(Z),
  Z =:= (X \/ Y).

assign(X,Z) :-
  num(X),
  num(Z),
  Z =:= X.

not(X, Z) :-
  num(X),
  num(Z),
  Z =:= \X.

rshift(X,Y,Z) :-
  num(X),
  num(Y),
  num(Z),
  Z =:= (X >> Y).

lshift(X,Y,Z) :-
  num(X),
  num(Y),
  num(Z),
  Z =:= (X << Y).



solve([D,E,F,G,H,I,X,Y]):-
  assign(123,X),
  assign(456,Y),
  and(X,Y,D),
  or(X,Y,E),
  lshift(X,2,F),
  rshift(Y,2,G),
  not(X,H),
  not(Y,I),
  sort([D,E,F,G,H,I,X,Y], [ 72,507,492, 114,65412,65079,123,456]).
