#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

// Function of the title of the game
void title() {
  cout << "\n============================================================================================";
  cout << "\n     CCCCC         A          SSSSSSSSS      IIIIIIIII      NN       NN       OOOOOOOO    ";
  cout << "\n   CC            A   A        SS                III         NN N     NN      OO      OO   ";
  cout << "\n  CC            A     A       SSSSSSSSS         III         NN   N   NN      OO      OO   ";
  cout << "\n   CC          AAAAAAAAA             SS         III         NN     N NN      OO      OO   ";
  cout << "\n     CCCCC    A         A     SSSSSSSSS      IIIIIIIII      NN       NN       OOOOOOOO    ";
  cout << "\n============================================================================================\n";
}

// Function of the rules of the game
void rules() {
  cout << "=======================================================================================================================" << endl;
  cout << "Rules:" << endl;
  cout << endl;
  cout << "1: The player must deposit any amount that the player desires to start the game." << endl;
  cout << endl;
  cout << "2: The player must guess a number between 1 to 10." << endl;
  cout << endl;
  cout << "3: If the player's guess number matches the winning number, then the player wins and gets 10 times of his bet amount." << endl;
  cout << endl;
  cout << "4: If the player's guess number doesn't match the winning number, then the player loses and loses his bet amount." << endl;
  cout << "=======================================================================================================================" << endl;
}

// Function of the casino random number generator game
int casinoGame () {
  int randomNumber = 0;
  srand (time(NULL));
  // Generates a random number from 1 to 10
  randomNumber = rand() % 10 + 1;
  return randomNumber;
}

// Function of checking the user's guess number and the winning number, and showing the result to the user
int checkResult (int guessNumber, int randomNumber, int deposit, 
string name) {
  int moneyResult = 0;
  // Switch case to display the winning number
  cout << "Casino Board:" << endl;
  switch(randomNumber) {
    case 1:
      cout << "===========================================================" << endl;
      cout << "|W| - |2| - |3| - |4| - |5| - |6| - |7| - |8| - |9| - |10|" << endl;
      cout << "===========================================================" << endl;
    break;

    case 2:
      cout << "===========================================================" << endl;
      cout << "|1| - |W| - |3| - |4| - |5| - |6| - |7| - |8| - |9| - |10|" << endl;
      cout << "===========================================================" << endl;
    break;

    case 3:
      cout << "===========================================================" << endl;
      cout << "|1| - |2| - |W| - |4| - |5| - |6| - |7| - |8| - |9| - |10|" << endl;
      cout << "===========================================================" << endl;
    break;

    case 4:
      cout << "===========================================================" << endl;
      cout << "|1| - |2| - |3| - |W| - |5| - |6| - |7| - |8| - |9| - |10|" << endl;
      cout << "===========================================================" << endl;
    break;

    case 5:
      cout << "===========================================================" << endl;
      cout << "|1| - |2| - |3| - |4| - |W| - |6| - |7| - |8| - |9| - |10|" << endl;
      cout << "===========================================================" << endl;
    break;

    case 6:
      cout << "===========================================================" << endl;
      cout << "|1| - |2| - |3| - |4| - |5| - |W| - |7| - |8| - |9| - |10|" << endl;
      cout << "===========================================================" << endl;
    break;

    case 7:
      cout << "===========================================================" << endl;
      cout << "|1| - |2| - |3| - |4| - |5| - |6| - |W| - |8| - |9| - |10|" << endl;
      cout << "===========================================================" << endl;
    break;

    case 8:
      cout << "===========================================================" << endl;
      cout << "|1| - |2| - |3| - |4| - |5| - |6| - |7| - |W| - |9| - |10|" << endl;
      cout << "===========================================================" << endl;
    break;

    case 9:
      cout << "===========================================================" << endl;
      cout << "|1| - |2| - |3| - |4| - |5| - |6| - |7| - |8| - |W| - |10|" << endl;
      cout << "===========================================================" << endl;
    break;

    case 10:
      cout << "===========================================================" << endl;
      cout << "|1| - |2| - |3| - |4| - |5| - |6| - |7| - |8| - |9| - |W|" << endl;
      cout << "===========================================================" << endl;
    break;
  }
  cout << endl;
  // Checks if the user's guess number is equal to the winning number
  if(guessNumber == randomNumber){
    // The user wins and gets 10 times of his bet amount
    moneyResult = deposit * 10;
    cout << name << " wins " << "$" << moneyResult << "." << endl;
  } else {
    // The user loses and loses his bet amount
    moneyResult = deposit * -1;
    cout << "Sorry " << name << ". You lost the bet! " << "-$" << moneyResult*-1 << endl;
  }
  cout << endl;
  return moneyResult;
}

