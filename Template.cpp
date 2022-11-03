#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <time.h>
#include <chrono>
//#include "OOComparison.cpp"
using namespace std::chrono;
//#include <main.cpp>
using namespace std;


class IntWrapperNew {
public:
    IntWrapperNew(int value) : val((value)) {};


    bool operator<(const IntWrapperNew &rhs) const {
        return val < rhs.getVal();
    }

    bool operator>(const IntWrapperNew &rhs) const {
        return val > rhs.getVal();
    }

    bool operator<=(const IntWrapperNew &rhs) const {
        return val <= rhs.getVal();
    }

    bool operator>=(const IntWrapperNew &rhs) const {
        return val >= rhs.getVal();
    }

    int getVal() const {
        return val;
    };

private:
    //IComparable& intWrapper;
    int val;
};

class StringWrapperNew {
public:
    StringWrapperNew(string value) : stringVal((std::move(value))) {};


    bool operator<(const StringWrapperNew &rhs) const {
        return stringVal.size() < rhs.getVal().size();
    }

    bool operator>(const StringWrapperNew &rhs) const {
        return stringVal.size() > rhs.getVal().size();
    }

    bool operator<=(const StringWrapperNew &rhs) const {
        return stringVal.size() <= rhs.getVal().size();
    }

    bool operator>=(const StringWrapperNew &rhs) const {
        return stringVal.size() >= rhs.getVal().size();
    }


    string getVal() const {
        return stringVal;
    };

private:
    //IComparable& intWrapper;
    string stringVal;
};

template <typename IComparable>

void sortNew(vector<IComparable*> v) {
    vector<IComparable*> temp;
    temp.push_back(0);

    for (int i = 0; i < v.size(); i++) {
        if (!(v.at(i) < (v.at(i + 1)))) {
            temp[0] = v[i];
            v[i] = v[i + 1];
            v[i + 1] = temp[0];
        }
    }

}

template <typename IComparable>
void sortVerificationNew(vector<IComparable*> v) {
    vector<IComparable*> temp;
    temp.push_back(0);

    for (int i = 0; i < v.size(); i++) {
        if (!(v.at(i) < (v.at(i + 1)))) {
            sort(v);
        }
    }
    cout << "Ordering is correct" << endl;
}

