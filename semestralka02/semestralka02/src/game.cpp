#include "game.hpp"

std::shared_ptr<baseBlock> game::create(const char& entry, const int& collumn, const int& row)
{
	switch (entry) {
	case 'B': {
		std::string choice;

		std::cout << "Player or robot? ";
		std::cin >> choice;

		if (choice == "player") {
			std::string pName;
			std::cout << "Choose player name: ";
			std::cin >> pName;
			auto temp = std::make_shared<bomber>(collumn, row);
			temp->playerName = pName;
			movingBlocks.push_back(temp);

			return temp;
		}
		else {
			std::cout << "Created robot" << std::endl;
			auto robot = std::make_shared<aiBomber>(collumn, row);
			movingBlocks.push_back(robot);

			return robot;
		}
	}

	case 'G': {
		auto newG = std::make_shared<ghost>(collumn, row);
		movingBlocks.push_back(newG);
		return newG;
	}

	case 'X':
		return std::make_shared<sturdyBlock>(collumn, row);

	case ' ':
		return std::make_shared<grass>(collumn, row);

	case '#':
		return std::make_shared<indestructibleBlock>(collumn, row);

	case 'W':
		return std::make_shared<weakBlock>(collumn, row);

	case 'b':
		return std::make_shared<powerup1>(collumn, row);

	case 'r':
		return std::make_shared<powerup2>(collumn, row);

	case 'a':
		return std::make_shared<powerup3>(collumn, row);

	case 't':
		return std::make_shared<powerup4>(collumn, row);

	default:
		return std::make_shared<grass>(collumn, row);
	}
}

void game::load_screen()
{
	int collumn = 0;
	int row;

	for (std::vector< std::shared_ptr<baseBlock>>& entire_row : board)
	{
		row = 0;
		for (std::shared_ptr<baseBlock>& single : entire_row)
		{
			std::cout << single->display();
			row++;
		}

		std::cout << std::endl;
		collumn++;
	}
}

bool game::loadGrid(std::ifstream& f) {
	std::string line;
	size_t row = 1;
	size_t collumn = 0;
	unsigned int countlines = 0;

	while (getline(f, line))
	{
		countlines++;
		std::vector< std::shared_ptr<baseBlock>> newrow;
		newrow.push_back(create('#', 0, row));
		for (collumn = 0; collumn < line.length(); collumn++)
		{
			std::shared_ptr<baseBlock> created = create(line[collumn], collumn + 1, row);
			newrow.push_back(created);
		}

		newrow.push_back(create('#', (line.length() + 1), row));
		board.push_back(newrow);
		row++;
	}

	if (countlines == 0) {
		std::cout << "no matrix to load" << std::endl;
		return false;
	}

	unsigned int properLen = board[0].size();
	for(const auto & row: board)
		if (row.size() != properLen) {
			std::cout << "matrix is not rectangle" << std::endl;
			return false;
		}
		

	collumn = 0;
	std::vector< std::shared_ptr<baseBlock>> newrow;
	for (const auto& block : board[0])
	{
		collumn++;
		newrow.push_back(create('#', block->x, 0));
	}
	board.insert(board.begin(), newrow);

	collumn = 0;
	std::vector< std::shared_ptr<baseBlock>> anotherrow;
	for (const auto& block : board[0])
	{
		collumn++;
		anotherrow.push_back(create('#', block->x, row));
	}
	board.push_back(anotherrow);

	return true;
}

game::game() : numOfActivePlayers(0) {
}

bool game::shouldContinue() const {
	unsigned int countPlayers = 0;
	unsigned int countGhosts = 0;

	for (auto& object : movingBlocks) {
		if (object->isGhost())
			countGhosts++;
		if (object->isPlayer())
			countPlayers++;
	}

	if (countPlayers == 0)
		return false;

	if (countPlayers == 1 && countGhosts == 0)
		return false;

	return true;
}

int game::gameCleanUp() {
	for (auto& object : movingBlocks) {
		if (object->isPlayer()) {
			std::cout << "player " << std::dynamic_pointer_cast<bomber>(object)->playerName << " has won!" << std::endl;
			std::cout << "their score is " << std::dynamic_pointer_cast<bomber>(object)->score << std::endl;
			return  std::dynamic_pointer_cast<bomber>(object)->score;
		}
	}

	std::cout << "The ghosts have won!" << std::endl;
	return 0;
}

int game::doGame() {
	while (shouldContinue()) {
		std::cout << "starting turn" << std::endl;

		load_screen();

		std::cout << "moving blocks" << std::endl;

		for (auto& movingblock : movingBlocks) {
			if (movingblock->active()) {
				auto a = movingblock->move(board);

				if (std::dynamic_pointer_cast<bomb>(a) != nullptr)
					bombs.push_back(std::dynamic_pointer_cast<bomb>(a));

				load_screen();
			}
		}

		std::cout << "bomb actions" << std::endl;

		for (auto& bomb : bombs) {
			bomb->bombProcess(board);
		}

		load_screen();
	}

	return gameCleanUp();
}