#include <iostream>
#include<time.h>

using std::cout; using std::endl;
#define chk_sec 2 // 2√ 

int main()
{
    time_t chk_prvsec = time(nullptr);
    cout << chk_prvsec << endl;
    int count = 0;

    time_t sec;

    while (count !=3 )    {
        sec = time(nullptr);
        if (sec - chk_prvsec >= chk_sec)
        {
            chk_prvsec = sec;
            count++;
            cout << count << "»∏" << endl;
        }
    }


    return 0;
}