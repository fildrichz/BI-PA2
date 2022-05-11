#pragma once

#include "bomber.hpp"

class aiBomber : public bomber, std::enable_shared_from_this<aiBomber> {

protected:
	std::string direction;

	void changeDirection();

	bool checkForPlayer(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board);

public:

	aiBomber(const unsigned int x, const unsigned int y);

	virtual std::shared_ptr< baseBlock> move(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board); //override;

	bool isPlayer() const; //override;

	bool isGhost() const; //override;

};
