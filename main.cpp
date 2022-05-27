#include <iostream>// cout cin
#include <string>// string
#include <vector>// vectors
#include <ctime>// get srand
#include <stdio.h> // getChar
#include <unistd.h> // getChar system("stty raw");
#include <chrono> // for time
#include <cmath> // for rounding
using namespace std;
// takes the string sentence and put into a vector {"Words","words","more"}
// the string str = sentence; the string toke = " "; space, that's what it uses to know when to break apart each word. When it finds a space, it break it apart
vector<string> split(string str, string token){
    vector<string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}
// changes strings into characters
vector<char> StringToChar(string s){
  vector<char> ch(s.begin(),s.end());
  return ch; 
}
// prints the sentence
void Print(vector<char> ch, vector<int> co){
 for(int i=0;i<ch.size();i++) {
   //"\u001b[38;2;22;255;255m;"
   for(int j=0;j<1;j++){
     switch(co[i]){
       case 1:
        cout << "\u001b[38;2;255;000;000m";
        cout << ch.at(i);
        break;
       case 2:
        cout << "\u001b[38;2;000;255;000m";
        cout << ch.at(i);
       break;
       default:
        cout << "\u001b[38;2;255;255;255m";
        cout << ch.at(i);
       }
    }
  }
}
// main function
int main () {
  srand(time(0)); // for random
  // ArraySentence is the possible sentence you would be typing
  vector<string> ArraySentence = {"A friend to all is a friend to none.","Every art and every inquiry, and likewise every action and choice, seems to aim at some good, hence it has been beutifully said, that the good is that at which all things aim.","All human beings, by nature, desire to know.","Anybody can become angry, that is easy, but to be angry with the right person and to the right degree and at the right time and for the right purpose, and in the right way, that is not within everybody's power and is not easy.","Excellence is an art won by training and habituation. We do not act rightly because we have virtue or excellence, but we rather have those because we have acted rightly. We are what we repeatedly do. Excellence, then, is not an act but a habit.","Excellence is never an accident. It is always the result of high intention, sincere effort, and intelligent execution; it represents the wise choice of many alternatives, choice, not chance, determines your destiny.","Friends hold a mirror up to each other; through that mirror they can see each other in ways that would not otherwise be accessible to them, and it is this mirroring that helps them improve themselves as persons","I count him braver who overcomes his desires than him who conquers his enemies; for the hardest victory is over self.","I have gained this by philosophy that I do without being commanded what others do only from fear of the law.","Men acquire particular quality by constantly acting in a particular way.","Perfect friendship is the friendship of men who are good, and alike in excellence; for these wish well alike to each other qua good, and they are good in themselves.","Teenagers these days are out of control. They eat like pigs, they are disrespectful of adults, they interrupt and contradict their parents, and they terrorize their teachers.","The aim of art is to represent not the outward appearance of things, but their inward significance.","The difference between a learned man and an ignorant one is the same as that between a living man and a corpse.","A man who has a why, can bare with any how."};
  // sentence
  string sentence = ArraySentence.at(rand() % ArraySentence.size());
  vector<string> cutSentence = split(sentence," ");
  
 //string sentence = "I am good.";
  // main vectors
  vector<char> Char_Sentence = StringToChar(sentence);
  vector<char> Char_SentenceTyped; 
  vector<char> Char_SentenceTypedAll; 
  vector<int> color; 
  // adds 0 which means no color
  while(color.size() != Char_Sentence.size()){
    color.push_back(0); 
  }
  // for the console input
  system("stty raw");
  int i = 0;
  // timer start. gets the system clock time and puts it in variable start
  auto start = chrono::system_clock::now();
  // main loop
  while(Char_SentenceTyped.size() != Char_Sentence.size()){
    cout << endl << endl;
    // prints the sentence
    Print(Char_Sentence,color);
    cout << endl<<":";
    // gets the input whenever you type a character
  	char input = getchar(); 
    Char_SentenceTypedAll.push_back(input); // push all typed
    // checks if the input if it's correct
    if(input == Char_Sentence.at(i)){
      color.at(i) = 2;// printing green 
      // push all that is correct
      Char_SentenceTyped.push_back(input);
      i++;
    } 
    else{
      color.at(i) = 1; // When wrong, it adds 1, printing red
    }
    // Clears the screen
    system("clear");
  }
  // Finds the new time. Gets the new system time and puts into end
    auto end = chrono::system_clock::now();
  // Finds how many times you pressed the wrong key
  int howManyWrong = Char_SentenceTypedAll.size() - Char_Sentence.size();
  // Finds the time. Subtracts endtime with start time
  chrono::duration<double> elapsed_seconds = end - start;
  // finds words per minutes
  double WPM = (cutSentence.size()) / (elapsed_seconds.count()/60);
  // print the words per minute and rounds down
  cout << endl<<lround(WPM)<< "WPM";
 // calls the main function again 
  main();
}
// Thanks have fun typing