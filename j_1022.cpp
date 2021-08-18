#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;

struct Book{
    int ID = 10000000;
    string bookName = "";
    string author = "";
    string keywords = "";
    string publisher = "";
    string year = "";
};

Book book[10000];

string extend(int id) {
    string ID = "", idStr;
    idStr = to_string(id);
    int num=0;
    while (id < 10000000) {
        id *= 10;
        num++;
    }
    while(num>1) {
        ID += "0";
        num--;
    }
    ID += idStr;
    return ID;
}

void findID(int opt, string option) {
    //cout << option << endl;
    int id[10000] = {11111111};
    int i = 0, total = 0;
    option = option.substr(3);
    try {
        for (; i<N; i++) {
            //cout << option << endl;
            if (opt==1 && book[i].bookName == option) {
                id[total] = book[i].ID;
                total++;
            }
            if (opt==2 && book[i].author == option) {
                id[total] = book[i].ID;
                total++;
            }
            if (opt==3 && book[i].keywords.find(option)!=std::string::npos){
                id[total] = book[i].ID;
                total++;
            }
            if (opt==4 && book[i].publisher == option) {
                id[total] = book[i].ID;
                total++;
            }
            if (opt==5 && book[i].year == option) {
                id[total] = book[i].ID;
                total++;
            }
        }
        i = 0;
        if (total==0) {
            cout << "Not Found" << endl;
            return;
        }
        sort(id,id+total);
        while (i < total) {
            cout << extend(id[i]) << endl;
            i++;
        }
        return;
    } catch (exception &e){
        cout << "Exception: " << e.what() << endl;
    }
    return;
}

int main() {
    string tmpID, tmpN, tmpM;
    getline(cin,tmpN);
    N = atoi(tmpN.c_str());
    //cin >> N;
    //getchar();//吸收换行符
    //cout << N << endl;
    int i = 0;
    while (i<N) {
        //cin >> tmpID;
        getline(cin,tmpID);
        //getchar();//吸收换行符
        getline(cin,book[i].bookName);
        //cout << tmpName << endl;
        //book[i].bookName = tmpName;
        //cout << book[i].bookName << endl;
        getline(cin,book[i].author);
        getline(cin,book[i].keywords);
        getline(cin,book[i].publisher);
        getline(cin,book[i].year);
        //cin >> book[i].year;
        //getchar();//吸收换行符
        book[i].ID = atoi(tmpID.c_str());
        //cout << "ID: " << book[i].ID << endl;
        //cout << "bookName: " << book[i].bookName << endl;
        //cout <<
        i++;
    }
    //cout << endl;
    int M;
    i = 0;
    //getline(cin,M);
    getline(cin,tmpM);
    M = atoi(tmpM.c_str());
    //getchar();//吸收换行符
    string option = "";
    while (i<M) {
        getline(cin,option);
        cout << option << endl;
        //if(option[0] == '1') findID(1,option);
        switch (option[0]){
            case '1':
                findID(1,option);
                break;
            case '2':
                findID(2,option);
                break;
            case '3':
                findID(3,option);
                break;
            case '4':
                findID(4,option);
                break;
            case '5':
                findID(5,option);
                break;
            default:
                break;
        }
        i++;
    }
    return 0;
}
