# cctype

## `isalnum`

用于判断一个字符是否为字母或数字。

## `isalpha`

判断一个字符是否为字母。

## `isdigit`

判断一个字符是否为十进制数字（0 - 9）

## `islower`

判断一个字符是否为小写字母。

## `isupper`

判断一个字符是否为大写字母

## `isspace`

判断一个字符是否为空白字符，如空格、制表符、换行符等。

## `tolower`

将一个大写字母转换为小写字母，如果输入不是大写字母则返回原字符。

## `toupper`

将一个小写字母转换为大写字母，如果输入不是小写字母则返回原字符。









# iostram

+ cin
+ cout

## getline(std::cin, line);

+ 从输入流（std：：cin）中读取一行文本并读取到line字符串中

+ 可用于消耗行末的换行符

+ 从输入流 `ss` 里读取字符，直至遇到指定的分隔符 `.` 或者到达流的末尾，接着把读取到的内容存于 `segment` 这个字符串对象中。

  ```cpp
  getline(ss, segment, '.')
  ```

  

## find

```cpp
int posA = order.find(charA);
int posB = order.find(charB);
```

- **功能**：在 `std::string` 对象 `order` 中查找字符 `charA` 或 `charB` **第一次出现**的位置，并返回该位置的索引。如果未找到，则返回 `std::string::npos`。在 `customCompare` 函数中，通过这个方法确定字符在给定字母顺序中的位置，进而比较字符串的大小。

# algorithm 库

## reverse

+ 用于反转

+ #### `std::reverse(result.begin(), result.end());`

  - **功能**：这行代码调用了 `<algorithm>` 库中的 `std::reverse` 函数，用于反转 `result` 字符串中的字符顺序。
  - 参数解释：
    - `result.begin()`：返回一个指向 `result` 字符串第一个字符的迭代器。
    - `result.end()`：返回一个指向 `result` 字符串最后一个字符之后位置的迭代器。
  - **工作原理**：`std::reverse` 函数会交换 `[result.begin(), result.end())` 范围内的元素，使得字符串的顺序反转。例如，如果 `result` 初始值为 `"123"`，调用 `std::reverse(result.begin(), result.end());` 后，`result` 的值将变为 `"321"`。

- 



## sort

```cpp
std::sort(words.begin(), words.end(), [&](const std::string& a, const std::string& b) {
    return customCompare(a, b, order);
});
```

- **功能**：对 `words` 向量中的元素进行排序。`words.begin()` 和 `words.end()` 分别表示排序范围的起始和结束迭代器，第三个参数是一个 lambda 函数，它调用了 `customCompare` 函数，根据自定义的字母顺序规则来确定元素的排序顺序。

# vector

+ 简介
  该头文件提供了 `std::vector` 容器类。`std::vector` 是一种动态数组，能够根据需要自动调整大小。在代码中，使用 `std::vector<std::string>` 来存储从输入字符串行中分割出来的多个单词，方便后续对这些单词进行排序等操作

## std::vector<std::string>



## push_back

#### `result.push_back(sum % 10 + '0');`

- **功能**：这行代码将当前位的计算结果添加到 `result` 字符串的末尾。
- 参数解释：
  - `sum`：表示当前位相加的结果，包括进位。
  - `sum % 10`：取 `sum` 的个位数，即当前位相加后的结果。
  - `'0'`：字符 `'0'` 的 ASCII 码值。在 C++ 中，字符和整数可以相互转换，通过将 `sum % 10` 加上 `'0'`，可以将整数转换为对应的字符。例如，`0 + '0'` 得到字符 `'0'`，`1 + '0'` 得到字符 `'1'`，以此类推。
  - `result.push_back(...)`：`std::string` 类的成员函数，用于将一个字符添加到字符串的末尾。
- **工作原理**：首先计算 `sum % 10` 得到当前位的结果，然后将其转换为对应的字符，最后使用 `push_back` 函数将该字符添加到 `result` 字符串的末尾。例如，如果 `sum` 为 `12`，则 `sum % 10` 为 `2`，`2 + '0'` 得到字符 `'2'`，将 `'2'` 添加到 `result` 字符串的末尾。

