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
		if (GetHoneyVolume() > 0) {
			SetHoneyExist(true);
		}
	}
	static void DecreaseHoneyVolume(int volume) {
	
		GetInstance().honeyVolume = GetInstance().honeyVolume- volume;
	}
	static int TakeHoney(int volume) {
		if (GetHoneyVolume() > 0 && GetHoneyVolume() > volume) {
			int _volume = GetInstance().honeyVolume- volume;
			GetInstance().honeyVolume = _volume;
		/*	GetInstance().SetHoneyVolume(GetInstance().honeyVolume);*/
			return volume;
		}
		else {
			GetInstance().SetHoneyVolume(0);
			return 0;
		}
	}
	static void SetHoneyExist(bool status) {
		 GetInstance().honeyExist  = GetInstance().GetHoneyVolume() > 0 ? true: GetInstance().honeyExist = false;
	/*	if (GetInstance().honeyVolume > 0) {
			GetInstance().honeyExist = true;
		}
		else {
			GetInstance().honeyExist = false;
		}*/
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
	static bool GetHoneyExist() {
		return GetInstance().honeyExist;
	}
	void operator=(const Honey&) = delete;
private:
	int honeyVolume=0;
	bool filledUp =false;
	int maxCapacity = INT_MAX;
	bool honeyExist = false;
};