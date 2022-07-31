#include <iostream>
// 静态链接 mirai-cpp 要在引入头文件前定义这个宏
#define MIRAICPP_STATICLIB
#include <mirai.h>
#include <mirai/events/MemberJoinEvent.hpp>

using namespace std;
using namespace Cyan;
int main(int argc, char *argv[])
{
    MiraiBot bot;
    SessionOptions opts = SessionOptions::FromCommandLine(argc, argv);
    bot.Connect(opts);
    cout << "Bot working..." << endl;
    bot.On<Message>(
        [](Message m)
        {
            m.Reply(m.MessageChain);
        });
    char ch;
    while ((ch = getchar()) != 'q')
        ;
    bot.Disconnect();
}