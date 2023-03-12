#include "pch.h"
#include "IGame.h"

using namespace testing;
//class MockGame: public IGame
//{
//public:
//	MOCK_METHOD(void, NotifyAllListeners, (), (override));
//	MOCK_METHOD(void, NewGame, (), (override));
//	MOCK_METHOD(void, StartRound, (uint8_t), (override));
//	MOCK_METHOD(Board, GetBoard, (), (override));
//	MOCK_METHOD(IPlayerPtr, GetPlayer, (), (override));
//	MOCK_METHOD(IPlayerPtr, GetRobot, (), (override));
//	MOCK_METHOD(uint8_t, GetTurnNumber, (), (override));
//	MOCK_METHOD(Board::BoardState, GetGameState, (), (override));
//	MOCK_METHOD(void, AddListener, (IGameListenerPtr), (override));
//	MOCK_METHOD(void, RemoveListener, (IGameListenerPtr), (override));
//	MOCK_METHOD(void, CheckGameState, (), (override));
//	MOCK_METHOD(uint8_t, SetOptionForRobot, (), (override));
//};

class MockListener : public IGameListener
{
public:
	MOCK_METHOD(void, Update, (), (override));
	MOCK_METHOD(void, ShowGameState, (), (override));
};
TEST(HangmanGameTest, Mocc)
{
	auto game = IGame::Produce();
	std::shared_ptr<MockListener> ml = std::make_shared<MockListener>();
	game->AddListener(ml);
	

	EXPECT_CALL(*ml, Update());
	game->StartRound(1);

	// Verify the expectations
	Mock::VerifyAndClearExpectations(&ml);
}
TEST(XO_GAMETEST, CorrectBoardPlacement)
{
	auto game = IGame::Produce();
	IGameListenerPtr igl;
	game->AddListener(igl);
	auto board = game->GetBoard();

	auto player = game->GetPlayer();
	board.setOption(2, player);

	ASSERT_EQ(board.GetBoard()[0][2], Sign::X);
}

TEST(XO_GAMETEST, IncorrectBoardPlacement)
{
	auto game = IGame::Produce();
	IGameListenerPtr igl;
	game->AddListener(igl);
	auto board = game->GetBoard();

	auto player = game->GetPlayer();
	board.setOption(1, player);


	ASSERT_FALSE(board.GetBoard()[0][2]== Sign::X);
}

TEST(XO_GAMETEST, GameWonTest)
{
	auto game = IGame::Produce();
	IGameListenerPtr igl;
	game->AddListener(igl);
	auto board = game->GetBoard();

	auto player = game->GetPlayer();
	board.setOption(0, player);
	board.setOption(1, player);
	board.setOption(2, player);

	board.CheckGameState();
	game->CheckGameState();
	ASSERT_EQ(board.CheckGameState(), Board::BoardState::Win);
}

TEST(XO_GAMETEST, GameLostTest)
{
	auto game = IGame::Produce();
	IGameListenerPtr igl;
	game->AddListener(igl);
	auto board = game->GetBoard();

	auto robot = game->GetRobot();
	board.setOption(0, robot);
	board.setOption(1, robot);
	board.setOption(2, robot);

	board.CheckGameState();
	game->CheckGameState();
	ASSERT_EQ(board.CheckGameState(), Board::BoardState::Win);
	ASSERT_EQ(board.GetBoard()[0][0], Sign::O);
	ASSERT_EQ(board.GetBoard()[0][1], Sign::O);
	ASSERT_EQ(board.GetBoard()[0][2], Sign::O);

}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}