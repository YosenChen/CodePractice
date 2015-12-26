#include <help_tool.h>

int main()
{
    HelpTool::Timer t;
    t.start("test");
    for (int i=0; i<1000000000; i++) ;
    t.end(1);
    t.getTime(1);

    t.start("test");
    for (int i=0; i<1000000000; i++) ;
    t.end(1);
    t.getTime(1);

    t.start("cont' test", 0);
    for (int i=0; i<2000000000; i++) ;
    t.end(1);
    t.getTime(1);

    system("pause");
    return 0;
}