//
// Created by JeongMin on 2019-03-03.
//

#include <iostream>
#include <fstream>
#include <sstream>

#include <utility>
#include <algorithm>

#include <vector>
#include <string>

#define FOR(i,b,e) for((i)=(b); (i)<(e); ++i)
#define reFOR(i,e,b) for((i)=((e)-1); (i)>=(b); --i)

using namespace std;
vector<string> strVec;

bool reChkPalin(const string& str)
{
    int strlen = int(str.length());
    int mid = strlen/2;
    int i;

    string fPart, bPart, fSub, bSub;
    auto strBeg = str.begin();

    fPart.insert(fPart.begin(), strBeg, strBeg+mid);
    bPart.insert(bPart.begin(), str.rbegin(), str.rbegin()+mid);
    cout << bPart.length() << endl;

    FOR(i,0,mid){
        if(fPart[i] != bPart[i]){
            fSub.insert(fSub.cbegin(), fPart.begin(), fPart.begin()-(i-1));
            bSub.insert(bSub.cbegin(), bPart.begin(), bPart.begin()-(i-1));
            if(fPart.find_first_of(bSub) || bPart.find_first_of(fSub))
                return true;
        }
    }
    return false;
}

bool chkPalin(const string& str)
{
    int mid = (int(str.length()))/2;
    int i;
    FOR(i,0,mid)
        if(str[i] != str[str.length()-1-i])
            return false;
    return true;
}


int main()
{
    ifstream ifs("palin.inp", ios::binary);
    ofstream ofs("palin.out", ios::binary);
    istringstream iss;
    ostringstream oss;

    int i, num = 0;
    string inp, result;
    try {
        ifs >> num;

        FOR(i, 0, num){
            ifs >> inp;
            strVec.push_back(move(inp));
        }

        FOR(i, 0, num){
            if(chkPalin(strVec[i]))
                oss << "1\n";
            else{
                if(reChkPalin(strVec[i]))
                    oss << "2\n";
                else
                    oss << "3\n";
            }
        }
        result = oss.str();
        result.pop_back();
        ofs << result;
    }
    catch(const ios_base::failure& e){
        ofs.close();
        ifs.close();
        cerr << "Error : " << e.what();
        return EXIT_FAILURE;
    }

    ofs.close();
    ifs.close();
    return EXIT_SUCCESS;
}
