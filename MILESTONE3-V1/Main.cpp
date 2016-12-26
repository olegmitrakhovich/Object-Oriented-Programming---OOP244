#include "ScmApp.h"

using namespace sict;
using namespace std;

int main() {

ScmApp X("test.txt");

int x = 0;

        do{
        x = X.run();
        }while (x != 0);

	return 0;
}



