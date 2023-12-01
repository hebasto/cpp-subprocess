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
  std::string command = "python3 " + std::string(argv[0]) + ".py";
  test_redirection(command);
  return 0;
}
