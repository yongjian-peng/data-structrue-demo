#include "stdc++.h"

using namespace std;

class MapDemo {
    public:
        int main() {

            // unordered_set<string> uset;
            // uset.emplace("http://c.biancheng.net/java/");
            // uset.emplace("http://c.biancheng.net/c/");
            // uset.emplace("http://c.biancheng.net/python/");

            // cout << "useet size = " << uset.size() << endl;

            // for (auto iter = uset.begin(); iter != uset.end(); ++iter) {
            //     cout << *iter << endl;
            // }
            unordered_set<int> obs;
            int s = 100;
            obs.insert(s);
            obs.insert(20);

            cout << "obs size " << obs.size() << endl;

            for (auto iter = obs.begin(); iter != obs.end(); iter++) {
                cout << *iter << endl;
            }

                // unordered_map<string, string> umap;

                // umap.emplace("Python教程", "http://c.biancheng.net/python/");
                // umap.emplace("Java教程", "http://c.biancheng.net/java/");
                // umap.emplace("Linux教程", "http://c.biancheng.net/linux/");

                // cout << "umap size = " << umap.size() << endl;

                // // for
                // for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
                //     cout << iter->first << " " << iter->second << endl;
                // }

                return 0;
        }
};