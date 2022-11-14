
#include<iostream>
#include<string>
#include <vector>
#include <dirent.h>
using namespace std;

vector<string> bianliwenjian(string p){
    struct dirent *ptr;    
    DIR *dir;
    string PATH =p;
    dir=opendir(PATH.c_str()); 
    vector<string> files;

    while((ptr=readdir(dir))!=NULL)
    {
        if(ptr->d_name[0] == '.')
            continue;
        files.push_back(ptr->d_name);
    }  
    closedir(dir);
    return files;
    // learn from https://blog.csdn.net/adong76/article/details/39432467 thanks 
}

