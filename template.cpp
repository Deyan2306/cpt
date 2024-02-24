#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int INF = 1e9;
const double PI = acos(-1.0);
const double EPS = 1e-9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

#define YES 1&1
#define NO 1&0

template<typename T>
void print_vector(const vector<T>& v) {
    for (const auto& elem : v) {
        cout << elem << " ";
    }
    cout << endl ;
}

template<typename T>
void print_matrix(const vector<vector<T>>& mat) {
    for (const auto& row : mat) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

template<typename T>
void read_vector(vector<T>& v, int n) {
    v.resize(n);
    for (auto& elem : v) {
        cin >> elem;
    }
}

stringstream output;
void add_to_out(const string& str) {
    output << str;
}

/* May the source be with you */
int main(void) {

    cout << output.str();
    return 0;
}
