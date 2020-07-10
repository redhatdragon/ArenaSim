#pragma once
#include <Entt.h>
#include "PhysicsEngineConvex.h"
#include "Asset.h"

// So far this looks too difficult to make properly dynamic enough for these types of mechanics.

struct Health {
	uint32_t current;
	uint32_t max;

	float getHealthPercentage() {
		current / max;
	}
	// Return remaining health after damage
	uint32_t damage(uint32_t num) {
		if (num > current)
			current = 0;
		current -= num;
		return current;
	}
};
struct Mana {
	uint32_t current;
	uint32_t max;

	// Return if success
	bool spend(uint32_t num) {
		if (num > current)
			return false;
		current -= num;
		return true;
	}
};

struct GearSlotType {
	uint32_t type;
};

struct Ability {

};
struct HasteOnProc: public Ability {
	float chance;
	uint32_t amount;
	HasteOnProc(float _chance, uint32_t _amount) {
		chance = _chance;
		amount = _amount;
	}
};

struct Gear {
	std::string slotType;
	uint32_t durability;

	std::vector<Ability*> abilities;
	Gear(const std::string& _slotType, uint32_t _durability) {
		slotType = _slotType;
		durability = _durability;
	}
	void addAbility(Ability *ability) {
		abilities.push_back(ability);
	}
};

entt::registry reg;
PhysicsEngine physics;

void makePally(int x, int y) {
	auto pally = reg.create();
	BodyID bodyID = physics.addBodyRect(x, y, 64, 64);
	physics.setUserData(bodyID, (void*)pally);
	reg.emplace<BodyID>(pally, bodyID);
	reg.emplace<TextureID>(pally, TextureCodex::add("data/Pally.png"));

	Health health = { 1000, 1000 };
	reg.emplace<Health>(pally, health);
	Mana mana = { 100, 100 };
	reg.emplace<Mana>(pally, mana);

	Gear helment = Gear("helment", 40);
	Ability *hasteOnProc = new HasteOnProc(5, 250);
	helment.addAbility(hasteOnProc);
	reg.emplace<Gear>(pally, helment);
}