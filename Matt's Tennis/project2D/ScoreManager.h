#pragma once

class ScoreManager
{
public:
	ScoreManager();
	~ScoreManager();

	void SetHighScore(int nHighScore);
	int GetHighScore();

private:
	int m_nHighScore;
};

