#include <iostream>
#include <string>
#include <cctype>

using namespace std;

short ReadNumber(string  Message)
{
	short Number = 0;
	
		cout << Message << "\n";
		cin >> Number;
	
	return Number;

}

string ReadString()
{
	string UserString = " ";
	cout << "Enter string\n";
	getline(cin, UserString);
	return UserString;
}

enum enWhatToCount {SmallLetters = 1 , CapitalLetters = 2 , AllLetters = 3 , Ponctuoation = 4 };

short CountLetters(string & UserString , enWhatToCount WhatToCount  = enWhatToCount::AllLetters)
{
	

	if (WhatToCount == enWhatToCount::AllLetters)
		return UserString.length();
	

	short Counter = 0;
	for (short i = 0 ; i < UserString.length() ; i++)
	{
		if (WhatToCount == enWhatToCount::SmallLetters && islower(UserString[i]))
			Counter++;

		if (WhatToCount == enWhatToCount::CapitalLetters && isupper(UserString[i]))
			Counter++;

		if (WhatToCount == enWhatToCount::Ponctuoation && ispunct(UserString[i]))
			Counter++;
	}
		

	return Counter;

}

short CountLowerCaseLetters(string & UserString)
{
	short Counter = 0;
	for (short i = 0 ; i < UserString.length() ; i++)
	{

		islower(UserString[i]) ? Counter++ : 0;

	}

	return Counter;
}

short CountUpperCaseLetters(string & UserString)
{
	short Counter = 0;

	for (short i = 0 ; i < UserString.length() ; i++)
	{

		isupper(UserString[i]) ? Counter++ : 0;


	}
	
	return Counter;

}

int main()
{

	string UserString = ReadString();

	cout << "String length = " << UserString.length();
	cout << "\nUpper case letters = " << CountUpperCaseLetters(UserString);
	cout << "\nLower case letters = " << CountLowerCaseLetters(UserString);

	cout << "\n2nd method\n";
	cout << "String length = " << CountLetters(UserString, enWhatToCount::AllLetters);
	cout << "\nUpper case letters = " << CountLetters(UserString , enWhatToCount::CapitalLetters);
	cout << "\nLower case letters = " << CountLetters(UserString, enWhatToCount::SmallLetters);
	cout << "\nPunctuoations = " << CountLetters(UserString, enWhatToCount::Ponctuoation);

	
	return 0;
}