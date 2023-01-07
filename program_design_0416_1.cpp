#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class active_region
{
protected:
    double VBB, VCC, VBE, RB, RC, Beta;

public:
    virtual void DC_analysis();
};

class saturation_region : public active_region
{
public:
    void DC_analysis();
};

void active_region::DC_analysis()
{
    cin >> VBB >> VCC >> VBE >> RB >> RC >> Beta;
    double IB, IC, IE, VCE;
    IB = (VBB - VBE) / RB;
    IC = Beta * IB;
    IE = (1 + Beta) * IB;
    VCE = VCC - (IC * RC);
    cout << fixed << setprecision(2);
    cout << IC << " " << IB << " " << IE << " " << VCE << endl;
}

void saturation_region::DC_analysis()
{
    cin >> VBB >> VCC >> VBE >> RB >> RC >> Beta;
    double VCE = 0.2;
    double IC, IB, IE;
    IC = (VCC - VCE) / RC;
    IB = (VBB - VBE) / RB;
    IE = IC + IB;
    cout << fixed << setprecision(2);
    cout << IC << " " << IB << " " << IE << " " << VCE << endl;
}

int main()
{
    bool region;
    cin >> region;
    active_region *ptr = (region == true ? new active_region : new saturation_region);
    ptr->DC_analysis();
    return 0;
}
