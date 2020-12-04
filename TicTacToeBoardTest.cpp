/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, failed_to_switch) 
{
	ASSERT_FALSE(TicTacToeBoard().toggleTurn() == X);
}

TEST(TicTacToeBoardTest, place_x) 
{
	ASSERT_TRUE(TicTacToeBoard().placePiece(0, 0) == X);
}

TEST(TicTacToeBoardTest, fail_place_x) 
{
	ASSERT_FALSE(TicTacToeBoard().placePiece(-1, 3) == X);
}

TEST(TicTacToeBoardTest, place_piece_over_another)
{
    TicTacToeBoard tic;
    tic.placePiece(0, 0);
    ASSERT_FALSE(tic.placePiece(0, 0) == O);
}

TEST(TicTacToeBoardTest, get_piece)
{
    TicTacToeBoard tic;
    tic.placePiece(0, 0);
    ASSERT_TRUE(tic.getPiece(0, 0) == X);
}

TEST(TicTacToeBoardTest, fail_get_piece)
{
    TicTacToeBoard tic;
    tic.placePiece(0, 0);
    ASSERT_FALSE(tic.getPiece(-1, -1) == X);
}

TEST(TicTacToeBoardTest, blank_board_has_no_winner) 
{
	ASSERT_TRUE(TicTacToeBoard().getWinner() == Invalid);
}

TEST(TicTacToeBoardTest, x_is_winner) 
{
    TicTacToeBoard tic;
    tic.placePiece(0, 0);
    tic.placePiece(1, 1);
    tic.placePiece(0, 1);
    tic.placePiece(2, 1);
    tic.placePiece(0, 2);
	ASSERT_TRUE(tic.getWinner() == X);
}

TEST(TicTacToeBoardTest, o_is_winner) 
{
    TicTacToeBoard tic;
    tic.placePiece(0, 1);
    tic.placePiece(0, 0);
    tic.placePiece(0, 2);
    tic.placePiece(1, 1);
    tic.placePiece(1, 0);
    tic.placePiece(2, 2);
	ASSERT_TRUE(tic.getWinner() == O);
}

TEST(TicTacToeBoardTest, no_winner) 
{
    TicTacToeBoard tic;
    tic.placePiece(0, 2);
    tic.placePiece(0, 0);
    tic.placePiece(1, 0);
    tic.placePiece(0, 1);
    tic.placePiece(1, 1);
    tic.placePiece(1, 2);
    tic.placePiece(2, 1);
    tic.placePiece(2, 0);
    tic.placePiece(2, 2);
	ASSERT_TRUE(tic.getWinner() == Blank);
}

