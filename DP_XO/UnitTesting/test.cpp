#include "pch.h"
#include "../DP_XO/IGame.h"

TEST(TestCaseName, TestName) {
	IGamePtr game = IGame::Produce();
	EXPECT_EQ(game->GetTurnNumber(), 0);
  ASSERT_EQ(1, 2);
  EXPECT_TRUE(true);
}