#include <fstream>
#include <bitset>
using namespace std;
ifstream cin("test.in");
ofstream cout("test.out");
int rst, rdr, cst, cdr, mid1, mid2;
long long maxi;
string x;
bitset<1000> v;

inline void upper_half(int &st, int &dr, int &mid)
{
    dr = mid;
    mid = (st+dr)/2;
    
}
inline void lower_half(int &st, int &dr, int &mid)
{
    st = mid+1;
    mid = (st+dr)/2;
}

int main()
{

    while(cin>>x)
    {
        mid1 = 63;
        mid2 = 3;
        rst = cst = 0;
        cdr = 7;
        rdr = 127;
        for( int i = 0; i<=6; ++i){
            if(x[i] == 'F')
                lower_half(rst, rdr, mid1);
            if(x[i] == 'B')
                upper_half(rst, rdr, mid1);
        }
        for( int i = 7; i <=9; ++i ){
            if(x[i] == 'L')
                lower_half(cst, cdr, mid2);
            if(x[i] == 'R')
                upper_half(cst, cdr, mid2);
        }
        long long rez = mid1*8+mid2;
        v[rez] = 1;
        if(rez > maxi)
            maxi = rez;
    }
    
//    PART 1 OUTPUT
    cout<<maxi;
    
    for( int i = 1; i<= 1000; ++i)
        if(!v[i] && v[i+1] && v[i-1])
//            PART 2 OUTPUT
            cout<<i<<" ";

    return 0;
}
