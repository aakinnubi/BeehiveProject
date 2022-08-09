// BeehiveProject.cpp : Defines the entry point for the application.
//

#include "BeehiveProject.h"
#include <thread>
#include "Header Files/Beehive.h"
#include <mutex>
#include <atomic>
#include "Header Files/Honey.h"
#include "Header Files/Farmer.h"

using namespace std;
int waitTime = 20;
mutex pencil;
void ProduceHoney(int _width, int _height, int _length, int _volume, bool start) {
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	int height = _height;
	int length = _length;
	int volume = _volume;
	int width = _width;
	int size = (width) * (length) * (height);
	int v = volume;
	if (v >= size) {
		cout << "The heeive is filled with Honey already. "
			"or volume bigger than heeive capacity.Volume specified is : " << to_string(v) << " while th capacity is : " << to_string(size) <<endl << "\n";
	}
	else {
		pencil.lock();
		waitTime = (rand() % 20) + 5;
		Beehive::SetWaitTime(waitTime);
		int wait = waitTime; 
		Beehive::SetHeight(height);
		Beehive::SetWidth(height);
		Beehive::SetLength(length);
		Beehive::SetVolume(volume);
		Beehive::SetProduce(true);
		cout << "Another Beehives is currently producing... " << endl << "\n";
			cout << "Wait time has decreament to : " << wait << "\n";
		wait = Beehive::WaitTime();
		if (wait == 0) {
			std::cout << Beehive::GetVolume() << "\n";
			int currentBeehiveVolume = Beehive::GetVolume();
			Honey::SetHoneyVolume(currentBeehiveVolume);
			pencil.unlock();
			cout << "Beehives is done producing... another beehives starts immediately" << endl << "\n";
			string message = "Honey is currently having the volume of " + to_string(Honey::GetHoneyVolume());
			cout << message << endl << "\n";
		}
	
	}

}

void FarmerTakeHoney() {
	pencil.lock();
	int i = 0;
	int previousHoneyValue = (Honey::GetHoneyVolume());
	while (Honey::GetHoneyVolume() > 0 && Honey::GetHoneyExist() && (Honey::GetHoneyVolume() -i) > 0 ) {
		int newVolumeFarmer = Honey::TakeHoney(i);
		Farmer::SetIsCurrentlyTakingHoney(true);
		Farmer::SetQuantityToBeTaken(newVolumeFarmer);
		/*pencil.unlock();*/
		++i;
	}
	pencil.unlock();
	string message = "Honey is currently having the volume of " + to_string(Honey::GetHoneyVolume()) +"  but the previous value was : "+to_string(previousHoneyValue);
	cout << message << endl << "\n";
}
int main()
{
	cout << "Hello CMake." << endl;
	/*vector<std::thread> threads = {
	
	};*/

	std::thread t1(ProduceHoney,20,20,300,30000,true);
	std::thread t2(ProduceHoney, 20, 20, 300, 30000, true);
	std::thread t3(ProduceHoney, 20, 20, 300, 30000, true);
	std::thread t4(ProduceHoney, 20, 20, 300, 30000, true);
	if (t1.joinable()) {
		t1.join();
	}
	if (t2.joinable()) {
		t2.join();
	}
	if (t3.joinable()) {
		t3.join();
	}
	if (t4.joinable()) {
		t4.join();
	}
	std::thread farmerThread(FarmerTakeHoney);
	if (farmerThread.joinable()) {
		farmerThread.join();
	}
	return 0;
}


//Beehive task :
//Create a small program that creates 4 beehive threads that all produce honey.
//They all produce their honey after some random number of seconds between 5 - 15 seconds. [sleep before moving next]
//When a beehive has produced honey it places in some static container object that holds a single instance of honey.
//If the container already has a honey instance in it then the beehives need to wait until the container is free and empty.
//Be careful that multiple threads don't try to place honey there at the same time!
//The farmer thread will take honey from the container if honey exists.
//You also need to be careful again that it is not touching the container when the beehives are touching it.
//You can represent an instance of honey with a boolean to keep things simple.
//For additional challenge change the 5 - 15 second timer on the beehives to waiting to see if 1 of 4 flower objects has produced any pollen.
//The flowers can produce pollen at a set rate or random rate

