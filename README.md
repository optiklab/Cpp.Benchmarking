# Cpp.Benchmarking

This repo contains examples of benchmarking CPU usage in C++ programs on different ways and platforms.

- Using C++ Chrono API
- Using Windows GetProcessTimes() API
- Using Windows PDH API (aka Performance Counters Win32 API)
- Using POSIX clock_t
- Using POSIX clock_getcpuclockid
- etc.

Code contains links and references to the sources.

# Useful links

https://www.gnu.org/software/libc/manual/html_node/CPU-Time.html

https://man7.org/linux/man-pages/man7/posixoptions.7.html

https://habr.com/ru/articles/282301/

http://www.philosophicalgeek.com/2009/01/03/determine-cpu-usage-of-current-process-c-and-c/