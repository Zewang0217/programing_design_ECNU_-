+ 这个文件夹用于存放关于数据结构的一些实现与应用
+ 同样的，每个文件都有注释，需要自己去除





+ 注意：因为使用了类模板，所以类的方法都在头文件中



## 中序波兰式

读取运算符步骤详解（优先级）

## **Step 1️⃣ 读取当前运算符**

```cpp
char currOp = expr[i];  // 读取当前的运算符
```

当代码执行到 `else` 这里时，说明 `expr[i]` 是 `+`、`-`、`*` 或 `/` 之一，我们将其存入 `currOp`。

------

## **Step 2️⃣ 处理栈顶运算符**

```cpp
while (!ops.isEmpty()) {  
    ops.top(topOp);  // 读取栈顶运算符（但不弹出）
```

- 只要**运算符栈 `ops` 不是空的**，就一直检查栈顶运算符 `topOp`。
- `ops.top(topOp)` **只是读取** 栈顶运算符的值，并不会把它弹出。

------

## **Step 3️⃣ 遇到左括号，停止计算**

```cpp
if (topOp == '(') {  
    break;  // 遇到 '(' 说明优先级受限，停止计算
}
```

如果栈顶运算符是 `(`：

- 说明我们在处理一对括号 `(...)` 里面的内容。
- 不能在 `)` 之前执行运算，所以 **直接停止** 计算。

------

## **Step 4️⃣ 处理优先级较高的运算符**

```cpp
if (precedence(topOp) >= precedence(currOp)) {  
    ops.pop();  // 弹出栈顶运算符
```

- 如果 `topOp` 的优先级 `>=` `currOp`

  ：

  - **`topOp` 先计算！**

  - 例如：

    ```css
    2 * 3 + 4
       ↑   ↑
       |   |
    topOp currOp
    ```

    - `*` (`topOp`) 的优先级比 `+` (`currOp`) 高，所以 **先计算 `2 \* 3`**。

------

## **Step 5️⃣ 计算栈顶运算符的结果**

```cpp
double right, left;
operands.top(right);
operands.pop();
operands.top(left);
operands.pop();
```

- **先从 `operands` 栈** 取出 **右操作数**（`right`）。
- **再取出左操作数**（`left`）。

```cpp
double res = applyOp(left, right, topOp);
```

- 调用 `applyOp(left, right, topOp)` 计算结果。

- 注意！

   计算次序是 

  左 -> 右

  ，即：

  ```css
  left topOp right
  例如：  2 * 3
  ```

  - 先 `2`（左操作数）
  - 再 `3`（右操作数）
  - 最后 `*`（运算符）

```cpp
operands.push(res);
```

- 计算的 **结果入栈**，以备后续计算使用。

------

## **Step 6️⃣ 低优先级运算符停止计算**

```cpp
else {  
    break;  // 遇到低优先级的运算符，停止计算
}
```

如果 `topOp` 的优先级 **低于** `currOp`，停止计算：

- 例如：

  ```css
  2 + 3 * 4
    ↑   ↑
    |   |
  topOp currOp
  ```

  - `+` (`topOp`) 的优先级低于 `*` (`currOp`)。
  - 所以不能先算 `2 + 3`，应该 **先把 `\*` 入栈**，让 `3 * 4` 先算。

------

## **Step 7️⃣ 当前运算符 `currOp` 入栈**

```cpp
ops.push(currOp);
i++;
```

- **当前运算符 `currOp` 入栈**，等待后续计算。
- **索引 `i++`，继续处理下一个字符**。