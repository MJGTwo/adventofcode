

negfloor :: String -> Int -> Int -> Int
negfloor "" c f = f
negfloor str@(x:xs) c f
  | c == -1 = f
  | x == '(' = (negfloor xs (c+1) (f+1))
  | x == ')' = (negfloor xs (c-1) (f+1))



main =  do
    putStr "Your answer: "
    l <- getLine
    print (negfloor l 0 0)
