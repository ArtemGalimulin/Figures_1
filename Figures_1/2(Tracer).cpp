#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>

class Tracer {
  std::vector<std::string> calls;
public:
  Tracer() {
    calls = {};
  }
  void Message(std::string s) {
    time_t now = time(nullptr);
    std::tm local_time = {};
    localtime_s(&local_time, &now);
    char time_buffer[100];
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", &local_time);
    std::string time(time_buffer);
    std::string call = "Message time: " + time + ". Message: " + s;
    calls.push_back(call);
    std::cout << call << '\n';
  }
  void All_messages() const {
    for (int i = (int)calls.size() - 1; i >= 0; i--) {
      std::cout << calls[i] << '\n';
    }
  }
};
int main() {
  Tracer tracer;
  std::string s1;
  std::string s2;
  std::cin >> s1 >> s2;
  tracer.Message(s1);
  std::this_thread::sleep_for(std::chrono::seconds(5));
  tracer.Message(s2);
  std::this_thread::sleep_for(std::chrono::seconds(5));
  tracer.All_messages();
  return 0;
}