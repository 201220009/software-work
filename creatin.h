#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int maax[10];

void creatinput(string t) {
    srand((unsigned)time(0));
    char p[52];
    int i, j;
    for (i = 0; i < 26; p[i] = 'A' + i, i++);
    for (j = 0; j < 26; p[i] = 'a' + j, i++, j++);


    ifstream in(t);
    ofstream out("input.txt",ios::trunc);
    string temp = "";
    if (!in.is_open()) {
        cout << "open false!";
        exit(-1);
    }
    
    while (in >>temp ) {
    
        if (temp[0]=='i') {
           
            int dou_index = 0;
            for (int i = 0; i<temp.size(); i++) {
                if (temp[i] == ',') {
                    dou_index = i;
                    break;
                }
            }
            int min = atoi(temp.substr(4, dou_index - 4).c_str());
            int max = atoi(temp.substr(dou_index + 1, temp.length() - dou_index - 1).c_str());
            int random = (rand() % (max - min + 1)) + min;
           
            out << random<<endl;
        }
        else if (temp[0] == 'c') {
            char r2 = p[rand() % 52];
            out << r2 << endl;
        }
        else {
            int dou_index = 0;
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] == ',') {
                    dou_index = i;
                    break;
                }
            }
            int min = atoi(temp.substr(4, dou_index - 4).c_str());
            int max = atoi(temp.substr(dou_index + 1, temp.length() - dou_index - 1).c_str());
            int len = (rand() % (max - min + 1)) + min;
            string r3 = "";
            for (int i = 0; i < len; i++) {
                r3.push_back(p[rand() % 52]);
            }
            out << r3 << endl;
        }
    }
    in.close();
    out.close();
}
