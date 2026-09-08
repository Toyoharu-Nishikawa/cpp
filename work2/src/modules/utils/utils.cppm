export module utils;

import std; // 標準ライブラリのインポート（C++20/C++23）

export namespace utils {
    void print_message(const char* msg) {
        std::cout << "[Utils] " << msg << std::endl;
    }
}
