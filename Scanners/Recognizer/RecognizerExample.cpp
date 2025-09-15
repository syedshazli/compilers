#include <iostream>
#include <string>
#include <vector>
enum class state : int{
    serror,
    s0, 
    s1, 
    s2, 
    s3, 
    s4, 
    s5, 
    s6
};

state operator++(state& currentState, int)
{
    int convNum = static_cast<int>(currentState);
    ++convNum;
    currentState = static_cast<state>(convNum);
    return currentState;
}

// these are the accepted states
//     s1 = 1,
//     s2 = 2,
//     s3 = 3, 
//     s4 = 4, 
//     s5 = 5,
//     s6 = 6

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

state checkCurrentState(char currentChar, state currentState)
{
   
   if(!isAlphaNum(currentChar))
   {
    return state::serror;
   }

   return currentState; // FIXME: This is a placeholder. We still have not progressed to next state in the enum
}

// This function is the meat and potatoes of it all.
// given the current state, the input string, the current index:
// Go to the next state in the enum
state goToNextState(state currentState, std::vector<state> totalStates)
{
    return currentState++;
}

// given the current state, check if this is an accepted state
// return true if yes, false if not
bool checkAcceptedState(state currentState, std::vector<state> acceptedStates)
{
    
}
bool startRecognizer(std::string inputString)
{
    std::vector<state> acceptedStates = {state::s1, state::s2, state::s3, state::s4, state::s5, state::s6};
    std::vector<state> totalStates = {state::serror, state::s0, state::s1, state::s2, state::s3, state::s4, state::s5, state::s6};
    state myState;
    myState = state::s0;
    
    int i = 0;

    while(myState != state::serror && i < inputString.size())
    {

      myState = checkCurrentState(inputString[i], myState);
      if(myState == state::serror)
      {
        return false;
      }
      // check accepted states if we're at the last character
       if (i == inputString.size() - 1)
       {
        return checkAcceptedState(myState, acceptedStates);
       }
       // otherwise, move on to the next state in the enum
       goToNextState(myState, totalStates);
       
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
