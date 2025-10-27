// input, a CFG provided by the user (make it arrays of states or something)
// output: A Tree of the program
#include <iostream>
#include <vector>
#include <string>

struct CFG{

    std::vector<std::string> states; 

};

// FIXME: Is this needed?

// FIXME: Populate with the nodes and all that
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node() : left(nullptr), right(nullptr){}
};

class Tree{
    public:
    // intialize tree with node
        Tree() {
        Node rootNode;
        }

};

CFG convertInputToCFG(int argc, char *input[])
{
    // for each line of input, add each line to the set of states as a string
    CFG userCFG;
    for(int i = 1; i < argc; i++)
    {
         userCFG.states.emplace_back(input[i]);
    }
   
    return userCFG;
}

void printUserInput(CFG userInput)
{
    std::cout<<"User CFG:"<<std::endl;
    for (auto it : userInput.states)
    {

        
        std::cout<<it<<'\n';
    }
}

// FIXME: Type might not need to be CFG's
bool convertCFGToRules(CFG userCFG, std::vector <CFG> &outputRules)
{

    
}

bool convertCFGToTree(std::vector <CFG> outputRules, Tree &userTree)
{

}

void printTree(Tree CFGTree)
{

}

void printErrorMessage()
{
    std::cout<<"Sorry, we couldn't generate a CFG for you. Please fix and try again.";
}

int main(int argc, char* argv[])
{
    CFG userCFG = convertInputToCFG(argc, argv);
    std::vector <CFG> outputRules;

    printUserInput(userCFG);

    if (!convertCFGToRules(userCFG, outputRules))
    {
        printErrorMessage();
        return 0;
    }

    

    Tree myTree;
    myTree.rootNode.leftNode = nullptr;
    if (!convertCFGToTree(outputRules, myTree))
    {
        printErrorMessage();
    }

    printTree(myTree);

}