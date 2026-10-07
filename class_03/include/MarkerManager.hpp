#ifndef MARKER_MANAGER_HPP
#define MARKER_MANAGER_HPP
#include <vector>

using namespace std;

//定义 Marker 结构体
struct Marker {
   int id;
   int x_mm;
   int y_mm;
   int priority;
};

//标记配置管理器
class MarkerManager {
private:
   vector<Marker> markers_;

public:
    //添加记录：成功ture，失败false
    bool add(const Marker& marker);


    //判断编号是否存在  
    bool contains(int id)const;  

    //展示全部记录
    void printAll() const;

    //展示优先级不低于阈值的记录数
    int countByPriority(int threshold) const;

};

#endif