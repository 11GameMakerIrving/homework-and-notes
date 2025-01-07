#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <time.h>  
using namespace std;

int main() {
    time_t now1,now2;
    char buffer[90];
    time(&now1);
    now2 = time(0);
      //identical

    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&now1));

    // 打印当前时间（以秒为单位）  ,from 1970/1/1
    cout << asctime(localtime(&now1))<< endl;
    cout << now2 << endl;
    cout << buffer << endl;
   /* printf("Current time: %s\n", asctime(localtime(&now1)));
    printf("Current time: %ld\n", now2);*/
   
    return 0;
}
