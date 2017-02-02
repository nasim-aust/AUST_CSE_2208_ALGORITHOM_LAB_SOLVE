#include <bits/stdc++.h>
#define SIZE 1001
using namespace std;
int a[SIZE][SIZE];
string s1, s2;
int lcs(string s1, int l1, string s2, int l2){
    for(int i = 1; i <= l1; i++){
        for(int j = 1; j <= l2; j++){
            if(s1[i-1]== s2[j-1]){
                a[i][j] = a[i-1][j-1] + 1;
            }
            else{
                a[i][j] = max(a[i-1][j], a[i][j-1]);
            }
        }
    }
    return a[l1][l2];
}

/*int lcscount(int l1, int l2){
    if(l1 == 0 || l2 == 0){
        return 1;
    }
    if(s1[l1-1] == s2[l2-1]){
        return lcscount(l1-1, l2-1);
    }
    else{
    if(a[l1-1][l2] == a[l1][l2-1]){
        return lcscount(l1, l2-1)+ lcscount(l1-1, l2);
    }
    else if(a[l1-1][l2] < a[l1][l2-1]){
        return lcscount(l1, l2-1);
    }
    else{
        return lcscount(l1-1, l2);
    }
    }
}*/

multiset <string> lcsgiver(int l1, int l2){//data structure
    multiset <string> s;
    multiset <string> :: iterator p;//syntax
    if(l1 == 0 || l2 == 0){
        s.insert("");
        return s;
    }
    if(s1[l1-1] == s2[l2-1]){
        multiset <string > temp = lcsgiver(l1-1, l2-1);
       p = temp.begin();
       while(p!= temp.end()){
           s.insert(*p+ s1[l1-1]);
           p++;
       }
    }
    else{
    if(a[l1][l2-1]>= a[l1-1][l2]){
        s = lcsgiver(l1, l2-1);
    }

    if(a[l1-1][l2]>= a[l1][l2-1]){
        multiset<string> temp = lcsgiver(l1-1, l2);
        s.insert(temp.begin(), temp.end());
    }
    }
    return s;
}

int main()
{
    s1 = "ATGCTGAT";
    s2 = "TGGCATA";
    cout<<"lcs length"<<lcs(s1,s1.length(), s2, s2.length())<<endl;
    //cout<<"total lcs "<<lcscount(s1.length(), s2.length())<<endl;
    multiset <string> s = lcsgiver(s1.length(), s2.length());
    multiset<string>::iterator p;
    p = s.begin();
    cout<<"total lcs "<<s.size()<<" "<<endl;
    while(p!= s.end()){
        cout<<*p<<endl;
        p++;
    }
    return 0;
}
