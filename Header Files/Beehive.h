#pragma once

#include <string>
#include <chrono>
#include <ctime>
#include <chrono>
#include <thread>  
using namespace std;
class Beehive {

protected:
    Beehive() {

   }
	Beehive(const int width, const int height, const int breadth, const int volume, const bool produce)
		:Width(width), Height(height), Length(breadth), Volume(volume),Produce(produce) {

	}
	~Beehive() {

	}

public:
  
    /**
     * Singletons should not be cloneable.
     */
    Beehive(Beehive& other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const Beehive&) = delete;
    /**
     * This is the static method that controls the access to the singleton
     * instance. On the first run, it creates a singleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */

    static Beehive &GetInstance() {
        static Beehive beehive;
        return beehive;
    }
    /**
     * Finally, any singleton should define some business logic, which can be
     * executed on its instance.
     */
    static int WaitTime() {
        return GetInstance().waitTime(GetInstance().GetWaitTime());
    }
    static void SetWaitTime(int waitSeconds) {
        GetInstance().timeToWait = waitSeconds;
    }
    static int GetWaitTime() {
      return  GetInstance().timeToWait;
    }
    static int GetVolume() {
       return GetInstance().volume();
    }
    static bool GetProduce() {
        return GetInstance().produced();
   }
    static int GetWidth() {
        return GetInstance().Width;
    }
    static int GetHeight() {
        return GetInstance().Height;
    }
    static int GetLength() {
        return GetInstance().Length;
    }
    static void SetWidth(int width) {
        GetInstance().Width = width;
    }
    static void SetHeight(int height) {
        GetInstance().Height = height;
    }
    static void SetLength(int length) {
        GetInstance().Length = length;
    }
    static void SetVolume(int volume) {
        GetInstance().Volume = volume;
    }
    static void SetProduce(bool isProduce) {
        GetInstance().Produce = isProduce;
    }
private:
	int Width = 10;
	int Height = 10;
	int Length =10;
	int Volume = 0;
	bool Produce =false;
    int timeToWait = 0;
    string getCurrentDateTime()
    {
        time_t tt;
        struct tm* st;

        time(&tt);
        st = localtime(&tt);
        return asctime(st);
    }
    int volume() const {
        return Volume;
    }
    bool produced()const {
        return Produce;
    }
    int waitTime(int waitSeconds) const {
        /* int currentValue = **waitSeconds;*/
        while (waitSeconds-- > -1) {
            if (waitSeconds == 0) {
                return waitSeconds;
                break;
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        return -1;
    }
};