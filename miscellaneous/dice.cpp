#include <iostream>
#include <vector>

int count = 0;

void rollDiceRec(const std::vector<int> &faces, std::vector<int> &currentCombination, int diceIndex)
{
	if (diceIndex == faces.size())
	{
		std::cout << "Combination number " << ++count << ": ";
		for (int number : currentCombination)
		{
			std::cout << number << " ";
		}
		std::cout << std::endl;
		return;
	}

	for (int face = 1; face <= faces[diceIndex]; face++)
	{
		currentCombination[diceIndex] = face;
		rollDiceRec(faces, currentCombination, diceIndex + 1);
	}
}

void rollDice(const std::vector<int> &faces)
{
	std::vector<int> currentCombination(faces.size());
	rollDiceRec(faces, currentCombination, 0);
}

int main()
{
	std::cout << "Enter the amount of dice: ";
	int diceAmount;
	std::cin >> diceAmount;

	std::vector<int> diceFaces(diceAmount);
	std::cout << "Enter the amount of faces for each dice:\n";
	for (int i = 0; i < diceAmount; i++)
	{
		std::cout << "Dice #" << i + 1 << ": ";
		std::cin >> diceFaces[i];
	}

	rollDice(diceFaces);

	return 0;
}
