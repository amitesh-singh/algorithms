- build with -g3 -fsanitize=address 
- needed to install libasan6 pkg on ubuntu
- use ldd ./newbinary to check if the libasan is linked properly
- export ASAN_OPTIONS=verify_asan_link_order=0 might be required
- run the binary
