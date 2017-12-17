import Data.List
import Data.Array.Unboxed
import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)

main :: IO ()
main = return ()

bsToInt :: BC.ByteString -> Int
bsToInt = fst . fromJust . BC.readInt

getIntBC :: IO Int
getIntBC = bsToInt <$> BC.getLine

getIntListBC :: IO [Int]
getIntListBC = map bsToInt . BC.words <$> BC.getLine

--2進数へ基数変換
int2bin :: Int -> [Int]
int2bin 0 = []
int2bin n = n `mod` 2 : int2bin (n `div` 2)

--[lb, ub) x未満のmax
upperBound :: Int -> UArray Int Int -> Int
upperBound x xs = innerUB (0-1) ((+1) . snd $ bounds xs) x xs

innerUB :: Int -> Int -> Int -> UArray Int Int -> Int
innerUB lb ub x xs
  | ub - lb > 1 = let mid = lb + (ub - lb) `div` 2
                   in if (xs ! mid) < x then innerUB mid ub x xs
                                        else innerUB lb mid x xs
  | otherwise   = lb

--(lb, ub] xより大きいmin
lowerBound :: Int -> UArray Int Int -> Int
lowerBound x xs = innerLB (0-1) ((+1) . snd $ bounds xs) x xs

innerLB :: Int -> Int -> Int -> UArray Int Int -> Int
innerLB lb ub x xs
  | ub - lb > 1 = let mid = lb + (ub - lb) `div` 2
                   in if (xs ! mid) > x then innerLB lb mid x xs
                                        else innerLB mid ub x xs
  | otherwise   = ub

repeatMemo :: IOUArray Int Int -> [Int] -> IO (IOUArray Int Int)
repeatMemo memo (a:b:_) = do
  return =<< foldM memoize memo [a..b]

memoize :: IOUArray Int Int -> Int -> IO (IOUArray Int Int)
memoize memo x = do
  n <- readArray memo x
  writeArray memo x (n+1)
  return memo