## `emplace_back` 函数

`emplace_back` 是 `std::vector` 容器提供的一个成员函数，其作用是在容器的末尾直接构造一个新元素。与 `push_back` 不同，`emplace_back` 可以避免不必要的对象拷贝或移动操作，因为它是直接在容器的内存空间中构造对象。
而`emplace_back`能直接在`vector`末尾就地构造对象，传入构造`std::pair<int, int>`所需的参数即可，无需提前构造对象，效率更高，代码也更简洁。

## resize

```cpp
vector<T> v;
v.resize(new_size);
```

+ `new_size`: 新的大小

+ 如果size变大，新的元素会添加并且初始化为默认值

+ 如果size变小，则多余的元素被删除

```cpp
vector<int> v;
v.resize(5, 100);  // Resizes to 5 elements, initializing each with 100
```

## insert

1. 在指定位置插入一个元素

```cpp
iterator insert( iterator pos, const T& value );
```

- **功能**：在 `pos` 所指向的位置之前插入一个新元素，其值为 `value`。
- **返回值**：返回指向新插入元素的迭代器。

2. 在指定位置插入 n 个相同元素

```cpp
void insert( iterator pos, size_type n, const T& value );
```

- **功能**：在 `pos` 所指向的位置之前插入 `n` 个值为 `value` 的元素。
- **返回值**：无

3. 在指定位置插入另一个容器的元素范围

```cpp
template< class InputIt >
void insert( iterator pos, InputIt first, InputIt last );
```

- **功能**：在 `pos` 所指向的位置之前插入由迭代器 `first` 和 `last` 所指定范围（`[first, last)`）内的元素。
- **返回值**：无

# sstream

## isstringstream

```cpp
std::istringstream iss(line);
std::string word;
while (iss >> word) {
    words.push_back(word);
}
```

- **功能**：`std::istringstream` 可以将字符串 `line` 当作输入流处理。通过 `iss >> word` 操作，会从这个字符串流中**依次提取出**以空格分隔的单词，每次提取一个单词并存储到 `word` 中，然后将其添加到 `words` 向量里，从而实现将一行字符串分割成多个单词的功能。



## stringstream

+ `std::stringstream` 可以将字符串当作流来处理，支持向其中写入数据（输出操作）和从其中读取数据（输入操作），常用于字符串和其他数据类型之间的转换、字符串的拼接和分割等操作。
+ **`<<` 运算符**：用于向 `std::stringstream` 对象中写入数据，类似于 `std::cout`。
+ **`>>` 运算符**：用于从 `std::stringstream` 对象中读取数据，类似于 `std::cin`。

# utility

## pair



## make_pair

在 C++ 里，`make_pair` 是标准库 `<utility>` 中定义的一个函数模板，其主要作用是创建一个 `std::pair` 对象。下面从定义、使用方法、优势、示例代码几个方面详细介绍。

### 定义

`std::make_pair` 函数模板的原型如下：

```cpp
template< class T1, class T2 >
std::pair<T1,T2> make_pair( T1 t, T2 u );
```

此函数接受两个参数 `t` 和 `u`，返回一个 `std::pair<T1, T2>` 对象，其中 `T1` 和 `T2` 是根据传入参数的类型自动推导得出的。

### 优势

- **类型推导**：`make_pair` 可以自动推导传入参数的类型，不用显式指定 `std::pair` 的模板参数，让代码更简洁。例如，不用写成 `std::pair<int, const char*>(10, "hello")`，直接用 `std::make_pair(10, "hello")` 即可。
- **代码可读性**：使用 `make_pair` 能让代码更清晰，更易读，特别是在复杂的表达式中



# string

## size() 和 length()

**`size()` 和 `length()`**
 返回字符串的长度（字符数），效果相同。

