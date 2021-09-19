# smart_pointers
This is my simple realization of smart pointers for better understanding of us.
# Usage
At the moment, simple analogue of a std::unique_ptr<T> has been implemented.
```c++
unique_pointer<int> ptr1(new int(4));
unique_pointer<int> ptr2(std::move(ptr1));
```