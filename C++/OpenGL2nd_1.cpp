#include <stdio.h>
#include <random>

enum MARK{
	HEART,
	SPADE,
	CLUB,
	DIAMOND,
};

struct PlayingCard{
	int mark;
	int number;
};

void Init(PlayingCard playingCards[]){
	int i =0;
	for(int m = 0; m < 4; m++){

		for(int n = 0; n < 13; n++){
			playingCards[i + n].mark = m;
			playingCards[i + n].number = n + 1;

		}
		i += 13;

	}

}

void ShowCard(PlayingCard playingCards[]){
	
	
	for(int i = 0; i < 5; i++){
		switch(playingCards[i].mark){
			case HEART:
				printf(" HEART %d \n",playingCards[i].number);
			break;
			case SPADE:
				printf(" SPADE %d \n",playingCards[i].number);
			break;
			case CLUB:
				printf(" CLUB %d \n",playingCards[i].number);
			break;
			case DIAMOND:
				printf(" DIAMOND %d \n",playingCards[i].number);
			break;
			default:
			break;
		}

	}
	printf("\n");

}

void ShuffleCard(PlayingCard playingCards[]){
	std::mt19937 random(std::random_device{}());
	PlayingCard tmp;
	for(int i = 0; i < 52; i++){
		tmp.mark = playingCards[i].mark;
		tmp.number = playingCards[i].number;
		int changeNum = std::uniform_int_distribution<>(0,51)(random);
		playingCards[i].mark = playingCards[changeNum].mark;
		playingCards[i].number = playingCards[changeNum].number;
		playingCards[changeNum].mark = tmp.mark;
		playingCards[changeNum].number = tmp.number;

	}
}

void main(){
	PlayingCard playingCards[52];
	

	Init(playingCards);
//	ShowCard(playingCards);
	ShuffleCard(playingCards);
	ShowCard(playingCards);




}

