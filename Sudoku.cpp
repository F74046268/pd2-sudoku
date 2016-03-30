#include "Sudoku.h"
void Sudoku::giveQuestion(){setQuestion(*map);}
void Sudoku::setQuestion(int *map){
	int i,j;
	answer[0][0]=1;answer[0][1]=4;answer[0][2]=5;answer[0][3]=3;answer[0][4]=2;
	answer[0][5]=7;answer[0][6]=6;answer[0][7]=9;answer[0][8]=8;answer[1][0]=8;
	answer[1][1]=3;answer[1][2]=9;answer[1][3]=6;answer[1][4]=5;answer[1][5]=4;
	answer[1][6]=1;answer[1][7]=2;answer[1][8]=7;answer[2][0]=6;answer[2][1]=7;
	answer[2][2]=2;answer[2][3]=9;answer[2][4]=1;answer[2][5]=8;answer[2][6]=5;
	answer[2][7]=4;answer[2][8]=3;answer[3][0]=4;answer[3][1]=9;answer[3][2]=6;
	answer[3][3]=1;answer[3][4]=8;answer[3][5]=5;answer[3][6]=3;answer[3][7]=7;
	answer[3][8]=2;answer[4][0]=2;answer[4][1]=1;answer[4][2]=8;answer[4][3]=4;
	answer[4][4]=7;answer[4][5]=3;answer[4][6]=9;answer[4][7]=5;answer[4][8]=6;
	answer[5][0]=7;answer[5][1]=5;answer[5][2]=3;answer[5][3]=2;answer[5][4]=9;
	answer[5][5]=6;answer[5][6]=4;answer[5][7]=8;answer[5][8]=1;answer[6][0]=3;
	answer[6][1]=6;answer[6][2]=7;answer[6][3]=5;answer[6][4]=4;answer[6][5]=2;
	answer[6][6]=8;answer[6][7]=1;answer[6][8]=9;answer[7][0]=9;answer[7][1]=8;
	answer[7][2]=4;answer[7][3]=7;answer[7][4]=6;answer[7][5]=1;answer[7][6]=2;
	answer[7][7]=3;answer[7][8]=5;answer[8][0]=5;answer[8][1]=2;answer[8][2]=1;
	answer[8][3]=8;answer[8][4]=3;answer[8][5]=9;answer[8][6]=7;answer[8][7]=6;
	answer[8][8]=4; 
	for(j=0;j<9;j++)
	{
		for(i=0;i<9;i++)
		{
			*(map+j*9+i)=0;
		}
	}
	*(map+0*9+2)=answer[0][2];*(map+0*9+3)=answer[0][3];*(map+1*9+0)=answer[1][0];
	*(map+1*9+7)=answer[1][7];*(map+2*9+1)=answer[2][1];*(map+2*9+4)=answer[2][4];
	*(map+2*9+6)=answer[2][6];*(map+3*9+0)=answer[3][0];*(map+3*9+5)=answer[3][5];
	*(map+3*9+6)=answer[3][6];*(map+4*9+1)=answer[4][1];*(map+4*9+4)=answer[4][4];
	*(map+4*9+8)=answer[4][8];*(map+5*9+2)=answer[5][2];*(map+5*9+3)=answer[5][3];
	*(map+5*9+7)=answer[5][7];*(map+6*9+1)=answer[6][1];*(map+6*9+3)=answer[6][3];
	*(map+6*9+8)=answer[6][8];*(map+7*9+2)=answer[7][2];*(map+7*9+7)=answer[7][7];
	*(map+8*9+5)=answer[8][5];*(map+8*9+6)=answer[8][6];

	for(j=0;j<9;j++)
	{
		for(i=0;i<9;i++)
		{
			cout<<*(map+j*9+i)<<" ";
		}
			cout<<endl;
	}
}

void Sudoku::readIn(){
	int i,j,k;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cin>>arr[i][j];
			temp[i][j]=arr[i][j];
			map[i][j]=arr[i][j];
			if(arr[i][j]>0){temp[i][j]=1;}
		}
	}

	for(k=0;k<9;k++)
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				possible[i][j][k]=1;
			}
		}
	}

}

