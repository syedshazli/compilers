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


    char firstChar = argv[1][0]; // FIXME: 1 indexed because first is the executable (I think, need to check)
    state myState;
    myState = s0;
    if(sizeof(argv[1]) > 6 || sizeof(argv[1]) == 0)
    {
        myState = serror;
    }

    while(myState != serror && character isnt the last character )
    {
      
    }

    if(myState is in acceptedStates )
    {
        return true;
    }
    else
    {
        return false;
    }
}