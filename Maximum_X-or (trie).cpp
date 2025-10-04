#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mx=5e5+123;
const ll mod=1e9+7;
struct node {
    int cnt; 
    node *next[2];
    node () {
        cnt = 0;
        for (int i = 0; i < 2; i++) next[i] = NULL;
    }
};

node *root;

string bin(ll n) {
    string ans = "";
    for (int i = 31; i >= 0; i--) {
        ans += ((n >> i) & 1) ? '1' : '0';
    }
    return ans;
}

void insert(string s) {
    node *cur = root;
    for (int i = 0; i < s.size(); i++) {
        int id = s[i] - '0';
        if (cur->next[id] == NULL) cur->next[id] = new node();
        cur = cur->next[id];
        cur->cnt++;
    }
}


void erase(string s) {
    node *cur = root;
    for (int i = 0; i < s.size(); i++) {
        int id = s[i] - '0';
        node *nxt = cur->next[id];
        if (!nxt) return;
        nxt->cnt--;
        if (nxt->cnt == 0) {
            delete nxt;
            cur->next[id] = NULL;
            return;
        }
        cur = nxt;
    }
}

ll search(string s) {
    ll ans = 0;
    node *cur = root;
    for (int i = 0; i < 32; i++) {
        int bit = s[i] - '0', need = 1 - bit;
        if (cur->next[need] && cur->next[need]->cnt > 0) {
            ans |= (1LL << (31 - i));
            cur = cur->next[need];
        } 
        else cur = cur->next[bit];
        
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll t = 1;
    cin >> t;
    
    while (t--) {
        root = new node();
       
    }
}
