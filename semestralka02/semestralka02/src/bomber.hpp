
#include "bomberBase.hpp"

class bomber: public bomberBase{

public:
	/**
	* bomberman constructor.
	*
	* \param x coordinate
	* \param y coordinate
	*/
	bomber(const unsigned int x, const unsigned int y);

	/**
	* move method, guided by player manually.
	*/
	virtual std::shared_ptr< baseBlock> move(std::vector< std::vector< std::shared_ptr<baseBlock>>>& board); //override;

	/**
	* returns true.
	*/
	virtual bool isPlayer() const; //override.

};
