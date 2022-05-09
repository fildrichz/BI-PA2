#pragma once

#include "movingBlock.hpp"
#include <string>

class bomber: public movingBlock{

	unsigned int score;
	std::string playerName;

public:

	bool placeBomb(std::vector< std::vector< std::shared_ptr<baseBlock>>> board, std::vector< std::shared_ptr< bomb >> bombs);

};
