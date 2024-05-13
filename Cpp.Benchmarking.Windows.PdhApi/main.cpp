#include "CPdhQuery.h"

using namespace std;

#ifdef UNICODE
#define tcout std::wcout
#else
#define tcout std::cout
#endif

void DumpMap(std::map<std::tstring, double> const& m)
{
    std::map<std::tstring, double>::const_iterator itr = m.begin();
    while (m.end() != itr)
    {
        if (itr->second > 0) // Remove this condition if you want to see all Processes including those taking 0 CPU time
        {
            tcout << itr->first << " " << itr->second << std::endl;
        }
        ++itr;
    }
    tcout << " ################################################ " << std::endl;
}

//g++ -std=c++17 "main.cpp" -o main
//g++ -std=c++14 "main.cpp" -o main

int main(int argc, char** argv)
{
    try
    {
        // uncomment to try different counter paths
        CPdhQuery pdhQuery(
            std::tstring(_T("\\Process(*)\\% Processor Time"))
            //std::tstring(L"\\Processor Information(_Total)\\% Processor Time")
            //std::tstring(_T("\\Thread(*)\\Context Switches/sec"))
            //std::tstring(_T("\\Thread(firefox/0)\\Context Switches/sec"))
            //tstring(L"\\Processor(*)\\% Processor Time")
            //tstring(_T("\\Processor(*)\\Interrupts/sec"))
            //tstring(L"\\Processor(_Total)\\Interrupts/sec")
        );
        for (int i = 0; i < 100; ++i)
        {
            Sleep(1000);
            DumpMap(pdhQuery.CollectQueryData());
        }
    }
    catch (CPdhQuery::CException const& e)
    {
        tcout << e.What() << std::endl;
    }

    return 0;
}