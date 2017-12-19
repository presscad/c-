#include <iostream>

#include <thread>

std::thread::id main_thread_id = std::this_thread::get_id();

void hello()
{
	std::cout << "Hello Concurrent World\n";
	if (main_thread_id == std::this_thread::get_id())
		std::cout << "This is the main thread.\n";
	else
		std::cout << "This is not the main thread.\n";
}

void pause_thread(int n) {
	std::this_thread::sleep_for(std::chrono::seconds(n));
	std::cout << "pause of " << n << " seconds ended\n";
}

int main() {
	std::thread t(hello);
	std::cout << t.hardware_concurrency() << std::endl;//���Բ���ִ�ж��ٸ�(��׼ȷ)
	std::cout << "native_handle " << t.native_handle() << std::endl;//���Բ���ִ�ж��ٸ�(��׼ȷ)
	t.join();
	std::thread a(hello);
	a.detach();
	std::thread threads[5];                         // Ĭ�Ϲ����߳�

	std::cout << "Spawning 5 threads...\n";
	for (int i = 0; i < 5; ++i)
		threads[i] = std::thread(pause_thread, i + 1);   // move-assign threads
	std::cout << "Done spawning threads. Now waiting for them to join:\n";
	for (auto &thread : threads)
		thread.join();
	std::cout << "All threads joined!\n";
}