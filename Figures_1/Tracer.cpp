#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <source_location>

class Tracer {
  struct Entry {
    std::string message;
    std::string time;
    std::string function;
    std::string file;
    unsigned int line;

    Entry(const std::string& msg, const std::string& tm,
          const std::string& func, const std::string& file, int l)
        : message(msg), time(tm), function(func), file(file), line(l) {}
    void Print() const {
      std::cout << "---------------------------------------------" << '\n';
      std::cout << message << ", Time: " << time << ", File: " << file
                << ", Line: " << line << '\n';
    }
  };
  static std::vector<Entry> stack_history;
  static std::string Now() {
    std::time_t t =
        std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    char buf[26];
    ctime_s(buf, sizeof(buf), &t);
    buf[24] = '\0';
    return std::string(buf);
  }
  std::string function;
  std::string time;
  std::string file;
  unsigned int line;

 public:
  Tracer(const std::source_location& source = std::source_location::current())
      : function(source.function_name()),
        time(Now()),
        file(source.file_name()),
        line(source.line()) {
    std::string message = "Entry into " + function;
    Entry current_entry = Entry(message, Now(), function, file, line);
    stack_history.push_back(current_entry);
    std::cout << "---------------------------------------------" << '\n';
    std::cout << message << ", Time: " << time << ", File: " << file
              << ", Line: " << line << '\n';
  }
  ~Tracer() {
    std::string message = "Exit from " + function;
    Entry current_entry = Entry(message, Now(), function, file, line);
    stack_history.push_back(current_entry);
    std::cout << "---------------------------------------------" << '\n';
    std::cout << message << ", Time: " << Now() << ", File: " << file
              << ", Line: " << line << '\n';
  }
  void HistoryPrint() {
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << '\n';
    std::cout << "Stack:" << '\n';
    for (unsigned int i = 0; i < stack_history.size(); i++) {
      stack_history[i].Print();
    }
    std::cout << "End of stack" << '\n';
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << '\n';
  }
};

std::vector<Tracer::Entry> Tracer::stack_history;

void f(int x) {
  Tracer t1;
  std::cout << x << '\n';
}

void g() {
  Tracer t2;
  f(1);
}

//int main() {
//  Tracer t;
//  g();
//  t.HistoryPrint();
//}
