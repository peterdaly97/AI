#include "grid.h"

Grid::Grid() {
	if (!m_font.loadFromFile("arial.ttf"))	// Checks to make sure font is correct
	{
		std::cout << "Problem loading font file!" << std::endl;
	}

	for (int i = 0; i < m_height; i++) {
		for (int e = 0; e < m_width; e++) {
			m_grid[e][i] = new Tile(sf::Vector2f(50 * e, 50 * i), &m_font);
		}
	}

	initObstacles();

}


Grid::~Grid() {}

void Grid::update() {

	for (int i = 0; i < m_height; i++) {
		for (int e = 0; e < m_width; e++) {
			m_grid[e][i]->update();
		}
	}
}

void Grid::render(sf::RenderWindow * window) {
	for (int i = 0; i < m_height; i++) {
		for (int e = 0; e < m_width; e++) {
			m_grid[e][i]->render(window);
		}
	}
}

void Grid::select(sf::Vector2f pos) {
	if (!m_start && !m_grid[(int)pos.x][(int)pos.y]->m_end && 
		!m_grid[(int)pos.x][(int)pos.y]->m_obstacle) {
		m_start = true;
		m_grid[(int)pos.x][(int)pos.y]->m_start = true;
	}
	else if (!m_end && !m_grid[(int)pos.x][(int)pos.y]->m_start && 
		!m_grid[(int)pos.x][(int)pos.y]->m_obstacle) {
		m_end = true;
		m_grid[(int)pos.x][(int)pos.y]->m_end = true;
		 
		m_startCalc = true;
	}
		
}

void Grid::setUpHeatMap() {
	int startX;
	int startY;
	Tile* startTile = new Tile(sf::Vector2f(0, 0), &m_font);

	for (int i = 0; i < m_height; i++) {
		for (int e = 0; e < m_width; e++) {
			if (m_grid[e][i]->m_start) {
				startTile = m_grid[e][i];
				pq.push_back(startTile);
				startX = e;
				startY = i;
			}
				
		}
	}

	m_grid[startX][startY]->m_cost = 0;
	pq.push_back(startTile);
	int cost = 0;
	qq.push_back(std::pair<std::vector<Tile*>, int>(pq, cost + 1));
	heatLoop();
	
	m_startCalc = false;
}

void Grid::heatLoop() {
	for (std::pair<std::vector<Tile*>, int> nextPQ : qq) {
		nextPQ = *qq.begin();
		for (Tile * p : nextPQ.first) {
			heatMap(p, p->m_tile.getPosition().x / 50,
				p->m_tile.getPosition().y / 50, nextPQ.second);
		}
		qq.erase(qq.begin());
	
	}

	if (qq.size() > 0)
		heatLoop();
}

void Grid::heatMap(Tile * tile, int x, int y, int cost) {
	if (x < 29 && !m_grid[x + 1][y]->m_start && !m_grid[x + 1][y]->m_obstacle
		&& m_grid[x + 1][y]->m_cost == 0) {

		m_grid[x + 1][y]->setCost(cost);
		m_grid[x + 1][y]->setLine(180.0);
		pq.push_back(m_grid[x + 1][y]);
	}
	if (x > 0 && !m_grid[x - 1][y]->m_start && !m_grid[x - 1][y]->m_obstacle
		&& m_grid[x - 1][y]->m_cost == 0) {

		m_grid[x - 1][y]->setCost(cost);
		m_grid[x - 1][y]->setLine(0.0);
		pq.push_back(m_grid[x - 1][y]);
	}
	if (y < 19 && !m_grid[x][y + 1]->m_start && !m_grid[x][y + 1]->m_obstacle
		&& m_grid[x][y + 1]->m_cost == 0) {

		m_grid[x][y + 1]->setCost(cost);
		m_grid[x][y + 1]->setLine(270.0);
		pq.push_back(m_grid[x][y + 1]);
	}
	if (y > 0 && !m_grid[x][y - 1]->m_start && !m_grid[x][y - 1]->m_obstacle
		&& m_grid[x][y - 1]->m_cost == 0) {

		m_grid[x][y - 1]->setCost(cost);
		m_grid[x][y - 1]->setLine(90.0);
		pq.push_back(m_grid[x][y - 1]);
	}	

	if (y > 0 && x > 0 && !m_grid[x - 1][y - 1]->m_start && !m_grid[x - 1][y - 1]->m_obstacle
		&& m_grid[x - 1][y - 1]->m_cost == 0) {

		m_grid[x - 1][y - 1]->setCost(cost);
		m_grid[x - 1][y - 1]->setLine(45.0);
		pq.push_back(m_grid[x - 1][y - 1]);
	}
	if (y < 19 && x > 0 && !m_grid[x - 1][y + 1]->m_start && !m_grid[x - 1][y + 1]->m_obstacle
		&& m_grid[x - 1][y + 1]->m_cost == 0) {

		m_grid[x - 1][y + 1]->setCost(cost);
		m_grid[x - 1][y + 1]->setLine(315.0);
		pq.push_back(m_grid[x - 1][y + 1]);
	}
	if (y > 0 && x < 29 && !m_grid[x + 1][y - 1]->m_start && !m_grid[x + 1][y - 1]->m_obstacle
		&& m_grid[x + 1][y - 1]->m_cost == 0) {

		m_grid[x + 1][y - 1]->setCost(cost);
		m_grid[x + 1][y - 1]->setLine(135.0);
		pq.push_back(m_grid[x + 1][y - 1]);
	}
	if (y < 19 && x < 29 && !m_grid[x + 1][y + 1]->m_start && !m_grid[x + 1][y + 1]->m_obstacle
		&& m_grid[x + 1][y + 1]->m_cost == 0) {

		m_grid[x + 1][y + 1]->setCost(cost);
		m_grid[x + 1][y + 1]->setLine(225.0);
		pq.push_back(m_grid[x + 1][y + 1]);
	}

	qq.push_back(std::pair<std::vector<Tile*>, int>(pq, cost + 1));
	pq.clear();
}

void Grid::initObstacles() {

	m_grid[10][0]->m_obstacle = true;
	m_grid[10][1]->m_obstacle = true;
	m_grid[10][2]->m_obstacle = true;
	m_grid[10][3]->m_obstacle = true;
	m_grid[10][4]->m_obstacle = true;
	m_grid[10][5]->m_obstacle = true;
	m_grid[10][6]->m_obstacle = true;
	m_grid[10][7]->m_obstacle = true;
	m_grid[10][8]->m_obstacle = true;
	m_grid[10][9]->m_obstacle = true;
	m_grid[10][10]->m_obstacle = true;
	m_grid[10][11]->m_obstacle = true;
	m_grid[10][12]->m_obstacle = true;
	m_grid[10][13]->m_obstacle = true;

	m_grid[10][13]->m_obstacle = true;
	m_grid[11][13]->m_obstacle = true;
	m_grid[12][13]->m_obstacle = true;
	m_grid[13][13]->m_obstacle = true;
	m_grid[14][13]->m_obstacle = true;
	m_grid[15][13]->m_obstacle = true;
	m_grid[16][13]->m_obstacle = true;
	m_grid[17][13]->m_obstacle = true;

	m_grid[17][12]->m_obstacle = true;
	m_grid[17][11]->m_obstacle = true;
	m_grid[17][10]->m_obstacle = true;
	m_grid[17][9]->m_obstacle = true;
	m_grid[17][8]->m_obstacle = true;
	m_grid[17][7]->m_obstacle = true;
}

