//Program for footwear management system that allows its customers to add or buy footwear and display it
#include <iostream>
#include<string>
#include<stdlib.h>
using namespace std;
class Footwear//Stores and displays specifications of footwear.
{
	public:
		int size, count;
		double price;
		void input()
		{
			cout<<"Enter the details of the Footwear:"<<endl;
			cout<<"size: "<<endl;
			cin>> size;
			cout<<"PRICE: "<< endl;
			cin>> price;
			cout<<"QUANTITY: "<<endl;
			cin>>count;
		}
		void display()
		{
			cout<<"\nDETAILS OF FOOTWEAR :"<<endl;
			cout<<"\nSIZE:"<< size<<"\n PRICE: "<<price<<"\n QUANTITY: "<<count<<endl;
			
		}
		
};
class manufacture: public Footwear//Takes details about the foootwear from the manufacturer.
{
	public:
		int change;
		double new_price;
		void check()
		{
			cout<<"Do you want to make any modifications to the price of the footwear you are selling?"<<endl;
			cout<<"Enter 0 for no and 1 for yes"<<endl;
			cin>>change;
			switch(change)
			{
				case 0: cout<<"No changes are being made to the footwear's price"<<endl;
				break;
				case 1: cout<<"The price for which you wish to sell the footwear?"<<endl;
				cout<<"MRP SHOULD NOT EXCEED 10000"<<endl;
				cin>>new_price;
				if(new_price>price)
				{
					if((new_price-price)>10000)
					{
					cout<<"SORRY. WE DO NOT ACCEPT THE PROPOSED PRICE AND ARE NOT BUYING THE FOOOTWEAR"<<endl;
					count=0;
				}
				else
				price=new_price;
			}
			else
			price=new_price;
			break;
			default: cout<<"Wrong option chosen.There are no changes in the pricing and the footwear is manufactured at its original price "<<endl;
				}
				
				
			}
			void show(){
				cout<< "UPDATED PRICE OF THE FOOTWEAR NOW: "<<new_price;
			}
            
		};
		class Buyer//Customer buys the footwear
		{
			public:
			int fsize;
			void getsize()
			{
			cout<<"\nEnter the size of the footwear you want to buy:"<<endl;
			cin>>fsize;
		}
		};
        class Rent//Person rents the 
		{
			public:
				int rsize;
			void getrsize()
			{
			cout<<"Enter the size of the footwear you want to rent:"<<endl;
			cin>>rsize;
		}
        };
		class ReturnFootwear//Person returns previously rented footwear
		{
		public:
			int d;
			void ret()
			{
			cout<<"How many days later are you returning the footwear?"<<endl;
			cin>>d;
			if(d>15)
			cout<<"You have to pay a fine of 1000 ruppees"<<endl;
			else
			cout<<"Thank you for returning the footwear on time"<<endl;	
			}
			
		};

        int main()
		{
        
			cout<<"Enter an option from below:"<<endl;
			cout<<"1: MANUFACTURE A FOOOTWEAR"<<endl;
			cout<<"2: BUY A FOOTWEAR"<<endl;
			cout<<"3:RENT A FOOTWEAR"<<endl;
			cout<<"4: RETURN FOOTWEAR(PREVIOUSLY RENTED)"<<endl;
			cout<<"5. EXIT"<<endl;
			int op;
			cin>>op;
			Footwear ob[150];
			manufacture s;
			Buyer b;
			Rent r;
			ReturnFootwear R;
			int i=0;
			do
			{
			switch(op)
			{
				case 1:ob[i].input();
				ob[i].display();
				s.check();
				s.show();
				i++;
				break;
				case 2:
				{
				  b.getsize();
				int j=i;
				while(j!=-1)
				{
					if( ob[i].size==b.fsize)
					{
						if(ob[j].count!=0)
						{
						cout<<"SOLD TO YOU"<<endl;
						ob[j].count--;
						ob[j].display();
						}
						else
						cout<<"Sorry not in stock"<<endl;
						
					}
					else
					cout<<"Sorry we do not have that Footwear"<<endl;
					j--;
					}
			}
				
		break;
	
		case 3: {
			
		r.getrsize();
			int j=i;
				while(j!=-1)
				{
					if( ob[j].size==r.rsize)
					{
						if(ob[j].count!=0)
						{
						cout<<"RENTED TO YOU"<<endl;
						ob[j].count--;
						ob[j].display();
						}
						else
						cout<<"Sorry not in stock"<<endl;
						
					}
					else
					cout<<"Sorry we do not have that FOOTWEAR"<<endl;
					j--;
					}}
					break;
					case 4:{
						cout<<"STATE THE SIZE OF THE BOOK YOU ARE RETURNING"<<endl;
					int f_size;
					cin>>f_size;
					int j=i;
					while(j!=-1)
					{
						if(ob[j].size==f_size)
						{
						
						ob[j].count++;
						cout<<"Footwear returned succesfully"<<endl;
						ob[j].display();
					}
						else
						cout<<"Wrong size"<<endl;
					j--;	
					}
					R.ret();}
					break;
					default:cout<<"Wrong option. Try Again"<<endl;
                    
					}
					
				}while(op!=5);
            
				return 0;
			}