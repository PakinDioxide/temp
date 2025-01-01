// PakinDioxide [to_num], vLvy [wol]
#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

map <string, ll> mp;

ll to_num(string s) {
    string t = "";
    stack <ll> st;
    st.push(0);
    for (int i = 0; i < s.size(); i++) {
        t += s[i];
        if (mp[t]) {
            ll k = mp[t];
            t = "";
            if (k < 10) st.push(k);
            else if (k < 100) {
                if (st.top() < 10 && st.top() > 0) st.top() *= k;
                else st.top() += k;
            } else if (st.top() != 0) st.top() *= k;
            else st.top() += k;
        }
    }
    ll ans = 0;
    while (!st.empty()) ans += st.top(), st.pop();
    return ans;
}

void wol(int n){
    int cnt=1;
    stack<string> ans;
    while(n>0){
        int m=n%10;
        n/=10;
        if (m == 0) {cnt++; continue;}
        if(cnt==1){
            if(m==1) ans.push("li");
            else if(m==2) ans.push("se");
            else if(m==3) ans.push("bas");
            else if(m==4) ans.push("yup");
            else if(m==5) ans.push("MeL");
            else if(m==6) ans.push("heppe");
            else if(m==7) ans.push("na");
            else if(m==8) ans.push("ooTa");
            else if(m==9) ans.push("Nei");
        }
        else if(cnt==2){
            if(m==1) ans.push("CaRa");
            else if(m==2) ans.push("Hoda");
            else if(m==3) ans.push("HodaCaRa");
            else if(m==4) ans.push("seHoda");
            else if(m==5) ans.push("seHodaCaRa");
            else if(m==6) ans.push("basHoda");
            else if(m==7) ans.push("basHodaCaRa");
            else if(m==8) ans.push("yupHoda");
            else if(m==9) ans.push("yupHodaCaRa");
            // if(m==1) ans.push("CaRa");
            // else if(m==2) ans.push("Hoda");
            // else if(m==3) ans.push("CaRaCaRa");
            // else if(m==4) ans.push("seHoda");
            // else if(m==5) ans.push("CaRaCaRaCaRaCaRaCaRa");
            // else if(m==6) ans.push("basHoda");
            // else if(m==7) ans.push("CaRaCaRaCaRaCaRaCaRaCaRaCaRa");
            // else if(m==8) ans.push("yupHoda");
            // else if(m==9) ans.push("CaRaCaRaCaRaCaRaCaRaCaRaCaRaCaRaCaRa");
            // if(m==1) ans.push("CaRa");
            // else if(m==2) ans.push("Hoda");
            // else if(m==3) ans.push("basCaRa");
            // else if(m==4) ans.push("seHoda");
            // else if(m==5) ans.push("MeLCaRa");
            // else if(m==6) ans.push("basHoda");
            // else if(m==7) ans.push("naCaRa");
            // else if(m==8) ans.push("yupHoda");
            // else if(m==9) ans.push("NeiCaRa");
        }
        else {
            int i;
            for(i=3; i<=cnt; i+=2){
                ans.push("Yap");
            }
            if(cnt%2==0) ans.push("CaRa");
            if(m==1) ans.push("li");
            else if(m==2) ans.push("se");
            else if(m==3) ans.push("bas");
            else if(m==4) ans.push("yup");
            else if(m==5) ans.push("MeL");
            else if(m==6) ans.push("heppe");
            else if(m==7) ans.push("na");
            else if(m==8) ans.push("ooTa");
            else if(m==9) ans.push("Nei");
        }
        cnt++;
    }
    string sss = "";
    while(!ans.empty()){
        sss+=ans.top();
        ans.pop();
    }
    cout << sss;
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string qs;
    cin >> qs;
    mp["se"] = 2; mp["yup"] = 4; mp["MeL"] = 5; mp["CaRa"] = 10; mp["Nei"] = 9; mp["ooTa"] = 8; mp["Hoda"] = 20; mp["na"] = 7; mp["li"] = 1; mp["heppe"] = 6; mp["Yap"] = 100; mp["bas"] = 3;
    ll q = to_num(qs);
    while (q--) {
        string x, y;
        char o;
        cin >> x >> o >> y;
        // cout << to_num(x) << ' ' << to_num(y) << '\n';
        if (o == '+') wol(to_num(x) + to_num(y)), cout << '\n';
        else wol(to_num(x) * to_num(y)), cout << '\n';
    }
    // cout << to_num("seYapYapseCaRaYapseYapseHodana");
    // ll q;
    // cin>> q;
    // wol(q);
    // cout << to_num(qs);
    // for (ll i = 1; i <= 1000000000000000; i++) {
    //     if (to_num(wol(i)) != i) cout << i << ' ';
    // }
    // cout << "DONE";
    // wol(2224700);
}