#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// Store word and category together
struct Word
{
    string name;
    string category;
};

// Display the word
void displayWord(string word, bool guessed[])
{
    for (int i = 0; i < word.length(); i++)
    {
        if (guessed[i] == true)
            cout << word[i] << " ";
        else
            cout << "_ ";
    }

    cout << endl;
}

// Check if all letters guessed
bool isWordGuessed(bool guessed[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (guessed[i] == false)
            return false;
    }

    return true;
}

int main()
{
    srand(time(0));

    // Word list with categories
    Word words[] =
    {
        // Animals
        {"cat", "Animal"},
        {"dog", "Animal"},
        {"lion", "Animal"},
        {"tiger", "Animal"},
        {"wolf", "Animal"},
        {"bear", "Animal"},
        {"deer", "Animal"},
        {"goat", "Animal"},
        {"rabbit", "Animal"},
        {"zebra", "Animal"},

        // Colors
        {"red", "Color"},
        {"blue", "Color"},
        {"green", "Color"},
        {"yellow", "Color"},
        {"purple", "Color"},
        {"orange", "Color"},
        {"black", "Color"},
        {"white", "Color"},
        {"pink", "Color"},
        {"brown", "Color"},

        // Countries
        {"pakistan", "Country"},
        {"india", "Country"},
        {"canada", "Country"},
        {"brazil", "Country"},
        {"china", "Country"},
        {"japan", "Country"},
        {"france", "Country"},
        {"germany", "Country"},
        {"turkey", "Country"},
        {"mexico", "Country"},

        // Fruits
        {"apple", "Fruit"},
        {"banana", "Fruit"},
        {"mango", "Fruit"},
        {"orange", "Fruit"},
        {"grapes", "Fruit"},
        {"peach", "Fruit"},
        {"melon", "Fruit"},
        {"berry", "Fruit"},
        {"lemon", "Fruit"},
        {"cherry", "Fruit"},

        // Vegetables
        {"potato", "Vegetable"},
        {"tomato", "Vegetable"},
        {"onion", "Vegetable"},
        {"carrot", "Vegetable"},
        {"cabbage", "Vegetable"},
        {"spinach", "Vegetable"},
        {"pepper", "Vegetable"},
        {"radish", "Vegetable"},
        {"garlic", "Vegetable"},
        {"turnip", "Vegetable"},

        // Sports
        {"soccer", "Sport"},
        {"tennis", "Sport"},
        {"cricket", "Sport"},
        {"hockey", "Sport"},
        {"boxing", "Sport"},
        {"golf", "Sport"},
        {"racing", "Sport"},
        {"diving", "Sport"},
        {"skating", "Sport"},
        {"baseball", "Sport"}
    };

    int totalWords = 60;

    // Pick random word
    int randomIndex = rand() % totalWords;

    string word = words[randomIndex].name;
    string category = words[randomIndex].category;

    // Track guessed letters
    bool guessed[20];

    for (int i = 0; i < word.length(); i++)
    {
        guessed[i] = false;
    }

    int attempts = 6;

    // Store wrong guesses
    char wrongGuesses[20];
    int wrongCount = 0;

    cout << "======= HANGMAN GAME =======" << endl;

    while (attempts > 0)
    {
        cout << "\nCategory: " << category << endl;

        displayWord(word, guessed);

        cout << "Attempts left: " << attempts << endl;

        // Show wrong guesses
        cout << "Wrong guesses: ";

        for (int i = 0; i < wrongCount; i++)
        {
            cout << wrongGuesses[i] << " ";
        }

        cout << endl;

        // User input
        char guess;

        cout << "Enter a letter: ";
        cin >> guess;

        guess = tolower(guess);

        // Validate input
        if (!isalpha(guess))
        {
            cout << "Please enter a valid letter!\n";
            continue;
        }

        // Check if already guessed
        bool alreadyTried = false;

        // Check wrong guesses
        for (int i = 0; i < wrongCount; i++)
        {
            if (wrongGuesses[i] == guess)
            {
                alreadyTried = true;
            }
        }

        // Check correct guesses
        for (int i = 0; i < word.length(); i++)
        {
            if (guessed[i] == true && word[i] == guess)
            {
                alreadyTried = true;
            }
        }

        if (alreadyTried == true)
        {
            cout << "You already tried that letter!\n";
            continue;
        }

        bool found = false;

        // Reveal matching letters
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == guess)
            {
                guessed[i] = true;
                found = true;
            }
        }

        // Wrong guess
        if (found == false)
        {
            attempts--;

            wrongGuesses[wrongCount] = guess;
            wrongCount++;

            cout << "Wrong guess!\n";
        }
        else
        {
            cout << "Good guess!\n";
        }

        // Win check
        if (isWordGuessed(guessed, word.length()))
        {
            cout << "\n🎉 You won!" << endl;
            cout << "The word was: " << word << endl;

            // Complexity
            cout << "\n===== COMPLEXITY ANALYSIS =====" << endl;
            cout << "Time Complexity: O(n)" << endl;
            cout << "Space Complexity: O(n)" << endl;

            return 0;
        }

        cout << "----------------------" << endl;
    }

    // Lose
    cout << "\n💀 You lost!" << endl;
    cout << "The word was: " << word << endl;

    // Complexity
    cout << "\n===== COMPLEXITY ANALYSIS =====" << endl;
    cout << "Time Complexity: O(n)" << endl;
    cout << "Space Complexity: O(n)" << endl;

    return 0;
}