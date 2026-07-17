#include<iostream>
using namespace std;

#include <bits/stdc++.h> 
string replaceSpaces(string &str){
	// Write your code here.
	string ans = "";
	for(char &c : str){
		if(c==' ')
			ans += "@40";
		else
			ans+= c;
	}
	return ans;
}

// In place
string replaceSpaces(string &str){
	// Write your code here.
	int n = str.length();
	int spaces = 0;
	for(char &c : str)
		if(c==' ') spaces++;
	
	str.resize(n+2*spaces);

	int i=n-1,j=str.size()-1;
	while(i>=0){
		if(str[i]==' '){
			str[j--] = '0';
			str[j--] = '4';
			str[j--] = '@';
		}
		else
			str[j--] = str[i];
		i--;
	}
	return str;
}