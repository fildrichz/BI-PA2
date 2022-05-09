#pragma once

#include "baseBlock.hpp"
#include "bomber.hpp"

class bomb: public baseBlock{

protected:
	int timeLeft;
	int explosionSize;

	std::shared_ptr<bomber> belongsTo;

	bool tick();

	int explode(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board);

public:

	bomb(const unsigned int x, const unsigned int y, const int eSize, const int timer, std::shared_ptr<bomber>& belongsTo);

	void bombProcess(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board);


};
