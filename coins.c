#include <stdio.h>
#include <unistd.h>

int stamp,amount,balance=-0,tend,totalCoin;

int main(){
menu:{
	printf("\n1 - A stamp of twenty five rupees. \n");
	printf("2 - A stamp of fifteen rupees. \n");
	printf("3 - A stamp of ten rupees. \n");
	printf("4 - Exit.");
	printf("---------------------------------------- \n\n");

	printf("Enter You want stamp number: ");
	scanf("%d",&stamp);
	printf("---------------------------------------- \n\n");
}
	if (stamp==4)
	{
	 	printf("Thank you..\n");
	}
	else if(stamp>4 || stamp<1){
		printf("No stamp available.\n");
		goto menu;
	}
	else{
		printf("Machine balance is: %d",balance);

		if (stamp==1)
		{
			if(balance==0){
				tend=25;
			}
			else{
				tend=balance-25;
			}
		}
		else if (stamp==2)
		{
			if(balance==0){
				tend=15;
			}
			else{
				tend=balance-15;
			}
		}
		else{
			if(balance==0){
				tend=10;
			}
			else{
				tend=balance-10;
			}
		}
		printf("\nYou want to tendered amount is:%d",tend);
		printf("\n---------------------------------------- \n\n");

		printf("A fifty rupees coin. \n");
		printf("A twenty five rupees coin. \n");
		printf("A ten rupees coin. \n");
		printf("A five rupees coin. \n");
		printf("---------------------------------------- \n\n");

		printf("Enter your tendered coin amount: ");
		scanf("%d",&amount);
		printf("Enter the number of coine you tendered: ");
		scanf("%d",&totalCoin);
		printf("\n---------------------------------------- \n\n");

		if (totalCoin>2)
		{
			printf("No Change!\n");
		}
		else{
			switch(stamp){
				case 1:
					goto option1;
				case 2:
					goto option2;
				case 3:
					goto option3;
				default:
					printf("No stamp available.\n");
					break;
			}
		}



		option1:{
			if (amount>=25)
			{
				balance=amount-25;
				printf("We success recived your 25 rupees stamp.\n");
				printf("Your balance is: %d\n",balance);
			}
			else{

				printf("Insufficient amount tendered.\n");
			}
			goto menu;
		}
		option2:{
			if (amount>=15)
			{
				balance=amount-15;

				printf("We success recived your 15 rupees stamp.\n");
				printf("Your balance is: %d\n",balance);
			}
			else{
				printf("Insufficient amount tendered.\n");
			}
			goto menu;
		}
		option3:{
			if (amount>=10)
			{
				balance=amount-10;
				printf("We success recived your 10 rupees stamp.\n");
				printf("Your balance is: %d\n",balance);
			}
			else{
				printf("Insufficient amount tendered.\n");
			}
			goto menu;
		}
	}
 	return 0;
}
