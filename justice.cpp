#include"runout.h"
#include"creatin.h"

using namespace std;
int main() {
    ofstream out1("equal.csv", ios::app);
    ofstream out2("inequal.csv", ios::app);
    out1 << "file1" << ',' << "file2" << endl;
    out2 << "file1" << ',' << "file2" << endl;
    vector<string> wenjianjia = bianliwenjian("./input");

    for (int k = 0; k < wenjianjia.size(); k++) {
        vector<string> chenxulist = bianliwenjian("./input/" + wenjianjia[k]);
        for (int i = 0; i < chenxulist.size() - 1; i++) {
            for (int j = i + 1; j < chenxulist.size(); j++) {


                bool flag = true;
                if (chenxulist[i][chenxulist[i].size() - 1] == 'p' && chenxulist[j][chenxulist[j].size() - 1] == 'p') {
                    for (int t = 0; t < 8; t++) {
                        creatinput("./input/" + wenjianjia[k] + "/stdin_format.txt");

                        string caozuo = "g++ ./input/" + wenjianjia[k] + "/" + chenxulist[i];
                        system(caozuo.c_str());
                        system("./a.out <input.txt >output1.txt");

                        string caozuo2 = "g++ ./input/" + wenjianjia[k] + "/" + chenxulist[j];
                        system(caozuo2.c_str());
                        system("./a.out <input.txt >output2.txt");

                        ifstream in1("output1.txt");

                        ifstream in2("output2.txt");
                        string temp1 = "";
                        string temp2 = "";

                        while (in1 >> temp1) {

                            if (!(in2 >> temp2)) {
                                flag = false;
                                break;
                            }
                            else if (in2 >> temp2 && temp1 != temp2) {
                                flag = false;
                                break;
                            }
                        }

                        while (in2 >> temp2) {

                            if (!(in1 >> temp1)) {
                                flag = false;
                                break;
                            }
                            else if (in1 >> temp1 && temp1 != temp2) {
                                flag = false;
                                break;
                            }
                        }

                    }
                    if (flag == false) {
                        out2 << "/input/" + wenjianjia[k] + "/" + chenxulist[i] << ',' << "/input/" + wenjianjia[k] + "/" + chenxulist[j] << endl;
                    }
                    else {
                        out1 << "/input/" + wenjianjia[k] + "/" + chenxulist[i] << ',' << "/input/" + wenjianjia[k] + "/" + chenxulist[j] << endl;
                    }


                }
            }
        }



    }


}