void Sudoku::solve(){
int i=0,j=0,k=0,count=0,sum=0;
	if(Validable()==0){cout<<0<<endl;return;} //check the question is correct or not
	
	for(i=0;i<9;i++)					//find all possible
	{
		for(j=0;j<9;j++)
			{
					checkPossible(i,j);
			}
	}

	for(k=0;k<9;k++)										//overlap all possibles which in one block
	{														//in one block, all possible(means 1 to 9)  should be counted
		count=0;											// if one of possibles is 0, then this question has no solution.
		for(i=0;i<3;i++)								
		{
			for(j=0;j<3;j++)
			{
				if(possible[i][j][k]==true)count++;
			}
		}
		if(count==0){cout<<0<<endl;return;}
		
		count=0;
		for(i=3;i<6;i++)
		{
			for(j=3;j<6;j++)
			{
				if(possible[i][j][k]==true)count++;
			}
		}
		if(count==0){cout<<0<<endl;return;}

		count=0;
		for(i=6;i<9;i++)
		{
			for(j=6;j<9;j++)
			{
				if(possible[i][j][k]==true)count++;
			}
		}
		if(count==0){cout<<0<<endl;return;}


	
	}
								
	getFirst(i,j);						//find the solution
	do{

	
		arr[i][j]++;
		
		
		if(arr[i][j]>9)					//if this blank >9 , back to the last blank
		{
		
			arr[i][j]=0;
			back(i,j);
			
		}
		else if(checkUnity(unity,i,j)==1)
		{
			
			getNext(i,j);				//jump to the next blank
	
			if((i*9+j)==81)				//if all of the blank has been filled,check backward that this question is 1 or more solutions
			{
				for(i=0;i<9;i++)
				{
					for(j=0;j<9;j++)
					{
						map[i][j]=arr[i][j];
					}
				}
				i=8,j=9;
				sum++;
				back(i,j);
			}
		}
	}while((i*9+j)>=0&&(i*9+j)<81&&sum<2);
	
	

	if(sum==1)
	{
		cout<<sum<<endl;
		for(i=0;i<9;i++)					//print out answer
		{
			for(j=0;j<9;j++)
			{
				cout<<map[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else if(sum>1)
	{
		cout<<sum<<endl;
	}
	else if(sum<1)
	{
		cout<<0<<endl;
	}
	
}

void Sudoku::changeNum(int a, int b){
int i,j;
	
	if(a<1||a>9||b<1||b>9){cout<<"no such number can let you change"<<endl;return;}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(arr[i][j]==a){arr[i][j]=b;}
			else if(arr[i][j]==b){arr[i][j]=a;}
		}
	}

	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			temp[i][j]=arr[i][j];
			if(temp[i][j]>1){temp[i][j]=1;}
		}
	}
}

void Sudoku::changeRow(int a, int b){
int i,j;
	if(b<a){i=a;a=b;b=i;}
	if(a<0||b<0||a>2||b>2){cout<<"no such number can let you change"<<endl;return;}
	for(i=0;i<3;i++)
	{
		for(j=0;j<9;j++)
		{
			map[i+3*b][j]=arr[i+3*a][j];
			map[i+3*a][j]=arr[i+3*b][j];
		}
	}
	

	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			arr[i][j]=map[i][j];
			temp[i][j]=arr[i][j];
			if(temp[i][j]>1){temp[i][j]=1;}
		}
	}
}

void Sudoku::changeCol(int a, int b){
int i,j;
	if(b>a){i=a;a=b;b=i;}
	if(a<0||b<0||a>2||b>2){cout<<"no such number can let you change"<<endl;return;}
	for(j=0;j<3;j++)
	{
		for(i=0;i<9;i++)
		{
			map[i][j+3*b]=arr[i][j+3*a];
			map[i][j+3*a]=arr[i][j+3*b];
		}
	}

	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			arr[i][j]=map[i][j];
			temp[i][j]=arr[i][j];
			if(temp[i][j]>1){temp[i][j]=1;}
		}
	}

}

void Sudoku::rotate(int n){
int i,j;
	if(n<0||n>100){cout<<"input n must between 0 and 100"<<endl;return;}
	while(n>0){
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				map[j][i+(8-2*i)]=arr[i][j];
			
			}
		}
	
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				arr[i][j]=map[i][j];
				temp[i][j]=arr[i][j];
				if(temp[i][j]>1){temp[i][j]=1;}
			}
		}
		n--;
	}
}

void Sudoku::flip(int n){
int i,j;
if(n==0){
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			map[8-i][j]=arr[i][j];
		}
		
	}

	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			arr[i][j]=map[i][j];
			temp[i][j]=arr[i][j];
			if(temp[i][j]>1){temp[i][j]=1;}
		}
	}
}

else if(n==1){
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			map[i][8-j]=arr[i][j];
		}
	}

	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			arr[i][j]=map[i][j];
			temp[i][j]=arr[i][j];
			if(temp[i][j]>1){temp[i][j]=1;}
		}
	}
}
else 
cout<<"input n must be 0 or 1"<<endl;
}

void Sudoku::transform(){
int i,j;

	cout<<endl<<endl;
	changeRow(1,2);
	flip(1);
	changeRow(1,2);
	rotate(2);
	changeCol(0,1);

	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
}




void Sudoku::getFirst(int &i, int &j){		//find the first blank to solve
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(temp[i][j]==0)return;
		}
	}
}

