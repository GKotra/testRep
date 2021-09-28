#include "Mastermind.h"
#include <cstdlib>
#include <set>

Mastermind::Mastermind(int lengthOfCodePegs, int numOfTurns)
    : m_redPegCount(0)
    , m_whitePegCount(0)
    , m_lengthOfCodePegs(lengthOfCodePegs)
    , m_maxNumOfTurns(numOfTurns)
{
    init();
}

Mastermind::~Mastermind()
{
    resetMemberVariables();
}

void Mastermind::init()
{
    /*init() can be extended with additional necessary steps to be taken care before starting a new game*/
    generateSecretCode(m_lengthOfCodePegs);
}

void Mastermind::generateSecretCode(int length)
{
    static std::string coloursPalette = "RANDOM";
    char* codePegs;
    codePegs = new char[length];
    srand(time(NULL));

    for (int i = 0; i < length; i++)
    {
        codePegs[i] = coloursPalette[rand() % coloursPalette.length()];
    }
    m_codePegs.assign(codePegs, length);
}

void Mastermind::startGame()
{
    bool success = false;
    success = inputGuessAndValidateUntilValid();
    if (success)
    {
       compareInputAndGenerateHints();
    }
}

bool Mastermind::inputGuessAndValidateUntilValid()
{
    std::string  guess = "";
    std::cout << "\n Enter your  guess" << std::endl;
    std::cin >> guess;
    toUpperCase(guess);
    if (isGuessValid(guess))
    {
        setGuess(guess);
        return true;
    }
    else
    {
        inputGuessAndValidateUntilValid();
    }
}

std::string Mastermind::toUpperCase(std::string& s)
{
    for (unsigned int i = 0; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
    }
    return s;
}

bool Mastermind::isGuessValid(std::string guess)
{
    if ((guess.empty()) || (guess.length() != m_lengthOfCodePegs) ||
        (guess.find_first_not_of("RANDOM") != std::string::npos))
    {
        std::cout << " Please enter a valid input pattern representing pegs of length " << m_lengthOfCodePegs;
        std::cout << " \n Please select 4 pegs from the given colour palette \n";
        std::cout << " R - for Ruby\n";
        std::cout << " A - for Amber\n";
        std::cout << " N - for Neon\n";
        std::cout << " D - for Denim blue\n";
        std::cout << " O - for Orange\n";
        std::cout << " M - for Magenta\n";
        return false;
    }
    return true;
}

void Mastermind::compareInputAndGenerateHints()
{
    int tries = 0;
    while (tries < m_maxNumOfTurns)
    {
        tries++;

        int redPegCount = 0;
        int whitePegCount = 0;
        unsigned int i;

        for (i = 0; i < m_codePegs.size(); i++)
        {
            if (m_codePegs[i] == m_guess[i])
            {
                redPegCount++;
            }
        }

        /*Find out the colours present in the current code pegs pattern*/ 
        std::set<int> coloursPresent;
        std::set<int>::iterator iter;
        for (i = 0; i < m_codePegs.size(); i++)
            if (coloursPresent.count(m_codePegs[i]) == 0)
                coloursPresent.insert(m_codePegs[i]);

        /*For each colour present, find the smallest number of times it appeared
        in  both codePegs, guess and sum them up*/
        std::set<int>::iterator colourIter;
        int color, count1, count2;
        for (colourIter = coloursPresent.begin();
            colourIter != coloursPresent.end(); ++colourIter)
        {
            color = *colourIter;
            count1 = count(m_codePegs.begin(), m_codePegs.end(), color);
            count2 = count(m_guess.begin(), m_guess.end(), color);
            if (count1 < count2)
                whitePegCount += count1;
            else
                whitePegCount += count2;
        }
        whitePegCount = whitePegCount - redPegCount;

        m_redPegCount = redPegCount;
        m_whitePegCount = whitePegCount;

        std::cout << "\t Red Pegs: " << redPegCount;
        std::cout << "\t White Pegs: " << whitePegCount;
        std::cout << "\t Tries Used: " << tries;

        if (redPegCount != m_lengthOfCodePegs && tries < m_maxNumOfTurns)
        {
           #ifdef UNIT_TEST
            tries = m_maxNumOfTurns;
            break;
           #endif
           #ifndef UNIT_TEST
           bool success = inputGuessAndValidateUntilValid();
           #endif
        }
        if (redPegCount == m_lengthOfCodePegs)
        {
            std::cout << "\nYayy, you cracked the code!! you won in tries " << tries << std::endl;
            break;
        }
        if (redPegCount != m_lengthOfCodePegs && tries == m_maxNumOfTurns)
        {
            std::cout << "\nGame over!! You have exhausted your tries " << tries << std::endl;
            std::cout << "\nThe correct code is " << m_codePegs << std::endl;
        }
    }
}

void Mastermind::resetMemberVariables()
{
    m_codePegs.clear();
    m_guess.clear();
    m_maxNumOfTurns = 0;
    m_lengthOfCodePegs = 0;
}

void Mastermind::setMaxNumOfTurns(const int maxNumOfTurns)
{
    m_maxNumOfTurns = maxNumOfTurns;
}

int Mastermind::getMaxNumOfTurns() const
{
    return m_maxNumOfTurns;
}

void Mastermind::setLengthOfCodePegs(const int lengthOfCodePegs)
{
    m_lengthOfCodePegs = lengthOfCodePegs;
}

int Mastermind::getLengthOfCodePegs() const
{
    return m_lengthOfCodePegs;
}

void Mastermind::setGuess(const std::string& guess)
{
    m_guess = guess;
}

std::string Mastermind::getGuess() const
{
    return m_guess;
}

void Mastermind::setCodePegs(const std::string& guess)
{
    m_codePegs = guess;
}
std::string Mastermind::getCodePegs() const
{
    return m_codePegs;
}

void Mastermind::setRedPegCount(const int redPegCount)
{
    m_redPegCount = redPegCount;
}
int Mastermind::getRedPegCount() const
{
    return m_redPegCount;
}

void Mastermind::setWhitePegCount(const int whitePegCount)
{
    m_whitePegCount = whitePegCount;
}
int Mastermind::getWhitePegCount() const
{
    return m_whitePegCount;
}
