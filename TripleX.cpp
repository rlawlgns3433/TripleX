#include <iostream>
#include <ctime>
using namespace std;

void PrintIntroduction(int Difficulty){
    cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    cout << " secure server room...\nEnter thecorrect code to continue...\n\n";
}

bool PlayGame(int Difficulty){

    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty; // rand() returns a value in the range 0 and 32767
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    cout << "There are 3 numbers in the code";
    cout << "\n +The condes add-up to : " << CodeSum;
    cout << "\n +The codes multiply to give : "<<CodeProduct << endl;

    // Store player guess
    int GuessA, GuessB , GuessC;
    cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //check if the players guess is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
        return true;
    }
    else
    {
        cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
        return false;
    }

}

int main()
{
    srand(time(NULL)); // create new random sequence based on time of day
    int LevelDifficulty = 1;
    int const MaxDifficulty = 7; 
    while(LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear(); // clears any errors
        cin.ignore(); // discards the buffer

        if (bLevelComplete)
        {
            //increase the level difficulty
            ++LevelDifficulty;
        }
        
    }
    cout << "\n*** Great work agent! YOu got all the files! Now get out of there! ***\n";
    return 0;
}
