// dynamic programming | Scramble String | C++

/*

Problem link: https://leetcode.com/problems/scramble-string/

*/


#include<bits/stdc++.h>
using namespace std;

bool checkForScramble(string a, string b, unordered_map<string, bool> &mp){
        if(mp.find(a + "," + b) != mp.end()) return mp[a + "," + b];
        
        if(a == b) return true;
        if(a.length() <= 1) return false;
        
        bool flag = false;
        int n = a.length();
    for(int i = 1; i <= n - 1; i++){
  if(
    (checkForScramble(a.substr(0, i), b.substr(n - i, i), mp) 
    and 
    checkForScramble(a.substr(i, n - i), b.substr(0, n - i), mp)
   )
   || 
   (checkForScramble(a.substr(0, i), b.substr(0, i), mp) 
    and 
    checkForScramble(a.substr(i, n - i), b.substr(i, n - i), mp)
   )
   )  {
      flag = true;
      }
   }
        return mp[a + "," + b] = flag;
 
}
    
    
bool isScramble(string s1, string s2) {
        unordered_map<string, bool> mp;        
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1 != n2) return false;
        return checkForScramble(s1, s2, mp);
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    
    string ans = isScramble(s1, s2) ? "True" : "False";
        cout << ans << "\n";
    return 0;
}
