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
#include <chrono>

#define FOR(i,b,e) for((i)=(b); (i)<(e); ++i)
#define ALL(x) ((x).begin()),((x).end())

using namespace std;
using namespace chrono;
vector<string> strVec;

bool chkPalin(const string& str)
{
    int mid = (int(str.length()))/2;
    int i;
    FOR(i,0,mid)
        if(str[i] != str[str.length()-1-i])
            return false;
    return true;
}

bool reChkPalin(const string& str)
{
    int i;
    int strlen = int(str.length());
    string s, r;

    FOR(i,0,strlen){
        s = str.substr(0,i)+str.substr(i+1);
        r = s;
        reverse(ALL(r));
        if(r == s)
            return true;
    }
    return false;
}

int main()
{
    system_clock time;
    duration<double> diff_time;
    auto begin = time.now();

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
    auto end = time.now();
    diff_time = end - begin;
    cout << "tot time : " << diff_time.count() << " sec(s)\n";
    return EXIT_SUCCESS;
}
