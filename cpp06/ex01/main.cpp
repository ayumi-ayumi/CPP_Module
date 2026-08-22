#include <cstdint>
#include <iostream>

// 整数型ひとつをコールバック関数の引数として渡せるAPI
void callback_api(void(*callback)(std::intptr_t), std::intptr_t arg)
{
  callback(arg);
}

struct X {};

void on_call(std::intptr_t arg)
{
  // パラメータで渡される整数値を、元のX*に逆変換する
  X* x = reinterpret_cast<X*>(arg);
  delete x;

  std::cout << "on_call" << std::endl;
}

int main()
{
  int value = 42;

  // value変数へのポインタを、整数値として保持する
  std::intptr_t pointer_value = reinterpret_cast<std::intptr_t>(&value);
  std::cout << &value << std::endl;
  std::cout << std::hex << "0x" << pointer_value << std::endl;

  // コールバック関数の引数として、オブジェクトへのポインタを整数値に変換して渡す
  X* x = new X();
  callback_api(on_call, reinterpret_cast<std::intptr_t>(x));
}
