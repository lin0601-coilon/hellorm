#include "MarkerManager.hpp"
#include <iostream>

using namespace std;

//添加记录
bool MarkerManager::add(const Marker& marker){
    if(marker.id <= 0) {
        return false;
    }
    if(marker.priority< 0 || marker.priority > 100){
        return false;
    }
    if(contains(marker.id)){
        return false;
    }
    markers_.push_back(marker);
    return true;
}

//查询编号是否存在
bool MarkerManager::contains(int id)const {
    for(const Marker& m : markers_){
        if(m.id == id){
            return true;
        }
    }
    return false;
}
//展示全部记录
void MarkerManager::printAll() const {
    if (markers_.empty()){
        cout <<"(暂无记录)"<< endl;
        return;
    }
    for (const Marker& m : markers_){
        cout <<"编号"<< m.id
             <<"位置("<< m.x_mm<<","<<m.y_mm
             <<"),优先级" <<m.priority << endl;


    }
}

//统计优先级不低于阈值的记录数
int MarkerManager::countByPriority(int threshold) const {
    int count = 0;
    for (const Marker& m : markers_) {
        if(m.priority >= threshold){
            ++count;
        }
    }
    return count;
}
