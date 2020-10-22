#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc,char *argv[]) {
    int32_t
            nLow=0,dLow=1,
            nHigh=1,dHigh=0,
            nMed=1,dMed=1;
    double
            x,
            med=1;

    x = strtod(argv[1],nullptr);

    while (dMed < 100000000 && abs(x-med) > 1e-8) {
        if (x > med) {
            nLow = nMed;
            dLow = dMed;
        } else {
            nHigh = nMed;
            dHigh = dMed;
        }

        nMed = nLow + nHigh;
        dMed = dLow + dHigh;

        med = nMed / dMed;
    }

    cout << x << " is approximately " << nMed << " / " << dMed << endl;

    return 0;
}
