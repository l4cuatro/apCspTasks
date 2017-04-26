
/*

Copyright 2017 [redacted]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

using namespace std;

namespace ScoutDb {

	public class Team {
		
		unsigned short int teamIndex;
		
		unsigned short int allies[15],
			opponents[30];
			
		unsigned char record[3];
		
		unsigned char ap,
			wp;
		
		int sp;
		
		int allyScoreSum,
			oppScoreSum;
		
		string number; //Team Number
		
		Team(string num, unsigned short int index) { //Constructor
			teamIndex = index;
			number = num;
			sp = 0;
			ap = 0;
			allyScoreSum = 0;
			oppScoreSum = 0;
			for(int i = 0; i < sizeof(record); i++)
				record[i] = 0;
			
			for(int i = 0; i < sizeof(allies) / sizeof(short); i++) {
				allies[i] = 0;
				opponents[2 * i] = 0;
				opponents[2 * i + 1] = 0;
			}
		}

		void upStats(unsigned short int ally, unsigned short int opponent1, unsigned short int opponent2, bool bDidWinAuton, short int score, short int oppScore, unsigned char matchInd) {
			allies[matchInd] = ally;
			opponents[2 * matchInd] = opponent1;
			opponents[2 * matchInd + 1] = opponent2;
			if(score > oppScore) { //If a win
				record[0]++;
				sp += oppScore;
			}
			else if(score < oppScore) { //If a loss
				record[1]++;
				sp += score;
			}
			else { //If a tie
				record[2]++;
				sp += score;
			}
			allyScoreSum += score;
			oppScoreSum += oppScore;
			if(bDidWinAuton)
				ap++;
			wp = (2 * record[0]) + record[2];
			return;
		}
	
	}
	
}