#include <iostream>
#include <fstream>
#include <unistd.h>

//horrible hack to do fsync on ofstream.. sometimes file is not written
//even on flush(). 
int GetFileDescriptor(std::filebuf& filebuf)
{
  class my_filebuf : public std::filebuf
  {
  public:
    int handle() { return _M_file.fd(); }
  };

  return static_cast<my_filebuf&>(filebuf).handle();
}

int main()
{
   std::ofstream out("test.txt");

   out << "Hello World!";
   out.flush();

   fsync(GetFileDescriptor(*out.rdbuf()));
   out.close();

   return 0;
}
