#include "NBackendApplication.h"

using namespace nox;

int main(int argc, char * argv[])
{
    NBackendApplication::getInstance()->run(argc, argv);

    return 0;
}