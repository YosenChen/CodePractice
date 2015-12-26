#ifndef _HELP_TOOL_H_
#define _HELP_TOOL_H_

#define _WIN_OS_            1
#define _LINUX_OS_          0
#define _OS_ENV_            _WIN_OS_ //_WIN_OS_ or _LINUX_OS_

// Linux
// http://linux.die.net/man/3/clock_gettime
// clock_gettime()

// Windows
// http://stackoverflow.com/questions/2772564/get-current-time

#if _OS_ENV_ == _WIN_OS_
    //linux functions

    #include <Windows.h>
    #include <stdio.h>
    #include <cstring>

    //source: http://stackoverflow.com/questions/5404277/porting-clock-gettime-to-windows
    LARGE_INTEGER getFILETIMEoffset();
    int clock_gettime(struct timeval *tv);


    class HelpTool
    {
    public:
        class SysTime : public SYSTEMTIME
        {
            SysTime()
                : SYSTEMTIME()
            {
                wYear = wMonth = wDayOfWeek = wDay = wHour = wMinute = wSecond = wMilliseconds = 0;
            }

            void clear()
            {
                wYear = wMonth = wDayOfWeek = wDay = wHour = wMinute = wSecond = wMilliseconds = 0;
            }
            
        };

        class Timer
        {
        public:

            Timer()
                : _name("need to overwrite!")
            {
                memset(&start_tv, 0, sizeof(start_tv));
                memset(&end_tv, 0, sizeof(end_tv));
                memset(&delta_tv, 0, sizeof(delta_tv));
            }

            int start(const char* name, bool clr = 1)
            {
                clock_gettime(&start_tv);
                _name = name;

                if (clr) memset(&delta_tv, 0, sizeof(delta_tv));

                return 0;
            }
            timeval getTime(bool bPrint = 0) //call it only after end()
            {
                if (bPrint) printf("[%s] duration: %d(s) + %d(usec)\n", _name, delta_tv.tv_sec, delta_tv.tv_usec);
                return delta_tv;
            }
            timeval end(bool bPrint = 0)
            {
                clock_gettime(&end_tv);
                delta_tv.tv_sec += (end_tv.tv_sec - start_tv.tv_sec);
                delta_tv.tv_usec += (end_tv.tv_usec - start_tv.tv_usec);
                if (delta_tv.tv_usec < 0) // 1 cycle is enough
                {
                    delta_tv.tv_usec += 1000000; //10^6
                    delta_tv.tv_sec--;
                }
                if (delta_tv.tv_usec >= 1000000) // 1 cycle is enough
                {
                    delta_tv.tv_usec -= 1000000;
                    delta_tv.tv_sec++;
                }
                return getTime(bPrint);
            }

        private:
            timeval start_tv, end_tv, delta_tv;
            const char* _name;

        };

    private:
        

    };
    /*
    void main()
    {
        SYSTEMTIME st;
        GetSystemTime(&st);
        printf("Year:%d\nMonth:%d\nDate:%d\nHour:%d\nMin:%d\nSecond:% d\n" ,st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
    }
    */

#endif

#if _OS_ENV_ == _LINUX_OS_
    //linux functions

#endif

#endif