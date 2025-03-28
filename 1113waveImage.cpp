#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// ���ɲ���ͼ
std::vector<std::string> generateWaveform(const std::string& s) {
    int n = s.length();
    std::vector<std::vector<char>> rows(n, std::vector<char>(n, ' '));
    int currentRow = 0;
    rows[currentRow][0] = s[0];

    for (int i = 1; i < n; ++i) {
        if (s[i] > s[i - 1]) {
            --currentRow;
        }
        else if (s[i] < s[i - 1]) {
            ++currentRow;
        }
        rows[currentRow][i] = s[i];
    }

    // ȥ������Ŀ���
    std::vector<std::string> nonEmptyRows;
    for (const auto& row : rows) {
        bool isEmpty = true;
        for (char c : row) {
            if (c != ' ') {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            std::string line(row.begin(), row.end());
            // ȥ��ÿ���Ҷ˵Ķ���ո�
            while (!line.empty() && line.back() == ' ') {
                line.pop_back();
            }
            nonEmptyRows.push_back(line);
        }
    }
    return nonEmptyRows;
}

int main() {
    std::string input;
    while (std::getline(std::cin, input)) {
        std::vector<std::string> waveform = generateWaveform(input);
        for (const auto& line : waveform) {
            std::cout << line << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}