import Test.Hspec
import Checker (run, Operation(..))

main :: IO ()
main = hspec $ do
  describe "PushSwap Checker" $ do
    it "returns True with no operations" $ do
      run [1, 2, 3] [] `shouldBe` True
    it "returns True with PB, PA" $ do
      run [1, 2, 3] [PB, PA] `shouldBe` True
    it "returns True with empty list" $ do
      run [] [PB, PA] `shouldBe` True
    it "returns True with SA, PB, PA" $ do
      run [2, 1, 3, 6, 5, 8] [SA, PB, PB, PB, SA, PA, PA, PA]  `shouldBe` True
    it "returns False with PB, PA" $ do
      run [1, 3, 2] [PB, PA] `shouldBe` False
    it "returns False with PB, PA" $ do
      run [1, 2, 3] [PB, PB, PA] `shouldBe` False
    it "returns False with SB, SC" $ do
      run [1, 2, 3] [SB, SC] `shouldBe` False
    it "returns False with RA, RR, RB" $ do
      run [1, 2, 3] [RA, RR, RB] `shouldBe` False
    it "returns False with RRA, RRB, RRR" $ do
      run [1, 2, 3] [RRA, RRB, RRR] `shouldBe` False
