{-
-- EPITECH PROJECT, 2024
-- My.hs
-- File description:
-- My.hs
-}

mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = x < 0

myAbs :: Int -> Int
myAbs x
    | x < 0     = -x
    | otherwise = x

myMin :: Int -> Int -> Int
myMin x y
    | x < y     = x
    | otherwise = y

myMax :: Int -> Int -> Int
myMax x y
    | x > y     = x
    | otherwise = y

myTuple :: a -> b -> (a, b)
myTuple x y = (x, y)

myTruple :: a -> b -> c -> (a, b, c)
myTruple x y z = (x, y, z)

myFst :: (a, b) -> a
myFst (x, _) = x

mySnd :: (a, b) -> b
mySnd (_, y) = y

mySwap :: (a, b) -> (b, a)
mySwap (x, y) = (y, x)

myHead :: [a] -> a
myHead []    = error "empty list"
myHead (x:_) = x

myTail :: [a] -> [a]
myTail []     = error "empty list"
myTail (_:xs) = xs

myLength :: [a] -> Int
myLength []     = 0
myLength (_:xs) = 1 + myLength xs

myNth :: [a] -> Int -> a
myNth [] _     = error "index too large"
myNth (x:_) 0  = x
myNth (_:xs) n
    | n < 0     = error "negative index"
    | otherwise = myNth xs (n - 1)

myTake :: Int -> [a] -> [a]
myTake 0 _  = []
myTake _ [] = []
myTake n (x:xs)
    | n < 0     = []
    | otherwise = x : myTake (n - 1) xs

myDrop :: Int -> [a] -> [a]
myDrop 0 xs = xs
myDrop _ [] = []
myDrop n all@(_:xs)
    | n < 0     = all
    | otherwise = myDrop (n - 1) xs

myAppend :: [a] -> [a] -> [a]
myAppend [] ys  = ys
myAppend xs ys = myAppend (myInit xs) (myLast xs : ys)

myReverse :: [a] -> [a]
myReverse [] = []
myReverse xs = myLast xs : myReverse (myInit xs)

myInit :: [a] -> [a]
myInit []     = error "empty list"
myInit [_]    = []
myInit (x:xs) = x : myInit xs

myLast :: [a] -> a
myLast []     = error "empty list"
myLast [x]    = x
myLast (_:xs) = myLast xs

myZip :: [a] -> [b] -> [(a, b)]
myZip _ [] = []
myZip [] _ = []
myZip (x:xs) (y:ys) = (x, y) : myZip xs ys

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((x, y):zs) = let (xs, ys) = myUnzip zs
                      in (x:xs, y:ys)

myMap :: (a -> b) -> [a] -> [b]
myMap _ [] = []
myMap fn (x:xs) = fn x : myMap fn xs

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter fn (x:xs)
    | fn x      = x : myFilter fn xs
    | otherwise = myFilter fn xs

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl _ acc [] = acc
myFoldl fn acc (x:xs) = let acc' = fn acc x
                        in myFoldl fn acc' xs

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr fn acc xs = myFoldl (\x y -> fn y x) acc (myReverse xs)

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition _ [] = ([], [])
myPartition fn (x:xs)
    | fn x      = (x:ys, zs)
    | otherwise = (ys, x:zs)
    where (ys, zs) = myPartition fn xs

myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort _ [] = []
myQuickSort fn (x:xs) = let (bigger, smaller) = myPartition (fn x) xs
                        in myQuickSort fn smaller
                           `myAppend` [x]
                           `myAppend` myQuickSort fn bigger
