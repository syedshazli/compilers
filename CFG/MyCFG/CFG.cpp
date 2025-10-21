// input, a CFG provided by the user (make it arrays of states or something)
// output: A Tree of the program
#include <iostream>
#include <set>
#include <string>

struct CFG{

    std::set<std::string> states; 

};

// FIXME: Is this needed?
class Tree{

    // intialize tree with node
    Tree() {
        Node rootNode;
    }

};
// FIXME: Populate with the nodes and all that
class Node{

    int data;
    Node* left;
    Node* right;

    Node() : left(nullptr){}
};

CFG convertInputToCFG(char **input)
{

}

// FIXME: Type might not need to be CFG's
bool convertCFGToRules(CFG userCFG, std::set <CFG> &outputRules)
{

}

bool convertCFGToTree(std::set <CFG> outputRules, Tree &userTree)
{

}

void printTree(Tree CFGTree)
{

}

void printErrorMessage()
{
    std::cout<<"Sorry, we couldn't generate a CFG for you. Please fix and try again.";
}

int main(int argc, char** argv)
{
    CFG userCFG = convertInputToCFG(argv);
    std::set <CFG> outputRules;

    if (!convertCFGToRules(userCFG, outputRules))
    {
        printErrorMessage();
    }



    Tree myTree;
    if (!convertCFGToTree(outputRules, myTree))
    {
        printErrorMessage();
    }

    printTree(myTree);

}