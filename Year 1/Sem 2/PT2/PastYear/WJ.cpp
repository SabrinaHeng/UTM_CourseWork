//YONG WERN JIE A22EC0121
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Line{
    private:
        int m;
        int c;
    
    public:
        Line(int _m=1,int _c=0)
        {
            m=_m;
            c=_c;
        }
        void read()
        {
            cout<<"Enter the slope (m) and y-intercept of a line (c) => ";cin>>(*this).m>>(*this).c;
        }
        Line operator-(Line &right)
        {
            Line temp;
            temp.m=(*this).m-right.m;
            temp.c=(*this).c-right.c;
            return temp;
        }
        bool operator!=(Line &right)
        {
            if(((*this).m*right.m)==-1)
            return false;
            else
            return true;
        }
        string toString()
        {
            string str;
            string app1;
            if(m==1)
            {
                str="y=x";
                if(c!=0)
                {
                    app1=to_string(c);
                    if(c>0)
                    str+="+";
                    str.append(app1);
                }
                return str;
            }
            else if(m==-1)
            {
                str="y=-x";
                if(c!=0)
                {
                    app1=to_string(c);
                    if(c>0)
                    str+="+";
                    str.append(app1);
                }
                return str;
            }
            else if(m==0)
            {   
                if(c==0)
                {
                    cout<<"Error occured!";
                    return 0;
                }
                str="y=";
                app1=to_string(c);
                str.append(app1);
                return str;
            }
            else
            {
                string app2;
                str="y=";
                app1=to_string(m);
                app2=to_string(c);
                str+=app1;
                str+="x";
                if(c>0)
                {
                    str+="+";
                    str+=app2;
                }
                return str;
            }
        }

        int getM()const{
            return m;
        }
        int getC()const{
            return c;
        }

        friend void printLines(Line &object)
        {
            cout<<object.toString();
        }
};



int main()
{
    Line object[3]={Line(1,5)};
    cout<<"ORIGINAL LINES"<<endl;
    for (int i=0;i<3;i++)
    {
        cout<<"Line "<<(i+1)<<" slope(m) = "<<object[i].getM()<<", y-intercept(c) = "<<object[i].getC()<<", equation: ";
        printLines(object[i]);
        cout<<endl;
    }
    cout<<endl;
    cout<<"Set the second line from user input"<<endl;
    object[1].read();
    object[2]=object[0]-object[1];
    cout<<endl;
    cout<<"UPDATED LINES"<<endl;
    for (int i=0;i<3;i++)
    {   
        cout<<"Line "<<(i+1)<<" slope(m) = "<<object[i].getM()<<", y-intercept(c) = "<<object[i].getC()<<", equation: ";
        printLines(object[i]);
        cout<<endl;
    }cout<<endl;
    if(object[0]!=object[2])
    {
        cout<<"The first line is not perpendicular to the last line";
    }
    else
    {
        cout<<"The first line is perpendicular to the last line";
    }
    return 0;
}