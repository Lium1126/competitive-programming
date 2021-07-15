#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<vector<int> > v[200];
    long long input;
    for (int i = 1;i <= n;i++) {
        cin >> input;
        vector<int> temp;
        temp[0] = i;
        v[input % 200].push_back(temp);

        for (int j = 0;j < 200;j++) {
            if (v[j].size() != 0) {
                int s = v[j].size();
                for (int k = 0;k < s;k++) {
                    vector<int> temp = v[j][k];
                    temp.push_back(i);
                    v[(j + input) % 200].push_back(temp);
                }
            }
        }
    }

    bool flag = false;
    for (int i = 0;i < 200;i++) {
        if (v[i].size() >= 2) {
            flag = true;
            cout << "Yes" << endl;
            cout << v[i][0].size() << " " << endl;
            for (int j = 0;j < v[i][0].size();j++) {
                if (j != v[i][0].size() - 1) cout << v[i][0][j] << " ";
                else cout << v[i][0][j] << endl;                
            }

            cout << v[i][1].size() << " " << endl;
            for (int j = 0;j < v[i][1].size();j++) {
                if (j != v[i][1].size() - 1) cout << v[i][1][j] << " ";
                else cout << v[i][1][j] << endl;                
            }

        }
    }


    return 0;
}
