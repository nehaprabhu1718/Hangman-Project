/*

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "HTTPRequest.h"
#include "ofMain.h"
//#include "ofxHTTP.h"
//#include "ofxJSON.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;


//const string kKeyFile = "C:\Users\Neha Prabhu\Downloads\of_v0.10.1_vs2017_release (1)\of_v0.10.1_vs2017_release\apps\myApps\final-project-nehaprabhu1718/bin/data/keys.json";

const string kAlbumEndPoint = "	https://api.spotify.com/v1/albums";//artists/{id}/albums";
const string kApiKey = "NGJmYWQ5ZTRkMzY1NDdiZmJlYTg3YzE3NmE2MTk0YTA6ZWYwZDkyZWYwMTQ2NDJiYzk2OTdlZGQ1ZjM3YjkyZmM=";

string GetApiKey() {
	
	return kApiKey;
}

ofJson FillJson(const string& sentence) {
	ofJson root;

	 Example API Request (json):
		{
		  "text": "...",
		  "language": "...",
		  "replacer": "..."
		}

	root["text"] = sentence;
	root["language"] = "en";
	root["replacer"] = "*";

	return root;
}

ofJson MakeApiRequest() {
	// Initialize the file loader.
	ofURLFileLoader ctx;

	// Create the request.
	ofHttpRequest req;
	req.url = kAlbumEndPoint;
	req.method = ofHttpRequest::Method::GET;
	//req.body = requestJson.dump();
	req.contentType = "application/json";
	req.headers["Authorization"] = "Simple " + kApiKey;

	// Get the response (synchronously).
	ofHttpResponse res = ctx.handleRequest(req);

	ofJson responseJson = ofJson::parse(res.data);
	return responseJson;
}

string GetAlbumNames(std::vector<string> albumNames) {
	
	const ofJson responseJson = MakeApiRequest();

	 Example API response (json):
	   {
		 "result": {
		   "bad words": [
			 ...
			],
			"filtered text": "...",
			"original text": "..."
		 },
		 ...
	  }
	

	// Read json.
	
	for () {

	}
	const string name = responseJson["name"];

	for (const string& badWord : responseJson["result"]["bad words"]) {
		cout << "Found bad word: " << badWord << endl;
	}
	// Outputs:
	//   Found bad word: damn
	//   Found bad word: hell

	return filteredSentence;
	
}

int main(int argc, char**argv) {

	return 0;
}*/