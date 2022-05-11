#pragma once
#include "baseBlock.hpp"

class grass : public baseBlock, public std::enable_shared_from_this<grass> {

public:
	grass(const unsigned int xe, const unsigned int ye);

	std::shared_ptr<baseBlock> ruin();
};
