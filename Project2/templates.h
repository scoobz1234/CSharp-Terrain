#pragma once

template <class T>
T EnemyDamageRoll(T hitRoll) {
	int temp(0);
	(hitRoll != 0) ? temp = rndEChance(gen) : temp = 0;
	return temp;
}

template<class T>
T PlayerDamageRoll(T hitRoll) {
	int temp(0);
	(hitRoll != 0) ? temp = rndPChance(gen) :  temp = 0;
	return temp;
}