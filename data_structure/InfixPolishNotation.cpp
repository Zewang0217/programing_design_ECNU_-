#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <cmath>
#include "Stack.h"

using namespace std;

//优先级
int precedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}

double applyOp(double left, double right, char op) {
	switch (op) {
	case '+': return left + right;
	case '-': return left - right;
	case '*': return left * right;
	case '/': return left / right;
	}
	return 0;
}

/*
int main() {
	string expr;
	getline(cin, expr);

	bool hasDot = (expr.find('.') != string::npos);//静态变量，指没找到

	Stack<double> operands;//数
	Stack<char> ops;//运算符

	//开始运算
	int i = 0;
	while (i < expr.size()) {
	    //跳过空格
		if (isspace(expr[i])) {
			i++;
			continue;
		}

		//遇到‘（’就直接入栈（运算符栈）
		if (expr[i] == '(') {
			ops.push(expr[i]);
			i++;
		}

		//遇到‘）’就一直pop数栈直到遇到‘（’
		else if (expr[i] == ')') {
			char topOp;
			while (!ops.isEmpty()) {
				ops.top(topOp);
				if (topOp == '(') {
					break;
				}
				ops.pop();

				double right, left;
				operands.top(right);
				operands.pop();
				operands.top(left);
				operands.pop();

				double res = applyOp(left, right, topOp);

				operands.push(res);
			}
			if (!ops.isEmpty()) {
				ops.pop();
			}
			i++;
		}

		//处理数字、小数点、一元负号
		else if (isdigit(expr[i]) || expr[i] == '.' ||
			(expr[i] == '-' && (i == 0 || expr[i - 1] == '(' || expr[i - 1] == '+' ||
				expr[i - 1] == '-' || expr[i - 1] == '*' || expr[i - 1] == '/'))) {
			bool negative = false;
			if (expr[i] == '-') {
				negative = true;
				i++;
			}
			double val = 0;

			//整数
			while (i < expr.size() && isdigit(expr[i])) {
				val = val * 10 + (expr[i] - '0');
				i++;
			}

			if (i < expr.size() & expr[i] == '.') {
				i++;
				double factor = 0.1;
				while (i < expr.size() && isdigit(expr[i]) ){
					val += (expr[i] - '0') * factor;
					factor *= 0.1;
					i++;
				}
			}
			if (negative) {
				val = -val;
			}

			operands.push(val);
		}


		//遇到运算符+-
		else {
			char currOp = expr[i];
			char topOp;

			while (!ops.isEmpty()) {
				ops.top(topOp);
				if (topOp == '(') {
					break;
				}
				if (precedence(topOp) >= precedence(currOp)) {
					ops.pop();
					double right, left;
					operands.top(right);
					operands.pop();
					operands.top(left);
					operands.pop();

					double res = applyOp(left, right, topOp);
					operands.push(res);
				}
				else {
					break;
				}
			}
			ops.push(currOp);
			i++;
		}
	}

	char op;
	while (!ops.isEmpty()) {
		ops.top(op);
		ops.pop();
		double right, left;
		operands.top(right);
		operands.pop();
		operands.top(left);
		operands.pop();

		double res = applyOp(left, right, op);
		operands.push(res);
	}

	double finalResult;
	operands.top(finalResult);

	if (hasDot || fabs(finalResult - round(finalResult)) > 1e-9) {
		cout << fixed << setprecision(3) << finalResult;
	}
	else {
		cout << (long long)round(finalResult);
	}

	return 0;
}*/

/*详解处理运算符部分（优先级)
Step 1️⃣ 读取当前运算符

char currOp = expr[i];  // 读取当前的运算符
当代码执行到 else 这里时，说明 expr[i] 是 +、-、* 或 / 之一，我们将其存入 currOp。

Step 2️⃣ 处理栈顶运算符

while (!ops.isEmpty()) {
	ops.top(topOp);  // 读取栈顶运算符（但不弹出）
只要运算符栈 ops 不是空的，就一直检查栈顶运算符 topOp。
ops.top(topOp) 只是读取 栈顶运算符的值，并不会把它弹出。
Step 3️⃣ 遇到左括号，停止计算

if (topOp == '(') {
	break;  // 遇到 '(' 说明优先级受限，停止计算
}
如果栈顶运算符是 (：

说明我们在处理一对括号 (...) 里面的内容。
不能在 ) 之前执行运算，所以 直接停止 计算。

Step 4️⃣ 处理优先级较高的运算符

if (precedence(topOp) >= precedence(currOp)) {
	ops.pop();  // 弹出栈顶运算符
如果 topOp 的优先级 >= currOp：
topOp 先计算！
例如：

2 * 3 + 4
   ↑   ↑
   |    |
 topOp currOp
* (topOp) 的优先级比 + (currOp) 高，所以 先计算 2 * 3。
Step 5️⃣ 计算栈顶运算符的结果

double right, left;
operands.top(right);
operands.pop();
operands.top(left);
operands.pop();
先从 operands 栈 取出 右操作数（right）。
再取出左操作数（left）。

double res = applyOp(left, right, topOp);
调用 applyOp(left, right, topOp) 计算结果。
注意！ 计算次序是 左 -> 右，即：

left topOp right
例如：  2 * 3
先 2（左操作数）
再 3（右操作数）
最后 *（运算符）

operands.push(res);
计算的 结果入栈，以备后续计算使用。
Step 6️⃣ 低优先级运算符停止计算

else {
	break;  // 遇到低优先级的运算符，停止计算
}
如果 topOp 的优先级 低于 currOp，停止计算：


2 + 3 * 4
  ↑   ↑
  |   |
topOp currOp
+ (topOp) 的优先级低于 * (currOp)。
所以不能先算 2 + 3，应该 先把 * 入栈，让 3 * 4 先算。
Step 7️⃣ 当前运算符 currOp 入栈

ops.push(currOp);
i++;
当前运算符 currOp 入栈，等待后续计算。
索引 i++，继续处理下一个字符。
*/