```cpp
std::string s = "Hello";
std::cout << s.size();    // 输出 5
```

## empty

**`empty()`**
 判断字符串是否为空。

```cpp
if (s.empty()) { ... }
```

## clear

**`clear()`**
 清空字符串内容。

```cpp
s.clear();  // s 变为空字符串
```

## resize

**`resize(new_size)`**
 改变字符串的大小。如果增大，则新部分填充默认字符；如果减小，则截断。

```cpp
s.resize(3);  // 将 "Hello" 变成 "Hel"
```

## append

**`append()`**
 在字符串末尾追加内容。

```cpp
s.append(" World");  // 等价于 s += " World";
```

## substr（1031）

###    `if (link.substr(0, 7) == "http://")`

+ 从字符串中提取子字符串，**从0开始，提取7个**

### `currentLink.virtualAddress = link.substr(domainEnd);`

- `substr(domainEnd)` 用于从链接字符串中提取虚拟地址部分，即从域名后面的 `/` 开始到字符串末尾的部分。
- 将提取的虚拟地址赋值给 `currentLink` 结构体的 `virtualAddress` 成员变量。

## find（1031）

### `size_t protocolEnd = link.find("://");`

+ 在字符串中查找子字符串

**size_t domainEnd = link.find("/", protocolEnd + 3);**

+ 从 `protocolEnd  + 3 `这个位置开始找

## insert

**`insert()`**
 在指定位置插入字符串或字符。

```cpp
s.insert(0, "Hey, ");  // 在开头插入 "Hey, "
```



## erase

```cpp
string field;
field.erase(0, 1);
```

它的作用如下：

- **参数解释**：
  - 第一个参数 `0` 表示从字符串的索引 0（即第一个字符）开始。
  - 第二个参数 `1` 表示要删除 1 个字符。
- **具体效果**：
  - 这行代码将删除 `field` 字符串中的第一个字符。
  - 例如，如果 `field` 的值为 `" NAME"`（注意前面有一个空格），调用 `field.erase(0, 1);` 后，字符串变成 `"NAME"`。

这种用法常用于去除字符串中的不必要的前导字符，例如前面多余的空格。

## replace 

**`replace()`**
 替换字符串中一部分内容。

```cpp
s.replace(0, 3, "Hi");  // 将前3个字符替换为 "Hi"
```



## push_back()` 和 `pop_back()

分别在末尾添加一个字符和删除末尾一个字符。

```cpp
s.push_back('!');  
s.pop_back();  
```

## string::npos

`string::npos` 是 C++ 标准库中 `std::string` 类的一个静态常量，用来表示“未找到”或“无效的位置”。其值通常为 `size_t` 类型的最大值（即无符号整数的 -1），因此在字符串搜索函数（如 `find`、`rfind` 等）中，如果没有找到指定的子字符串，它们就会返回 `string::npos`。

例如：

```cpp
std::string s = "hello";
if (s.find("z") == std::string::npos) {
    std::cout << "未找到 'z'" << std::endl;
}
```

在这个例子中，`s.find("z")` 返回 `std::string::npos`，表示在字符串 `"hello"` 中没有找到字符 `'z'`。



# iomanip

## setw

**基本作用**：
 `setw(n)` 用于指定接下来输出的项至少占用 n 个字符的宽度。如果实际输出的字符数少于 n，则会在输出内容前面（或后面，取决于对齐方式）填充空格以满足宽度要求；如果实际输出字符数超过 n，则不会截断，依然全部输出。

