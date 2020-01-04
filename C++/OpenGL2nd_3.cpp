#include <stdio.h>
#include <random>

void main(){
	std::mt19937 random(std::random_device{}());
	const int max_play_count = 5;
	int win = 0;
	int lose = 0;
	printf("じゃんけんゲーム\n");

	for(int play_count = 0; play_count < max_play_count; ++play_count){
		int player_hand = 0;

		// 対戦回数を表示
		printf("[%d戦目]手を選択してください(0=グー 1=チョキ 2=パー):", play_count + 1);
		scanf("%d", &player_hand);

		// 乱数を使ってCPUの手を選択
		int cpu_hand = std::uniform_int_distribution<>(0, 2)(rand);
		
		// すべての勝敗の結果を表示し、勝敗回数を記録
		if(player_hand == cpu_hand)
		{	
			printf("引き分けです\n");
		}else if(player_hand == 2 && cpu_hand == 0  || player_hand == 1 && cpu_hand == 2 || player_hand == 2 && cpu_hand == 1){
				printf("あなたの勝ち\n");
				++win;
		}else{
			printf("あなたの負け\n");
				lose++;
		}


	}
	printf("勝ち=%d 負け=%d 引き分け=%d \n", win, lose, max_play_count - win- lose);
	if(win > lose){
		printf("あなたの勝ちです.\n");
		// 負ける場合の条件
	}else if(lose > win){
		printf("あなたの負けです.\n");
	}else{
		printf("引き分け.\n");
	}


}