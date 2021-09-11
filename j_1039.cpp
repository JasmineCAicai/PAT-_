#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

 int main() {
     unordered_map<string, int> name;
     vector<string> nameList;
     vector<vector<int>> stuCourses;
     vector<vector<string>> enrolls;
     
     int N, K;
     cin >> N >> K;
     int totalStudents = N;
     for (int i = 0; i < K; i++) {
         vector<string> tmp;
         enrolls.push_back(tmp);
     }
     
     while (K > 0) {
         int courseInd, totalStudents;
         cin >> courseInd >> totalStudents;
         string stuName;
         for (int i = 0; i < totalStudents; i++) {
             cin >> stuName;
             enrolls[courseInd-1].push_back(stuName);
         }
         K--;
     }
     
     int tmp = 0;
     while (tmp < N) {
         string stuName;
         cin >> stuName;
         name[stuName] = tmp;
         nameList.push_back(stuName);
         tmp++;
     }
     
     for (int i = 0; i < N; i++) {
         vector<int> tmp;
         tmp.push_back(0);
         stuCourses.push_back(tmp);
     }
     
     int sizeCourses = enrolls.size();
     for (int i = 0; i < sizeCourses; i++) {
         for (int j = 0; j < enrolls[i].size(); j++) {
             int index = name[enrolls[i][j]];
             stuCourses[index][0]++;
             stuCourses[index].push_back(i+1);
         }
     }
     
     for (int i = 0; i < totalStudents; i++) {
         cout << nameList[i];
         cout << " " << stuCourses[i][0];
         for (int j = 1; j < stuCourses[i].size(); j++) {
             cout << " " << stuCourses[i][j];
         }
         cout << endl;
     }
     
     return 0;
 }
