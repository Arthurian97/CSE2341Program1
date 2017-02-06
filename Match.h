class Match{
	public:
		int tags[11][11];
		int points[11][11];
		//int count;

		Match(){
			for(int j = 0; j < 11; j++){
				for(int i = 0; i < 11; i++){  
					tags[i][j] = 0;
				}
			}

			for(int j = 0; j < 11; j++){
				for(int i = 0; i < 11; i++){  
					points[i][j] = 0;
				}
			}
		}
		void log(int i, int j, int k){
			tags[i][j]+=1;
			int l=0;
			switch (k){
			case 1:
				l=5;
				break;
			case 2:
				l=8;
				break;
			case 3:
				l=10;
				break;
			case 4:
				l=15;
				break;
			}
			points[i][j]+=l;
		}		
		void calculatePlayerTotalTags(){
			for (int i=1;i<11;i++){
				int sumi=0;
				for (int j=1;j<11;j++){
					sumi+=tags[i][j];
				}
				tags[i][0]=sumi;
			}
		}
		void calculatePlayerTotalPoints(){
			for (int i=1;i<11;i++){
				int sumi=0;
				for (int j=1;j<11;j++){
					sumi+=points[i][j];
				}
				points[i][0]=sumi;
			}
		}
		void calculateTeamTotalPoints(){
			int sum=0;
			for (int i=1;i<11;i++){
				sum+=points[i][0];
			}
			points[0][0]=sum;
		}
		int getMostPointPlayer(){
			int topPlayer=0;
			int topPoints=0;
			for (int i=1;i<11;i++){
				if (points[i][0]>topPoints){
					topPlayer=i;
					topPoints=points[i][0];
				}
			}
			return topPlayer;
		}
};
