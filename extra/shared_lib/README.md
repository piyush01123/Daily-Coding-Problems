
This is an example of creating shared library in C++ and using them in Python:

```
  g++ -fPIC -shared -o libsummer.so src.cpp
  python test.py
```

`PIC` stands for position independent code.
