#pragma once

#include "ofMain.h"

struct Track {
	string song;
	string album;
	vector<string> artists;
};

class ofApp : public ofBaseApp{
private:
	
	
	int counter = 0;
	bool kGameOver = true;
	bool isWinner = false;
	int attempts = 0;
	std::vector<char> correctCharacters;
	std::vector<char> correctGuesses;
	bool hit = false;
	const int kMaxAttempts = 10;
	
	const string kApiKey = "BQDaCt8IkLy0CCVLNxhhqvZLQEPZuHh8TTqW7zfujbA8RANv4Mf9YGm96EyfM8aX7CS9MKZnz634sXT-Fr871OW4eBW2EzmvJ-KNNWXRI-2dLMEXgk4pQp_7-ib3vQ-9aY3YVh9FVVuc4A6hSkZ5Y_x9-40tS-crSk722FEx";
	const string kClientID = "4bfad9e4d36547bfbea87c176a6194a0";
	const string kClientSecret = "ef0d92ef014642bc9697edd5f37b92fc";
	const string kAuth = "NGJmYWQ5ZTRkMzY1NDdiZmJlYTg3YzE3NmE2MTk0YTA6ZWYwZDkyZWYwMTQ2NDJiYzk2OTdlZGQ1ZjM3YjkyZmM=";
	

	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofImage hangman_structure;
		ofImage hangman_head;
		ofImage hangman_body;
		ofImage hangman_pants;

		ofTrueTypeFont font;
		ofTrueTypeFont secondFont;
		    
};

class Word {
public:
	string aWord;
	std::vector<bool> shown;

	string EncodeSongName(string song);
};

