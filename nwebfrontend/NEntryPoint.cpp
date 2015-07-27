#include <nwebfrontend/NWebFrontendApplication.h>

using namespace nox;

int main(int argc, char * argv[])
{
    NWebFrontendApplication::getInstance()->run(argc, argv);

    return 0;
}