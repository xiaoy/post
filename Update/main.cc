/*****************************************
* Notice:c++11 示例代码,用于说明游戏循环逻辑
* Author:wulongfei
* Email:zgwulongefei@gmail.com
* Date:2016-2-10
*****************************************/

#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

static const long kMilliSecondsPerFrame = 1000;
static const float kFixedTime = 0.2f;
void FixedUpdate(){
    std::cout<< "FixedUpdate\n";
}
void Update(){
    std::cout<< "Update\n";
}
void LateUpdate(){
    std::cout<< "LateUpdate\n";
}
int main(){
    clock_t t = clock();
    while(true){
        float detTime = (clock() - t)/(float)CLOCKS_PER_SEC + kMilliSecondsPerFrame/1000;
        t = clock();
        int count = detTime/kFixedTime;
        for(int i = 0; i < count; ++i){
            FixedUpdate();
        }
        Update();
        LateUpdate();
        std::this_thread::sleep_for(std::chrono::milliseconds(kMilliSecondsPerFrame));
    }
}
