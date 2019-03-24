#include <iostream>
using namespace std;

void Permall(char *pStr, char *pBegin) {
    if (*pBegin ==  '\0') {
        cout << pStr << endl;
    } else {
        for (char *pCh = pBegin; *pCh != '\0'; pCh++) {
            char tmp = *pCh;
            *pCh = *pBegin;
            *pBegin = tmp;

            Permall(pStr, pBegin + 1);

            tmp = *pCh;
            *pCh = *pBegin;
            *pBegin = tmp;

        }
    }
}

int main() {
    char p[] = "abc";
    Permall(p, p); 
    return 0;
}
