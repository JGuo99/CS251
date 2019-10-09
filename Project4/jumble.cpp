/*
* Version 3.2
* Last Edit: 4/22/19
* Jeff Guo
*/
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void ssort(std::string &s) {
  //from freq.cpp
  std::sort(s.begin(), s.end());
}
/*
*   usage:   ./freq <filename>
*
*   example:  ./freq words.txt
*/
int main(int argc, char *argv[]){
  /*
     the variable jumHash is an unordered_map
        from strings to vector<string>.
  */
  std::unordered_map<std::string, vector<string>> jumHash;
  std::ifstream file;
  std::string word;

  if(argc != 2) {
    std::cout << "usage:  ./jumble <filename>\n";
    std::cout << "goodbye\n";
    return 1;
  }
  /*
  *  argv[1] is a C-string which is the filname specified
  *    by the user.  Let's try to open it.
  */
  file.open(argv[1], std::ios::in);

  if(!file.is_open()){
    std::cout << "Error: could not open file '" <<
                     argv[1] << "'\n";
    std::cout << "goodbye\n";
    return 1;
  }

  int numWords = 0;

  std::cout << "reading input file...\n";

  while(file >> word) {
    // file >> word;
    // Sort word
    string sorted = word;
    ssort(sorted);

    if(jumHash.count(sorted) == 0){
       jumHash[sorted].push_back(word);
     }else{
       jumHash[sorted].push_back(word);
    }

    numWords++;
  }

  std::cout <<
    "start entering jumbled words\n";
  std::cout <<
    "  when you are done, type ctrl-d (ctrl-z on windows)\n\n";
  std::cout << "> ";

  while(std::cin >> word){
    string sorted = word;
    ssort(sorted);

    if(jumHash.count(sorted) == 0){
       std::cout << "sorry no anagrams found ... try again " << endl;
    }else{
       std::cout << "English Anagrams Found: " << endl;

       for(int i = 0; i < jumHash[sorted].size(); i++ ){
           std::cout << jumHash[sorted][i] << endl;
       }
    }
  std::cout << "> ";
  }
  // user has quit.  Let's dump the map contents

  cout << "REPORT:" << endl;
  cout << "num_words    :  " << numWords << endl;
  cout << "num_classes  :  " << jumHash.size() << endl;

  int largestClassSize = -1;
  string largestClassKey;
  for(std::pair<std::string, vector<string>> entry : jumHash){
      int thisSize = entry.second.size();
      if (thisSize > largestClassSize ){
         largestClassSize = entry.second.size();
         largestClassKey = entry.first;
      }
  }
  cout << endl;
  cout << "size-of-largest-class   : " << largestClassSize << endl;
  cout << "largest-class key       : " << "'" << largestClassKey << "'" << endl;
  cout << "members of largest class:" << endl;
  for(int i = 0; i < jumHash[largestClassKey].size(); i++ ){
    cout << "\t" << "'" << jumHash[largestClassKey][i] << "'" << endl;
  }

#if 0
  if(0){
  std::cout << "jumHash contents:\n\n";

  printf("      WORD              #OCCURRENCES\n");
  printf("------------------------------------------\n\n");

  for(std::pair<std::string, int> entry : jumHash){
     printf("  %10s     %10d\n", entry.first.c_str(), entry.second);
  }
  }
#endif

  return 0;
}
