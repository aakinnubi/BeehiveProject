// BeehiveProject.cpp : Defines the entry point for the application.
//

#include "BeehiveProject.h"
#include <thread>
#include "Header Files/Beehive.h"
#include <mutex>
#include <atomic>
#include "Header Files/Honey.h"

using namespace std;
int waitTime = 20;
mutex pencil;
static atomic<Honey>* honey;
void ProduceHoney(int _width, int _height, int _length, int _volume, bool start) {
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	int* height = &_height;
	int* length = &_length;
	int* volume = &_volume;
	int* width = &_width;
	int size = (*width) * (*length) * (*height);
	int v = *volume;
	if (v >= size) {
		cout << "The heeive is filled with Honey already. "
			"or volume bigger than heeive capacity.Volume specified is : " << to_string(v) << " while th capacity is : " << to_string(size) <<endl;

	}
	else {
		 
		waitTime = (rand() % 20) + 5;
		int wait = Beehive::WaitTime(waitTime);

		std::cout << "Wait time has decreament to : " << wait << "\n";
		std::cout << Beehive::GetVolume() << "\n";
	}


}
int main()
{
	cout << "Hello CMake." << endl;
	std::thread t1(ProduceHoney,20,20,300,30000,true);
	std::thread t2(ProduceHoney, 20, 20, 300, 30000, true);
	std::thread t3(ProduceHoney, 20, 20, 300, 30000, true);
	std::thread t4(ProduceHoney, 20, 20, 300, 30000, true);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	return 0;
}


//Beehive task :
//Create a small program that creates 4 beehive threads that all produce honey.
//They all produce their honey after some random number of seconds between 5 - 15 seconds.
//When a beehive has produced honey it places in some static container object that holds a single instance of honey.
//If the container already has a honey instance in it then the beehives need to wait until the container is free and empty.
//Be careful that multiple threads don't try to place honey there at the same time!
//The farmer thread will take honey from the container if honey exists.
//You also need to be careful again that it is not touching the container when the beehives are touching it.
//You can represent an instance of honey with a boolean to keep things simple.
//For additional challenge change the 5 - 15 second timer on the beehives to waiting to see if 1 of 4 flower objects has produced any pollen.
//The flowers can produce pollen at a set rate or random rate

//Use case Extraction 

//1. Program can only have 4 threads
//2. The 4 Threads can all produce honey
//3. Each can only produce honey at 5 to 15 seconds
//4. after producing honey between 5-15 seconds program will wait 5 seconds before producing another
//5. Honey class must be Singleton and can only be instantiate once
//6.Honey quantity & Instance will only be available once per thread
//7.