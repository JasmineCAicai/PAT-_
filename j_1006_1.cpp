#include <iostream>

using namespace std;

int main() {
    int M, hhin, mmin, ssin, hhout, mmout, ssout, HHIn = 24, HHOut = 0, MMIn = 60, MMOut = 0, SSIn = 60, SSOut = 0;
    string id, idIn, idOut;
    char in[9], out[9];
    
    cin >> M;
    
    for (int i=0; i<M; i++) {
        cin >> id;
        cin >> in;
        cin >> out;
        
        hhin = in[0]*10 + in[1] + 48;
        mmin = in[3]*10 + in[4] + 48;
        ssin = in[6]*10 + in[7] + 48;
        
        hhout = out[0]*10 + out[1] + 48;
        mmout = out[3]*10 + out[4] + 48;
        ssout = out[6]*10 + out[7] + 48;
        
        // In
        if ((in[0]=='0' && HHIn >= 10) || (hhin < HHIn)) {
            idIn = id;
            HHIn = hhin;
            MMIn = mmin;
            SSIn = ssin;
        }
        else if (hhin == HHIn) {
            if ((in[3]=='0' && MMIn >= 10) || (mmin < MMIn)) {
                idIn = id;
                HHIn = hhin;
                MMIn = mmin;
                SSIn = ssin;
            }
            else if (mmin == MMIn) {
                if ((in[6]=='0' && SSIn >= 10) || (ssin < SSIn)) {
                    idIn = id;
                    HHIn = hhin;
                    MMIn = mmin;
                    SSIn = ssin;
                }
            }
        }
        
        // Out
        if (hhout > HHOut) {
            idOut = id;
            HHOut = hhout;
            MMOut = mmout;
            SSOut = ssout;
        }
        else if (hhout == HHOut) {
            if (mmout > MMOut) {
                idOut = id;
                HHOut = hhout;
                MMOut = mmout;
                SSOut = ssout;
            }
            else if (mmout == MMOut) {
                if (ssout > SSOut) {
                    idOut = id;
                    HHOut = hhout;
                    MMOut = mmout;
                    SSOut = ssout;
                }
            }
        }
    }
    
    cout << idIn << " " << idOut << endl;
    return 0;
}
