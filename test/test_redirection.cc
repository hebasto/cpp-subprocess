#include <string>
#include <tuple>
#include <subprocess.hpp>

using namespace subprocess;

void test_redirection(const std::string& command)
{
  auto p = Popen(command, output{PIPE}, error{PIPE});
  OutBuffer out;
  ErrBuffer err;
  std::tie(out, err) = p.communicate();
  std::cout << out.buf.data() << std::endl;
  std::cout << err.buf.data() << std::endl;
}

int main(int argc, char* argv[]) {
  std::string path{argv[0]};
  if (path.size() >= 4 && path.substr(path.size() - 4) == ".exe") {
      path.resize(path.size() - 4);
  }
  std::string command = "python3 " + path + ".py";
  test_redirection(command);
  return 0;
}
