#pragma once

#include "bomber.hpp"

/**
 * class implementing bomberman guided by computer.
 */
class aiBomber : public bomber {
protected:

	/**
	 * bomberman remembers it's direction.
	 */
	std::string direction;

	/**
	 * method to change direction.
	 * 
	 */
	void changeDirection();

	/**
	 * checks if player is inside blast radius if bomb was placed on current location.
	 * 
	 * \param board game board, used to search for player
	 * \return true if player is in blast radius, else false
	 */
	bool checkForPlayer(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board);

public:

	/**
	 * constructor.
	 * 
	 * \param x coordinate
	 * \param y coordinate
	 */
	aiBomber(const unsigned int x, const unsigned int y);

	/**
	 * move, now implemented to be guided by computer.
	 */
	virtual std::shared_ptr< baseBlock> move(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board); //override;

	/**
	 * is not player.
	 */
	bool isPlayer() const; //override;

	/**
	 * counts as ghost.
	 */
	bool isGhost() const; //override;
};