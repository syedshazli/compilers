// input, a CFG provided by the user (make it arrays of states or something)
// output: A Tree of the data
#include <iostream>
#include <set>

struct CFG{

    std::set<string> states; 

};

CFG getUserInput(char *input)
{

}

// FIXME: Type might not need to be CFG's
bool convertCFGToRules(CFG userCFG, std::set <CFG> outputRules)
{

}
int main(int argc, char* argv)
{
    CFG userCFG = getUserInput(char *argv);
    std::set <CFG> outputRules;
    if (!convertCFGToRules(userCFG, outputRules))
    {
        return;
    }

    convertCFGToTree();

    printTree();

}