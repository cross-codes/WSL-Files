#include <iostream>
#include <string>
using namespace std;

int main()

{
    cout << "Helllo";
    string s;
    cin >> s;
    int n= s.size();
    cout << n;
    int max=0;
    int freq=1;
    while(n!=0) {
        for(int i=0;i<n-1;i++) {
            while(s[i]==s[i+1]) {
                freq++;
            }
            if(freq>max) 
            {
                max=freq;
            }       
        }   
        freq=1;
        n--;
    }
    cout << max;
    return 0;
}
