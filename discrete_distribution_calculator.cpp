//discrete distribution calculator......
#include <iostream>
#include<cmath>    //header-file from math-operation.
#include <iomanip>
using namespace std;

class random  //class name
{
    //int n,x;
    float p,q;//binomial-distribution and geometric-distribution variables
   long double  NCR;  //binomial-distribution variable
   long double result; //final answer variable
   long double mean;  //posion-distribution variable
public:
                /* BINOMIAL-DISTRIBUTION METHOD */

    void get_bino_geo()  //binomial-distribution & geometric function-member
    {
        cout<<"\n-->Enter The Success : ";  //prompt
        cin>>p;  //user's input
        if(p<1)  //condition-checker
        {
            q = 1-p;
            cout<<"-->Entered Failure  : "<<q<<endl;
        }
        else{
            cout<<"-->Enter The Failure  : ";
            cin>>q;
        }
    }
    long double fact(int n)  //factorial logic
    {
          if (n == 0 || n == 1)
          return 1;
          else
          return n * fact(n - 1);
    }
    void cal(int n,int x)  //calculation of binomial-distribution
    {
        if(n>=x) //condition-checker
            {
        long double ans_p,ans_q; //local-variables.
        ans_p = pow(p,x);  //power function use
        ans_q = pow(q,(n-x)); //power function use.
        NCR = fact(n) / (fact(x) * fact(n-x)); //logic for NCR
        cout<<"\n\n-->NCR(Combinational-number) : "<<NCR<<endl<<endl; //prompt
        result = NCR*ans_p*ans_q;  //answer of binomial-distribution
        cout<<"\n\n-->Binomial-Distribution : "<<fixed<<result<<endl<<endl; //prompt
            }
            else
            {
                cout<<"\n\n.......MATH.ERROR.......\n\n";  //prompt
            }
    }
    void mean_bino(int n) //calculation of mean of binomial-distribution
    {
        result = n*p;  //final answer store
        cout<<"\n\n-->Mean Of Binomial-Distribution : "<<result<<endl<<endl; //prompt
    }
    void variance_bino(int n) //calculation of variance and S.D of binomial-distribution
    {
        result = n*p*q; //final answer store.
        cout<<"\n\n-->Variance of Binomial-Distribution : "<<result<<endl<<endl;//promot
        result = sqrt(n*p*q); //final answer store.
        cout<<"\n\n-->Standard Deviation of Binomial-Distribution : "<<result<<endl<<endl;//prompt
    }
                           /* POISON-DISTRIBUTION METHOD    */

    void get_lambda() //poison-distribution function member.
    {
        cout<<"-->Enter Mean or Variance For Lambda : "; //prompt
        cin>>mean; //input's User
    }
    void poisson_result(int x)  //poison-distribution calculation
    {
        long double e; //local-variable
        e = exp(-mean); //exp() use
        long double lambda; //local-variable
        lambda = pow(mean,x); //power function use
        result = (e*lambda)/fact(x); //final answer is store
        cout<<"\n\n-->Poisson-Distribution : "<<fixed<<result<<endl<<endl;//prompt
    }
                /* GEOMETRIC-DISTRIBUTION METHOD*/

    void geometric_result(int x) //calculation of geometric-distribution
    {
        long double ans_q; //local-variable
        if(x>1) //condition-checker
        {
        ans_q = pow(q,(x-1)); //store in local-variable
        result = ans_q*p; //final answer store
        cout<<"\n\n-->Geometric-Distribution : "<<fixed<<result<<endl<<endl; //prompt
        }
        else{
            cout<<"-->Invalid Value Of X : "<<x<<endl; //prompt
        }
    }
    void geo_mean() //calculation of mean of geometric-distribution
    {
        result = (1/p); //final answer store
        cout<<"\n\n-->Mean Of Geometric-Distribution : "<<result<<endl<<endl; //prompt
    }
    void geo_variance() //calculation of variance and S.D of geometric-distribution
    {
        result = q/(p*p); //final answer store
        cout<<"\n\n-->Variance Of Geometric-Distribution : "<<result<<endl<<endl; //prompt
        long double result1; //local-varible
        result1 = sqrt(result); // answer store to local-variable
        cout<<"-->Standard-Deviation Of Geometric-Distribution : "<<result1<<endl<<endl;//prompt
    }

};

