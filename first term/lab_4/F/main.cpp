#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int n;
vector<double> h;

double B()
{
    double l = 0, r = h[0];
    while (r - l > 0.0000000001) {
        h[1] = (l + r) / 2;
        bool Up = true;
        for (int i = 2; i < n; i++) {
            h[i] = 2 * h[i - 1] - h[i - 2] + 2;
            if (h[i] < 0) {
                Up = false;
                break;
            }
        }
        if (Up) {
            r = h[1];
        }
        else {
            l = h[1];
        }


    }
    return h[n - 1];

}
int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("garland.in");
    fout.open("garland.out");
    fin >> n;
    h.resize(n);
    fin >> h[0];
    double a = B();
    fout.precision(9);
    fout << fixed << a;
    fin.close();
    fout.close();
}