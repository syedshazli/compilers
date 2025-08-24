#include <iostream>


enum class state{
    serror,
    s0, 
    s1, 
    s2, 
    s3, 
    s4, 
    s5, 
    s6
};

// these are the accepted states, but it won't be implemented
// enum class acceptedStates{
//     s1 = 1,
//     s2 = 2,
//     s3 = 3, 
//     s4 = 4, 
//     s5 = 5,
//     s6 = 6
// };

bool isAlphaNum(char currentChar)
{
   if ((currentChar >= 'a' && currentChar <= 'z') ||
       (currentChar >= '0' && currentChar <= '9') ||
       (currentChar >= 'A' && currentChar <= 'Z')) 
   {
     return true;
   } 
   else 
   {
     return false;
   }
}
// FIXME: fix the params?
state getCurrentState(char currentChar)
{
   // how do we get the current state?
   // Our states are s1-s6
   // take in the current character. 
   // If it's not a valid alphanumeric character, return error state
   // else, progress to the next state in the enum
   // the CRUX of the regex problem, so let's read about it next.
   if(!isAlphaNum(currentChar))
   {
    return state::serror;
   }
   return state::s0; // FIXME: This is a placeholder
}

// FIXME: Fix the params?
bool startRecognizer(int argc, char **argv)
{
    char currentChar = argv[1][0]; // FIXME: 1 indexed because first is the executable (I think, need to check)
    int charLength = sizeof(argv[1]);
    state myState;
    myState = state::s0;
    if(sizeof(argv[1]) > 6 || sizeof(argv[1]) == 0)
    {
        myState = state::serror;
    }
    
    int i = 0;

    while(myState != state::serror && i < 6)
    {
      myState = getCurrentState(currentChar); //FIXME: SHOULD BE IMPLEMENTED
      i +=1;
      currentChar = argv[1][i];
    }

    if(myState != state::s0 || myState != state::serror )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printSuccess(bool myReturn)
{
if(myReturn)
    {
        std::cout<<"This is a valid string for the constraints we gave you!"<<std::endl;
    }
    else
    {
        std::cout<<"This string did not follow our rules, sorry."<<std::endl;
    }
}
int main(int argc, char **argv){

    /**
     * "A recognizer to accept a six-character identifier 
     *  consisting of an alphabetic character 
     *  followed by zero to five alphanumeric characters." 
     * Usage: clang++ RecognizerExample.cpp -o recognize
     * ./recognize [STRING]
     */
    bool myReturn;
    if(argc != 2)
    {
        myReturn = false;
    }
    else
    {
        myReturn = startRecognizer(argc, argv);
    }
    
    printSuccess(myReturn);
    
}
