{-
-- EPITECH PROJECT, 2024
-- Checker.hs
-- File description:
-- Checker.hs
-}

module Checker (parseArgs, parseOperations, run, Operation(..)) where

import Data.List (sort)
import Text.Read (readMaybe)

newtype DoubleList a = DoubleList ([a], [a]) deriving (Show)
data Operation = SA | SB | SC | PA | PB | RA | RB | RR | RRA | RRB | RRR
                 deriving (Show)

sa :: DoubleList a -> DoubleList a
sa (DoubleList (x1:x2:xs, ys)) = DoubleList (x2:x1:xs, ys)
sa x = x

sb :: DoubleList a -> DoubleList a
sb (DoubleList (xs, y1:y2:ys)) = DoubleList (xs, y2:y1:ys)
sb x = x

sc :: DoubleList a -> DoubleList a
sc x = sb $ sa x

pa :: DoubleList a -> DoubleList a
pa (DoubleList (xs, y:ys)) = DoubleList (y:xs, ys)
pa x = x

pb :: DoubleList a -> DoubleList a
pb (DoubleList (x:xs, ys)) = DoubleList (xs, x:ys)
pb x = x

ra :: DoubleList a -> DoubleList a
ra (DoubleList (x:xs, ys)) = DoubleList (xs ++ [x], ys)
ra x = x

rb :: DoubleList a -> DoubleList a
rb (DoubleList (xs, y:ys)) = DoubleList (xs, ys ++ [y])
rb x = x

rr :: DoubleList a -> DoubleList a
rr x = ra $ rb x

rra :: DoubleList a -> DoubleList a
rra dl@(DoubleList ([], _)) = dl
rra (DoubleList (xs, ys)) = DoubleList (last xs : init xs, ys)

rrb :: DoubleList a -> DoubleList a
rrb dl@(DoubleList (_, [])) = dl
rrb (DoubleList (xs, ys)) = DoubleList (xs, last ys : init ys)

rrr :: DoubleList a -> DoubleList a
rrr x = rra $ rrb x

applyOperation :: DoubleList a -> Operation -> DoubleList a
applyOperation list SA = sa list
applyOperation list SB = sb list
applyOperation list SC = sc list
applyOperation list PA = pa list
applyOperation list PB = pb list
applyOperation list RA = ra list
applyOperation list RB = rb list
applyOperation list RR = rr list
applyOperation list RRA = rra list
applyOperation list RRB = rrb list
applyOperation list RRR = rrr list

applyOperations :: DoubleList a -> [Operation] -> DoubleList a
applyOperations = foldl applyOperation

parseOperation :: String -> Maybe Operation
parseOperation "sa" = Just SA
parseOperation "sb" = Just SB
parseOperation "sc" = Just SC
parseOperation "pa" = Just PA
parseOperation "pb" = Just PB
parseOperation "ra" = Just RA
parseOperation "rb" = Just RB
parseOperation "rr" = Just RR
parseOperation "rra" = Just RRA
parseOperation "rrb" = Just RRB
parseOperation "rrr" = Just RRR
parseOperation _ = Nothing

parseOperations :: String -> Maybe [Operation]
parseOperations input = traverse parseOperation $ words input

parseArgs :: [String] -> Maybe [Int]
parseArgs = traverse readMaybe

isSorted :: Ord a => DoubleList a -> Bool
isSorted (DoubleList (xs, [])) = xs == sort xs
isSorted _ = False

run :: [Int] -> [Operation] -> Bool
run list ops = let sorted = applyOperations (DoubleList (list, [])) ops
               in isSorted sorted
