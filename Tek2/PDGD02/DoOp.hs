{-
-- EPITECH PROJECT, 2024
-- DoOp.hs
-- File description:
-- DoOp.hs
-}

import System.Environment (getArgs)
import System.Exit (exitWith, exitSuccess, ExitCode(..))

myElem :: Eq a => a -> [a] -> Bool
myElem _ []     = False
myElem e (x:xs) = x == e || myElem e xs

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv a b = Just (a `div` b)

safeMod :: Int -> Int -> Maybe Int
safeMod _ 0 = Nothing
safeMod a b = Just (a `mod` b)

safeNth :: [a] -> Int -> Maybe a
safeNth [] _     = Nothing
safeNth (x:_) 0  = Just x
safeNth (_:xs) n
    | n < 0     = Nothing
    | otherwise = safeNth xs (n - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc x = (+1) <$> x

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup _ [] = Nothing
myLookup x ((y1, y2): ys)
    | x == y1   = Just y2
    | otherwise = myLookup x ys

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo fn x y = fn <$> x <*> y

readUnsignedInt :: [Char] -> Maybe Int
readUnsignedInt str
    | all (`elem` ['0'..'9']) str = Just (read str :: Int)
    | otherwise                   = Nothing

readInt :: [Char] -> Maybe Int
readInt ('-':xs) = negate <$> readUnsignedInt xs
readInt xs       = readUnsignedInt xs

getLineLength :: IO Int
getLineLength = length <$> getLine

printAndGetLength :: String -> IO Int
printAndGetLength str = putStrLn str >> return (length str)

printBox :: Int -> IO ()
printBox 1 = putStrLn "++"
printBox n
    | n <= 0 = return ()
    | otherwise =
        let side = "+" ++ replicate (n * 2 - 2) '-' ++ "+\n"
            middle = "|" ++ replicate (n * 2 - 2) ' ' ++ "|\n"
        in putStr $ side ++ concat (replicate (n - 2) middle) ++ side

concatLines :: Int -> IO String
concatLines n
    | n <= 0    = return ""
    | otherwise = (++) <$> getLine <*> concatLines (n - 1)

getInt :: IO (Maybe Int)
getInt = readInt <$> getLine

doop :: (Int, String, Int) -> Maybe Int
doop (a, "+", b) = Just (a + b)
doop (a, "-", b) = Just (a - b)
doop (a, "*", b) = Just (a * b)
doop (a, "/", b) = a `safeDiv` b
doop (a, "%", b) = a `safeMod` b
doop _           = Nothing

parseArgs :: [String] -> Maybe (Int, String, Int)
parseArgs [a, op, b] = do
    a' <- readInt a
    b' <- readInt b
    return (a', op, b')
parseArgs _          = Nothing

main :: IO ()
main = do
    args <- getArgs
    case doop <$> parseArgs args of
        Just (Just x) -> print x >> exitSuccess
        _             -> exitWith (ExitFailure 84)
