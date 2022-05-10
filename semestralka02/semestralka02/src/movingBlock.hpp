#pragma once

#include "baseBlock.hpp"
#include "powerup.hpp"


class movingBlock: public baseBlock {

protected:
	bool isActive;

	bool go(std::vector< std::vector< std::shared_ptr<baseBlock>>> & board, const std::vector<int>& direction);

	bool goInDirection(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board, const std::string & where);

	bool checkDirectionValidity(const std::vector< std::vector< std::shared_ptr<baseBlock>>>& board, const std::vector<int>& target) const;

public:

	movingBlock(const unsigned int x, const unsigned int y);




	virtual std::shared_ptr< baseBlock> move(std::vector< std::vector< std::shared_ptr<baseBlock>>> & board) = 0;

	virtual bool isGhost() const;
	virtual bool isPlayer() const;

	virtual std::shared_ptr<baseBlock> ruin() override
	{
	}


	virtual void walkedOn(std::shared_ptr< baseBlock>& thing);


};
