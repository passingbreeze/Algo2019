#include <bits/stdc++.h>
#include <boost/variant.hpp>

using namespace std;

struct SimpleVariantVisitor : public boost::static_visitor<void>
{
    void operator() (const string& s) const {
        cout << "String : " << s << endl;
    }

    void operator() (long n) const {
        cout << "long : " << n << endl;
    }
};

int main()
{
    boost::variant<string, long, double> v1;
    v1 = "안녕하세요";

    boost::apply_visitor(SimpleVariantVisitor(), v1);
    return EXIT_SUCCESS;
}