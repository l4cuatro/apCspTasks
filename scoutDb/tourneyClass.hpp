
namespace ScoutDb {
	class Tourney {
		short teamCt,
			matchCt;
		unsigned char matchesPerTeam;
		
		Team* Teams;
		short* allyArr;
		int* allySums;
		
		string input = " ";
		
		Tourney(short teamCount, short matchCount) {
			teamCt = teamCount;
			matchCt = matchCount;
			matchesPerTeam = floor(4 * matchCt / teamCt);
			Teams = (Team*)(calloc(teamCt * sizeof(Team)));
			allyArr = (short*)(calloc(teamCt * teamCt * sizeof(short)));
			allySums = (int*)(calloc(teamCt * sizeof(int)));
			
			for(short i = 0; i < teamCt; i++) {
				cout << "Team Number?";
				cin >> input;
				Teams[i] = Team(input, i, matchesPerTeam);
			}
		}
	};
}