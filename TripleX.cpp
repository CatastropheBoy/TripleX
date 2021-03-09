#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
//     std::cout << """
//            _ ._  _ , _ ._
//         (_ ' ( `  )_  .__)
//       ( (  (    )   `)  ) _)
//      (__ (_   (_ . _) _) ,__)
//          `~~`\\ ' . /`~~`
//               ;   ;
//               /   \\
// _____________/_ __ \\_____________""";
    std::cout << "\n\nA hacker has sabotaged reactor " << Difficulty;
    std::cout << " causing it to go critical.\nYou must break the hacker's codes to shut off the reactor and avert a total meltdown...\n\n";
}


bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare 3 numbers
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int Codec = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + Codec;
    const int CodeProduct = CodeA * CodeB * Codec;

    // Print sum and product to console
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "\n+ The codes add up to: " << CodeSum << std::endl;
    std::cout << "\n+ The codes multiply to give : " << CodeProduct << std::endl;

    // Store player guesses
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nCorrect! Move on to the next challenge.\n";
        return true;
    }

    else
    {
        std::cout << "\nThat isn't right...";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // Creates new random seed based on time of day
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loops game until all challenges are complete
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }        
    }
    std::cout << "You win!";

    return 0;
}
