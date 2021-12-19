// NumberToRomanNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*Create a RomanNumerals class that can convert a roman numeral to and from an integer value. It should 
follow the API demonstrated in the examples below. Multiple roman numeral values will be tested for 
each helper method.

Modern Roman numerals are written by expressing each digit separately starting with the 
left most digit and skipping any digit with a value of zero. In Roman numerals 1990 is 
rendered: 1000=M, 900=CM, 90=XC; resulting in MCMXC. 2008 is written as 2000=MM, 8=VIII; 
or MMVIII. 1666 uses each Roman symbol in descending order: MDCLXVI.

Input range : 1 <= n < 4000

In this kata 4 should be represented as IV, NOT as IIII (the "watchmaker's four").*/

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class RomanHelper 
{
    vector<char> CharNumber = {'I','V','X','L','C','D','M'};
    vector<int> IntNumber = {1,5,10,50,100,500,1000};

    public:
    std::string to_roman(unsigned int n)
    {
        string Value = "";             //  return number in roman number

        int preValue = 6;              //  index max value

        for(int i = 6; i >= 0; i--)
        {
            //  the highest value that may occur before the current value CM -> 900, C[4], M[6]
            if (preValue == i && i > 0)  preValue -= 2;  

            while (n >= IntNumber[i])    //  option to example 3050 MMML
            {
                Value += CharNumber[i];
                n -= IntNumber[i];
            }

            if (n >= (IntNumber[i] - IntNumber[preValue]) && n != 0)    //  other option example CM = 900 (1000-100)
            {
                Value += CharNumber[preValue];
                Value += CharNumber[i];
                n -= (IntNumber[i] - IntNumber[preValue]);
            }
        }
        return Value;
    }

    int from_roman(std::string rn)
    {
        int Value = 0;

        map <char, int> convertRomanToNumber;       //  create dictionary number Roman value to usualy number
                                                    
        for (int i = 0; i < CharNumber.size(); i++)  convertRomanToNumber[CharNumber[i]] = IntNumber[i];    //  inicjalization dictionary

        for (int i = 0; i < rn.length(); i++)       //  change value roman on normal number
        {
            if (i != rn.length()-1 && convertRomanToNumber[rn[i]] < convertRomanToNumber[rn[i + 1]])  //  when we have XC or IV
            {
                Value += (convertRomanToNumber[rn[i + 1]] - convertRomanToNumber[rn[i]]);
                i++;
            }
            else
                Value += convertRomanToNumber[rn[i]];           //  option when have MMCC or MDC  
        }
        return Value;
    }


} RomanNumerals;

int main()
{
    RomanHelper Obiect;

    cout << Obiect.to_roman(1000) << endl;
    cout << Obiect.to_roman(4) << endl;
    cout << Obiect.to_roman(1) << endl;
    cout << Obiect.to_roman(9) << endl;
    cout << Obiect.to_roman(1990) << endl;
    cout << Obiect.to_roman(2008) << endl;
    cout << Obiect.to_roman(3999) << endl << endl;

    cout << Obiect.from_roman("XXI") << endl;
    cout << Obiect.from_roman("I") << endl;
    cout << Obiect.from_roman("IX") << endl;
    cout << Obiect.from_roman("IV") << endl;
    cout << Obiect.from_roman("MMVIII") << endl;
    cout << Obiect.from_roman("MDCLXVI") << endl;

}


