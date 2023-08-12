#include "LevelObject.h"
class LevelLoader
{
public:
	LevelObject* level;

	void RenderLevel() {
		level->RenderLevel();
	};

	void switchLevel(LevelObject* newLevel) {
		level = newLevel;
	}
	void useLevelMechanics() {
		level->LevelMechanics();
	}

};