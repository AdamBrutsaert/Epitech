{-
-- EPITECH PROJECT, 2024
-- Main.hs
-- File description:
-- Main.hs
-}

module Main (main) where

import System.Environment (getArgs)
import System.Exit (exitWith, ExitCode (ExitFailure), exitSuccess)
import Checker (parseArgs, parseOperations, run)

main :: IO ()
main = do
    line <- getLine
    args <- getArgs
    case (parseArgs args, parseOperations line) of
        (Just l, Just ops) -> if run l ops
                              then putStrLn "OK" >> exitSuccess
                              else putStrLn "KO" >> exitWith (ExitFailure 84)
        _                     -> putStrLn "KO" >> exitWith (ExitFailure 84)
