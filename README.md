# CSCI-103-Project-2-Twenty-One
In this assignment you will use write program to implement the basic rules of the card game, Twenty-One (aka Blackjack). This program will require you to utilize the following knowledge and skills: for and while loops, conditionals, arrays and passing arguments.

The game of Twenty-One is a popular card game that can have many players
competing against a dealer. In our version, we will only allow ONE player vs. the
dealer. While this game usually contains betting, we will leave out that aspect
and just focus on implementing the rules of play and determining the winner. 

Shuffling: For each new hand, you should initialize the deck of 52 cards to have
values 0-51 in that order (i.e. cards[i] = i;) and then shuffle that deck using the
Fisher-Yates / Durstenfeld shuffle algorithm (shown below) so that we all get the
same card ordering:
// To shuffle an array a of n elements (indices 0..n-1):
for i from n−1 downto 1 do
 j ← random integer such that 0 ≤ j ≤ i
 (i.e. use a modulus operation on the random number)
 exchange a[j] and a[i]
As a check to ensure you are shuffling correctly, if you were to seed the random
number generator with a value of 37 (which is the seed used in the first sample
run shown below) and then printed out the contents of the deck after shuffling
(for debug purposes), then they should be:
6 14 2 39 24 23 32 4 12 49 27 36 21 42 10 8 38 51 46 47 22 5 37 41 16 15
43 40 3 31 44 34 17 18 9 26 1 35 19 11 30 48 13 20 25 33 29 28 0 45 50 7
2. Initially, the dealer's first card should not be shown to the user. Instead display a
?.
3. The player should be presented with the choice to type h to hit or s to stay.
However, if the player has 21 from the initial 2 cards of their hand, the dealer
should immediately start playing (i.e. no choice should be given to the player to
hold or stay).Also, any character other than h or s should cause the program to
immediately quit.
CS 103 Lab - TwentyOne
4 Last Revised: 8/19/2018
4. You must generate the following output based on the results of the game:
o Output Player busts on a separate line if the player goes over 21 OR
output Dealer busts on a separate line if the dealer goes over 21.
o Also, output Win, Tie, or Lose indicating if the player won, tied, or lost to
the dealer, respectively, followed the player score and the dealer score
separate by a space (all on one line).
5. When the hand ends the player should be allowed to play again (without
restarting the program or re-seeding the random number generator) by typing y
to play another hand or n to quit. If the user types any character other than y
the program should immediately quit.
6. Playing another hand should cause the deck to be reinitialized to 0-51 (i.e.
cards[i] = i;) and then shuffled (but do NOT re-seed the random number
generator...just start again by calling shuffle().)
7. If the player busts, the dealer does not play and the desired output should be
displayed. 

In the output of the game, you will see:
1. Show the cards in the proper format (e.g. 9-H, J-C, A-D
2. Show the Player busts, Dealer busts, and Win/Tie/Lose player-score dealer-score messages. These outputs are shown in
italics on the sample runs below
