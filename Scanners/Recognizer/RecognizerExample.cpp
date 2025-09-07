#include <iostream>
#include <string>

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

state getCurrentState(char currentChar, state currentState)
{
   
   if(!isAlphaNum(currentChar))
   {
    return state::serror;
   }

   return state::s0; // FIXME: This is a placeholder. We still have not progressed to next state in the enum
   // FIXME: ALSO add the new way to do FA's, which is sort of loop based or can accept different words
}


bool startRecognizer(std::string inputString)
{

    state myState;
    myState = state::s0;
    
    int i = 0;

    while(myState != state::serror && i < inputString.size())
    {
      myState = getCurrentState(inputString[i], myState); //FIXME: SHOULD BE IMPLEMENTED
      if(myState == state::serror)
      {
        return false;
      }
      i +=1;

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


bool convertArgvToString(char **argv, std::string &resultingString)
{

resultingString = std::string(argv[1]);

if (resultingString.length() > 6 || resultingString.length() == 0)
{
    return false;
}
return true;
}
int main(int argc, char **argv){

    /**
     * "A recognizer to accept a six-character identifier 
     *  consisting of an alphabetic character 
     *  followed by zero to five alphanumeric characters." 
     * Usage: clang++ RecognizerExample.cpp -o recognize
     * ./recognize [1-6 LETTER STRING]
     */
    bool myReturn;
    std::string inputString;

    if(argc != 2 || !convertArgvToString(argv, inputString))
    {
        
        myReturn = false;
    }
    else
    {

        // failing on the startRecognizer function
        myReturn = startRecognizer(inputString);
    }
    
    printSuccess(myReturn);
    
}
