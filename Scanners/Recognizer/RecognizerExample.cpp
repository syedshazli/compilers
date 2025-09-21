#include <iostream>
#include <string>
#include <set>



enum class state : int{
    serror,
    s0, 
    sDigitOrAlpha,
    sEnd
};

state operator++(state& currentState, int)
{
    int convNum = static_cast<int>(currentState);
    ++convNum;
    currentState = static_cast<state>(convNum);
    return currentState;
}



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
bool isAlphabetic(char currentChar)
{
    if ((currentChar >= 'a' && currentChar <= 'z') ||
        (currentChar >= 'A' && currentChar <= 'Z')) 
    {
        return true;
    }
    else
    {
        return false;
    }
}
state checkCurrentState(char currentChar, state currentState, int i)
{
   
   if(!isAlphaNum(currentChar))
   {
    return state::serror;
   }
   else if (i == 0 && !isAlphabetic(currentChar))
   {
        return state::serror;
   }

   return currentState;
}



bool checkAcceptedState(state currentState, std::set<state> acceptedStates)
{
    if (acceptedStates.find(currentState) != acceptedStates.end() )
    {
        return true;
    }
    return false;
}

bool startRecognizer(std::string inputString)
{
    std::set<state> acceptedStates = {state::sEnd};

    state myState;
    myState = state::s0;
    
    int i = 0;

    while(myState != state::serror && i < inputString.size())
    {

      myState = checkCurrentState(inputString[i], myState, i);
      if(myState == state::serror)
      {
        return false;
      }
      if (i == 0 && i != inputString.size()-1)
      {
      myState++;
      }
      else if (i == inputString.size()-1)
      {
        myState = state::sEnd;
      }
      i +=1;

    }

    if(checkAcceptedState(myState, acceptedStates))
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