int main() {
  // Available Balance variable
  int availableBalance = 100000;
  
  // Deposit variable
  int deposit = 0;

  // User Guessing Number variable
  int userGuessingNumber = 0;

  // Result Number variable
  int resultNumber = 0;

  // Result Money Variable
  int resultMoney = 0;

  // Player Name variable
  string playerName = "";

  // User Choice variable
  char userChoice = '\0';
  
  // Title
  title();
  cout << endl;

  // Rules
  rules();
  cout << endl;

  // Asking the user name to enter the game
  cout << "Enter your name to enter the game: ";
  cin >> playerName;
  cout << endl;


  cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
  cout << endl;

  // While loop with always true condition to make the game to continue on, until the user wants to stop playing
  while(1){
    cout << "Available Balance: $" << availableBalance << endl;
    cout << endl;
    
    // Asking the user for deposit input to bet
    cout << "Enter the deposit amount to bet: $";

    // Checking if the user's deposit input is valid or not
    while(!(cin >> deposit) || deposit > availableBalance){
      cin.clear();
      cin.ignore(123, '\n');
      cout << endl;
      cout << "Invalid Input! Try Again!" << endl;
      cout << endl;
      cout << "Enter the deposit amount to bet: $";
    }
    cout << endl;

    // Asking the user for guessing number input
    cout << "Casino Board:" << endl;
    cout << "===========================================================" << endl;
    cout << "|1| - |2| - |3| - |4| - |5| - |6| - |7| - |8| - |9| - |10|" << endl;
    cout << "===========================================================" << endl;
    cout << endl;
    cout << "Enter your guess number from 1 to 10: ";

    // Checking if the user's guessing number input is valid or not
    while(!(cin >> userGuessingNumber) || (userGuessingNumber < 1) || (userGuessingNumber > 10)){
      cin.clear();
      cin.ignore(123, '\n');
      cout << endl;
      cout << "Invalid Input! Try Again!" << endl;
      cout << endl;
      cout << "Enter your guess number from 1 to 10: ";
    }
    cout << endl;

    resultNumber = casinoGame();
    
    cout << "The Winning Number: " << casinoGame() << endl;
    cout << endl;

    resultMoney = checkResult(userGuessingNumber, resultNumber, deposit, playerName);

    // Calculating the new balance
    availableBalance += resultMoney;

    cout << "Available Balance: $" << availableBalance << endl;
    cout << endl;

    // Asking the user's input whether the user wants to continue playing or not
    cout << "Do you want to continue playing? (Y/y (yes) or N/n (no)): ";
    cin >> userChoice;
    cout << endl;

    // Checking if the user's choice input is valid or not
    while(userChoice != 'Y' && userChoice != 'y' && userChoice != 'N' && userChoice != 'n'){
      cout << "Invalid Input! Try Again!" << endl;
      cout << endl;
      cout << "Do you want to continue playing? (Y/y (yes) or N/n (no)): ";
      cin >> userChoice;
      cout << endl;
    }

    // The if conditions check user choice input whether the user want to continue playing or not
    if(userChoice == 'Y' || userChoice == 'y'){
      if(availableBalance <= 0){
        // This leaves the game because the user has no money left
        cout << "Sorry you don't have money to play the game" << endl;
        cout << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        break;
      }
      // This continues the game
      cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
      cout << endl;
      continue;
    } else {
      // This leaves the game
      cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
      cout << endl;
      break;
    }
  }
  // Goodbye message
  cout << "==============================" << endl;
  cout << "See Ya! Thank you for playing!" << endl;
  cout << "==============================" << endl;
}