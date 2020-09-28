/*******************************************************************************
 * CS 103 Twenty-One (Blackjack) PA
 * Name: Maya Ramde
 * USC email: ramde@usc.edu
 * Comments (you want us to know):
 *
 *
 ******************************************************************************/

// Add other #includes if you need
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Prototypes */
void shuffle(int cards[]);
void printCard(int id);
int cardValue(int id);
void printHand(int hand[], int numCards);
int getBestScore(int hand[], int numCards);

const int NUM_CARDS = 52;

/**
 * Global arrays to be used as look-up tables, if desired.
 * It is up to you if and how you want to use these 
 */
const char suit[4] = {'H','S','D','C'};
const char* type[13] = 
  {"2","3","4","5","6","7",
   "8","9","10","J","Q","K","A"};
const int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

/**
 * Should permute the deck of cards, effectively shuffling it.
 * You must use the Fisher-Yates / Durstenfeld shuffle algorithm
 *  described in the assignment writeup.
 */
void shuffle(int cards[])
{
  /******** You complete ****************/
    
    // Initialize deck to have values 0-51 in that order.
    for (int n = 0; n < 52 ; n++) {
        cards[n] = n;
    }
    
    // Shuffle the new hand using Fisher-Yates algorithm
    for (int i = 51; i > 0; i--) {
        int j = rand() % (i+1);
        int hold = cards[j];
        cards[j] = cards[i];
        cards[i] = hold;
    }

}

/**
 * Prints the card in a "pretty" format:   "type-suit"
 *  Examples:  K-C  (King of clubs), 2-H (2 of hearts)
 *  Valid Types are: 2,3,4,5,6,7,8,9,10,J,Q,K,A
 *  Valid Suits are: H, D, C, S
 */
void printCard(int id)
{
  /******** You complete ****************/
    
    // Isolate first 13 cards since they're in the H suit and assign type
    if (id < 13) {
        cout << type[id] << "-" << suit[0];

    } else if (id < 26) {
        // Isolate second 13 cards since they're in the H suit and assign type
        cout << type[id-13] << "-" << suit[1];

    } else if (id < 39) {
        // Isolate third 13 cards since they're in the H suit and assign type
        cout << type[id-26] << "-" << suit[2];

    } else {
        // Isolate fourth 13 cards since they're in the H suit and assign type
        cout << type[id-39] << "-" << suit[3];       
    }


}

/**
 * Returns the numeric value of the card.
 *  Should return 11 for an ACE and can then
 *  be adjusted externally based on the sum of the score.
 */
int cardValue(int id)
{
  /******** You complete ****************/
    // Based on the card id, assign its value and return the number
    // Divide id #s into four groups to separate the suits.
    if (id < 13) {
        return value[id];

    } else if (id < 26) {
        return value[id-13];

    } else if (id < 39) {
        return value[id-26];

    } else {
        return value[id-39];       
    }
}

/**
 * Should print out each card in the hand separated by a space and
 * then print a newline at the end.  
 * Should use printCard() to print out each card.
 */
void printHand(int hand[], int numCards)
{
  /******** You complete ****************/
    /* Output each card (include type and suit) with a space in between each card*/
    for(int i = 0; i < numCards; i++) {
        printCard(hand[i]);
        cout << " ";
    }
    cout << endl;


}

/**
 * Should return the total score of the provided hand.  
 * ACES should be treated as 11s to make the highest possible hand
 *  and only being reduced to 1s as needed to avoid busting.
 */
int getBestScore(int hand[], int numCards)
{
  /******** You complete ****************/
    int score = 0;
    int aceCount = 0;
        
    for (int i = 0; i < numCards; i++) {
        
        /* if the card has a value of 11, then it's an ace and we increase the ace count*/
        if(cardValue(hand[i]) == 11) {
            aceCount++;
        }
        score += cardValue(hand[i]);
    }
    /* if the aces in the hand cause the score to go over 21, then assign the ace a value of 1 */
    if (aceCount == 1 && score > 21) {
        score -= 10;
    } else if (aceCount > 1 && score > 21) {
        score -= (aceCount-1)*10; 
    } 
    
    return score;
}

