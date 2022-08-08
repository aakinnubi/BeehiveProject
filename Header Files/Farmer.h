#pragma once
class Farmer {

	~Farmer() {

	}
public:
	Farmer(Farmer& other) = delete;
	static Farmer& GetInstance() {
		static Farmer farmer;
		return farmer;
	}

	void operator=(const Farmer&) = delete;

	void SetQuantityToBeTaken(int quantity) {
		GetInstance().quantityToBeTaken = quantity;
	}
	void SetHoneyQuantity(int honeyQ) {
		GetInstance().honeyQuantity = honeyQ;
	}
	void SetIsCurrentlyTakingHoney(bool status) {
		GetInstance().isCurrentlyTakingHoney = status;
	}
	int  GetQuantityToBeTaken() {
		return GetInstance().quantityToBeTaken;
	}
	int GetHoneyQuantity() {
		return GetInstance().honeyQuantity;
	}
	bool GetIsCurrentlyTakingHoney() {
		return GetInstance().isCurrentlyTakingHoney;
	}
private:
	int quantityToBeTaken = 0;
	int honeyQuantity = 0;
	bool isCurrentlyTakingHoney = false;
};