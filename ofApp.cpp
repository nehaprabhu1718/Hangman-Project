
//access token - BQAWQX_VCk8j8TLppfZeSC1Qg18YHA9OsdSIndukgYkSoAarl-a81lbNryif7YiwjI3liknmMMhbIAn6xRyjn9C6BczuJq3w4TvfOSAs_-BnakMjWBfDvAbxPTn-WuO3w6wE6WYuNlrx1f94QrQd9U4YxJhHedTq_T68NQWQ

#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "ofMain.h"
#include "ofApp.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

Word word;
string encodedSong = word.aWord;
const string kAccessToken = "BQDt_JlQVkSvs1VAC4JBnNbCRo0SfmBG_BrV9LFJUzD8Vh7e1S0XPjGxEv41MQqlV7CjI6Xjeh8_Hb3bf6krRSC_AJtnTisP8hzsZvrQziVSNUDRaX7oXxeQ1kEl7mSprxeGi1_8DfecSg4l5AO06e8Bv-UGgigOo4clq9ad";
const string kAlbumEndPoint = "https://api.spotify.com/v1";

string GetRefreshToken() {
	return ofBufferFromFile("refresh_token.txt").getText();
}

void SaveRefreshToken(const string& token) {
	ofstream ofs(ofToDataPath("refresh_token.txt").c_str());
	ofs << token;
}
//--------------------------------------------------------------
string GetAccessToken() {
	return kAccessToken;
	
}

ofJson MakeApiRequest() {
	// Initialize the file loader.
	ofURLFileLoader ctx;

	// Create the request.
	ofHttpRequest req;
	req.url = kAlbumEndPoint + "/playlists/37i9dQZF1DXcBWIGoYBM5M/tracks";
	
	req.method = ofHttpRequest::Method::GET;

	req.contentType = "application/json";
	req.headers["Authorization"] = "Bearer " + GetAccessToken();

	// Get the response (synchronously).
	ofHttpResponse res = ctx.handleRequest(req);

	ofJson responseJson = ofJson::parse(res.data);
	return responseJson;
}

std::vector<Track> GetTracks() {

	const ofJson responseJson = MakeApiRequest();

	std::vector<Track> tracks;
	for (auto item : responseJson["items"]) {
		Track track;
		track.album = item["track"]["album"]["name"].dump();
		track.song = item["track"]["name"].dump();

		for (const auto& artistItem : item["track"]["artists"])
			track.artists.push_back(artistItem["name"]);

		tracks.push_back(track);
	}
	return tracks;
}

string Word:: EncodeSongName(string encodedString) {

	int len = word.aWord.length();
	std::string retval = std::string(len, '____');
		for (int j = 0; j < word.aWord.length(); j++) {
			bool boolvalue = word.shown.at(j);
			if (boolvalue == true) {
				retval[j] = word.aWord[j];
			}

		}

	return retval;

}

void ofApp::setup(){

	font.load("Highest.ttf",32);
	secondFont.load("Highest.ttf",60);
	ofBackground(255,0,0);
	hangman_pants.load("C:\\Users\\Neha Prabhu\\Downloads\\of_v0.10.1_vs2017_release (1)\\of_v0.10.1_vs2017_release\\apps\\myApps\\final-project-nehaprabhu1718\\bin\\images\\hangman_pants.png");
	hangman_body.load("C:\\Users\\Neha Prabhu\\Downloads\\of_v0.10.1_vs2017_release (1)\\of_v0.10.1_vs2017_release\\apps\\myApps\\final-project-nehaprabhu1718\\bin\\images\\hangman_body.png");
    hangman_head.load("C:\\Users\\Neha Prabhu\\Downloads\\of_v0.10.1_vs2017_release (1)\\of_v0.10.1_vs2017_release\\apps\\myApps\\final-project-nehaprabhu1718\\bin\\images\\hangman_head.jpg");
    hangman_structure.load("C:\\Users\\Neha Prabhu\\Downloads\\of_v0.10.1_vs2017_release (1)\\of_v0.10.1_vs2017_release\\apps\\myApps\\final-project-nehaprabhu1718\\bin\\images\\hangman_structure.gif");
    
}

//--------------------------------------------------------------
void ofApp::update(){

	if (attempts == kMaxAttempts) {
		kGameOver = true;
		counter++;
		isWinner = false;
	}

}

//--------------------------------------------------------------
void ofApp::draw() {

	hangman_structure.draw(0, 100, 800, 800);
	
	if (isWinner && kGameOver) {
		font.drawString("You Won!", 100, 1000);
	}
	else if(kGameOver) {
		font.drawString("You Lost!", 100, 1500);
		
	}
	
	if (attempts == 7) {
		hangman_head.draw(500, 200, 100, 100);
	}
	else if (attempts == 8) {
		hangman_head.draw(500, 200, 100, 100);
		hangman_body.draw(500, 300, 100, 100);
	}
	else if (attempts == 9) {
		hangman_head.draw(500, 200, 100, 100);
		hangman_body.draw(500, 300, 100, 100);
		hangman_pants.draw(500, 400, 100, 100);
	}

	const Track track = GetTracks()[counter];
	string encodedSongName;
	string currentSong;
	
	currentSong = track.song;
	word.aWord = currentSong;

	if (kGameOver) {
		word.shown = std::vector<bool>();
		for (int i = 0; i < currentSong.length(); i++) {
			if ((i % 3) == 0) {
				word.shown.push_back(false);

			}
			else {
				word.shown.push_back(true);
			}
		}
		kGameOver = false;
	}


	encodedSongName = word.EncodeSongName(currentSong);

	font.drawString("Guess the song!", 50, 50);

	secondFont.drawString(encodedSongName, 100, 1000);

	

	for (int i = 0; i < track.artists.size(); i++) {
		ofDrawBitmapString(track.artists, 0, 100);
	}

	font.drawString("Guess a character! (Spaces and other punctuation can be guessed)", 1800, 1000);
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	const char letter = static_cast<char>(key);

	cout << "Pressed: " << letter << endl;
 //check if user input of character is matching to the one that is the * 
	for (int i = 0; i < word.aWord.length(); i++) {
		if (letter == word.aWord.at(i)) {
			if (word.shown.at(i) == false) {
				word.shown.at(i) = true;
			}
		}
	}
	if (hit == false) {
		attempts++;
	}
			
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