/**
 * Main program logic for the game of 21
 */
int main(int argc, char* argv[])
{
  //---------------------------------------
  // Do not change this code -- Begin
  //---------------------------------------
  if(argc < 2){
    cout << "Error - Please provide the seed value." << endl;
    return 1;
  }
  int seed = atoi(argv[1]);
  srand(seed);

  int cards[52];
  int dhand[9];
  int phand[9];
  //---------------------------------------
  // Do not change this code -- End
  //---------------------------------------

  /******** You complete ****************/
    
    bool newGame = true;
    
    while (newGame == true) {
        // Initialize new hand of cards
        shuffle(cards);
        
        // Track card counts with variables
        int pCount = 2;
        int dCount = 2;
        int cardCount = 4;
        
        char action;
        bool stay = false;
        bool stop = false;
        
        // Assign the player's and dealer's initial hand
        phand[0] = cards[0];
        dhand[0] = cards[1];
        phand[1] = cards[2];
        dhand[1] = cards[3];
        
        // Show first round
        cout << "Dealer: ? ";
        printCard(dhand[1]);
        cout << endl;
        cout << "Player: ";
        printHand(phand, pCount);
        int dealerScore = getBestScore(dhand, dCount);
        
        int playerScore = getBestScore(phand, pCount);
        
        /* If the player has a score below 21 and he/she hits, deal the player another card */
        while (playerScore < 21 || stop == true) {
            
            // Output prompt for user's actions
            cout << "Type 'h' to hit or 's' to stay" << endl;
            
            cin >> action;
            // If the player stays, then exit the loop and calculate scores
            if (action == 's') {
                stay = true;
                stop = true;
                break;
            } else if (action == 'h') { 
                
            } else {
                break;
            }
            
            // Deal player new card and update card counts
            phand[pCount] = cards[cardCount];
            cardCount++;
            pCount++;
            
            // Display updated player hand
            cout << "Player : ";
            printHand(phand, pCount);
            
            // Calclulate player's updated score
            playerScore = getBestScore(phand, pCount);
            
        }
        // Calculate dealer's score
        dealerScore = getBestScore(dhand, dCount);
        
        // If the player hits and their new score is above 21, check who won
        if (playerScore > 21) {
            cout << "Player busts" << endl;
            cout << "Lose " << playerScore << " " << dealerScore << endl;
        } else if (stay == true && playerScore <= 21) {
            // If the player stayed, calculate who won
            
            /* if the dealer's score is below 17, have dealer take more cards until their score is 17 */
            while (dealerScore < 17) {
                dhand[dCount] = cards[cardCount];
                dCount++;
                cardCount++;
                dealerScore = getBestScore(dhand, dCount);
            }
            cout << "Dealer: ";
            printHand(dhand, dCount);
            
            // Calculate scores and winner
            if (dealerScore > 21) {
                cout << "Dealer busts" << endl;
                cout << "Win " << playerScore << " " << dealerScore;
            } else if (dealerScore > playerScore) {
                cout << "Lose " << playerScore << " " << dealerScore;
            } else if (dealerScore == playerScore) {
                cout << "Tie " << playerScore << " " << dealerScore;
            } else {
                cout << "Win " << playerScore << " " << dealerScore;
            }
             
        } else if (playerScore == 21) {
            while (dealerScore < 17) {
                dhand[dCount] = cards[cardCount];
                dCount++;
                cardCount++;
                dealerScore = getBestScore(dhand, dCount);
            }
            if (dealerScore != 21) {
                cout << "Win " << playerScore << " " << dealerScore;
            } else {
                cout << "Tie " << playerScore << " " << dealerScore;
            }
        }
        
        
        // Ask if user wants to play again
        cout << endl;
        cout << "Play again? [y/n]" << endl;
        char answer;
        cin >> answer;
        if (answer != 'y') {
            newGame = false;
        }
    }
   
  return 0;
}
