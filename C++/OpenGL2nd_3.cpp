#include <stdio.h>
#include <random>

void main(){
	std::mt19937 random(std::random_device{}());
	const int max_play_count = 5;
	int win = 0;
	int lose = 0;
	printf("����񂯂�Q�[��\n");

	for(int play_count = 0; play_count < max_play_count; ++play_count){
		int player_hand = 0;

		// �ΐ�񐔂�\��
		printf("[%d���]���I�����Ă�������(0=�O�[ 1=�`���L 2=�p�[):", play_count + 1);
		scanf("%d", &player_hand);

		// �������g����CPU�̎��I��
		int cpu_hand = std::uniform_int_distribution<>(0, 2);
		
		// ���ׂĂ̏��s�̌��ʂ�\�����A���s�񐔂��L�^
		if(player_hand == 2 && cpu_hand == 0){
			printf("���Ȃ��̏���\n");
			++win;
		}

	}
	printf("����=%d ����=%d ��������=%d \n", win, lose, max_play_count - win- lose);
	if(win > lose){
		printf("���Ȃ��̏����ł�.\n");

		// ������ꍇ�̏���
	}else if(lose > win){
		printf("���Ȃ��̕����ł�.\n");
	}else{
		printf("��������.\n");
	}


}