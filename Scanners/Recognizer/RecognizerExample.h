#include <string>
#include <set>

#pragma once
enum class state : int{
    serror,
    s0, 
    sDigitOrAlpha,
    sEnd
};

state operator++(state& currentState, int);



bool isAlphaNum(char currentChar);

bool isAlphabetic(char currentChar);

state checkCurrentState(char currentChar, state currentState, int i);


bool checkAcceptedState(state currentState, std::set<state> acceptedStates);

bool startRecognizer(std::string inputString);

void printSuccess(bool myReturn);

bool convertArgvToString(char **argv, std::string &resultingString);

