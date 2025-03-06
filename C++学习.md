# iostram

+ cin
+ cout

## getline(std::cin, line);

+ 从输入流（std：：cin）中读取一行文本并读取到line字符串中
+ 可用于消耗行末的换行符

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

# utility

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