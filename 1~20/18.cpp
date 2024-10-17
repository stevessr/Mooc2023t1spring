#include <iostream>
#include <vector>
#include <algorithm>  // 用于std::max_element和std::min_element
using std::cout, std::endl, std::cin, std::vector;

int main(){
    int times, temp;
    cin >> times;  // 输入序列的个数
    vector<int> alpha;

    // 读取输入数据
    for (int i = 0; i < times; i++){
        cin >> temp;
        alpha.push_back(temp);
    }

    // 找到最大值和最小值
    auto maxPosition = std::max_element(alpha.begin(), alpha.end());
    auto minPosition = std::min_element(alpha.begin(), alpha.end());

    // 输出最大跨度值
    cout << (*maxPosition - *minPosition) << endl;

    return 0;
}
