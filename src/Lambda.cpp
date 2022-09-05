#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// 代替谓词使用
void sort()
{
    std::vector<int> v1{1, 2, 4, 2, 3, 56, 4};
    std::sort(v1.begin(), v1.end(), [](int &a, int &b) -> bool
              { return a < b; });
    for (auto &&i : v1)
    {
        std::cout << i << std::endl;
    }
}

// 使用外部变量
void catch_var()
{
    int a = 123;
    // 值捕获
    auto f1 = [a]()
    {
        std::cout << a << std::endl;
    };
    // 引用捕获
    std::function f2 = [&a]()
    {
        std::cout << a << std::endl;
    };
    a = 321;
    f1();
    f2();
}

int main(int argc, char const *argv[])
{
    sort();
    catch_var();
    {
        int m = [](int x) { return [](int y) { return y * 2; }(x) + 6; }(5);
        std::cout << "m:" << m << std::endl;
        //输出m:16

        std::cout << "n:" << [](int x, int y) { return x + y; }(5, 4) << std::endl; //输出n:9

        std::function gFunc = [](int x) -> std::function<int(int)> { return [=](int y) { return x + y; }; };
        auto lFunc = gFunc(4);
        std::cout << lFunc(5) << std::endl;

        auto hFunc = [](const std::function<int(int)> &f, int z)
        { return f(z) + 1; };
        auto c = hFunc(gFunc(7), 8);
        {
            int a = 111, b = 222;
            auto func = [=, &b]() mutable
            { a = 22; b = 333; std::cout << "a:" << a << " b:" << b << std::endl; };

            func();
            std::cout << "a:" << a << " b:" << b << std::endl;

            a = 333;
            auto func2 = [=, &a]
            { a = 444; std::cout << "a:" << a << " b:" << b << std::endl; };
            func2();

            auto func3 = [](int x) -> std::function<int(int)>
            { return [=](int y)
              { return x + y; }; };

            std::function<void(int x)> f_display_42 = [](int x)
            { std::cout << x << std::endl; };
            f_display_42(44);
        }
    }
    return 0;
}
