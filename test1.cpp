#include <iostream>
#include <string>

using namespace std;

// int main()
// {
// 	string str;

// 	getline(cin, str);
// 	int add = stoi(str, nullptr, 16);
// 	printf("%d\n", add);
// }

#include <iostream>   // std::cout
#include <string>     // std::string, std::stoi

int main ()
{
  std::string str_hex = "7fbce";

	// cin >> str_hex;

  int i_hex = std::stoi(str_hex,nullptr,16);

  std::cout << str_hex << ": " << i_hex << '\n';

  return 0;
}