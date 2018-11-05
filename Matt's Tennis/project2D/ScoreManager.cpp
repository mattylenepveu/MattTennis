#include "ScoreManager.h"

ScoreManager::ScoreManager()
{
	m_nHighScore = 0;
}

ScoreManager::~ScoreManager()
{
}

void ScoreManager::SetHighScore(int nHighScore)
{
	m_nHighScore = nHighScore;
}

int ScoreManager::GetHighScore()
{
	return m_nHighScore;
}
