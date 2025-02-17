# Assert library
- Dùng để check xem lỗi ở đâu, lỗi như thế nào.
```bash
assert(expression);
assert(x==5 && x phải bằng 5);
```
- Có thể dùng macro để debuf
__+ #define LOG(condition, cmd) assert(condition && #cmd);__
etc.