**用法示例**：

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int num = 42;
    cout << setw(5) << num << endl;  // 输出至少5个字符宽度，如果num不足5位，会在前面填充空格
    return 0;
}
```

输出:   42

**常见搭配**：

- 与 `right` 或 `left` 搭配使用：
  使用 `setw` 设置宽度后，可以使用 `right`（默认）或 `left` 来确定内容是**右对齐**还是左对齐。

  ```
  cpp复制编辑cout << setw(10) << right << "Hello" << endl;  // "Hello" 右对齐，占10个字符宽度
  cout << setw(10) << left << "Hello" << endl;   // "Hello" 左对齐，占10个字符宽度
  ```

- 与其他格式控制符一起使用，如 `setfill` 用于设置填充字符（默认为空格）。

**注意事项**：
 `setw` 只对紧接着的输出项有效，对于后续的输出项需要再次设置宽度。

## setpresicion

设置浮点数输出的精度。与 `fixed` 或 `scientific` 搭配使用时，会控制小数点后数字的位数；否则控制总有效数字的位数。
 *示例：*

```cpp
cout << setprecision(4) << 3.1415926 << endl;
// 默认情况下可能输出 3.142（4位有效数字）
```

## fixed

**`fixed`固定`**
 使用定点格式输出浮点数。通常与 `setprecision` 配合，控制小数点后数字的个数。
 *示例：*

```cpp
cout << fixed << setprecision(2) << 3.1415926 << endl;
// 输出: 3.14
```

# cmath

## round

**作用：** 将一个浮点数四舍五入到最接近的整数。

**使用方式：**

- 例如，`round(3.4)` 返回 `3.0`；
- `round(3.5)` 返回 `4.0`；
- `round(-2.5)` 返回 `-3.0`（注意：C++ 的 round 是将 0.5 情况向远离 0 的方向舍入）。

**返回值：** 虽然返回值类型是浮点型（double），但其数值为整数。

# unordered_set

## `unordered_set()`

创建一个空的 `unordered_set`。

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> mySet;
    return 0;
}
```

## `unordered_set(InputIterator first, InputIterator last)`

使用迭代器 `first` 到 `last` 范围内的元素初始化 `unordered_set`。

```cpp
#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::unordered_set<int> mySet(vec.begin(), vec.end());
    return 0;
}
```

##  `insert(value)`

插入一个元素 `value` 到 `unordered_set` 中，如果元素已经存在，则不插入。返回一个 `std::pair<iterator, bool>`，其中 `iterator` 指向插入的元素或已存在的元素，`bool` 表示是否插入成功。

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> mySet;
    auto result = mySet.insert(10);
    if (result.second) {
        std::cout << "插入成功" << std::endl;
    }
    return 0;
}
```

## `erase(value)`

删除值为 `value` 的元素，如果元素存在则返回 `1`，否则返回 `0`。

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> mySet = {1, 2, 3};
    int count = mySet.erase(2);
    if (count == 1) {
        std::cout << "删除成功" << std::endl;
    }
    return 0;
}
```



## `erase(iterator)`

删除迭代器 `iterator` 所指向的元素，返回指向下一个元素的迭代器。

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> mySet = {1, 2, 3};
    auto it = mySet.find(2);
    if (it != mySet.end()) {
        mySet.erase(it);
    }
    return 0;
}
```

## `find(value)`

查找值为 `value` 的元素，如果找到则返回指向该元素的**迭代器**，否则返回 `end()` 迭代器。

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> mySet = {1, 2, 3};
    auto it = mySet.find(2);
    if (it != mySet.end()) {
        std::cout << "找到元素: " << *it << std::endl;
    }
    return 0;
}
```

## `count(value)`

返回值为 `value` 的元素的数量，由于 `unordered_set` 中元素**唯一**，返回值只能是 `0` 或 `1`。

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> mySet = {1, 2, 3};
    int count = mySet.count(2);
    std::cout << "元素 2 的数量: " << count << std::endl;
    return 0;
}
```

## `size()`

返回 `unordered_set` 中元素的数量。

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> mySet = {1, 2, 3};
    std::cout << "集合大小: " << mySet.size() << std::endl;
    return 0;
}
```

## `empty()`

判断 `unordered_set` 是否为空，如果为空返回 `true`，否则返回 `false`。

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> mySet;
    if (mySet.empty()) {
        std::cout << "集合为空" << std::endl;
    }
    return 0;
}
```

## `begin()`

返回指向 `unordered_set` 中第一个元素的迭代器。

