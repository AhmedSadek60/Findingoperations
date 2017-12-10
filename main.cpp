#include <iostream>
#include <vector>


using namespace std;
#define numOfOperations 15

enum{

};


void resultValue(string s){
    double result;
    string operations[numOfOperations]= {"^","*",".*","/","./","+",".+","-",".-","sin","cos","tan","log","ln","sqrt"};
    vector <string>lineOperators;
    vector <double>lineValues;
    string operationDetector;
    for(int i=0;i<s.length();i++)
    {
        for (int counter=0;counter < numOfOperations ;counter++)
        {
            string LetterBefore(1,s[i-1]),Letter(1,s[i]),LetterAfter(1,s[i+1]),LetterAfterAfter(1,s[i+2]),
                    wordOperation=(LetterBefore+Letter+LetterAfter),lnOperation=(Letter+LetterAfter),
                     sqrtOperation=(wordOperation+LetterAfterAfter);
            if (Letter==operations[counter])
            {
                operationDetector=operations[counter];
                if(s[i-1]=='.')
                    operationDetector= "."+operationDetector;

                lineOperators.push_back(operationDetector);
            }
            else if (wordOperation==operations[counter])
            {
                operationDetector=wordOperation;
                lineOperators.push_back(operationDetector);
            }
            else if(lnOperation==operations[counter] && Letter!=".")
            {
                operationDetector=lnOperation;
                lineOperators.push_back(operationDetector);
            }
            else if(sqrtOperation==operations[counter])
            {
                operationDetector=sqrtOperation;
                lineOperators.push_back(operationDetector);
            }
        }
    }
    for(int t=0; t<lineOperators.size();t++)
    {
        cout<<lineOperators[t]<<endl;
    }
}

int main() {
    resultValue("5.5.+8.9*sin(3.5)+8^log(8)cos(90)+ln(x)+sqrt(x^2)");
    int x;
    cin>>x;
    return 0;
}
