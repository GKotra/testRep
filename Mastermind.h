#ifndef MASTERMIND_H_
#define MASTERMIND_H_

#include <iostream>
#include <vector>

class Mastermind
{
public:
    explicit Mastermind(int lengthOfCodePegs, int numOfTurns);

    ~Mastermind();

    void init();

    void generateSecretCode(int length);

    void startGame();

    bool inputGuessAndValidateUntilValid();

    std::string toUpperCase(std::string& s);

    bool isGuessValid(std::string guess);

    void compareInputAndGenerateHints();

    void resetMemberVariables();

    void setMaxNumOfTurns(const int maxNumOfTurns);
    int getMaxNumOfTurns() const;

    void setLengthOfCodePegs(const int maxNumOfTurns);
    int getLengthOfCodePegs() const;

    void setGuess(const std::string& guess);
    std::string getGuess() const;

    void setCodePegs(const std::string& guess);
    std::string getCodePegs() const;

    void setRedPegCount(const int redPegCount);
    int getRedPegCount() const;

    void setWhitePegCount(const int whitePegCount);
    int getWhitePegCount() const;

private:
    std::string m_codePegs;
    std::string m_guess;
    int         m_redPegCount;
    int         m_whitePegCount;
    int         m_maxNumOfTurns;
    int         m_lengthOfCodePegs;
};

#endif  MASTERMIND_H_
