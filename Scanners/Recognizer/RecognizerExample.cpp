#include <iostream>


enum class state{
    s0, 
    s1, 
    s2, 
    s3, 
    s4, 
    s5, 
    s6, 
    serror
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

// fix the params
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
    // CHECK IF CHARACTER ISNT LAST CHARACTER
    while(myState != state::serror)
    {
      myState = getCurrentState(); //FIXME: SHOULD BE IMPLEMENTED
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
int main(int argc, char **argv){

    /**
     * "A recognizer to accept a six-character identifier 
     *  consisting of an alphabetic character 
     *  followed by zero to five alphanumeric characters." 
     */

    return startRecognizer(argc, argv);
    
}

state getCurrentState()
{

}