class Honey {
	Honey() {

	}
	~Honey() {

	}
public:
	Honey(Honey& other) = delete;

	static Honey &GetInstance() {
		static Honey honey;
		return honey;
	}
	static void SetHoneyVolume(int volume) {
		if (GetHoneyVolume() >= GetMaxCapacity()) {
			GetInstance().SetFilledUp(true);
		}
		else {
			GetInstance().honeyVolume += volume;
		}
	}
	static void SetFilledUp(bool status) {
		GetInstance().filledUp = status;
	}
	static int GetHoneyVolume() {
		return GetInstance().honeyVolume;
	}
	static int GetMaxCapacity() {
		return GetInstance().maxCapacity;
	}
	void operator=(const Honey&) = delete;
private:
	int honeyVolume;
	bool filledUp =false;
	int maxCapacity = INT_MAX;
};