#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cctype>
using std::string;
const int Num = 26;
const string wordlist[Num] = {"apiary","beetle","cereal","danger","ensjjmi","feafzfe","haalsk","iojo","jikja","kdasa","lcac","mioioj","nad","operate","queen"};
int main() {
    using std::cout;
    using std::cin;
    using std::endl;
    using std::tolower;
    std::srand(time(0));
    char play;
    cout<<"Will you play a game? <y/n>";
    cin>>play;
    play = tolower(play);
    while (play == 'y')
    {
        string target = wordlist[std::rand() % Num];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guess = 6;
        cout<<"Guess my secret world. It has "<<length<<" letters, and you guess\n"
        <<"one letter at a time. You get "<<guess<<" wrong answers.\n";
        cout<<"You world: "<<attempt <<endl;
        while (guess > 0 && attempt != target)
        {
            char letter;
            cout<<"Guess a letter: ";
            cin>>letter;
            if (badchars.find(letter) != string::npos
            || attempt.find(letter) != string::npos)
            {
                cout<<"You already guessed that. Try again!\n";
                continue;
            }
            int loc = target.find(letter);
            if (loc==string::npos)
            {
                cout<<"Bad guess.\n";
                --guess;
                badchars += letter; //add to string
            }
            else
            {
                cout<<"Good guess!\n";
                attempt[loc] = letter;
//                check if the letter appear again
                loc = target.find(letter,loc + 1);
                while (loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }
            cout<<"You world: "<<attempt<<endl;
            if (attempt != target)
            {
                if (badchars.length() > 0)
                    cout<<"Bad choices: "<<badchars<<endl;
                cout<<guess<<" bad guesses left\n";
            }
        }
        if (guess > 0)
            cout<<"That's right!\n";
        else
            cout<<"Sorry, the world is "<<target<<".\n";
        cout<<"Will you play again? <y/n>";
        cin>>play;
        play = tolower(play);
    }
    cout<<"Bye!\n";
    return 0;
}