void Sudoku::getNext(int &i, int &j){		//find the next blank to solve
int a=i,b=j+1;
	
	if(b>8){a++;b=0;}
	for(a=a;a<9;a++)
	{
		for(b=b;b<9;b++)
		{
			if(temp[a][b]==0){i=a,j=b;return ;}
			if(b==8){b=0;break;}
		}
	}

	i=8,j=9;return;
}

void Sudoku::back(int &i, int &j){			//back to the last position
int a=i,b=j-1;
	
	
	if(b<0){a--;b=8;}
	for(a=a;a>=0;a--)
	{
		
		for(b=b;b>=0;b--)
		{
			if(temp[a][b]==0){i=a,j=b;return ;}
			if(b==0){b=8;break;}
		}
	}
	
	i=0,j=-1;return ;
}

void Sudoku::checkPossible(int row, int column){		//all possibility set to true
	int i,j;
		if(map[row][column])      //if map have had answer,then possible will just has 1
		{
			for(i=0;i<9;i++)
			{
				possible[row][column][i]=false;
			}
			possible[row][column][map[row][column]-1]=true;
			return;
		}

		for(j=0;j<9;j++)		//compute row possible
		{
			if(map[row][j]){possible[row][column][map[row][j]-1]=false;}
		}

		for(i=0;i<9;i++)		//compute column possible
		{
			if(map[i][column]){possible[row][column][map[i][column]-1]=false;}
		}	
																													
		for(i=0;i<3;i++)     //compute cell possible
		{
			for(j=0;j<3;j++)
			{
				if(map[row-(row%3)+i][column-(column%3)+j]){possible[row][column][map[row-(row%3)+i][column-(column%3)+j]-1]=false;}
			}
		}
}

bool Sudoku::checkUnity(int *unity, int a, int b){     
int i=a,j=b,k;

	i=a;
	for(k=0;k<9;k++){*(unity+k)=0;}
	for(j=0;j<9;j++)                 //check this row
	{	
		if(arr[i][j]==0){continue;}
		(*(unity+arr[i][j]-1))++;
		if((*(unity+arr[i][j]-1))>1)
			return false;
	}

	j=b;
	for(k=0;k<9;k++){*(unity+k)=0;}
	for(i=0,j=b;i<9;i++)			//check this column
	{
		if(arr[i][j]==0){continue;}
		(*(unity+arr[i][j]-1))++;
		if((*(unity+arr[i][j]-1))>1)
			return false;
	}

	i=a,j=b;						//check this cell
	for(k=0;k<9;k++){*(unity+k)=0;}
	if(i>=0&&i<3)					//in the big row 1
	{
		if(j>=0&&j<3)				//in the block 1-1
		{
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					if(arr[i][j]==0){continue;}
					(*(unity+arr[i][j]-1))++;
					if((*(unity+arr[i][j]-1))>1)
						return false;
				}
			}
		}
		else if(j>=3&&j<6)			//in the block 1-2
		{
			for(i=0;i<3;i++)
			{
				for(j=3;j<6;j++)
				{
					if(arr[i][j]==0){continue;}	
					(*(unity+arr[i][j]-1))++;
					if((*(unity+arr[i][j]-1))>1)
						return false;
				}
			}
		}
		else if(j>=6&&j<9)			//in the block 1-3
		{
			for(i=0;i<3;i++)
			{
				for(j=6;j<9;j++)
				{
					if(arr[i][j]==0){continue;}
					(*(unity+arr[i][j]-1))++;
					if((*(unity+arr[i][j]-1))>1)
						return false;
				}
			}
		}

	}

	else if(i>=3&&i<6)				//in the big row 2
	{
		if(j>=0&&j<3)				//in the block 2-1
		{
			for(i=3;i<6;i++)
			{
				for(j=0;j<3;j++)
				{
		 			if(arr[i][j]==0){continue;}
					(*(unity+arr[i][j]-1))++;
					if((*(unity+arr[i][j]-1))>1)
						return false;
				}
			}
		}

		else if(j>=3&&j<6)			//in the block 2-2
		{
			for(i=3;i<6;i++)
			{
				for(j=3;j<6;j++)
				{
					if(arr[i][j]==0){continue;}
					(*(unity+arr[i][j]-1))++;
					if((*(unity+arr[i][j]-1))>1)
						return false;
				}
			}
		}

		else if(j>=6&&j<9)			//in the block 2-3
		{
			for(i=3;i<6;i++)
			{
				for(j=6;j<9;j++)
				{
					if(arr[i][j]==0){continue;}
					(*(unity+arr[i][j]-1))++;
					if((*(unity+arr[i][j]-1))>1)
						return false;
				}
			}
		}

	}

	else if(i>=6&&i<9)				//in the big row 3
	{
		if(j>=0&&j<3)				//in the block 3-1
		{
			for(i=6;i<9;i++)
			{
				for(j=0;j<3;j++)
				{
					if(arr[i][j]==0){continue;}
					(*(unity+arr[i][j]-1))++;
					if((*(unity+arr[i][j]-1))>1)
						return false;
				}
			}
		}

		else if(j>=3&&j<6)			//in the block 3-2
		{
			for(i=6;i<9;i++)
			{
				for(j=3;j<6;j++)
				{
					if(arr[i][j]==0){continue;}
					(*(unity+arr[i][j]-1))++;
					if((*(unity+arr[i][j]-1))>1)
						return false;
				}
			}
		}

		else if(j>=6&&j<9)			//in the block 3-3
		{
			for(i=6;i<9;i++)
			{
				for(j=6;j<9;j++)
				{
					if(arr[i][j]==0){continue;}
					(*(unity+arr[i][j]-1))++;
					if((*(unity+arr[i][j]-1))>1)
						return false;
				}
			}
		}

	}

