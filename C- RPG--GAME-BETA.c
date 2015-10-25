#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#define MAX 512

/*typedef struct {

};*/

int EnemyHP = 7;

int YushaHP = 15;

int YushaAttackProcess(void)
{
	int Waitval = 0;

	char str1[MAX] = { "勇者の攻撃！\n" };

	char str2[MAX] = { "のダメージを与えた！\n" };

	srand((unsigned)time(NULL));

	Waitval = rand() % 3 + 1;

	

	for (int i = 0; str1[i] != NULL; i++){
		printf("%c", str1[i]);
		Sleep(50);

	}
	printf("%d", Waitval);

	for (int i = 0; str2[i] != NULL; i++) {
		printf("%c", str2[i]);
		Sleep(50);

	}

	EnemyHP = EnemyHP - Waitval;

	return 0;
}

int EnemyAttackProcess(void)
{
	int Waitval = 0;

	char str1[MAX] = { "敵の攻撃！\n" };

	char str2[MAX] = { "のダメージを受けた！\n" };

	srand((unsigned)time(NULL));

	Waitval = rand() % 3 + 1;



	for (int i = 0; str1[i] != NULL; i++) {
		printf("%c", str1[i]);
		Sleep(50);

	}
	printf("%d", Waitval);

	for (int i = 0; str2[i] != NULL; i++) {
		printf("%c", str2[i]);
		Sleep(50);

	}

	YushaHP = YushaHP - Waitval;

	return 0;
}

int GameMain(void)
{

	

	

	char str[MAX] = { "敵が現れた！\n" };
	char str2[MAX] = { "勇者の攻撃!\n" };
	char str3[MAX] = { "コマンド？\n" };
	char str4[MAX] = { "「zキー」攻撃　" };
	char str5[MAX] = { "「xキー」逃げる\n" };
	
	char str7[MAX] = { "勇者は逃げ出した・・・\n" };
	char str8[MAX] = { "勇者の攻撃！\n" };
	char str9[MAX] = { "勇者は死にました。\n" };
	char str10[MAX] = { "敵を倒した。\n" };
	char str11[MAX] = { "ゲームクリアです。おめ！" };
 
	for (int i = 0; str[i] != NULL; i++) {
		printf("%c", str[i]);
		Sleep(50);
	}

	while (_getch() != 0x1b) {

		for (int i = 0; str3[i] != NULL; i++) {
			printf("%c", str3[i]);
			Sleep(50);
		}
		for (int i = 0; str4[i] != NULL; i++) {
			printf("%c", str4[i]);
			Sleep(50);
		}
		for (int i = 0; str5[i] != NULL; i++) {
			printf("%c", str5[i]);
			Sleep(50);
		}


		if (_getch() == 'z') {
			
			YushaAttackProcess();
			printf("デバッグ敵HP %d\n", EnemyHP);


			if (EnemyHP <= 0) {
				for (int i = 0; str10[i] != NULL; i++) {
					printf("%c", str10[i]); //敵を倒した
					Sleep(50);
				}
				for (int i = 0; str11[i] != NULL; i++) {
					printf("%c", str11[i]);
					Sleep(50);
				}
				getchar();
				return 0;
			}

			getchar();

			EnemyAttackProcess();
			printf("デバッグ勇者HP %d\n", YushaHP);
			if (YushaHP <= 0) {
				for (int i = 0; str9[i] != NULL; i++) {
					printf("%c", str9[i]);
					Sleep(50);
				}
				getchar();

				return 0;
			}

		}

		else if (_getch() == 'x') {

			for (int i = 0; str7[i] != NULL; i++) {
				printf("%c", str7[i]);
				Sleep(50);

			}

			return 0;
		}

	}

	getchar();

	return 0;
}


int main(void)
{
	GameMain();

	return 0;
}
