#include "Sudoku.h"
void Sudoku::giveQuestion(){setQuestion(*map);}
void Sudoku::setQuestion(int *map){
	int i,j;
	for(j=0;j<9;j++)
	{
		for(i=0;i<9;i++)
		{
			*(map+j*9+i)=0;
		}
	}
	*(map+0+2)=5;*(map+0+3)=3;*(map+1*9+0)=8;*(map+1*9+7)=2;
	*(map+2*9+1)=7;*(map+2*9+4)=1;*(map+2*9+6)=5;*(map+3*9+0)=4;
	*(map+3*9+5)=5;*(map+3*9+6)=3;*(map+4*9+1)=1;*(map+4*9+4)=7;
	*(map+4*9+8)=6;*(map+5*9+2)=3;*(map+5*9+3)=2;*(map+5*9+7)=8;
	*(map+6*9+1)=6;*(map+6*9+3)=5;*(map+6*9+8)=9;*(map+7*9+2)=4;
	*(map+7*9+7)=3;*(map+8*9+5)=9;*(map+8*9+6)=7;

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
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cin>>arr[i][j];
			temp[i][j]=arr[i][j];
			if(arr[i][j]>0){temp[i][j]=1;}
		}
	}
	
	
/*	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			arr[i][j]=map[i][j];
		}
	}

	for(i=0;i<9;i++){if(i==2||i==3)continue;cin>>arr[0][i];}
	for(i=0;i<9;i++){if(i==0||i==7)continue;cin>>arr[1][i];}
	for(i=0;i<9;i++){if(i==1||i==4||i==6)continue;cin>>arr[2][i];}
	for(i=0;i<9;i++){if(i==0||i==5||i==6)continue;cin>>arr[3][i];}
	for(i=0;i<9;i++){if(i==1||i==4||i==8)continue;cin>>arr[4][i];}
	for(i=0;i<9;i++){if(i==2||i==3||i==7)continue;cin>>arr[5][i];}
	for(i=0;i<9;i++){if(i==1||i==3||i==8)continue;cin>>arr[6][i];}
	for(i=0;i<9;i++){if(i==2||i==7)continue;cin>>arr[7][i];}
	for(i=0;i<9;i++){if(i==5||i==6)continue;cin>>arr[8][i];}
*/	
}

void Sudoku::solve(){
int i=0,j=0,judge=1;
									
	getFirst(i,j);						//find the solution
	do{
		cout<<"hellooooooooooooooooooo"<<endl;	
		arr[i][j]++;
		if(arr[i][j]>9)
		{
			arr[i][j]=0;
			back(i,j);
		}
		else if(checkUnity(unity,i,j)==1)
		judge=getNext(i,j);
	}while(judge);
	

	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

}

void Sudoku::changeNum(){
}

void Sudoku::changeRow(){
}

void Sudoku::changeCol(){
}

void Sudoku::rotate(){
}

void Sudoku::flip(){
}

void Sudoku::transform(){
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

bool Sudoku::getNext(int &i, int &j){		//find the next blank to solve
int a=i,b=j+1;
	if(b>8){i++,j=0;return true;}
	for(a=a;a<9;a++)
	{
		for(b=b;b<9;b++)
		{
			if(temp[a][b]==0){i=a,j=b;return true;}
			if(b==8){b=0;break;}
		}
	}
	return false;
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
return ;
}




bool Sudoku::checkUnity(int *unity, int a, int b){     
int i=a,j=b,k;

	i=a;
	for(k=0;k<9;k++){*(unity+k)=0;}
	for(j=0;j<9;j++)                 //check this row
	{	
		cout<<"check row"<<endl;   //
		if(arr[i][j]==0){continue;}
		(*(unity+arr[i][j]-1))++;
		if((*(unity+arr[i][j]-1))>1)
			return false;
	}

	j=b;
	for(k=0;k<9;k++){*(unity+k)=0;}
	for(i=0,j=b;i<9;i++)			//check this column
	{
		cout<<"check column"<<endl; //
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
					cout<<"check cell"<<endl; //
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

		else if(j>=3&&j<6)			//in the block 2-2
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

		else if(j>=6&&j<9)			//in the block 2-3
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

	else if(i>=6&&i<9)				//in the big row 3
	{
		if(j>=0&&j<3)				//in the block 3-1
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

		else if(j>=3&&j<6)			//in the block 3-2
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

		else if(j>=6&&j<9)			//in the block 3-3
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

return true;
/*
	for(i=0;i<9;i++)		//check rows
	{	
		for(k=0;k<9;k++){*(unity+k)=0;}
		for(j=0;j<9;j++)
		{
			(*(unity+arr[i][j]-1))++;
			if((*(unity+arr[i][j]-1))!=1)
				return false;
		}
	}

	for(j=0;j<9;j++)		//check columns;
	{
		for(k=0;k<9;k++){*(unity+k)=0;}
		for(i=0;i<9;i++)
		{
			(*(unity+arr[i][j]-1))++;
			if((*(unity+arr[i][j]-1))!=1)
				return false;
		}
	}
	
	for(i=0;i<3;i++)		//check cells
	{	
		for(k=0;k<9;k++){*(unity+k)=0;}
		for(j=0;j<3;j++)
		{
				(*(unity+arr[i][j]-1))++;
				if(*(unity+arr[i][j]-1)!=1)
					return false;
		}
		for(j=3;j<6;j++)
		{
				(*(unity+arr[i][j]-1))++;
				if(*(unity+arr[i][j]-1)!=1)
					return false;

	    }
		for(j=6;j<9;j++)
		{
				(*(unity+arr[i][j]-1))++;
				if(*(unity+arr[i][j]-1)!=1)
					return false;

		}
	}

	for(i=3;i<6;i++)
	{	
		for(k=0;k<9;k++){*(unity+k)=0;}
		for(j=0;j<3;j++)
		{
				(*(unity+arr[i][j]-1))++;
				if(*(unity+arr[i][j]-1)!=1)
					return false;
		}
		for(j=3;j<6;j++)
		{
				(*(unity+arr[i][j]-1))++;
				if(*(unity+arr[i][j]-1)!=1)
					return false;

	    }
		for(j=6;j<9;j++)
		{
				(*(unity+arr[i][j]-1))++;
				if(*(unity+arr[i][j]-1)!=1)
					return false;

		}
	}

	for(i=6;i<9;i++)
	{	
		for(k=0;k<9;k++){*(unity+k)=0;}
		for(j=0;j<3;j++)
		{
				(*(unity+arr[i][j]-1))++;
				if(*(unity+arr[i][j]-1)!=1)
					return false;
		}
		for(j=3;j<6;j++)
		{
				(*(unity+arr[i][j]-1))++;
				if(*(unity+arr[i][j]-1)!=1)
					return false;

	    }
		for(j=6;j<9;j++)
		{
				(*(unity+arr[i][j]-1))++;
				if(*(unity+arr[i][j]-1)!=1)
					return false;

		}
	}
*/
}
