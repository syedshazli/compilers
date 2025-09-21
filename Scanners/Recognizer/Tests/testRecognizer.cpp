#include "../RecognizerExample.h"
#include <assert.h>

int main()
{
    std::string inputString = "a";
    assert(startRecognizer(inputString) == true);
}