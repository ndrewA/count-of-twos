#include <iostream>

size_t countTwos(const int& n)
{
    int cnt = 0;
    size_t tenPower = 1;
    int nCopy = n;
    while(nCopy)
    {
        int curDigit = nCopy%10;
        int nextNum = nCopy/10;
        int lastCnt = cnt;
        if(curDigit > 2) {
            cnt += (nextNum+1)*tenPower;
        } else if(curDigit == 2) {
            if(nextNum == 0) cnt += n%tenPower + 1;
            else cnt += nextNum*tenPower + n%tenPower;
        } else if(curDigit < 2 && nextNum != 0) {
            cnt += nextNum*tenPower;
        }
        tenPower *= 10;
        nCopy/=10;
    }
    return cnt;
}

int main()
{
    size_t res = countTwos(100);
    std::cout << "res = " << res << '\n';
    return 0;
}
