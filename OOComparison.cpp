#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <time.h>
#include <chrono>
#include "Template.cpp"
using namespace std::chrono;
//#include <main.cpp>
using namespace std;

class IComparable {
public:
    virtual bool isLessThan(IComparable* rhs) const = 0;
};

class IntWrapper : public IComparable {
public:
    IntWrapper(int value) : val((value)) {};

    bool isLessThan(IComparable* rhs) const override {
        IntWrapper* sref = dynamic_cast<IntWrapper *>(rhs);
        return *this < *sref;
    }

    bool operator<(const IntWrapper &rhs) const {
        return val < rhs.getVal();
    }

    bool operator>(const IntWrapper &rhs) const {
        return val > rhs.getVal();
    }

    bool operator<=(const IntWrapper &rhs) const {
        return val <= rhs.getVal();
    }

    bool operator>=(const IntWrapper &rhs) const {
        return val >= rhs.getVal();
    }

    int getVal() const {
        return val;

    };

private:
    //IComparable& intWrapper;
    int val;
};

class StringWrapper : public IComparable {
public:
    StringWrapper(string value) : stringVal((std::move(value))) {};

    bool isLessThan(IComparable* rhs) const override {
        StringWrapper* sref = dynamic_cast<StringWrapper *>(rhs);
        return *this < *sref;
    }


    bool operator<(const StringWrapper &rhs) const {
        return stringVal.size() < rhs.getVal().size();
    }


    string getVal() const {
        return stringVal;
    };

private:
    //IComparable& intWrapper;
    string stringVal;
};

void sort(vector<IComparable*> v) {
    vector<IComparable*> temp;
    temp.push_back(0);

    for (int i = 0; i < v.size(); i++) {
        if (v.at(i + 1)) {
            if (!(v.at(i)->isLessThan(v.at(i + 1)))) {
                temp[0] = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp[0];
            }
        }
    }

}

void sortInt(vector<IntWrapper> v) {
    vector<IntWrapper> temp;
    temp.push_back(0);

    for (int i = 0; i < v.size(); i++) {
            if (!(v.at(i) < (v.at(i + 1)))) {
                temp.at(0) = v.at(i);
                v.at(i) = v.at(i + 1);
                v.at(i + 1) = temp.at(0);
            }

    }

}

void sortVerification(vector<IComparable*> v) {
    vector<IComparable*> temp;
    temp.push_back(0);

    for (int i = 0; i < v.size(); i++) {
        if (!(v.at(i)->isLessThan(v.at(i + 1)))) {
            sort(v);
        }
    }
    cout << "Ordering is correct" << endl;
}





int main() {
    srand(time(NULL));

    string alphabet[26] = { "a", "b", "c" , "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
                            "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    string tempString = "";


    vector<IComparable*> numList;
    vector<IntWrapper> intWrap;
    vector<StringWrapper> stringWrap;

    vector<IntWrapperNew> intWrapNew;
    vector<StringWrapperNew> stringWrapNew;

   // for (int i = 0; i < 1000000; i++) {
  //      intWrap.push_back(IntWrapper(rand() % 1000));
  //  }

    for (int i = 0; i < 1000000; i++) {
            intWrapNew.push_back(IntWrapperNew(rand() % 1000));
    }


  //  for (int i = 0; i < 1000000; i++) {
  //     stringWrap.push_back(StringWrapper(alphabet[rand() % 26] + alphabet[rand() % 26]
  //                             + alphabet[rand() % 26] + alphabet[rand() % 26]));
   //}

    for (int i = 0; i < 1000000; i++) {
             stringWrapNew.push_back(StringWrapperNew(alphabet[rand() % 26] + alphabet[rand() % 26]
                                     + alphabet[rand() % 26] + alphabet[rand() % 26]));
        }


    IntWrapper a = IntWrapper(2);
    IntWrapper* b = new IntWrapper(5);
    IntWrapper* c = new IntWrapper(1);

    StringWrapper string1 = StringWrapper("hi");
    StringWrapper* string2 = new StringWrapper("hello");
    StringWrapper* string3 = new StringWrapper("h");

    cout << a.isLessThan(b) << endl;
    cout << a.isLessThan(c) << endl;

    cout << string1.isLessThan(string2) << endl;
    cout << string1.isLessThan(string3) << endl;

    auto start = high_resolution_clock::now();
  //  sort(intWrap.begin(), intWrap.end());
   //   sort(stringWrap.begin(), stringWrap.end());

      sort(intWrapNew.begin(), intWrapNew.end());
        sort(stringWrapNew.begin(), stringWrapNew.end());

  //  for (int i = 0; i < 1000000; i++) {
  //      cout << intWrap[i].getVal() << endl;
   // }

     for (int i = 0; i < 1000000; i++) {
         cout << intWrapNew[i].getVal() << endl;
     }


   // for (int i = 0; i < 1000000; i++) {
  //      cout << stringWrap[i].getVal() << endl;
   // }

    for (int i = 0; i < 1000000; i++) {
              cout << stringWrapNew[i].getVal() << endl;
         }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time in microseconds: " << endl;
    cout << duration.count() << endl;
    return 0;
}

