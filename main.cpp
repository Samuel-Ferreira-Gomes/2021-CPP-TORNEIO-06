
/* URI_1715 - Handebol------------------------------

//Creator: Samuel_Ferreira.
//Created: 2021/03/06


#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, m, temp, ans=0;
    bool ok = 1;
    cin >> n >> m;
    while(n--){
        ok = 1;
        for(int i=0; i<m; i++){
            cin >> temp;
            if(!temp)
                ok = 0;
        }
        if(ok)
            ans++;
    }
    cout << ans << '\n';
}
*/

/* URI_1770 - Shuffle-----------------------------
	
//Creator: Samuel_Ferreira.
//Created: 2021/03/06


#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    struct songs{
        int a;
        int b;
    };
    int m,k;
    while(cin >> m >> k){
        vector<songs> d(m);
        int temp, confirm=0, ans=0;
        for(int i=0; i < m; i++){
            d[i].a=1;
            cin >> d[i].b;
        }
        bool ok = 1;
        for(int i = 0; i < k; i++){
            cin >> temp;
            if(d[temp-1].a){
                d[temp-1].a=0;
                confirm++;
            }
            if(confirm<m){
                ans+=d[temp-1].b;
            }
            else if(confirm==m && ok){
                ans+=d[temp-1].b;
                cout << ans << '\n';
                ok = 0;
            }
        }
        if(confirm!=m)
            cout << -1 << '\n';
    }
}
*/ 

/* URI_2296 - Trilhas-----------------------------

//Creator: Samuel_Ferreira.
//Created: 2021/03/06


#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, p, ans=100000000, ansIt;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> p;
        int p1,p2,rl=0,lr=0;
        for(int i2=0; i2+1<p; i2++){
            if(!i2)
                cin >> p1 >> p2;
            else{
                cin >> p2;
            }
            if(p1<=p2){
                lr+=(p2-p1);
            }
            else{
                rl+=(p1-p2);
            }
            p1 = p2;
        }
        int temp = (lr < rl ? lr : rl);
        if(temp<ans){
            ans=temp;
            ansIt = i;
        }

    }
    cout << ansIt << '\n';
}

*/

/* URI_2466 - Sinuca ---------------------------------

//Creator: Samuel_Ferreira.
//Created: 2021/03/05 (eddited 2021/03/06)


#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

int verif(vector<int> arr, vector<int> arr2) {
    for (unsigned int i = 0; i + 1 < arr.size(); i++) {
        if (arr[i] == arr[i + 1])
            arr2[i] = 1;
        else
            arr2[i] = -1;
    }
    if (arr2.size() == 1)
        return arr2[0];
    else
        return(verif(arr2, vector<int> (arr2.size()-1)));
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> arr2(n - 1);
    cout << (verif(arr, arr2) == 1 ? "preta\n" : "branca\n");

}
*/

/* URI_2662 - Escala Musical --------------------------------

//Creator: Samuel_Ferreira.
//Created: 2021/03/08


#include<iostream>
#include <string>
using namespace std;

int main() {
    
    bool ver[] = { 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 };
    bool song[24] = { 0 };
    int n, temp, ans=100;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
            temp = temp % 12;
        if (song[temp - 1] == 0) {
            song[temp - 1] = 1;
            song[temp + 11] = 1;
        }
    }
    for (int i = 0; i + 12 < 24; i++) {
        if ((song[i + 1] == ver[1]) &&
            (song[i + 3] == ver[3]) &&
            (song[i + 6] == ver[6]) &&
            (song[i + 8] == ver[8]) &&
            (song[i + 10] == ver[10]))
        {
            if (i < ans)
                ans = (i);
        }
    }
    string notes[] = { "do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si" };
    if (ans == 100)
        cout << "desafinado\n";
    else
        cout << notes[ans] << '\n';
}

*/

