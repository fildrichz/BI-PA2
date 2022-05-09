#pragma once

#include "baseBlock.hpp"

class bomb: public baseBlock{
	int timeLeft;

	bool tick();

	int explode(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board);

public:

	void bombProcess(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board);


};