## `end()`

返回指向 `unordered_set` 中最后一个元素之后位置的迭代器。

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> mySet = {1, 2, 3};
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

## `clear()`

清空 `unordered_set` 中的所有元素。

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> mySet = {1, 2, 3};
    mySet.clear();
    if (mySet.empty()) {
        std::cout << "集合已清空" << std::endl;
    }
    return 0;
}
```

# unordered_map

`unordered_map` 是 C++ 标准库中的一个容器，它位于 `<unordered_map>` 头文件中，用于存储键值对，并且可以根据键快速查找对应的值。下面是关于 `unordered_map` 的详细用法总结：

### 1. 包含头文件

在使用 `unordered_map` 之前，需要包含相应的头文件：

```cpp
#include <unordered_map>
```

### 2. 声明和初始化

可以使用以下几种方式声明和初始化 `unordered_map`：

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // 声明一个空的 unordered_map，键为 string 类型，值为 int 类型
    std::unordered_map<std::string, int> myMap;

    // 插入元素的方式初始化
    myMap["apple"] = 1;
    myMap["banana"] = 2;
    myMap["cherry"] = 3;

    // 初始化列表初始化
    std::unordered_map<std::string, int> anotherMap = {
        {"dog", 4},
        {"cat", 5},
        {"bird", 6}
    };

    return 0;
}
```

### 3. 插入元素

可以使用以下几种方法向 `unordered_map` 中插入元素：

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> myMap;

    // 使用 [] 运算符插入元素
    myMap["apple"] = 1;

    // 使用 insert 方法插入元素
    myMap.insert({"banana", 2});

    // 使用 make_pair 插入元素
    myMap.insert(std::make_pair("cherry", 3));

    return 0;
}
```

### 4. 访问元素

可以使用 `[]` 运算符或 `at()` 方法访问 `unordered_map` 中的元素：

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> myMap = {
        {"apple", 1},
        {"banana", 2},
        {"cherry", 3}
    };

    // 使用 [] 运算符访问元素
    std::cout << "Value of apple: " << myMap["apple"] << std::endl;

    // 使用 at() 方法访问元素
    std::cout << "Value of banana: " << myMap.at("banana") << std::endl;

    return 0;
}
```

### 5. 检查元素是否存在

可以使用 `find()` 方法检查某个键是否存在于 `unordered_map` 中：

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> myMap = {
        {"apple", 1},
        {"banana", 2},
        {"cherry", 3}
    };

    // 检查键 "apple" 是否存在
    if (myMap.find("apple") != myMap.end()) {
        std::cout << "Key 'apple' exists." << std::endl;
    } else {
        std::cout << "Key 'apple' does not exist." << std::endl;
    }

    return 0;
}
```

### 6. 删除元素

可以使用 `erase()` 方法删除 `unordered_map` 中的元素：

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> myMap = {
        {"apple", 1},
        {"banana", 2},
        {"cherry", 3}
    };

    // 删除键为 "banana" 的元素
    myMap.erase("banana");

    return 0;
}
```

### 7. 遍历元素

可以使用范围 for 循环或迭代器遍历 `unordered_map` 中的元素：

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> myMap = {
        {"apple", 1},
        {"banana", 2},
        {"cherry", 3}
    };

    // 使用范围 for 循环遍历
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 使用迭代器遍历
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}
```

### 8. 获取元素数量

可以使用 `size()` 方法获取 `unordered_map` 中元素的数量：

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> myMap = {
        {"apple", 1},
        {"banana", 2},
        {"cherry", 3}
    };

    std::cout << "Number of elements: " << myMap.size() << std::endl;

    return 0;
}
```

### 9. 清空 `unordered_map`

可以使用 `clear()` 方法清空 `unordered_map` 中的所有元素：

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> myMap = {
        {"apple", 1},
        {"banana", 2},
        {"cherry", 3}
    };

    // 清空 unordered_map
    myMap.clear();

    std::cout <
```

