# smart_pointers
This is my simple realization of smart pointers for better understanding of us.
# Usage
At the moment, simple analogue of a std::unique_ptr<T> has been implemented.
```c++
unique_pointer<int> ptr1(new int(4));
unique_pointer<int> ptr2(std::move(ptr1));
```
# Example
```c++
int* a = new int(55);
int* b = new int(45);

unique_pointer<int> ptr1(new int(4));
// unique_pointer<int> ptr2(ptr1); ERROR
unique_pointer<int> ptr2(std::move(ptr1));

std::cout << "ptr1 value is nullptr? ";
if (ptr1.get() == nullptr)
	std::cout << "yes" << std::endl;
else
	std::cout << "no, it's " << *ptr1 << std::endl;

std::cout << "ptr2 value is nullptr? ";
if (ptr2.get() == nullptr)
	std::cout << "yes" << std::endl;
else
	std::cout << "no, it's " << *ptr2 << std::endl;
```
Output:
```
ptr1 value is nullptr? yes
ptr2 value is nullptr? no, it's 4
```