#include <iostream>
#include <string>
#include <vector>//Dynamic array
#include <fstream>//Dynamic array
using namespace std;
//Function for drawing the title, the parts of the hang man, instruccions and spaces for the latters.
void draw(string message, bool printTop = true, bool printBottom = true){

	if(printTop){
		cout << "+---------------------------------+\n";
		cout << "|";
	}else{
		cout << "|";
	}

	bool front = true;
	for(int i = message.length(); i < 33; i++){
		if(front){
			message = " " + message;
		}else{
			message = message + " ";
		}
		front = !front;
	}
	cout << message.c_str();

	if(printBottom){
		cout << "|\n";
		cout << "+---------------------------------+\n";
	}else{
		cout << "|\n";
	}
}

void kill_the_man(int guessCount = 0){
	// The first Line will be draw if the prayer made one mistake
	if(guessCount >= 1){
		draw("|", false, false);
	}else{
		draw("", false, false);
	}
	//The second line for the second mistake
	if(guessCount >= 2){
		draw("|", false, false);
	}else{
		draw("", false, false);
	}
	//Three mistakes / The head
	if(guessCount >= 3){
		draw("0", false, false);
	}else{
		draw("", false, false);
	}
	//Four mistakes, first arm
	if(guessCount == 4){
		draw("/  ", false, false);
	}
	//Five mistakes, first arm and the body
	if(guessCount == 5){
		draw("/| ", false, false);
	}
	//Six mistakes, first arm, the body and the second arm
	if(guessCount >= 6){
		draw("/|\\", false, false);
	}else{
		draw("", false, false);
	}
	//Seven mistakes, second part of the body
	if(guessCount >= 7){
		draw("|", false, false);
	}else{
		draw("", false, false);
	}
	//Eight mistakes, the first leg
	if(guessCount == 8){
		draw("/", false, false);
	}
	//Nine mistakes, the second leg
	if(guessCount >= 9){
		draw("/ \\", false, false);
	}else{
		draw("", false, false);
	}
}

//Function to find the latters of the guess and take out the latters that are in the guess
void letters(string guessU, char from, char to){

	string s;
//algorithm to find letters and display them
	for(char i = from; i <= to; i++){
		if(guessU.find(i) == string::npos){
			s += i;
			s += " ";
		}else{
			s += "  ";
		}
	}
	draw(s, false, false);
}
//Function to display the letters
void Printletters(string used){
	draw("Available letters");
	letters(used, 'A', 'M');
	letters(used, 'N', 'Z');
}

//Function to check win
bool checkWin(string word, string guessed){
	bool won = true;
	string s;

	for(int i = 0; i < word.length(); i++){
		if(guessed.find(word[i]) == string::npos){
			won = false;
			s += "_ ";
		}else{
			s += word[i];
			s += " ";
		}
	}
	draw(s, false);
	return won;
}

//Make the game playable by the user

//Select a random word to play
/*string RandomWord(){
	int lineCount = 0;
	string word[4];
	
	for(int i = 0; i > 5; i++){
		cout << "Enter the word number " << word[i] << " \n";
		cin >> word[i];
	}
	int possibleWord = rand() % 4 + 0;
	string wordChosen = word[possibleWord];
	
	return wordChosen;
}*/
//To see the tries left of the user
int triesLeft(string word, string guessed){
	int error = 0;
    for (int i = 0; i < guessed.length(); i++)
    {
        if (word.find(guessed[i]) == string::npos){
            error++;
        }
    }
    return error;
}

int main(){

	

	string guesses;
	string wordToGuess;
	char ans;
	int tries = 0;
	bool win = false;

do{

	int lineCount = 0;
	string word[4];
	
	for(int i = 0; i > 5; i++){
		cout << "Enter the word number " << word[i] << " \n";
		cin >> word[i];
	}
	int possibleWord = rand() % 4 + 0;
	string wordChosen = word[possibleWord];


		do{
			system("clear"); //This function is going to upgrade the game in real time
			draw("HANG MAN");//Title
			kill_the_man(tries);//The hang man being drawing
			Printletters(guesses);//Letters yhe user guessed
			draw("GUESS THE WORD");//Second title 
			win = checkWin(wordChosen, guesses);

			if(win){
				break;
			}

			char x;
			cout << "> ";
			cin >> x;
			if (guesses.find(x) == string::npos){
				guesses += x;
			}

			tries = triesLeft(wordChosen, guesses);

		}while(tries < 10);

		if(win){
			draw("You WON!!!!!");
			cout << "Do you want to play again? Y/N \n";
			cin >> ans;
		}else{
			draw("GAME OVER");
			cout << "Do you want to play again? Y/N \n";
			cin >> ans;
		}

		getchar();
	}while(ans == 'y' || ans == 'Y');
	return 0;
}