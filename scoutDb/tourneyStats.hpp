/*
 * tourneyStats.hpp
 *
 *  Created on: Apr 5, 2017
 *      Author: Lentil
 */

using namespace std;

#ifndef TOURNEYSTATS_HPP_
#define TOURNEYSTATS_HPP_

#include <string.h>
#include <iostream>

unsigned char WP_PER_WIN = 2,
	WP_PER_TIE = 1,
	AP_PER_WIN = 4;

class Team {
	unsigned char rank,
		tourneyIndex,
		wp,
		ap,
		autonWins,
		record[3] = { 0, 0, 0 };
	unsigned short int sp;
	string teamNum;
	double opr,
		dpr,
		ccwm;

	Team(unsigned char tourneyInd,
		string teamNumber) {
		rank =
			wp =
			ap =
			autonWins =
			0;
		opr =
			dpr =
			ccwm =
			0;
		sp = 0;
		tourneyIndex = tourneyInd;
		teamNum = teamNumber;
	}

	void upRecord(unsigned char score, unsigned char oppScore, bool bDidAuton) {
		if(bDidAuton) //If auton is won
			autonWins++; //Increase number of auton wins
		if(score > oppScore) { //If a win
			record[0]++; //Increase number of wins
			sp += oppScore;
		}
		else if(score < oppScore) { //If a loss
			record[1]++; //Increase number of losses
			sp += score;
		}
		else { //If a tie
			record[2]++; //Increase number of ties
			sp+= score;
		}

		upWp();
		upAp();

		return;
	}

	unsigned char upWp() {
		return wp = record[0] * WP_PER_WIN + record[2] * WP_PER_TIE;
	}

	unsigned char upAp() {
		return ap = autonWins * AP_PER_WIN;
	}

};

class Match {
	unsigned char red1,
		red2,
		blue1,
		blue2;
	int number,
		redScore = 0,
		blueScore = 0;

	Match(int num,
		unsigned char redInd1,
		unsigned char redInd2,
		unsigned char blueInd1,
		unsigned char blueInd2) {
		number = num;
		red1 = redInd1;
		red2 = redInd2;
		blue1 = blueInd1;
		blue2 = blueInd2;
	}

	void upMatch(int RedScore, int BlueScore) {
		redScore = RedScore;
		blueScore = BlueScore;
	}

};

class Tournament {

	unsigned char allianceCaptains[8],
		alliances[8][3];

	Team Teams[150];

	Tournament(unsigned int matchCt, unsigned char teamCt) {
		for(int i = 0; i < sizeof(alliances) / sizeof(unsigned char); i++) {
			allianceCaptains[i] = 0;
			for(int x = 0; x < sizeof(alliances[i]) / sizeof(unsigned char); x++)
				alliances[i][x] = 0;

		}
	}
};





#endif /* TOURNEYSTATS_HPP_ */
