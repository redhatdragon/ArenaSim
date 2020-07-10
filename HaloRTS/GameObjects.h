#pragma once
#include <stdint.h>
#include <string>
#include <vector>
#include <memory>
#include "PhysicsEngineConvex.h"

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

struct Modifier {

};
struct Event {

};

struct Effect {
	std::vector<Modifier> modifiers;
	std::vector<Event> onEvents;
	uint64_t timeAlive;
};
struct HasteOnProc : public Effect {
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
	void addAbility(Ability* ability) {
		abilities.push_back(ability);
	}
};
struct GearAzerite: public Gear {
	// Need stuff for azerite traits
};

class Player {
	// Maybe these should be array indexes
	std::unique_ptr<Gear> helment, shoulders, neck, chest, wrist, gloves, leggings, boots;
	BodyID bodyID;

public:
	Health health;
	Mana mana;

private:


};

enum EFFECT_ID {

	EFFECT_JUDGEMENT_OF_LIGHT
};

class Target {



};

int getTotalSpellPower(Player* player) {

}

int getTotalDamageMultiplier(Player* player) {

}

class Paladin {

public:

	float xPosition;
	float yPosition;

	Armor* AzeriteHelm = nullptr;
	Armor* AzeriteShoulders = nullptr;
	Armor* AzeriteChest = nullptr;

	float health;
	float maxHealth;

	float getHealthPercent() {

		float healthPercent = health / maxHealth;
		return healthPercent;
	}

	void Judgement(Target* target) {

		unsigned int damage = 1.125 * TotalSpellPower;
		float TargetHealthPercent = target->getHealthPercent;

		if (getHealthPercent() > TargetHealthPercent) {

			damage += getAzeriteIndomitableJusticeDamage() * (getHealthPercent() - TargetHealthPercent);
		}

		damage *= getTotalDamageMultiplier();
		DealDamage(target, DAMAGE_SCHOOL_HOLY, damage);

		if (hasTalent(TALENT_JUDGEMENT_OF_LIGHT)) { 

			applyEffect(target, this, EFFECT_JUDGEMENT_OF_LIGHT);
		}
	}



void applyEffect(Target* target, Paladin* source, EFFECT_ID) {

	switch (EFFECT_ID) {

		case EFFECT_JUDGEMENT_OF_LIGHT:
		{
			// If The Debuff is already active on the target from the same source
			if (target->hasDebuff(source, DEBUFF_JUDGEMENT_OF_LIGHT)) {

				// Refresh the debuff
				Debuff* curDebuff = getDebuff(source, DEBUFF_JUDGEMENT_OF_LIGHT);
				curDebuff->duration = 30;
				curDebuff->stacks = 25;
			}

			else {

				Debuff* tempDebuff = new Debuff();
				tempDebuff->duration = 30;
				tempDebuff->stacks = 25;
				tempDebuff->debuffID = DEBUFF_JUDGEMENT_OF_LIGHT;
				tempDebuff->source = source;
				target->debuffs[target->debuffCount] = new Debuff();
				target->debuffCount++;
			}		
		}
	}
}

void dealDamage(Target* target, Target* source, DAMAGE_SCHOOL_TYPE, float damage) {
		
	int finalDamage = (damage * target->getDamageTakenMultiplier());
	finalDamage d

	if (target->hasDebuff(DEBUFF_JUDGEMENT_OF_LIGHT)) {
			
		if (source->health < source->maximumHealth) {

			Debuff* tempDebuff = getDebuff(DEBUFF_JUDGEMENT_OF_LIGHT);
			Target* source = tempDebuff->source;
			float heal = source->getTotalSpellPower() * source->getTotalHealingMultiplier() * source->getHolyMastery() * 0.05;
			tempDebuff->stacks -= 1;

			if (tempDebuff->stacks < 1) {

				removeDebuff(target, tempDebuff);
			}

			source->heal()
		}
	}
}

	float getAzeriteIndomitableJusticeDamage() {

		float damage = 0;

		if (AzeriteHelm->hasTrait(AZERITE_TRAIT_INDOMITABLE_JUSTICE)) {
			damage += 132.373321 * (1.009464786^AzeriteHelm->ArmorItemLevel);
		}

		if (AzeriteShoulders->hasTrait(AZERITE_TRAIT_INDOMITABLE_JUSTICE)) {
			damage += 132.373321 * (1.009464786^AzeriteHelm->ArmorItemLevel);
		}

		if (AzeriteChest->hasTrait(AZERITE_TRAIT_INDOMITABLE_JUSTICE)) {
			damage += 132.373321 * (1.009464786^AzeriteHelm->ArmorItemLevel);
		}

		return damage;
	}
private:



};