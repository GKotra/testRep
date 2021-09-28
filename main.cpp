#include <iostream>
#include "Mastermind.h"

int main()
{
	std::cout << " Welcome to MASTERMIND!!" << std::endl;
	std::cout << " The computer has chosen a 4 character sequence of colours representing 4 pegs\n";
	std::cout << " You have 8 chances to guess the pegs chosen by computer \n";
	std::cout << " For every guess, you get hints in the form of number of red and white key pegs \n";
	std::cout << " Red key pegs indicates presence of exact matching pegs both colour and position \n";
	std::cout << " White key pegs indicates presence of correct colour pegs but at the wrong position) \n";
	std::cout << " Go forward and guess the 4 pegs from the given colour palette\n";
	std::cout << " R - for Ruby\n";
	std::cout << " A - for Amber\n";
	std::cout << " N - for Neon\n";
	std::cout << " D - for Denim blue\n";
	std::cout << " O - for Orange\n";
	std::cout << " M - for Magenta\n";

	Mastermind m(4, 8);
	m.startGame();
	return 0;
}
