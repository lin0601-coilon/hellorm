#include<iostream>
#include<vector>
#include"MarkerManager.hpp"

using namespace std;


void printMarker(const Marker& m){
    cout <<"编号"<< m.id
         <<"位置("<< m.x_mm<<","<<m.y_mm
         <<"),优先级" <<m.priority << endl;
}                                                        
int countByPriority(const vector<Marker>& markers, int threshold){
    int count = 0;
    for (const Marker& m : markers){
        if (m.priority >= threshold)
        {
            ++count;
        }
    } 
    return count;
}

int main() 
{

cout <<"====='第一题演示‘====="<<endl;

//创建三条记录，存入vector
vector <Marker> markers;
markers.push_back({1,100,200,80});
markers.push_back({2,200,-50,95});
markers.push_back({3,0,0,60});

//用范围 for 循环逐条记录
cout <<"三条记录"<< endl;
for (const Marker& m : markers){
    printMarker(m);
}

//统计优先级不低于80的组
int highCount = countByPriority(markers, 80);
cout <<"优先级不低于80的组"<< highCount << endl;

//对第一条记录指针定义指针和引用
if(!markers.empty()){
   Marker* ptr = &markers[0];//指针 用&取得第一条记录的地址
   Marker& ref = markers[0];//引用 ref是第一条记录的别名

   cout <<"通过指针读取第一条记录编号"<< ptr->id << endl;
   cout <<"通过引用读取第一条记录编号"<< ref.id << endl;
}

cout << "===== ‘第二题演示‘ =====" << endl;

MarkerManager manager;

bool r1 = manager.add({1, 100, 200, 80});
bool r2 = manager.add({2, 200, -50, 95});
bool r3 = manager.add({3, 0, 0, 60});

cout << "添加编号1：" << (r1 ? "成功" : "失败") << endl;
cout << "添加编号2：" << (r2 ? "成功" : "失败") << endl;
cout << "添加编号3：" << (r3 ? "成功" : "失败") << endl;

bool r4 = manager.add({2, 300, 400, 70});
cout << "尝试添加重复编号2：" << (r4 ? "成功" : "失败") << endl;

bool r5 = manager.add({4, 10, 10, 101});
cout << "尝试添加优先级101：" << (r5 ? "成功" : "失败") << endl;

cout << "编号1是否存在：" << (manager.contains(1) ? "是" : "否") << endl;
cout << "编号2是否存在：" << (manager.contains(2) ? "是" : "否") << endl;
cout << "编号3是否存在：" << (manager.contains(3) ? "是" : "否") << endl;
cout << "编号4是否存在：" << (manager.contains(4) ? "是" : "否") << endl;

cout << "====='第三题演示'=====" << endl;

cout << "展示全部记录：" << endl;
manager.printAll();

cout << "阈值80的统计结果：" << manager.countByPriority(80) << endl;
cout << "阈值90的统计结果：" << manager.countByPriority(90) << endl;

// 空管理器演示
cout << "\n空管理器演示：" << endl;
MarkerManager emptyManager;
cout << "空管理器展示：" << endl;
emptyManager.printAll();
cout << "空管理器阈值80的统计结果：" << emptyManager.countByPriority(80) << endl;
return 0;

}