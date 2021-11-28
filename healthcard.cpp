#include<iostream>
#include<windows.h> //HEADER FOR PRINTING MESSAGE BOX IN GUI FORM
#include<string.h>
#include<fstream>
#include<ctime>     //HEADER FOR PRINTING THE TIME OF DISEASE UPDATION
using namespace std;
void changeColor(int desiredColor);

//TO CHANGE THE COLOUR OF THE OUTPUT
void changeColor(int desiredColor){
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

int loginAttempt=0;
// CREATION OF ID TEXT FILE
void init_files()	{
	int flag=0;
	fstream file;
	file.open("id.txt",ios::in);
	
	if(!file)	flag=1;
	file.close();
	
	if(flag)	{
		file.open("id.txt",ios::out);
		file<<100000;
		file.close();
	}
}
// DATASTRUCTURE FOR USER LOGIN
class user	{
    string Name;
    string Pass;
	
	public:
    void getuser()	{
        while (loginAttempt < 3)	{
        
        cout << "\nUser_Name : ";
        cin >> Name;
        cout << "\nPassword  : ";
        cin >> Pass;

        if (Name=="KMC" && Pass=="KMC01" || Name=="LLC" && Pass=="LLC01" || Name=="CMC" && Pass=="CMC01")	{
            MessageBox(NULL,"Welcome to Health card services!\nThank you for logging in ","THE HEALTH CARD",MB_OK| MB_ICONINFORMATION);
            system("CLS");
            break;
        }
        else	{
             MessageBox(NULL,"Invalid login attempt. Please try again. ","THE HEALTH CARD",MB_OK| MB_ICONINFORMATION);
           system ("CLS");
       }
            loginAttempt++;
        }
        if(loginAttempt==3) MessageBox(NULL,"LOGIN ATTEMPT CROSSED THE LIMIT !!! ","THE HEALTH CARD",MB_OK| MB_ICONINFORMATION);
    	}
};
//DATASTRUCTURE FOR INDIVIDUAL PERSON
class person	{
	char phoneno[50],rel_ph_no[50];
    float hei,wei,Bmi,h,w;
    int id,year,n,n1,n2,n3,age,chlo,sys,dia;
    char name[25],gender[20],status[20],bld_grp[20],diab[5];
	int i,flag;
	public:
		person():Bmi(0){}
		int increment(int y);
		int ide();
		int ide1();
		void assign();
		void get();
		void details();
		void display();
		int disp_details(int id);
	    void update();
}p;

int person::increment(int y)	{
    return ++id;
}

int person::ide()	{
		ifstream fin("id.txt", ios::in |ios::out); //USED TO INCREMENT THE ID VALUE
        int value;
        fin>>value;
        fin.close();
		return value;
}

void person::assign()	{
    id=ide();
}

void person::get()	{    //TO GET INPUT FROM THE USER WITH PROPER VALIDATIONS
        increment(id);
        cout<<"\nName:";
        scanf(" %[^\n]s",name);
    	cout << "\nAge: ";
    	cin >> age;
	    cout<<"\nSelect Gender: \n1.Male \n2.Female \n";
	    do	{
	    cin>>n;
	    switch(n)	{
		 case 1:
		        strncpy(gender,"Male",5);
		        break;
		 case 2:
		        strncpy(gender,"Female",7);
		        break;
		 default:MessageBox(NULL,"INVALID CHOICE!!","THE HEALTH CARD",MB_OK| MB_ICONINFORMATION);
	    }
        }while(n!=1 && n!=2);
        
		do{
			i=0;
            cout<<"\nPhone no: ";
            cin>>phoneno;
            if (strlen(phoneno) > 10)
                flag=1;
            else
            {
                while(phoneno[i]!='\0' && isdigit(phoneno[i])!=0)
                    ++i;
                if (i==10)
                    flag=0;
                else{
                MessageBox(NULL,"ENTER A 10 DIGIT PHONE NUMBER !!","THE HEALTH CARD",MB_OK| MB_ICONINFORMATION);
                    flag=1;
                }
            }
            cin.ignore();
        }while(i!=10 || flag==1);
        
        do{
        	i=0;
            cout<<"\nRelation Phone no: ";
            cin>>rel_ph_no;
            if (strlen(rel_ph_no) > 10)
                flag=1;
            else
            {
                while(rel_ph_no[i]!='\0' && isdigit(rel_ph_no[i])!=0)
                    ++i;
                if (i==10)
                    flag=0;
                else{
                MessageBox(NULL,"ENTER A 10 DIGIT PHONE NUMBER !!","THE HEALTH CARD",MB_OK| MB_ICONINFORMATION);
                    flag=1;
                }
            }
            cin.ignore();
        }while(i!=10 || flag==1);
        cout<<"\nHeight(in cm):";
        do	{
	        cin>>h;
	        if(h>0)	{
	        	hei=(h*0.01);
			}
			else	{
				MessageBox(NULL,"Enter the correct height ","THE HEALTH CARD",MB_OK| MB_ICONINFORMATION);
			}
	    }while(hei==0);
	    
        cout<<"\nWeight(in kg):";
        do	{
	        cin>>w;
	        if(w>0)	{
	        	wei=w;
			}
			else	{
				MessageBox(NULL,"Enter the appropriate weight ","THE HEALTH CARD",MB_OK| MB_ICONINFORMATION);
			}
	    }while(wei==0);
	    
	    cout<<"\nSelect Marital Status: \n 1.Married \n 2.Unmarried \n";
	    do	{
		    cin>>n1;
		    switch(n1)	{
			 case 1: strncpy(status,"Married",8);
			        break;
			 case 2: strncpy(status,"Unmarried",11);
			        break;
			 default:MessageBox(NULL,"INVALID CHOICE","THE HEALTH CARD",MB_OK| MB_ICONINFORMATION);
		    }
        }while(n1!=1 && n1!=2);
        cout<<"\nEnter Blood_sugar value : ";
	    do	{
	    	cin>>n2;
		    if(n2 > 75 && n2 < 200)	{
		    	strncpy(diab,"No",4);
		    	cout<<"\nYou are healthy :)\n";
	        }
		    else if(n2 > 200)	{
		    strncpy(diab,"Yes",3);
		    cout<<"\nYes! You are diabetic :( \n";
		    }
		    else if( n2> 0 && n<=75)
		    {
		    	strncpy(diab,"yes",3);
		    	cout<<"\nYes! You are diabetic :( \n";
			}
		    else if(n2 != 0){
			MessageBox(NULL,"INAPPROPRIATE VALUE!PLEASE RE-ENTER:(","THE HEALTH CARD",MB_OK| MB_ICONINFORMATION);
		    }
        }while(n2<=0);
        
		cout<<"\nEnter cholestrol(0-170):";
        do{
          cin>>chlo;
          if(chlo < 0 || chlo  >170)
          {
          	MessageBox(NULL,"INVALID ENTRY!PLEASE RE-ENTER:(","THE HEALTH CARD",MB_OK| MB_ICONINFORMATION);
		  }
        }while(chlo < 0 || chlo  >170);
        
        cout<<"\nBlood pressure:-\n";
        cout<<"\tSystolic(90-120):";
        do	{
            cin>>sys;
            if(sys<90 || sys>120)
            {
            MessageBox(NULL,"INAPPROPRIATE VALUE!PLEASE RE-ENTER:(","THE HEALTH CARD",MB_OK| MB_ICONINFORMATION);
			}
        }while(sys<90 || sys>120);
        
        cout<<"\tDiastolic(60-80):";
        do{
            cin>>dia;
            if(dia<60 || dia >80)
            {
            MessageBox(NULL,"INVALID ENTRY!PLEASE RE-ENTER:(","THE HEALTH CARD",MB_OK| MB_ICONINFORMATION);	
			}
        }while(dia<60 || dia >80);
        Bmi=wei/(hei*hei);
        
        cout<<"\nSelect Blood Group:\n1.A+\n2.A-\n3.B+\n4.B-\n5.O+\n6.O-\n7.AB+\n8.AB-";
	    do	{
	    cout<<"\nEnter choice-";
	    cin>>n3;
	    switch(n3)	{
		case 1:
			strncpy(bld_grp,"A+",3);
 			break;
		case 2:
			strncpy(bld_grp,"A-",3);
			break;
		case 3:
			strncpy(bld_grp,"B+",3);
			break;
		case 4:
			strncpy(bld_grp,"B-",3);
			break;
		case 5:
			strncpy(bld_grp,"O+",3);
			break;
		case 6:
			strncpy(bld_grp,"O-",3);
			break;
		case 7:
			strncpy(bld_grp,"AB+",3);
			break;
		case 8:
			strncpy(bld_grp,"AB-",3);
			break;
		default:
			MessageBox(NULL,"INVALID CHOICE","THE HEALTH CARD",MB_OK| MB_ICONINFORMATION);
			break;
	   }}while(n3!=1 && n3!=2 && n3!=3 && n3!=4 && n3!=5 && n3!=6 && n3!=7 && n3!=8);
}

void person::display()	{ //TO DISPLAY THE CONTENTS STORED IN THE FILE FOR A PARTICULAR ID
	changeColor(1); 
	cout<<"\n Name   : "<<name<<"\n ID     :"<<id<<"\n Age    : "<<age<<"\t(as per 2020)"<<"\n Gender : "<<gender<<"\n Phone Number    : "<<phoneno<<"\n Relation Number :"<<rel_ph_no<<"\n Height: "<<hei<<" mt"<<"\n Weight: "<<wei<<" kg"<<"\n Marital Status: "<<status<<"\n BMI         :"<<Bmi<<"\n Diabetics   : "<<diab<<"\n Cholestrol  : "<<chlo<<"\n Blood group : "<<bld_grp<<"\n Blood pressure :- "<<"\n Systolic    : "<<sys<<"\t Diastolic   : "<<dia;
	
}

void person::details()	{                     //STORES THE USER GIVEN INPUT IN BINARY FILE 
    ofstream fout;
    fout.open("project.dat",ios::in|ios::out|ios::binary|ios::app);
    p.get();
    fout.write((char*)&p,sizeof(p));
    fout.close();
}

int person::disp_details(int id)	{        //USED TO RETRIEVE THE DETAILS FROM THE FILE ACCORDING TO THE SPECIFIED ID
    fstream fin;
    int flag=0;
    fin.open("project.dat",ios::in|ios::binary);
    
    while(fin.read((char *)&p,sizeof(p)))	{
        if(id==p.id)	{
        p.display();
        flag+=1;
        }
    }
    if(flag==0)	{
        	MessageBox(NULL,"THIS ID DOESNOT EXIST IN THE DATABASE","THE HEALTH CARD",MB_OK| MB_ICONINFORMATION);
    }
    return flag;
    fin.close();
}

void person::update()	{                    //STORES THE NEWLY UPDATED DETAILS IN PROJECT  BINARY FILE 
	int ID;
  	cout<<"\n Enter the ID whose healthcard name is to be modified:-";
  	cin>>ID;
  	fstream f;
  	f.open("project.dat",ios::in|ios::out|ios::binary);
  	f.seekg(0);
  	while(f.read((char*)&p,sizeof(p)))	{
   		if(ID==p.id)	{
		    cout<<"\n New details :-\n";
		    p.get();
		    p.id=ID;
		    f.seekp(-sizeof(p),ios::cur);
		    f.write((char*)&p,sizeof(p));
   		}
   	   else
   	   {
   	   		MessageBox(NULL,"THIS ID DOESNOT EXIST IN THE DATABASE","THE HEALTH CARD",MB_OK| MB_ICONINFORMATION);
   	   		break;
		  }
   }
 	f.close();
}

int person::ide1()	{
    ofstream fout("id.txt");
	fout<<p.id;
	fout.close();
}

//DATA STRUCTURE FOR DISEASE UPDATION
class disease	{                 
	int id;
	char d[100],str[20];
	time_t now;
	struct tm *ti;
	
	public:
	disease()	{strcpy(d,"NIL");}
	void getdata();
	void dispdata();
	void getdata1();
	void dispdata1(int id);
}d1;

void disease::getdata()	{                                     //TO STORE THE DISEASE OF THE PERSON ACCORDING TO THE ID SPECIFIED  
	cout<<"Enter your healthcard ID:-\n";
	cin>>id;
	cout<<"Enter disease history-\n";
	cin>>d;
	time(&now);
	ti = localtime(&now);
	strcpy(str,asctime(ti));
}

void disease::dispdata()	{
	changeColor(1);
	cout<<"\n "<<d<<"\t->"<<str;
}

void disease::getdata1()	{                                  //TO STORE THE DISEASE GIVEN BY THE USER IN DISEASE BINARY FILE
	fstream file;
	file.open("disease.dat",ios::in|ios::out|ios::binary|ios::app);
	d1.getdata();
	file.write((char*)&d1,sizeof(d1));
	file.close();
}

void disease::dispdata1(int id)	{                              // TO PRINT THE STORED DISEASE 
    fstream fin;
    int flag=0;
    fin.open("disease.dat",ios::in|ios::binary);
    
	while(fin.read((char*)&d1,sizeof(d1)))	{
    	if(id==d1.id)	{
        d1.dispdata();
        flag+=1;
        }
    }
    if(flag==0)	{
        cout<<"NIL";
    }
    fin.close();
}

int main()	{
    user u;
	int n,s,id;
	init_files();
    p.assign();
    u.getuser();
    
    if(loginAttempt!=3)	{
        do	{
        cout<<"\n\nMENU :-\n\n1. Add new details of a person.\n2. Update existing card details of a person.\n3. Update or add disease history of a person.\n4. View the card details of a person.\n5. Exit.\n\nEnter your choice : ";
        cin>>n;
        system("CLS");
        switch(n)	{
            case 1:
               	cout<<"\n------------Adding New Card Details-------------\n";
               	p.details();
               	system("CLS");
                break;
            case 2:
               	cout<<"\n--------------Updating Card Details---------------\n";
                p.update();
                system("CLS");
                break;
            case 3:
                cout<<"\n----------------Updating Disease History------------------\n";
               	d1.getdata1();
               	system("CLS");
                break;
            case 4:
               	cout<<"Enter ID to view your HealthCard:-";
               	cin>>id;
               	changeColor(4);
               	cout<<"\n<<<<<<<<<<<<<<<<<<<Health Card>>>>>>>>>>>>>>>>>>>>>>\n\n";
               	changeColor(8);
               	
               	CONSOLE_FONT_INFOEX cfi;                             //VARIABLE FOR CHANGING THE FONT STYLE
   					 cfi.cbSize = sizeof cfi;
    				 cfi.nFont = 0;
   					 cfi.dwFontSize.X = 0;
   					 cfi.dwFontSize.Y = 20;
   					 cfi.FontFamily = FF_DONTCARE;
    				 cfi.FontWeight = FW_NORMAL;
    				 wcscpy(cfi.FaceName, L"Lucida Console");
    				SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);   //INBUILT FUNCTION FOR CHANGING THE FONT STYLE
    				
                    if(p.disp_details(id)==1)	{	
                    cout<<"\n Disease History:- ";
                	d1.dispdata1(id);}
                	
                  changeColor(8);
                  
                 wcscpy(cfi.FaceName, L"Consolas");
    	         SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
                 cout<<"\n\n<<<<<<<<<<<<<<<<<<<*>>>>>>>>>>>>>>>>>>>>>>";
                 break;
            case 5:
                p.ide1();
					MessageBox(NULL,"     THANK YOU VISIT AGAIN !!! ","THE HEALTH CARD",MB_OK| MB_ICONINFORMATION);
				system("CLS");
                break;
            default:
                 MessageBox(NULL,"INVALID CHOICE...\nENTER THE NUMBER BETWEEN 1 AND 5","THE HEALTH CARD",MB_OK| MB_ICONINFORMATION);
                break;
        }
        }while(n!=5);
    }
}