/* URI_2663 - Fase -----------------------------------

//Creator: Samuel_Ferreira.
//Created: 2021/03/05


#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int total, vagas, ans = 0;
    cin >> total >> vagas;
    vector<int> arr(total, 0);
    while (cin >> arr[--total] && total);
    int V = vagas;
    while (vagas--) {

        int it = 0 , well = -10;

        for (unsigned int i = 0; i < arr.size(); i++) {
            if (arr[i] > well) {
                well = arr[i];
                it = i;
            }
        }
        arr.erase(arr.begin() + it);
        ans++;
        if (ans == V) {
            for (unsigned int i = 0; i < arr.size();) {
                if (well == arr[i]) {
                    ans++;

                    arr.erase(arr.begin() + i);
                    i = 0;
                }
                else
                    i++;
            }
            break;
        }
    }
    cout << ans << '\n';
}
*/

/* URI_2779 - Álbum da Copa------------------------------

//Creator: Samuel_Ferreira.
//Created: 2021/03/05


#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int total,n, temp;
    vector<int> arr(0);
    cin >> total >> n;
    for(int i=0;i<n;i++){
        cin >> temp;
        if(i==0)
            arr.push_back(temp);
        else{
            bool ok = 1;
            for(int i2=0;i2<arr.size();i2++){
                if(temp==arr[i2]){
                    ok = 0;
                    break;
                }
            }
            if(ok)
                arr.push_back(temp);
        }

    }

    cout << (total-arr.size()) << '\n';
}

*/

/* URI_2782 - Escadinha------------------------------------

//Creator: Samuel_Ferreira.
//Created: 2021/03/05


#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, ans=0;
    cin >> n;
    vector<int> arr(n,0);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int ind = 0;

    if(n == 1)
        ans =1;
    else{
        for(int i = 0; i+1 < n; i++){
            if(!i){
                ind = ((arr[i])-(arr[i+1]));
                ans++;
            }
            else if (ind != ((arr[i])-(arr[i+1]))){
                ind = ((arr[i])-(arr[i+1]));
                ans++;
            }
            else
                continue;

        }
    }
    cout << ans << '\n';
}
*/

/* URI_2783 - Figurinhas da Copa-----------------------------------

//Creator: Samuel_Ferreira.
//Created: 2021/03/05


#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n,c,m,temp,ans,fakeC;
    cin >> n >> c >> m;
    vector<int> especial(c,0);
    fakeC=c;
    while(cin >> especial[--fakeC] && fakeC);
    vector<int> arr(0);
    for(int i = 0;i < m;i++){
        bool ok = 1;
        cin >> temp;
        if(!i)
            arr.push_back(temp);
        else{

            for(int i2=0;i2<arr.size();i2++){
                if(arr[i2]==temp){
                    ok = 0;
                    break;
                }
            }
            if(ok)
                arr.push_back(temp);
        }
        if(ok){
            for(int i2=0; i2<especial.size(); i2++){
                if(arr[arr.size()-1]==especial[i2])
                    ans++;
            }
        }
    }
    cout << (c-ans) << '\n';
}
*/

/* URI_2884 - Interruptores ----------------------------------

//Creator: Samuel_Ferreira.
//Created: 2021/03/06


#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, m, l, temp;
    cin >> n >> m;
    cin >> l;
    vector<bool> arr(m,0);
    for(int i=0; i< l; i++){
        cin >> temp;
        arr[temp-1] = 1;
    }
    int temp2;
    vector<vector<int>> inter(n,vector<int>(0));
    for(int i=0; i<n; i++){
        cin >> temp;
        while(temp--){
            cin >> temp2;
        inter[i].push_back(temp2);
        }
    }
    int nProvi = (n*2);
    bool ok = 0;
    for(int i=0, h=0; h<nProvi; i++,h++){
            if(i == n)
                i=0;
        for(unsigned int i2=0; i2<inter[i].size();i2++){
            arr[inter[i][i2]-1] = (!(arr[inter[i][i2]-1]));
        }
        ok=1;
        for(int i2=0; i2<m; i2++){
            if(arr[i2]!=0){
                ok = 0;
                break;
            }
        }
        if(ok){
            cout << (h+1) << '\n';
            break;
        }

    }
    if(!ok)
        cout << -1 << '\n';
}
*/