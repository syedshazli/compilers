#include <iostream>

enum state{
    s0, 
    s1, 
    s2, 
    s3, 
    s4, 
    s5, 
    s6, 
    serror
};

enum acceptedStates{
    s1,
    s2,
    s3, 
    s4, 
    s5,
    s6
};

int main(int argc, char **argv){

    /**
     * "A recognizer to accept a six-character identifier 
     *  consisting of an alphabetic character 
     *  followed by zero to five alphanumeric characters." 
     */


    char currentChar = argv[1][0]; // FIXME: 1 indexed because first is the executable (I think, need to check)
    state myState;
    myState = s0;
    if(sizeof(argv[1]) > 6 || sizeof(argv[1]) == 0)
    {
        myState = serror;
    }
    
    int i = 0;
    while(myState != serror && character isnt the last character )
    {
      state = getCurrentState() //FIXME: SHOULD BE IMPLEMENTED
      i +=1;
      currentChar = argv[1][i];
    }

    if(myState is in acceptedStates ) // FIXME: Figure out how to check if two enum vals are same.. or replace the enums with sets?
    {
        return true;
    }
    else
    {
        return false;
    }
}