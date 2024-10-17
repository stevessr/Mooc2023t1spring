#include <iostream>
using namespace std;

int main() {
    long M, N, X;
    cin >> M >> N >> X;
    
    long currentPower = N;  // 当前战斗力
    long currentEnergy = X;  // 当前剩余的能量元素
    
    while (currentEnergy > 0) {
        // 计算需要多少个能量元素来恢复满体力M
        long energyNeeded = (M + currentPower - 1) / currentPower;  // 向上取整，确保恢复到M
        
        // 如果能量元素足够，进行战斗并提升战斗力
        if (currentEnergy >= energyNeeded) {
            currentEnergy -= energyNeeded;  // 消耗能量元素
            currentPower += M / currentPower;  // 战斗力提升
        } else {
            break;  // 能量元素不足，无法恢复满体力，结束
        }
    }
    
    cout << currentPower << endl;  // 输出最大战斗力
    
    return 0;
}
