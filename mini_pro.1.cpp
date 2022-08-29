#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	
ofstream f;
ifstream p;
int ch,i,r,sem,qid=0,n, right=0, noq=0;
string U, P, name, branch;
string Question, op1, op2, op3, op4, ans, user_ans;
cout<<"PRESS 1 FOR TEACHER \nPRESS 2 FOR STUDENT: "<<endl;
cin>>ch;

if(ch==1)
{
	cout<<"ENTER USER ID: "<<endl;
	cin>>U;
	cout<<"ENTER PASSWORD: "<<endl;
	cin>>P;
	
	if(U=="Seed" && P=="IT")
	{
		cout<<"PRESS 1 TO ADD QUESTION"<<endl;
		cout<<"PRESS 2 TO SHOW PASS RESULT"<<endl;
		cout<<"PRESS 3 TO SHOW FAIL RESULT"<<endl;
		cin>>ch;
		
		if(ch==1)
		{
			f.open("q.txt",ios::app);
			cout<<"NUMBER OF QUESTIONS YOU WANT TO ADD: ";
			cin>>n;
			for(i=0; i<=n; i++)
			{
				cout<<"ENTER THE QUESTION AND FOUR OPTIONS AND DESIRED ANSWER: ";
				cin>>Question>>op1>>op2>>op3>>op4>>ans;
				f<<Question<<"\t"<<op1<<"\t"<<op2<<"\t"<<op3<<"\t"<<op4<<"\t"<<ans<<"\n";
			}
				f.close();
		}
	
		
	


        if(ch==2)
        {
	     p.open("result.txt", ios::app);
	     while(1)
	     {
	    	p>>r>>name>>branch>>sem>>right>>noq;
	    	if(p.eof())
	    	{
		    	break;
	    	}
		
	    	float per = right*100/noq;
	    	if(per>=60)
		    {
		    	cout<<r<<name<<"\n";
	    	}
	    	}
			p.close();
    	
       }
       
        if(ch==3)
        {
	     p.open("result.txt", ios::app);
	     while(1)
	     {
	    	p>>r>>name>>branch>>sem>>right>>noq;
	    	if(p.eof())
	    	{
		    	break;
	    	}
		
	    	float per = right*100/noq;
	    	if(per<60)
		    {
		    	cout<<r<<name<<"\n";
	    	}
	    	p.close();
    	 }
       }
       
       


   }
}
	
else
{
		cout<<"ENTER STUDENT DETAILS: ";
		p.open("q.txt");
		cin>>r>>name>>branch>>sem;
		
		
		while(1)
		{
		
		p>>Question>>op1>>op2>>op3>>op4>>ans;
		if(p.eof())
		{
			break;
		}
		qid++;
		cout<<"["<<qid<<"] "<<Question<<"\n";
		cout<<"1)"<<op1;
		cout<<"\n2)"<<op2;
		cout<<"\n3)"<<op3;
		cout<<"\n4)"<<op4;
		cout<<"\n"<<"ENTER YOUR ANSWER: ";
		cin>>user_ans;
		
		if(user_ans==ans)
		{
			right++;
		}
		noq++;
		
	  }
	  p.close();
	  
	  cout<<right<<"/"<<noq;
	  f.open("result.txt", ios::app);
	  f<<r<<name<<"\t"<<branch<<"\t"<<sem<<"\t"<<right<<"\t"<<noq<<"\n";
	  f.close();
	  
	
	  
	
}

}
