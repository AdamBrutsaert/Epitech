{-
-- EPITECH PROJECT, 2024
-- Tree.hs
-- File description:
-- Tree.hs
-}

data Tree a = Empty | Node (Tree a) a (Tree a) deriving (Show)

instance Functor Tree where
    fmap _ Empty = Empty
    fmap fn (Node left x right) = Node (fmap fn left) (fn x) (fmap fn right)

instance Foldable Tree where
    foldr _ acc Empty = acc
    foldr fn acc (Node left x right) = foldr fn (fn x $ foldr fn acc right) left

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree x Empty = Node Empty x Empty
addInTree x (Node left y right)
    | x < y     = Node (addInTree x left) y right
    | otherwise = Node left y (addInTree x right)

listToTree :: Ord a => [a] -> Tree a
listToTree = foldl (flip addInTree) Empty

treeToList :: Tree a -> [a]
treeToList Empty = []
treeToList (Node left x right) = treeToList left ++ x : treeToList right

treeSort :: Ord a => [a] -> [a]
treeSort = treeToList . listToTree
