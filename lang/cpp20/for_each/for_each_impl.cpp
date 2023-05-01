#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

template<typename Iterator, typename Func>
void for_each2(Iterator first, Iterator last, Func f)
{
    const size_t threads_max_count = std::thread::hardware_concurrency();
    if (threads_max_count <= 0) std::runtime_error("no thread support");

    size_t chunk_size = (last - first + threads_max_count + 1) / threads_max_count;
    std::cout << "thread count: " << threads_max_count << std::endl;
    std::cout << "chunk size: " << chunk_size << std::endl;
    std::vector<std::thread> threads(threads_max_count);
    Iterator first_chunk = first;
    for (size_t i = 0; i < threads_max_count; ++i) {
        Iterator last_chunk = (i == threads_max_count - 1) ? last : std::next(first_chunk, chunk_size);
        threads[i] = std::thread([first_chunk, last_chunk, f = std::forward<decltype(f)>(f)](){
            std::cout << "thread id: " << std::this_thread::get_id() << std::endl;
            for (Iterator itr = first_chunk; itr != last_chunk; ++itr) {
                f(*itr);
            }
        });

        first_chunk = last_chunk;
    }

    for (auto i = 0; i < threads_max_count; ++i) {
        threads[i].join();
    }
}

int main()
{
    std::vector<int> v { 1, 2, 3, 4, 5};
    for_each2(std::begin(v), std::end(v), [](int e){
        std::cout << e << '\n';
    }); 
    return 0;
}