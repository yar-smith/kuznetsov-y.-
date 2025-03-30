

#include <iostream>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int a;
    while (true) {
        std::cout << u8"Введите целое положительно число\n";
        std::cin >> a;
        if (a > 0) {
            break;
        }
    }
    int i = 0;
    int res = 0;
    while (i <= a) {
        res += i;
        i++;
    }
    std::cout << res << std::endl;
    int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
    int j = 0;
    while (j < std::size(arr)) {
        std::cout << arr[j] << " ";
        j++;
    }
    int k = 0;
    std::cout << "\n";
    while (k < std::size(arr)) {
        if (k % 2 == 0) {
            std::cout << arr[k] << std::endl;
        }
        k++;
    }
    int h = 0;
    int res2 = 0;
    std::cout << "\n";
    while (h < std::size(arr)) {
        if (h % 2 != 0) {
            res2 += arr[h];
        }
        h++;
    }
    std::cout << res2;

}