return true;
}
bool Sudoku::Validable(){
int i,j,k;
	for(i=0;i<9;i++)		//check rows
	{	
		for(k=0;k<9;k++){*(unity+k)=0;}
		for(j=0;j<9;j++)
		{
			if(map[i][j]==0){continue;}
			(*(unity+map[i][j]-1))++;
			if((*(unity+map[i][j]-1))!=1)
				return false;
		}
	}

	for(j=0;j<9;j++)		//check columns;
	{
		for(k=0;k<9;k++){*(unity+k)=0;}
		for(i=0;i<9;i++)
		{
			if(map[i][j]==0){continue;}
			(*(unity+map[i][j]-1))++;
			if((*(unity+map[i][j]-1))!=1)
				return false;
		}
	}
	
	for(k=0;k<9;k++){*(unity+k)=0;}  //check block 1-1
	for(i=0;i<3;i++)		
	{	
		for(j=0;j<3;j++)
		{
				if(map[i][j]==0){continue;}
				(*(unity+map[i][j]-1))++;
				if(*(unity+map[i][j]-1)!=1)
					return false;
		}
	}

	for(k=0;k<9;k++){*(unity+k)=0;}	 //check block 1-2
	for(i=0;i<3;i++)
	{
		for(j=3;j<6;j++)
		{
				if(map[i][j]==0){continue;}
				(*(unity+map[i][j]-1))++;
				if(*(unity+map[i][j]-1)!=1)
					return false;

	    }
	}

	for(k=0;k<9;k++){*(unity+k)=0;}
	for(i=0;i<3;i++)
	{
		for(k=0;k<9;k++){*(unity+k)=0;}
		for(j=6;j<9;j++)
		{
				if(map[i][j]==0){continue;}
				(*(unity+map[i][j]-1))++;
				if(*(unity+map[i][j]-1)!=1)
					return false;

		}
	}

	for(k=0;k<9;k++){*(unity+k)=0;}
	for(i=3;i<6;i++)
	{	
		for(j=0;j<3;j++)
		{
				if(map[i][j]==0){continue;}
				(*(unity+map[i][j]-1))++;
				if(*(unity+map[i][j]-1)!=1)
					return false;
		}
	}
	
	for(k=0;k<9;k++){*(unity+k)=0;}
	for(i=3;i<6;i++)
	{
		for(j=3;j<6;j++)
		{
				if(map[i][j]==0){continue;}
				(*(unity+map[i][j]-1))++;
				if(*(unity+map[i][j]-1)!=1)
					return false;

	    }
	}

	for(k=0;k<9;k++){*(unity+k)=0;}
	for(i=3;i<6;i++)
	{
		for(j=6;j<9;j++)
		{
				if(map[i][j]==0){continue;}
				(*(unity+map[i][j]-1))++;
				if(*(unity+map[i][j]-1)!=1)
					return false;

		}
	}

	for(k=0;k<9;k++){*(unity+k)=0;}
	for(i=6;i<9;i++)
	{	
		for(j=0;j<3;j++)
		{
				if(map[i][j]==0){continue;}
				(*(unity+map[i][j]-1))++;
				if(*(unity+map[i][j]-1)!=1)
					return false;
		}
	}

	for(k=0;k<9;k++){*(unity+k)=0;}
	for(i=6;i<9;i++)
	{
		for(j=3;j<6;j++)
		{
				if(map[i][j]==0){continue;}
				(*(unity+map[i][j]-1))++;
				if(*(unity+map[i][j]-1)!=1)
					return false;

	    }
	}	

	for(k=0;k<9;k++){*(unity+k)=0;}
	for(i=6;i<9;i++)
	{
		for(j=6;j<9;j++)
		{
				if(map[i][j]==0){continue;}
				(*(unity+map[i][j]-1))++;
				if(*(unity+map[i][j]-1)!=1)
					return false;

		}
	}
return true;
}

