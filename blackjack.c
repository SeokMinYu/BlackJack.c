#include <stdio.h>//입출력 함수를 쓰기위한 헤더파일
#include <stdlib.h>//rand함수와 system함수를 쓰기위한 헤더파일
#define PAS system("pause")
#define CLS system("cls")
#include <time.h>//동일한 랜덤값이 반복됨을 피하기 위해 time을 쓰기 위한 헤더파일
int num, bat_money, win=0, lose=0, draw=0, money=10000;
int p_card1, p_card2, p_total, d_card1, d_card2, d_total,p_card3,p_card4,d_card3,d_card4;
void manual();
void start();
void score();
void scoreBoard();


int main(void)//메인함수
{	
	while(1) 
	{
		printf("┌────────┐\n");
		printf("│ Black Jack v1.3│\n");
		printf("└────────┘\n");
		
		printf("\n[1] 게임 시작 [2] 게임 방법 [3] 스코어 [0] 종료\n>> ");
		scanf("%d", &num);
		
		switch(num)
		{
		case 1://게임시작 - 카드 제 1선택
			{
				CLS;//화면지우기
				printf("블랙잭 게임을 시작합니다. ! ! !\n");
				start();	
				break;
			}
			
		case 2://게임방법
			{ 
				manual();
				break;
			}
			
		case 3://스코어보기
			{
				scoreBoard();
				break;
			}
		case 0://게임종료
			printf("게임이 종료됩니다\n");
			return 0;
			
		default://1~3을 제외한 다른 숫자를 입력하였을 경우
			{
				printf("잘못입력하셨습니다.\n");
				printf("\n");
				PAS;
				CLS;
				break;
				return 0;
			}//case마지막
		}//switch닫기
	}//while닫기
}//int main(void)닫기	

void manual(){//게임방법함수
	CLS;
	printf("블랙잭이란 : \n");
	printf("\n");
	printf("①블랙잭이란 카드의 합이 21점 또는 21점에 가장 가까운 사람이 이기는 게임입니다.\n");
	printf("②사용하는 카드는 총 52장( ♥13장 + ♠13장 + ♣13장 + ◆13장 )입니다.\n");
	printf("③카드의 종류는 2, 3, 4, 5, 6, 7, 8, 9, 10, A, K, Q, J입니다.\n");
	printf("\n");
	PAS;
	CLS;
	printf("게임방법 : \n");
	printf("\n");
	printf("①배팅할 액수를 입력합니다.(100원 이상)\n");
	printf("②자신의 패에 따라 카드를 2~4번 뽑을 수 있습니다.\n");
	printf("③숫자의 합이 21이면 블랙잭입니다.\n");
	printf("④카드를 뽑아 나온 숫자가 딜러보다 21에 가까우면 이깁니다.\n");
	printf("⑤단, 21을 초과하면 무조건 패배합니다.\n");
	printf("⑥딜러와 플레이어 모두21을 초과하면 21에 가까운 사람이 이깁니다.\n");
	printf("⑦딜러와 플레이어의 숫자가 같으면 비깁니다.\n");
	printf("⑧승리하면 배팅한 금액 이상을 얻고, 패배하면 배팅한 금액을 잃습니다.\n");
	printf("\n");
	PAS;
	CLS;			
}

void scoreBoard(){   //스코어판
	CLS;
	printf("* * * * * * * * Player Score * * * * * * * *\n");
	printf("win : %d lose : %d draw: %d\n",win,lose,draw);
	printf("* * * * * * * * * * * * * *  * * * * * * * *\n");
	PAS;
	CLS;
}

