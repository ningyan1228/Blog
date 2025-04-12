#include <iostream>

int main() {
    int x;
    std::cin >> x;

    if (x >= 1 && x <= 100) {
        std::cout << x / 4 << std::endl;
    }
    else {
        std::cout << "输入不在有效范围内（1到100之间）" << std::endl;
    }

    return 0;
}
对于给定的三个两位数x,y,z,检查其中有多少个数字满足，个位和十位至少有一位是偶数。直接输出满足条件的数字个数
输入描述：
在一行上输入三个整数x,y,z,（x大于等于10，y，z小于等于99）代表给定的数字。
输出描述：
输出一个整数，代表满足条件的数字数量
#include <iostream>
using namespace std;

// 判断一个两位数是否至少有一位是偶数
bool hasEvenDigit(int num) {
    int tens = num / 10;
    int ones = num % 10;
    return (tens % 2 == 0 || ones % 2 == 0);
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    int count = 0;

    if (hasEvenDigit(x)) count++;
    if (hasEvenDigit(y)) count++;
    if (hasEvenDigit(z)) count++;

    cout << count << endl;

    return 0;
}
对于给定的由大小写字母混合构成的字符串s，下标从1开始，我们需要讲每一个k的倍数位进行大小写转换（即对于第k,2*k,...位）。而对于其他位置，无论大小写，直接使用其在字母表中的位置替换其在字符串中的位置（从1开始）。
输入描述
第一行输入一个正整数k（k大于等于1，小于等于10的五次方），代表进位倍数。
第二行输入一个长度为1小于等于len(s)小于等于10的五次方，由大小写字母构成的字符串s,代表需要进行操作的字符串。
输出描述：
输出一行，代表需要进行操作的字符串。

#include <iostream>
#include <string>
using namespace std;

// 获取字母在字母表中的位置（不区分大小写）
int getAlphaIndex(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 1;
    }
    else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 1;
    }
    return 0; // 理论上不会出现非字母
}

// 转换大小写
char switchCase(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a';
    }
    return c;
}

int main() {
    int k;
    string s;
    cin >> k >> s;

    string result = s; // 初始化结果字符串
    int len = s.length();

    for (int i = 0; i < len; ++i) {
        int pos = i + 1; // 下标从1开始
        if (pos % k == 0) {
            // 是k的倍数，进行大小写转换
            result[i] = switchCase(s[i]);
        }
        else {
            // 非k倍数，替换为对应字母在字母表中的位置
            int index = getAlphaIndex(s[i]);
            string indexStr = to_string(index);
            result.replace(i, 1, indexStr);
            i += indexStr.length() - 1; // 调整i以适配替换后长度变化
        }
    }

    cout << result << endl;
    return 0;
}
