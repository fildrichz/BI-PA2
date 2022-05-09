#pragma once

#include "baseBlock.hpp"


class movingBlock: public baseBlock {

public:

	movingBlock(const unsigned int x, const unsigned int y);


	virtual std::shared_ptr< baseBlock> move();
	virtual std::shared_ptr< baseBlock> move(const std::vector<int>& direction);

	virtual bool isGhost() const;
	virtual bool isPlayer() const;


	virtual void walkedOn(std::shared_ptr< baseBlock>& thing);


};