void start()//게임시작
{         
	int num1,num2;
	//int money = 10000; //초기금액
	
	printf("\n");
				PAS;
				CLS;
				
				printf("초기금액은 10000원입니다.\n\n");
				while(1){
					printf("현재금액은 %d원입니다.\n",money);
					printf("배팅액을 입력하십시오(최소 100원 최대 10000) : ");
					scanf("%d", &bat_money);
					
					if(bat_money<=10000 && bat_money>=100)
					{
						printf("\n");
						srand(time(NULL));//그냥 rand만 쓰면 한번 랜덤한 수가 나온다음 그 수가 반복이 되므로 srand와 time을 써서 막아준다.
						p_card1 = rand()%13+1;
						p_card2 = rand()%13+1;
						p_card3 = rand()%13+1;
						p_card4 = rand()%13+1;//플레이어
						d_card1 = rand()%13+1;
						d_card2 = rand()%13+1;
						d_card3 = rand()%13+1;
						d_card4 = rand()%13+1;//딜러
						p_total = p_card1 + p_card2;//플레이어카드합
						d_total = d_card1 + d_card2;//딜러카드합
						
						printf("당신이 가지고 있는 카드의 숫자는 %d, %d  -- 두 장의 합은 %d입니다.\n", p_card1, p_card2,p_total);
						if(p_total == 21)
						{
							printf("블랙잭입니다. 축하합니다.\n");
							money+=(bat_money)*2;
							win++;
							PAS;
							CLS;
							break;
						}
						
						else if(p_total > 21)
						{
							printf("21을 초과하여 플레이어가 졌습니다.\n");
							money-=bat_money;
							lose++;
							PAS;
							CLS;
							break;
						}
						
						printf("카드를 더 뽑으시려면 (1), 아니면 (2) 눌러주세요. : ");
						scanf("%d",&num1);
						
						switch(num1)
						{
						case 1:
							{
								p_total=p_total+p_card3;
								d_total=d_total+d_card3;
								printf("당신이 가지고 있는 카드의 숫자는 %d, %d, %d  -- 세 장의 합은 %d 입니다.\n",p_card1,p_card2,p_card3,p_total);
								
								printf("카드를 더 뽑으시려면 (1), 아니면 (2) 눌러주세요. : ");
								scanf("%d",&num2);
								
								if(num2==1){
									p_total=p_total+p_card4;
									d_total=d_total+d_card4;
									printf("당신이 가지고 있는 카드의 숫자는 %d, %d, %d, %d  -- 네 장의 합은 %d 입니다.\n",p_card1,p_card2,p_card3,p_card4,p_total);
									score();
									break;
								}
								
								
								else if(num2==2)
								{
									score();
									break;
								}
								
								else
									printf("잘못입력하셨습니다. \n");
								
							}						
							
						case 2:
							{
								score();						
								break;
							}
							
						default:{
							printf("다시입력하세요.\n");
							continue;
								}
							
						}break;
					}
					
					
					else if(100>bat_money || 10000<bat_money)
					{
						printf("100원 미만이거나 10000원 초과하셨습니다.\n");
						PAS;
						CLS;
					}
				}
}

void score(){        // 스코어(승,무,패)
	while(1){
		if(p_total==21)
		{
			printf("블랙잭입니다. 축하합니다.\n");
			money+=(bat_money)*2;
			win++;
			PAS;
			CLS;
			break;
		}
		else if(d_total==21)
		{
			printf("딜러의 블랙잭입니다.\n");
			money-=bat_money;
			lose++;
			PAS;
			CLS;
			break;
		}

		else if(p_total==d_total==21)
		{
			printf("Player : %d, Dealer : %d 로 비겼습니다.\n",p_total , d_total);
			draw++;
			PAS;
			CLS;
			break;
		}
		
		else if((d_total>21)&&(p_total<21))
		{
			printf("Player : %d, Dealer : %d 로 이겼습니다.\n",p_total, d_total);
			money+=(bat_money)*2;
			win++;
			PAS;
			CLS;
			break;
		}
		
		else if((p_total>21)&&(d_total<21))
		{
			printf("Player : %d, Dealer : %d 로 졌습니다.\n",p_total, d_total);
			money-=bat_money;
			lose++;
			PAS;
			CLS;
			break;
		}
		
		else if((d_total>21)&&(p_total>21))
		{
			printf("Player : %d , Dealer : %d 로 21이 넘었으므로 비겼습니다\n",p_total, d_total);
			draw++;
			PAS;
			CLS;
			break;
		}
		
		else if(p_total<21 && p_total>d_total)
		{
			printf("Player : %d, Dealer : %d 로 이겼습니다.\n",p_total, d_total);
			money+=(bat_money)*2;
			win++;
			PAS;
			CLS;
			break;
		}
		
		else if(d_total<21 && p_total<d_total)
		{
			printf("Player : %d, Dealer : %d 로 졌습니다.\n",p_total, d_total);
			money-=bat_money;
			lose++;
			PAS;
			CLS;
			break;
		}break;
	}
}



