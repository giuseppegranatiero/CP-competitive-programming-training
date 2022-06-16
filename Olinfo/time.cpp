#include <iostream>
#include <cassert>
using namespace std;
// casi particolari: h1=h2 ma m1>m2
int main() {
    assert(freopen("input.txt", "r", stdin)!=NULL);
	assert(freopen("output.txt", "w", stdout)!=NULL);
    int h1, h2, h3, m1, m2, m3;
    cin >> h1 >> m1;
    cin >> h2 >> m2;
    if (h1<h2){
        h1 *=60*60;
        m1 *=60;
        int s1 = h1+m1;
        h2 *=60*60;
        m2 *=60;
        int s2 = h2+m2;
        int diff=s2-s1;
        h3 = diff/60/60;
        m3 = (diff%3600)/60;
    }
    else if (h1==h2 && m1<=m2){
        h1 *=60*60;
        m1 *=60;
        int s1 = h1+m1;
        h2 *=60*60;
        m2 *=60;
        int s2 = h2+m2;
        int diff=s2-s1;
        h3 = diff/60/60;
        m3 = (diff%3600)/60;
    }
    else {
        h1 *=60*60;
        m1 *=60;
        int s1 = 24*60*60-(h1+m1);
        h2 *=60*60;
        m2 *=60;
        int s2 = h2+m2;
        int diff=s2+s1;
        h3 = diff/60/60;
        m3 = (diff%3600)/60;
    }
    cout << h3 << " " << m3;
}