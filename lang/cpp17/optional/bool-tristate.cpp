#include <stdio.h>
#include <optional>

struct Trool {
  std::optional<int> v;
};

void p( const Trool &t )
{
  const char* c = (const char*)&t;
  for( int i=0; i<sizeof t; i++ )
  {
    printf( "%02X ", *c++ & 0xFF);
  }
  printf( "\n" );
}

int main( int argc, char** argv )
{
  Trool a = { 0xFFFFFFFF};

  p( a );
}