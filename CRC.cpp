#include <bits/stdc++.h>
using namespace std;
int main()
{

    int Dataword_size;
    cout<<"Enter Dataword size: ";
    cin>>Dataword_size;
    vector<int>Dataword;
    cout<<"Enter Dataword:";
    for(int i=0;i<Dataword_size;i++)
    {
        int temp;
        cin>>temp;
        Dataword.push_back(temp);
    }

    vector<int>gen;
    gen.push_back(1);
    for(int i=0;i<5;i++){
     gen.push_back(0);
    }
    for(int i=0;i<3;i++){
     gen.push_back(1);
    }

    int bits=gen.size()-1;
   cout<<"\nNumber of 0's appended: "<<bits;
    for (int i=0;i<bits;i++)
    {
        Dataword.push_back(0);
    }

   vector<int>codeword;
   for(int i=0;i<Dataword.size();i++){
     codeword.push_back(Dataword[i]);
   }

    cout<<"\nGENERATED DATAWORD :";
    for(int i=0;i<codeword.size();i++){
     cout<<codeword[i]<<" ";
    }
     int i,j,k;

    for(int i=0;i<Dataword_size;i++)
    {
        j=0;
        k=i;
        if (codeword[k]>=gen[j])
        {
            for(j=0,k=i;j<gen.size();j++,k++)
            {
                if((codeword[k]==1 && gen[j]==1) || (codeword[k]==0 && gen[j]==0))
                {
                    codeword[k]=0;
                }
                else
                {
                    codeword[k]=1;
                }
            }
        }
    }

    int add_bits[15];
    for(int i=0,j=Dataword_size;i<bits;i++,j++)
    {
        add_bits[i]=codeword[j];
    }

    cout<<"\nadding bits: ";
    for(int i=0;i<bits;i++)
    {
        cout<<add_bits[i]<<" ";
    }

    cout<<"\nSent CodeWord: ";
    vector<int>transmit;
    for(i=0;i<Dataword_size;i++)
    {
        int temp=Dataword[i];
        transmit.push_back(temp);
    }
    for(i=Dataword_size,j=0;i<Dataword_size+bits;i++,j++)
    {
        int temp=add_bits[j];
        transmit.push_back(temp);

    }
    for(i=0;i<Dataword_size+bits;i++)
    {
        cout<<transmit[i]<<" ";
    }
    cout<<endl<<endl;

    //-------------------------------------------TRANSMISSION---------------------------------//

int hops;
double prob ;
cout<<"Number of hopes:  ";
cin>>hops ;
cout<<"Crossover probability [between 0 & 1]: ";
cin>>prob ;

int errors=0 ;
if(hops==1)
{
    for(int i =0 ; i<transmit.size() ; i++)
    {
     double x=(((double) rand() +(999*i)) / (RAND_MAX));
     cout<<"x="<<x<<endl;
      if( x<=prob)
       {
         //cout<<"x="<<x<<endl;
         if(transmit[i]==0)
         {
          transmit[i] = 1;
          errors++;
         }

         else
         {
          transmit[i] = 0;
          errors++ ;
         }

       }
    }
}
else

{

    for(int i =0 ; i<transmit.size() ; i++)
    {
      if(  ((double) rand() / (RAND_MAX)) <= 2*prob*(1-prob))
       if(transmit[i]==0)
         {
          transmit[i] = 1;
          errors++;
         }

         else
         {
          transmit[i] = 0;
          errors++ ;
         }
    }

}
cout<<endl;
 //------------------------------------------RECEIVER---------------------------------------//
    cout<<"\n-----------Receiver side--------- ";
    cout<<endl;
    cout<<"\nReceived Frame: "<<endl;
     for(i=0;i<transmit.size();i++)
    {
        cout<<transmit[i]<<" ";
    }
    cout<<endl<<endl;
    cout<<"No of errors : "<<errors<<endl ;


   for(int i=0;i<Dataword_size;i++)
     {
        j=0;
        k=i;
        if (transmit[k]>=gen[j])
        {
            for(j=0,k=i;j<gen.size();j++,k++)
            {
                if((transmit[k]==1 && gen[j]==1) || (transmit[k]==0 && gen[j]==0))
                {
                    transmit[k]=0;
                }
                else
                {
                    transmit[k]=1;
                }
            }
        }
    }
    int r[30];
    for(int i=0,j=Dataword_size;i<bits;i++,j++)
    {
        r[i]=transmit[j];
    }
    cout<<"\nAfter Dividing The Remainder is: ";

    for(i=0;i<bits;i++)
    {
        cout<<r[i]<<" ";
    }

    int flag=0;
    for(i=0;i<bits;i++)
    {
        if(r[i]!=0)
        {
            flag=1;
            break;
        }
    }

    if(flag==0)
    {
        cout<<"\n\nSince Remainder is 0 therefore Message Transmitted is Correct"<<endl;
    }
    else
    {
        cout<<"\n\nSince Remainder is Not 0 therefore Message Transmitted Contains Error"<<endl;
    }
    return 0;
}
