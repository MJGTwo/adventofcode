import Control.Monad
import Data.Char


countLetters :: String -> Char -> Int
countLetters str c = length $ filter (== c) str

main = forever $ do
    putStr "Give me some input: "
    l <- getLine
    print ((countLetters l '(')-(countLetters l ')'))
