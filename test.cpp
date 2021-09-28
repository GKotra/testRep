#include "pch.h"
#include "Mastermind.h"
#define UNIT_TEST 1

TEST(TestCaseForValidationOfInput, validateGuess_WithInputOfDesiredLengthAndColours_ExpectInputIsValid)
{
	Mastermind game(4, 8);
	bool isValid = game.isGuessValid("COBH");
	EXPECT_EQ(true, isValid);
}

TEST(TestCaseForValidationOfInput, validateGuess_WithInputLengthGreaterThanGiven_ExpectInputIsInvalid)
{
	Mastermind game(4, 8);
	bool isValid = game.isGuessValid("COBHAM");
	EXPECT_EQ(false, isValid);
}

TEST(TestCaseForValidationOfInput, validateGuesss_WithUnDesiredColours_ExpectInputIsInvalid)
{
	Mastermind game(4, 8);
	bool isValid = game.isGuessValid("ABCD");
	EXPECT_EQ(false, isValid);
}

TEST(TestCaseForComparisionOfGuessWithSecretCode, 
	inputGuess_ValidGuess_ExpectInvalidInput)
{
	Mastermind game(4, 8);
	game.setCodePegs("COCO");
	game.setGuess("MOMM");
	game.compareInputAndGenerateHints();

	EXPECT_EQ(1, game.getRedPegCount()); 
	EXPECT_EQ(0, game.getWhitePegCount());
}

TEST(TestCaseForComparisionOfGuessWithSecretCode,
	compareInputAndGenerateHints_ValidGuess_ExpectValidHints)
{
	Mastermind game(4, 8);
	game.setCodePegs("COCO");
	game.setGuess("COMO");
	game.compareInputAndGenerateHints();

	EXPECT_EQ(3, game.getRedPegCount());
	EXPECT_EQ(0, game.getWhitePegCount());
}

TEST(TestCaseForComparisionOfGuessWithSecretCode,
	compareInputAndGenerateHints_MatchingGuess_ExpectValidHints)
{
	Mastermind game(4, 8);
	game.setCodePegs("COCO");
	game.setGuess("COCO");
	game.compareInputAndGenerateHints(); 

	EXPECT_EQ(4, game.getRedPegCount());
	EXPECT_EQ(0, game.getWhitePegCount());
}