int main()
{
   cout<<"\t\t\t.............DISCRETE DISTRIBUTION CALCULATOR...............\n\n\n"; //prompt
   cout<<"\t\t*WARNING*(NO CUMULATIVE (X) VALUE ...ONLY FIXED (X) VALUE.....)*WARNING*\n\n\n"; //prompt
   int op,ch; //local-variables
   do{ //do-while is use
   cout<<"Select The Option :----->\n\n"; //prompts
   cout<<"1.Binomial-Distribution Method (Calculator)\n\n";
   cout<<"2.Poisson-Distribution Method (Calculator)\n\n";
   cout<<"3.Geometric-Distribution Method (Calculator)\n\n";
   cout<<"4.EXIT\n";
   cout<<"-->Enter Your Option : ";
   cin>>op; //user's input
   switch(op) //switch condition
   {
case 1: //binomial-distribution method
     random e; //class-object
     cout<<"\t\t\t........Binomial-Distribution Method (Calculator)............\n"; //prompt
    int n,r;//local-variables
    e.get_bino_geo(); //access function
    cout<<"\n-->Enter The Total Number Of Trails  : "; //prompt
    fflush(stdin);//clearer(garbage-values)
    cin>>n;//user's input
    cout<<"-->Enter Fixed (X) Value : "; //prompt
    fflush(stdin);
    cin>>r;
    e.cal(n,r); //access function
    if(n>=r) //condition checker
    {
    do //do-while is use
    {
    cout<<"\nSelect The Option :----->\n\n"; //prompts
    cout<<"1.Mean\n\n";
    cout<<"2.Variance and Standard-Deviation\n\n";
    cout<<"3.Exit\n";
    cout<<"-->Enter Your Option : ";
    cin>>ch; //input
    switch(ch) //switch condition
    {
    case 1:  //mean
        e.mean_bino(n); //access function
        break;
    case 2: //variance//S.D
        e.variance_bino(n); //calling funciton
        break;
    case 3:
        cout<<"\t\t...........(Removed From Mean And Variance System)...........\n\n"; //prompt
        break;
    default:
        cout<<"\n.........Invalid Input......\n\n";
        break;
    }
    }
    while(ch!=3);
    break;
    }
    else{cout<<"\n\n.........MATH.ERROR........\n\n";}
    case 2: //poison-distribution
        random p1;  //class-object
        int x; //local-variable
        cout<<"\t\t\t........Poisson-Distribution Method (Calculator)............\n"; //prompt
        cout<<"\n-->Enter Fixed (X) Value : ";
        cin>>x;//input
        p1.get_lambda(); //calling function
        p1.poisson_result(x); //calling function
        break;
    case 3: //geometric-distribution
        random g; //class-object
        cout<<"\t\t\t........Geometric-Distribution Method (Calculator)............\n";//prompt
         int w;//local-variables
        cout<<"\n-->Enter Fixed (X) Value : ";
        cin>>w; //input
        g.get_bino_geo(); //calling function
        g.geometric_result(w); //calling function
           do //do-while is use
            {
                cout<<"\nSelect The Option :-----> \n\n"; //prompts
                cout<<"1.Mean\n\n";
                cout<<"2.Variance and Standard-Deviation\n\n";
                cout<<"3.Exit\n";
                cout<<"-->Enter Your Choice : ";
                cin>>ch;
                switch(ch)  //switch-conditon
                {
                case 1: //mean
                    g.geo_mean();  //calling function
                    break;
                case 2: //variance//S.D
                    g.geo_variance();//calling function
                    break;
                case 3:
                    cout<<"\t\t.......(Remove From Mean And Variance System).....\n\n";//prompt
                    break;
                default:
                    cout<<"\n.......Invalid Input.....\n\n";
                    break;
                }
            }
            while(ch!=3);
            break;
    case 4:
        cout<<"\n\n\t\t\t..............EXIT FROM SYSTEM...........\n"; //exit prompt
        break;
    default:
        cout<<"\n........Invalid Input........\n\n";
        break;

   }


   }while(op!=4);
    cout<<"\n\n.........Group Members Informations......\n\n";  //group members statements
    cout<<"(1).Pruthvi Tirmal ---> IU1941050077 ---->CE(B)\n\n";
    cout<<"(2).Divya Shaparia ---> IU1941050072 ---->CE(B)\n\n";
    cout<<"(3).Aleem Wadhwaniya ---> IU1941050085 ---->CE(B)\n\n";
    return 0;
}
