#include <iostream>
#include <malloc/malloc.h>

struct Obj {
    int x;
    Obj(){
        std::cout << "ctor ";
    }

    ~Obj() {
        
    }
};

int main() {
    Obj* p = new Obj[10];

    std::cout << "p = " << p << '\n';

    delete[] p;
}
/*
(lldb) b main
Breakpoint 1: where = test`main + 16 at malloc_or_new.cpp:12:14, address = 0x0000000100002ee0
(lldb) run
Process 32654 launched: '/Users/sagarjangra/code/test' (arm64)
Process 32654 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = breakpoint 1.1
    frame #0: 0x0000000100002ee0 test`main at malloc_or_new.cpp:12:14
   9    };
   10  
   11   int main() {
-> 12       Obj* p = new Obj[10];
   13  
   14       std::cout << "p = " << p << '\n';
   15       std::cout << "malloc_size(p) = " << malloc_size(p) << '\n';
Target 0: (test) stopped.
(lldb) n
Process 32654 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = step over
    frame #0: 0x0000000100002f0c test`main at malloc_or_new.cpp:14:15
   11   int main() {
   12       Obj* p = new Obj[10];
   13  
-> 14       std::cout << "p = " << p << '\n';
   15       std::cout << "malloc_size(p) = " << malloc_size(p) << '\n';
   16  
   17       delete[] p;
Target 0: (test) stopped.
(lldb) p p
(Obj *) 0x0000000123004090
(lldb) memory read --format x --size 8 p-32 p
0x123004010: 0x0000000000000000 0x0000000000000000
0x123004020: 0x0000000000000000 0x0000000000000000
0x123004030: 0x0000000000000000 0x0000000000000000
0x123004040: 0x0000000000000000 0x0000000000000000
0x123004050: 0x0000000000000000 0x0000000000000000
0x123004060: 0x0000000000000000 0x0000000000000000
0x123004070: 0x0000000000000000 0x0000766300000000
0x123004080: 0x0000000000000004 0x000000000000000a
(lldb) 
0x123004090: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
0x1230040a0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
(lldb) quit
Quitting LLDB will kill one or more processes. Do you really want to proceed: [Y/n] y
sagarjangra@Sagars-MacBook-Air code % clang++ -g malloc_or_new.cpp -o test
sagarjangra@Sagars-MacBook-Air code % ./test
ctor ctor ctor ctor ctor ctor ctor ctor ctor ctor p = 0x133e05f50
malloc_size(p) = 0
sagarjangra@Sagars-MacBook-Air code % 

*/