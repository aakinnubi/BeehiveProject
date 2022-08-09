#pragma once
class Farmer {
	Farmer() {

	}
	~Farmer() {

	}
public:
	Farmer(Farmer& other) = delete;

	static Farmer& GetInstance() {
		static Farmer farmer;
		return farmer;
	}

	void operator=(const Farmer&) = delete;

	static void SetQuantityToBeTaken(int quantity) {
		GetInstance().quantityToBeTaken += quantity;
	}
	static void SetHoneyQuantity(int honeyQ) {
		GetInstance().honeyQuantity += honeyQ;
	}
	static void SetIsCurrentlyTakingHoney(bool status) {
		GetInstance().isCurrentlyTakingHoney = status;
	}
	static int  GetQuantityToBeTaken() {
		return GetInstance().quantityToBeTaken;
	}
	static int GetHoneyQuantity() {
		return GetInstance().honeyQuantity;
	}
	static bool GetIsCurrentlyTakingHoney() {
		return GetInstance().isCurrentlyTakingHoney;
	}
private:
	int quantityToBeTaken = 0;
	int honeyQuantity = 0;
	bool isCurrentlyTakingHoney = false;
};