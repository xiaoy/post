/*****************************************
* Notice:c++ 示例代码,用于说明游戏循环逻辑
* Author:wulongfei
* Email:zgwulongefei@gmail.com
* Date:2016-2-10
*****************************************/
#include <iostream>


void FixedUpdate(){}
void Update(){}
void LateUpdate(){}

int main(){
    while(true){
        FixedUpdate();
        Update();
        LateUpdate();
    }
}
